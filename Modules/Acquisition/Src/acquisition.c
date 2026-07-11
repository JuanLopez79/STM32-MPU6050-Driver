#include "acquisition.h"

#include "mpu6050.h"

static SystemContext_t *system = NULL;

void Acquisition_Init(SystemContext_t *context) {
	system = context;

	MPU6050_Init(&system->acquisition.mpu, system->hardware.hi2c1);
}

void Acquisition_Update(void) {
	MPU6050_Handle_t *mpu = &system->acquisition.mpu;

	MPU6050_ReadAcceleration(mpu);
	MPU6050_ReadGyroscope(mpu);
	MPU6050_ReadTemperature(mpu);

	system->data.imu.acceleration.x = mpu->accel.x;
	system->data.imu.acceleration.y = mpu->accel.y;
	system->data.imu.acceleration.z = mpu->accel.z;

	system->data.imu.angularRate.x = mpu->gyro.x;
	system->data.imu.angularRate.y = mpu->gyro.y;
	system->data.imu.angularRate.z = mpu->gyro.z;

	system->data.imu.temperature = mpu->temperature;
}

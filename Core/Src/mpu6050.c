#include "mpu6050.h"
#include "mpu6050_registers.h"

/*=========================================================
 *              Funciones privadas
 *========================================================*/

static HAL_StatusTypeDef MPU6050_WriteRegister(MPU6050_Handle_t *mpu,
		uint8_t reg, uint8_t data) {
	return HAL_I2C_Mem_Write(mpu->hi2c,
	MPU6050_I2C_ADDRESS, reg,
	I2C_MEMADD_SIZE_8BIT, &data, 1,
	HAL_MAX_DELAY);
}

static HAL_StatusTypeDef MPU6050_ReadRegister(MPU6050_Handle_t *mpu,
		uint8_t reg, uint8_t *data) {
	return HAL_I2C_Mem_Read(mpu->hi2c,
	MPU6050_I2C_ADDRESS, reg,
	I2C_MEMADD_SIZE_8BIT, data, 1,
	HAL_MAX_DELAY);
}

static HAL_StatusTypeDef MPU6050_ReadRegisters(MPU6050_Handle_t *mpu,
		uint8_t reg, uint8_t *buffer, uint16_t length) {
	return HAL_I2C_Mem_Read(mpu->hi2c,
	MPU6050_I2C_ADDRESS, reg,
	I2C_MEMADD_SIZE_8BIT, buffer, length,
	HAL_MAX_DELAY);
}

HAL_StatusTypeDef MPU6050_Init(MPU6050_Handle_t *mpu, I2C_HandleTypeDef *hi2c) {
	HAL_StatusTypeDef status;
	uint8_t who_am_i;

	if ((mpu == NULL) || (hi2c == NULL)) {
		return HAL_ERROR;
	}

	mpu->hi2c = hi2c;

	status = MPU6050_WriteRegister(mpu,
	MPU6050_REG_PWR_MGMT_1,
	MPU6050_RESET_COMMAND);

	if (status != HAL_OK) {
		return status;
	}

	HAL_Delay(100);

	status = MPU6050_WriteRegister(mpu,
	MPU6050_REG_PWR_MGMT_1,
	MPU6050_WAKE_COMMAND);

	if (status != HAL_OK) {
		return status;
	}

	status = MPU6050_WriteRegister(mpu,
	MPU6050_REG_ACCEL_CONFIG,
	MPU6050_ACCEL_RANGE_2G);

	if (status != HAL_OK) {
		return status;
	}

	status = MPU6050_WriteRegister(mpu,
	MPU6050_REG_GYRO_CONFIG,
	MPU6050_GYRO_RANGE_250DPS);

	if (status != HAL_OK) {
		return status;
	}

	status = MPU6050_ReadWhoAmI(mpu, &who_am_i);

	if (status != HAL_OK) {
		return status;
	}

	if ((who_am_i != MPU6050_WHO_AM_I_ORIGINAL)
			&& (who_am_i != MPU6050_WHO_AM_I_CLONE)) {
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef MPU6050_ReadAcceleration(MPU6050_Handle_t *mpu) {
	uint8_t buffer[6];
	HAL_StatusTypeDef status;

	int16_t raw_x;
	int16_t raw_y;
	int16_t raw_z;

	if (mpu == NULL) {
		return HAL_ERROR;
	}

	status = MPU6050_ReadRegisters(mpu,
	MPU6050_REG_ACCEL_XOUT_H, buffer, sizeof(buffer));

	if (status != HAL_OK) {
		return status;
	}

	raw_x = (int16_t) ((buffer[0] << 8) | buffer[1]);

	raw_y = (int16_t) ((buffer[2] << 8) | buffer[3]);

	raw_z = (int16_t) ((buffer[4] << 8) | buffer[5]);

	mpu->accel.x = (float) raw_x / MPU6050_ACCEL_SENSITIVITY;
	mpu->accel.y = (float) raw_y / MPU6050_ACCEL_SENSITIVITY;
	mpu->accel.z = (float) raw_z / MPU6050_ACCEL_SENSITIVITY;

	return HAL_OK;
}

HAL_StatusTypeDef MPU6050_ReadGyroscope(MPU6050_Handle_t *mpu) {
	uint8_t buffer[6];
	HAL_StatusTypeDef status;

	int16_t raw_x;
	int16_t raw_y;
	int16_t raw_z;

	if (mpu == NULL) {
		return HAL_ERROR;
	}

	status = MPU6050_ReadRegisters(mpu,
	MPU6050_REG_GYRO_XOUT_H, buffer, sizeof(buffer));

	if (status != HAL_OK) {
		return status;
	}

	raw_x = (int16_t) ((buffer[0] << 8) | buffer[1]);

	raw_y = (int16_t) ((buffer[2] << 8) | buffer[3]);

	raw_z = (int16_t) ((buffer[4] << 8) | buffer[5]);

	mpu->gyro.x = (float) raw_x / MPU6050_GYRO_SENSITIVITY;
	mpu->gyro.y = (float) raw_y / MPU6050_GYRO_SENSITIVITY;
	mpu->gyro.z = (float) raw_z / MPU6050_GYRO_SENSITIVITY;

	return HAL_OK;
}

HAL_StatusTypeDef MPU6050_ReadTemperature(MPU6050_Handle_t *mpu) {
	uint8_t buffer[2];
	HAL_StatusTypeDef status;

	int16_t raw_temperature;

	if (mpu == NULL) {
		return HAL_ERROR;
	}

	status = MPU6050_ReadRegisters(mpu,
	MPU6050_REG_TEMP_OUT_H, buffer, sizeof(buffer));

	if (status != HAL_OK) {
		return status;
	}

	raw_temperature = (int16_t) ((buffer[0] << 8) | buffer[1]);

	mpu->temperature = ((float) raw_temperature / 340.0f) + 36.53f;

	return HAL_OK;
}

HAL_StatusTypeDef MPU6050_ReadWhoAmI(MPU6050_Handle_t *mpu, uint8_t *id) {
	if ((mpu == NULL) || (id == NULL)) {
		return HAL_ERROR;
	}

	return MPU6050_ReadRegister(mpu,
	MPU6050_REG_WHO_AM_I, id);
}

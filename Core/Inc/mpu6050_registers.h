#ifndef MPU6050_REGISTERS_H
#define MPU6050_REGISTERS_H

/*=========================================================
 *                  Direcciones I2C
 *========================================================*/

#define MPU6050_I2C_ADDRESS            (0x68 << 1)

/*=========================================================
 *                  Registros
 *========================================================*/

#define MPU6050_REG_PWR_MGMT_1         0x6B

#define MPU6050_REG_WHO_AM_I           0x75

#define MPU6050_REG_ACCEL_CONFIG       0x1C

#define MPU6050_REG_GYRO_CONFIG        0x1B

#define MPU6050_REG_ACCEL_XOUT_H       0x3B

#define MPU6050_REG_GYRO_XOUT_H        0x43

#define MPU6050_REG_TEMP_OUT_H         0x41

/*=========================================================
 *                  Valores de configuración
 *========================================================*/

#define MPU6050_RESET_COMMAND         0x80
#define MPU6050_WAKE_COMMAND          0x00

#define MPU6050_ACCEL_RANGE_2G        0x00
#define MPU6050_GYRO_RANGE_250DPS     0x00

#define MPU6050_WHO_AM_I_ORIGINAL     0x68
#define MPU6050_WHO_AM_I_CLONE        0x70

/*=========================================================
 *              Sensibilidad (±2g)
 *========================================================*/

#define MPU6050_ACCEL_SENSITIVITY      16384.0f

/*=========================================================
 *              Sensibilidad (±250 °/s)
 *========================================================*/

#define MPU6050_GYRO_SENSITIVITY       131.0f

#endif

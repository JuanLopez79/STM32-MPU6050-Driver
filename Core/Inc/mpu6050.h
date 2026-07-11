#ifndef MPU6050_H
#define MPU6050_H

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/*=========================================================
 *                      Tipos de datos
 *========================================================*/

/**
 * @brief Aceleración en unidades físicas (g).
 */
typedef struct
{
    float x;
    float y;
    float z;

} MPU6050_Accel_t;


/**
 * @brief Velocidad angular (°/s).
 */
typedef struct
{
    float x;
    float y;
    float z;

} MPU6050_Gyro_t;


/**
 * @brief Información del sensor.
 */
typedef struct
{
    I2C_HandleTypeDef *hi2c;

    MPU6050_Accel_t accel;

    MPU6050_Gyro_t gyro;

    float temperature;

} MPU6050_Handle_t;


/*=========================================================
 *                  API pública
 *========================================================*/

HAL_StatusTypeDef MPU6050_Init(
        MPU6050_Handle_t *mpu,
        I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef MPU6050_ReadAcceleration(
        MPU6050_Handle_t *mpu);

HAL_StatusTypeDef MPU6050_ReadGyroscope(
        MPU6050_Handle_t *mpu);

HAL_StatusTypeDef MPU6050_ReadTemperature(
        MPU6050_Handle_t *mpu);

HAL_StatusTypeDef MPU6050_ReadWhoAmI(
        MPU6050_Handle_t *mpu,
        uint8_t *id);

#ifdef __cplusplus
}
#endif

#endif

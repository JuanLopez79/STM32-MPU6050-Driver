#ifndef SYSTEM_CONTEXT_H
#define SYSTEM_CONTEXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "i2c.h"
#include "usart.h"
#include "mpu6050.h"

/*=========================================================
 * Tipos genéricos
 *=========================================================*/

typedef struct {
	float x;
	float y;
	float z;

} Vector3f_t;

/*=========================================================
 * Hardware
 *=========================================================*/

typedef struct {
	I2C_HandleTypeDef *hi2c1;
	UART_HandleTypeDef *huart2;

} HardwareContext_t;

/*=========================================================
 * Datos publicados por el sistema
 *=========================================================*/

typedef struct {
	Vector3f_t acceleration;

	Vector3f_t angularRate;

	float temperature;

} ImuData_t;

typedef struct {
	Vector3f_t acceleration;

	Vector3f_t angularRate;

	float temperature;

} MotionData_t;

typedef struct {
	ImuData_t imu;

	MotionData_t motion;

} DataContext_t;

/*=========================================================
 * Contextos internos de módulos
 *=========================================================*/

typedef struct {
	MPU6050_Handle_t mpu;

} AcquisitionContext_t;

typedef struct {

} ProcessingContext_t;

/*=========================================================
 * Contexto general del sistema
 *=========================================================*/

typedef struct {
	HardwareContext_t hardware;

	DataContext_t data;

	AcquisitionContext_t acquisition;

	ProcessingContext_t processing;

} SystemContext_t;

#ifdef __cplusplus
}
#endif

#endif

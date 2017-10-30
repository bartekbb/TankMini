/*
 * motors.h
 *
 *  Created on: 24.10.2017
 *      Author: jurek
 */

#ifndef APPLICATION_USER_MOTORS_H_
#define APPLICATION_USER_MOTORS_H_

#include "stm32f1xx_hal.h"
#include "tim.h"

typedef struct Motor {
	int speed;
	int correction;
	uint8_t isCorrection;
	uint8_t isPIDEnable;
	float kp, ki, kd;


} Motor;



void motor_Set_Speed(Motor* LF, Motor* LR, Motor* RF, Motor* RR );
/* Function sets speeds to CCRx registers */

void motor_Calculate_Speed(Motor* motor);
/* Function calculates new speed values if closed control loop mode is enabled */

void motor_Init_With_Correction (Motor* LF, Motor* RF);

#endif /* APPLICATION_USER_MOTORS_H_ */

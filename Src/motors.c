/*
 * motors.c
 *
 *  Created on: 24.10.2017
 *      Author: jurek
 */


#include "motors.h"


Motor Left_F, Left_R, Right_F, Right_R;

//Debug vars
uint8_t L_A1, L_A2, R_A1, R_A2;
//

void motor_Speed(Motor* m, int value){
	m->speed = value;
}

void motor_Set_Speed_HW(Motor* LF, Motor* LR, Motor* RF, Motor* RR ){
/* Function sets speed values to TIM3 registers and to GPIO control pins
 * Arguments are pointers to structures of type Motor
 * LF - Left Front Motor | RF - Right Front Motor
 * LR - Left Rear  Motor | RR - Right Rear  Motor */
	//motor_Calculate_Speed(LF);
	//motor_Calculate_Speed(LR);
	//motor_Calculate_Speed(RF);
	//motor_Calculate_Speed(RR);

	if(LR->speed > 0 ){
		if(LR->speed <100) TIM3->CCR1 = LR->speed;
		else TIM3->CCR1=100;
	}
	else{
		if(LR->speed >-100) TIM3->CCR1 = -(LR->speed);
		else {TIM3->CCR1=100;}
	}
	if(LF->speed > 0 ){
		if(LF->speed <100) TIM3->CCR2 = LF->speed;
		else TIM3->CCR2=100;
	}
	else{
		if(LF->speed >-100) TIM3->CCR2 = -(LF->speed);
		else TIM3->CCR2=100;
	}
	if(RR->speed > 0 ){
		if(RR->speed <100) TIM3->CCR3 = RR->speed;
		else TIM3->CCR3=100;
	}
	else{
		if(RR->speed >-100) TIM3->CCR3 = -(RR->speed);
		else TIM3->CCR3=100;
	}
	if(RF->speed > 0 ){
		if(RF->speed <100) TIM3->CCR4 = RF->speed;
		else TIM3->CCR4=100;
	}
	else{
		if(RF->speed >-100) TIM3->CCR4 = -(RF->speed);
		else TIM3->CCR4=100;
	}
	if(LR->speed > 0){
		L_A1 = 1; L_A2 = 0;
		HAL_GPIO_WritePin(L_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(L_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_RESET);
	}else {
		if(LR->speed == 0){
			L_A1 = 1; L_A2 = 1;
			HAL_GPIO_WritePin(L_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(L_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_SET);
		}
		else{
			L_A1 = 0; L_A2 = 1;
			HAL_GPIO_WritePin(L_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(L_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_SET);
		}
	}

	if(RR->speed > 0){
		R_A1 = 1; R_A2 = 0;
		HAL_GPIO_WritePin(R_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(R_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_RESET);
	}else {
		if(RR->speed == 0){
			R_A1 = 1; R_A2 = 1;
			HAL_GPIO_WritePin(R_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(R_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_SET);
		}
		else{
			R_A1 = 0; R_A2 = 1;
			HAL_GPIO_WritePin(R_A1_GPIO_Port,L_A1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(R_A2_GPIO_Port,L_A2_Pin, GPIO_PIN_SET);
		}
	}

}

void motor_Init(Motor * m){
	m->correction = 0;
	m->isCorrection = 0;
	m->isPIDEnable = 0;
	m->kd = 0;
	m->kp = 0;
	m->ki = 0;
	m->speed = 0;
}

void motor_Init_With_Correction (Motor* m){
	m->correction = 5;
	m->isCorrection = 1;
	m->isPIDEnable = 0;
	m->kd = 0;
	m->kp = 0;
	m->ki = 0;
	m->speed = 0;

}

void motor_Calculate_Speed(Motor* motor){
	if (motor->isPIDEnable == 1){

	}
	else{
		if( motor->isCorrection == 1){
			motor->speed = motor->speed + motor->correction;
		}
	}

}



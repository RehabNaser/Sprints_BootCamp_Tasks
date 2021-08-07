/*
 * File Name: Motor_Config.c
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: C File for Motor Configuration ...
 */ 
 
#include "Motor.h"

Str_MotorConfig_t gastr_MotorConfig[MOTORS_MAX_NUMBERS][MOTOR_PINS_NUMBERS] = {
																				{{PORT_B,PIN3,PIN_OUTPUT}}
																			  };

uint8_t gau8_MotorsEnablePin[MOTORS_MAX_NUMBERS] = {
														PWM_CHANNEL_OC0
													};
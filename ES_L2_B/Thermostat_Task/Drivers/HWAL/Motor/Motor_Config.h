/*
 * File Name: Motor_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for Motor Configuration ...
 */ 
 
#ifndef __MOTOR_CONFIG__
#define __MOTOR_CONFIG__

#define MOTORS_MAX_NUMBERS 1
#define MOTOR_PINS_NUMBERS 1


#define MOTOR_ENABLE_PIN 0
#define MOTOR_DIRECTION1_PIN 1
#define MOTOR_DIRECTION2_PIN 2


enum Enu_MotorNumber
{
	MOTOR1 = 0,
	MOTOR2 = 1
};

enum Enu_MotorDirection
{
	BACKWARD = 0,
	FORWARD = 1
};

typedef struct Str_MotorConfig
{
	uint8_t MotorPort;
	uint8_t MotorPin;
	uint8_t MotorDirection;
}Str_MotorConfig_t ;

#endif
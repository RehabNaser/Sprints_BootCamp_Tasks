/*
 * File Name: Motor.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for Motors...
 */ 

#ifndef __MOTOR__
#define __MOTOR__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "Pwm.h"
#include "Motor_Config.h"
#include "Motor_RetVal.h"

//FUNCTIONS PROTOTYPES
uint8_t MotorInit(void);
uint8_t MotorStart(uint8_t MotorNumber);
uint8_t MotorStop(uint8_t MotorNumber);
uint8_t MotorSetSpeed(uint8_t MotorNumber,uint8_t MotorDuty);

#endif
/*
 * File Name: Speed_Control_System.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The Speed Control System ...
 */ 

#ifndef __SPEED_CONTROL_SYSTEM__
#define __SPEED_CONTROL_SYSTEM__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Pwm.h"
#include "Gpio.h"
#include "Button.h"

#define SPEED_30 30
#define SPEED_60 60
#define SPEED_90 90


//FUNCTIONS PROTOTYPES
void SystemInit(void);
void SystemUpdate(void);

#endif
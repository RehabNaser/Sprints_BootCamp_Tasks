/*
 * File Name: Thermostat.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The Thermostat Project ...
 */ 

#ifndef __THERMOSTAT__
#define __THERMOSTAT__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Motor.h"
#include "LCD.h"
#include "Keypad.h"
#include "LM35.h"

#define TEMPERATURE_MAX_DIGITS 2

//FUNCTIONS PROTOTYPES
void SystemInit(void);
void SystemUpdate(void);

#endif
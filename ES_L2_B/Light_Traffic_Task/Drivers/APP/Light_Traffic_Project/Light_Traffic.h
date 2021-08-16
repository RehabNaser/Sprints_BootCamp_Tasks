/*
 * File Name: Light_Traffic.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The Light Traffic Project ...
 */ 

#ifndef __LIGHT_TRAFFIC__
#define __LIGHT_TRAFFIC__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"
#include "DIO.h"
#include "LED.h"
#include "String.h"

enum Enu_LEDNames
{
	GREEN_LED	= LED1,
	YELLOW_LED 	= LED2,
	RED_LED 	= LED3
};

//FUNCTIONS PROTOTYPES
void SystemInit(void);
void SystemUpdate(void);

#endif
/*
 * File Name: LED.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for LEDs...
 */ 

#ifndef __LED__
#define __LED__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "LED_Config.h"
#include "LED_RetVal.h"


//FUNCTIONS PROTOTYPES
uint8_t LED_Init(void);
uint8_t LED_On(uint8_t LEDNumber);
uint8_t LED_Off(uint8_t LEDNumber);
uint8_t LED_Toggle(uint8_t LEDNumber);
uint8_t LED_Status(uint8_t LEDNumber,ptr_uint8_t LEDState);

#endif
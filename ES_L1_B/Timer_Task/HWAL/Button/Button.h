/*
 * File Name: Button.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for buttons...
 */ 

#ifndef __BUTTON__
#define __BUTTON__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpio.h"
#include "Button_Config.h"
#include "Button_RetVal.h"


//FUNCTIONS PROTOTYPES
uint8_t ButtonInit(void);
uint8_t ButtonRead(uint8_t ButtonNumber,ptr_uint8_t ButtonState);
uint8_t ButtonStillPressed(uint8_t ButtonNumber);

#endif
/*
 * File Name: LED.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for LEDs...
 */ 

#include "LED.h"

extern Str_LEDConfig_t gastr_LEDConfig[];
													
uint8_t LED_Init(void)
{
	for(uint8_t au8_IterationNo=0;au8_IterationNo<LEDS_MAX_NUMBERS;au8_IterationNo++)
	{
		GpioSetPinDirection(	gastr_LEDConfig[au8_IterationNo].LEDPort,
								gastr_LEDConfig[au8_IterationNo].LEDPin,
								gastr_LEDConfig[au8_IterationNo].LEDDirection );			
	}	
}

uint8_t LED_On(uint8_t LEDNumber)
{
	DIO_WritePin(	gastr_LEDConfig[LEDNumber].LEDPort,
					gastr_LEDConfig[LEDNumber].LEDPin,
					PIN_HIGH );	
}

uint8_t LED_Off(uint8_t LEDNumber)
{
	DIO_WritePin(	gastr_LEDConfig[LEDNumber].LEDPort,
					gastr_LEDConfig[LEDNumber].LEDPin,
					PIN_LOW );		
}

uint8_t LED_Toggle(uint8_t LEDNumber)
{
	DIO_TogglePin(	gastr_LEDConfig[LEDNumber].LEDPort,
					gastr_LEDConfig[LEDNumber].LEDPin );		
}

uint8_t LED_Status(uint8_t LEDNumber,ptr_uint8_t LEDState)
{
	DIO_ReadPin(	gastr_LEDConfig[LEDNumber].LEDPort,
					gastr_LEDConfig[LEDNumber].LEDPin,
					LEDState );		
}
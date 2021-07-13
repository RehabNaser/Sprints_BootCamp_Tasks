/*
 * File Name: Led_Control_System.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The Led Control System ...
 */ 
 
 
#include "Led_Control_System.h" 

void SystemInit(void)
{
	ButtonInit();
	GpioSetPinDirection(PORT_B,PIN5,PIN_OUTPUT);
}

void SystemUpdate(void)
{
	uint8_t au8_ButtonState = NO_PRESSED;
	static uint8_t au8_ButtonFlag = 0;
	for(uint32_t i=0;i<100000;i++);//For Debouncing
	ButtonRead(BUTTON1,&au8_ButtonState);
	if(au8_ButtonState==PRESSED&&au8_ButtonFlag==0)
	{
		GpioTogglePin(PORT_B,PIN5);
		au8_ButtonFlag=1;
	}
	else if(au8_ButtonState==NO_PRESSED&&au8_ButtonFlag==1)
	{
		au8_ButtonFlag=0;
	}
}
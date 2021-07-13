/*
 * File Name: Button.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for buttons...
 */ 

#include "Button.h"

extern Str_ButtonConfig_t gastr_ButtonConfig[];
													
uint8_t ButtonInit(void)
{
	for(uint8_t au8_IterationNo=0;au8_IterationNo<BUTTONS_MAX_NUMBERS;au8_IterationNo++)
	{
		GpioSetPinDirection(	gastr_ButtonConfig[au8_IterationNo].ButtonPort,
								gastr_ButtonConfig[au8_IterationNo].ButtonPin,
								gastr_ButtonConfig[au8_IterationNo].ButtonDirection );
						   
		if(gastr_ButtonConfig[au8_IterationNo].ButtonConnectionMode == Pullup_SW)
		{
			GpioEnablePinPullup(	gastr_ButtonConfig[au8_IterationNo].ButtonPort,
									gastr_ButtonConfig[au8_IterationNo].ButtonPin );
		}			
	}
}

uint8_t ButtonRead(uint8_t ButtonNumber,ptr_uint8_t ButtonState)
{
	uint8_t au8_PinData; 
	GpioReadPin(	gastr_ButtonConfig[ButtonNumber].ButtonPort,
					gastr_ButtonConfig[ButtonNumber].ButtonPin,
					&au8_PinData );
	if(au8_PinData == PIN_HIGH)
	{
		if(gastr_ButtonConfig[ButtonNumber].ButtonConnectionMode == Pulldown)
		{
			*ButtonState = PRESSED;
		}
		else
		{
			*ButtonState = NO_PRESSED;
		}
	}
	else
	{
		if(gastr_ButtonConfig[ButtonNumber].ButtonConnectionMode == Pulldown)
		{
			*ButtonState = NO_PRESSED;
		}
		else
		{
			*ButtonState = PRESSED;
		}		
	}

}

uint8_t ButtonStillPressed(uint8_t ButtonNumber)
{
	uint8_t au8_PinData; 
					
	if(gastr_ButtonConfig[ButtonNumber].ButtonConnectionMode == Pulldown)
	{
		do
		{
			GpioReadPin(	gastr_ButtonConfig[ButtonNumber].ButtonPort,
							gastr_ButtonConfig[ButtonNumber].ButtonPin,
							&au8_PinData );
							
		}while(au8_PinData==PIN_HIGH);
	}
	else
	{
		do
		{
			GpioReadPin(	gastr_ButtonConfig[ButtonNumber].ButtonPort,
			gastr_ButtonConfig[ButtonNumber].ButtonPin,
			&au8_PinData );
			
		}while(au8_PinData==PIN_LOW);
	}	
}
/*
 * File Name: LM35.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for LM35 Temperature Sensor...
 */ 

#include "LM35.h"

extern Str_LM35Config_t gastr_LM35Config[];
									
uint8_t LM35_init(void)
{
	for(uint8_t au8_IterationNo=0;au8_IterationNo<LM35_NUMBERS;au8_IterationNo++)
	{
		DIO_SetPinDirection(	gastr_LM35Config[au8_IterationNo].LM35Port,
								gastr_LM35Config[au8_IterationNo].LM35Pin,
								gastr_LM35Config[au8_IterationNo].LM35Direction );			
	}
	ADC_Init(ADC_0);
}
									
uint8_t LM35_Read(uint8_t LM35Number)
{
	ADC_StartConversion(ADC_0,LM35Number);	
}

uint8_t LM35_CalculateTemp(ptr_uint8_t TemperatureVal)
{
	uint16_t DigitalValue;
	float32_t AnalogValue;
	ADC_GetConversionValue(ADC_0,&DigitalValue);
	ADC_ConvertReadingFromDigitalToAnalog(DigitalValue,&AnalogValue);
	*TemperatureVal=(uint8_t)(AnalogValue/LM35_VOLTAGE_PER_DEGREE);	
}
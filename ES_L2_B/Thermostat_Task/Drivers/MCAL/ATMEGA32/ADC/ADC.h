/*
 * File Name: ADC.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for ADC peripheral....
 */ 

#ifndef __ADC__
#define __ADC__

//FILES INCLUDING
//#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MC_REGISTERS.h"
#include "ADC_Config.h"
#include "ADC_RetVal.h"


//FUNCTIONS PROTOTYPES
uint8_t ADC_Init(uint8_t ADCNumber);
uint8_t ADC_Enable(uint8_t ADCNumber);
uint8_t ADC_Disable(uint8_t ADCNumber);

uint8_t ADC_StartConversion(uint8_t ADCNumber,uint8_t ADCPinNumber);
uint8_t ADC_GetConversionValue(uint8_t ADCNumber,ptr_uint16_t DigitalValue);//With Polling
uint8_t ADC_ConvertReadingFromDigitalToAnalog(uint16_t DigitalValue,float32_t* AnalogValue);

uint8_t ADC_EnableInterrupt(uint8_t ADCNumber);
uint8_t ADC_DisableInterrupt(uint8_t ADCNumber);
uint8_t ADC_SetCallback(uint8_t ADCNumber,Ptr_VoidFuncVoid_t Callback);

#endif
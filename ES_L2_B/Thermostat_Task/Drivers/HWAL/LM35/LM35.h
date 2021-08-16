/*
 * File Name: LM35.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for LM35 Temperature Sensor ...
 */ 

#ifndef __LM35__
#define __LM35__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC.h"
#include "LM35_Config.h"
#include "LM35_RetVal.h"


//FUNCTIONS PROTOTYPES
uint8_t LM35_init(void);
uint8_t LM35_Read(uint8_t LM35Number);
uint8_t LM35_CalculateTemp(ptr_uint8_t TemperatureVal);

#endif
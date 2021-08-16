/*
 * File Name: LM35_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for LM35 Temperature Sensor Configuration ...
 */ 
 
#ifndef __LM35_CONFIG__
#define __LM35_CONFIG__

#define LM35_NUMBERS 1

#define LM35_VOLTAGE_PER_DEGREE (0.01)

enum Enu_LM35Number
{
	LM35_1 = 0,
};

typedef struct Str_LM35Config
{
	uint8_t LM35Port;
	uint8_t LM35Pin;
	uint8_t LM35Direction;
}Str_LM35Config_t ;

#endif
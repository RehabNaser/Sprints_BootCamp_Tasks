/*
 * File Name: LED_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for LEDs Configuration ...
 */ 
 
#ifndef __LED_CONFIG__
#define __LED_CONFIG__

#define LEDS_MAX_NUMBERS 3

enum Enu_LEDNumber
{
	LED1 = 0,
	LED2 = 1,
	LED3 = 2,
};

enum Enu_LEDState
{
	OFF = 0,
	ON	= 1
};

typedef struct Str_LEDConfig
{
	uint8_t LEDPort;
	uint8_t LEDPin;
	uint8_t LEDDirection;
}Str_LEDConfig_t ;

#endif
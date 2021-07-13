/*
 * File Name: Button_Config.h
 * Creation Date: 09/07/2020
 * Author: Rehab
 * Description: Header File for Button Configuration ...
 */ 
 
#ifndef __BUTTON_CONFIG__
#define __BUTTON_CONFIG__

#define BUTTONS_MAX_NUMBERS 2

enum Enu_ButtonNumber
{
	BUTTON1 = 0,
};

enum Enu_ButtonState
{
	NO_PRESSED = 0,
	PRESSED = 1
};

enum Button_ConnectionMode
{
	Pulldown = 0,
	Pullup_HW = 1,
	Pullup_SW = 2
};

typedef struct Str_ButtonConfig
{
	uint8_t ButtonPort;
	uint8_t ButtonPin;
	uint8_t ButtonDirection;
	uint8_t ButtonConnectionMode;
}Str_ButtonConfig_t ;

#endif
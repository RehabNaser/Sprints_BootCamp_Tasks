/*
 * File Name: Master_Chat.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The Master Chat Project ...
 */ 

#ifndef __MASTER_CHAT__
#define __MASTER_CHAT__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI.h"
#include "UART.h"

#define MESSAGE_ARRAY_SIZE 256
#define MASSAGE_MAX_LENGHT 255

enum Enu_MessageLengthState
{
	LENGTH_IS_OK 	=	0,
	LENGTH_IS_LONG 	=	1
};

//FUNCTIONS PROTOTYPES
void SystemInit(void);
void SystemUpdate(void);

#endif
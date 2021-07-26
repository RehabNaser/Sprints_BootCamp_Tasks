/*
 * File Name: Slave_Chat.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The Slave Chat Project ...
 */ 

#ifndef __SLAVE_CHAT__
#define __SLAVE_CHAT__

//FILES INCLUDING
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"
#include "SPI.h"

#define MESSAGE_ARRAY_SIZE 256

//FUNCTIONS PROTOTYPES
void SystemInit(void);
void SystemUpdate(void);

#endif
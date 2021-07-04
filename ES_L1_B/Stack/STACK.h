/*
 * File Name: Stack.h
 * Creation Date: 02/07/2021
 * Author: Rehab
 * Description: Header File for Stack (Data Structure) Implementation Using Array.....
 */ 
 
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>

#include "STD_TYPES.h"

#define STACK_MAX_SIZE 50

typedef enum StackEmptyState		
{
	NotEmpty = 0,
	Empty = 1
	
}StackEmptyState_t;	

typedef enum StackFullState
{
	NotFull = 0,
	Full = 1
	
}StackFullState_t;

void StackInit(uint8_t Size); 

StackEmptyState_t StackIsEmpty(void); 
StackFullState_t StackIsFull(void); 

uint8_t StackGetSize(void);
uint8_t StackGetLength(void);

void StackPush(uint8_t Data); //Data always is uint8_t
uint8_t StackPop(void);

void StackPrint(void);

#endif
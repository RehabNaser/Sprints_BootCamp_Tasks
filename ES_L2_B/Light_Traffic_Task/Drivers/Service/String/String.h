/*
 * File Name: String.h
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: Header File for The String Service...
 */ 

#ifndef __STRING__
#define __STRING__

//FILES INCLUDING
#include "STD_TYPES.h"


//FUNCTIONS PROTOTYPES
void StringToUpper(ptr_int8_t);
void StringToLower(ptr_int8_t);
uint32_t StringLength(const ptr_int8_t);
void StringCopy(ptr_int8_t,const ptr_int8_t);
void StringConcatenate(ptr_int8_t,const ptr_int8_t);
int32_t StringCompare(const ptr_int8_t,const ptr_int8_t);
void StringReverse(ptr_int8_t);

#endif



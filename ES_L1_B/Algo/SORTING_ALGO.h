/*
 * File Name: SORTING_ALGO.h
 * Creation Date: 02/07/2021
 * Author: Rehab
 * Description: Header File for Sorting Algorithms....
 */ 
 
#ifndef SORTING_ALGO_H_
#define SORTING_ALGO_H_

#include "STD_TYPES.h"

typedef enum ArrayState
{
	NotAscending = 0,
	Ascending = 1,
	NotDescending = 0,
	Descending = 2
} ArrayState_t; 

ArrayState_t ArrayIsAscending(ptr_uint32_t Array,uint8_t ArraySize);
ArrayState_t ArrayIsDescending(ptr_uint32_t Array,uint8_t ArraySize);
void BubbleSortingAscending(ptr_uint32_t Array,uint8_t ArraySize);
void BubbleSortingDescending(ptr_uint32_t Array,uint8_t ArraySize);
#endif
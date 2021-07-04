/*
 * File Name: SEARCHING_ALGO.h
 * Creation Date: 02/07/2021
 * Author: Rehab
 * Description: Header File for Searching Algorithms....
 */ 

#ifndef SEARCHING_ALGO_H_
#define SEARCHING_ALGO_H_

#include <stdio.h> 
#include "STD_TYPES.h"
#include "SORTING_ALGO.h"

#define NOT_FOUND 255
 
uint8_t BinarySearch(ptr_uint32_t Array,uint8_t ArraySize,uint32_t Key);

#endif
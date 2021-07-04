/*
 * File Name: BALANCED_PARENTHESES.h
 * Creation Date: 02/07/2021
 * Author: Rehab
 * Description: Header File for Balanced Parentheses App.....
 */ 
 
#ifndef BALANCED_PARENTHESES_H_
#define BALANCED_PARENTHESES_H_

#include <string.h>

#include "STD_TYPES.h"
#include "STACK.h"

#define NOT_BALANCED "NotBalanced"
#define BALANCED "Balanced"

uint8_t* BalancedParentheses(uint8_t* Expression);

#endif
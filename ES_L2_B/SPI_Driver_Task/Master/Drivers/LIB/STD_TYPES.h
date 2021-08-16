/*
 * File Name: STD_TYPES.h
 * Creation Date: 02/07/2021
 * Author: Rehab
 * Description: Header File for standard data types....
 */ 
 
#ifndef __STD_TYPES__
#define __STD_TYPES__

volatile typedef unsigned char				uint8_t;
volatile typedef unsigned short int			uint16_t;
volatile typedef unsigned long int			uint32_t;
volatile typedef unsigned long long int		uint64_t;

volatile typedef signed char 			int8_t;
volatile typedef signed short int 		int16_t;
volatile typedef signed long int 		int32_t;
volatile typedef signed long long int 	int64_t;

volatile typedef float					float32_t;
volatile typedef double					double64_t;

volatile typedef uint8_t* 				ptr_uint8_t;
volatile typedef uint16_t* 				ptr_uint16_t;
volatile typedef uint32_t* 				ptr_uint32_t;
volatile typedef uint64_t* 				ptr_uint64_t;

volatile	typedef int8_t* 				ptr_int8_t;
volatile	typedef int16_t* 				ptr_int16_t;
volatile	typedef int32_t* 				ptr_int32_t;
volatile	typedef int64_t* 				ptr_int64_t;

volatile typedef void(*Ptr_VoidFuncVoid_t)(void);
#endif
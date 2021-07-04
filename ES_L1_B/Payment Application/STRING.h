/*
 * File Name: STRING.h
 * Creation Date: 04/07/2021
 * Author: Rehab
 * Description: Header File for My String Library ....
 */ 
 
#ifndef STRING_H_
#define STRING_H_

void StringToUpper(char*);
void StringToLower(char*);
unsigned int StringLength(const char*);
void StringCopy(char*,const char*);
void StringConcatenate(char*,const char*);
int StringCompare(const char*,const char*);
void StringReverse(char*);

#endif


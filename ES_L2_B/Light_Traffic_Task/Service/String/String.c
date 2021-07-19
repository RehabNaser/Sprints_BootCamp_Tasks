/*
 * File Name: String.c
 * Creation Date: 07/23/2020
 * Author: Rehab
 * Description: C File for The String Service ...
 */ 
 
 
#include"string.h"

//Write a C Function that converts any letter from lowercase to uppercase.
void StringToUpper(ptr_int8_t string)
{
	for(int32_t i=0;string[i]!='\0';i++)
	{
		if((string[i]>=97)&&(string[i]<=122))
		{
			string[i]-=32;
		}
	}
}
//Write a C Function that converts any letter from uppercase to lowercase.
void StringToLower(ptr_int8_t string)
{
	for(int32_t i=0;string[i]!='\0';i++)
	{
		if((string[i]>=65)&&(string[i]<=90))
		{
			string[i]+=32;
		}
	}
}
//Write a C program to find length of string using pointers.
uint32_t StringLength(const ptr_int8_t string)
{
	uint8_t length;
	for(length=0;string[length]!='\0';length++);
	return length;
}
//Write a C program to copy one string to another using pointers.
void StringCopy(ptr_int8_t destination,const ptr_int8_t source)
{
	for(int32_t i=0;source[i]!='\0';i++)
	{
		destination[i]=source[i];
	}	
}
//Write a C program to concatenate two strings using pointers.
void StringConcatenate(ptr_int8_t destination,const ptr_int8_t source)
{
	uint8_t den_len=StringLength(destination);
	for(int32_t i=0;source[i]!='\0';i++,den_len++)
	{
		destination[den_len]=source[i];
	}
}
//Write a C program to compare two strings using pointers.
int32_t StringCompare(const ptr_int8_t string1,const ptr_int8_t string2)
{
	for(int32_t i=0;((string1[i]!='\0')||(string2[i]!='\0'));i++)
	{
		if(string1[i]==string2[i])
		{
			continue;
		}
		else
		{
			return string1[i]-string2[i];
		}
	}
	return 0;
}
//Write a C program to find reverse of a string using pointers.
void StringReverse(ptr_int8_t string)
{
	uint8_t str_len=StringLength(string)-1;
	int8_t temp;	
	for(int32_t i=0;i<str_len;i++,str_len--)
	{
		temp=string[i];
		string[i]=string[str_len];
		string[str_len]=temp;
	}

}

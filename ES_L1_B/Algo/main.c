#include <stdio.h>

#include "STD_TYPES.h"
#include "SEARCHING_ALGO.h"

#define ARRAY_SIZE 5

int main (void)
{
	uint32_t Array[ARRAY_SIZE]={1,2,3,3,5};
	Array[5]=10;
	uint32_t Key = 10;
	uint8_t Index=BinarySearch(Array,ARRAY_SIZE,Key);

	if( Index == NOT_FOUND)
	{
		printf("%d Not Found \n",Key);
	}
	else
	{
		printf("%d Found on %d \n",Key,Index);
	}	
}
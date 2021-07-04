#include "SORTING_ALGO.h"

ArrayState_t ArrayIsAscending(ptr_uint32_t Array,uint8_t ArraySize)
{
	for(uint8_t i=0;i<ArraySize-1;i++)
	{
		if(Array[i]>Array[i+1])
		{
			return NotAscending;
		}
	}
	return Ascending;
}

ArrayState_t ArrayIsDescending(ptr_uint32_t Array,uint8_t ArraySize)
{
	for(uint8_t i=0;i<ArraySize-1;i++)
	{
		if(Array[i]<Array[i+1])
		{
			return NotDescending;
		}
	}
	return Descending;
}

void BubbleSortingAscending(ptr_uint32_t Array,uint8_t ArraySize)
{
	uint32_t Temp;
	uint8_t i=0,SwapingCounter=0;
	do
	{
		SwapingCounter=0;
		for(uint8_t i=0;i<ArraySize-1;i++)
		{
			if(Array[i]>Array[i+1])
			{
				Temp=Array[i];
				Array[i]=Array[i+1];
				Array[i+1]=Temp;
				SwapingCounter++;
			}

		}
		ArraySize--;
	}while(SwapingCounter>0);
}

void BubbleSortingDescending(ptr_uint32_t Array,uint8_t ArraySize)
{
	uint32_t Temp;
	uint8_t i=0,SwapingCounter=0;
	do
	{
		SwapingCounter=0;
		for(uint8_t i=0;i<ArraySize-1;i++)
		{
			if(Array[i]<Array[i+1])
			{
				Temp=Array[i];
				Array[i]=Array[i+1];
				Array[i+1]=Temp;
				SwapingCounter++;
			}

		}
		ArraySize--;
	}while(SwapingCounter>0);
}
#include "SEARCHING_ALGO.h"

uint8_t BinarySearch(ptr_uint32_t Array,uint8_t ArraySize,uint32_t Key)
{
	uint8_t First,Mid;
	int16_t Last;
	ArrayState_t ArraySortingType;
	First=0,Last=ArraySize-1;
	if(!ArrayIsAscending(Array,ArraySize))
	{
		if(!ArrayIsDescending(Array,ArraySize))
		{
			BubbleSortingAscending(Array,ArraySize);
			ArraySortingType = Ascending;
			printf("The Entered Array is sorted in Ascending Order\n");
		}
		else
		{
			ArraySortingType = Descending;
		}
	}
	else
	{
		ArraySortingType = Ascending;
	}
	
	while(First<=Last)
	{
		Mid=(First+Last)/2;
		if(ArraySortingType == Ascending)
		{
			if(Array[Mid]==Key)
			{
				return Mid;
			}
			else if(Array[Mid]>Key)
			{
				Last = Mid-1;
			}
			else
			{
				First = Mid+1;
			}			
		}
		else
		{
			if(Array[Mid]==Key)
			{
				return Mid;
			}
			else if(Array[Mid]>Key)
			{
				First = Mid+1;
			}
			else
			{
				Last = Mid-1;
			}			
			
		}
	}
	return NOT_FOUND;
}
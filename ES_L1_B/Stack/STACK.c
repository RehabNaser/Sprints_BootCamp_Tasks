#include "STACK.h"

uint8_t StackSize, MyStack[STACK_MAX_SIZE];
int8_t StackTop;

void StackInit(uint8_t Size)
{
	StackSize = Size;
	StackTop = -1;
}

StackEmptyState_t StackIsEmpty(void)
{
	if( -1 == StackTop)
	{
		return Empty;
	}
	else
	{
		return NotEmpty;
	}		
}

StackFullState_t StackIsFull(void)
{
	if( StackTop == StackSize)
	{
		return Full;
	}
	else
	{
		return NotFull;
	}
}

uint8_t StackGetSize(void)
{
	return StackSize;
}

uint8_t StackGetLength(void)
{
	return (StackTop + 1);
}

void StackPush(uint8_t Data)
{
	if(StackIsFull())
	{
		printf("Stack is Full, Can't push a new data.\n");
	}
	else
	{
		StackTop++;
		MyStack[StackTop] = Data;
	}
}

uint8_t StackPop(void)
{
	uint8_t Data;
	if(StackIsEmpty())
	{
		printf("Stack is Empty, Can't pop a new data.\n");
		Data = 0;
	}
	else
	{
		Data = MyStack[StackTop];
		StackTop--;
	}
	
	return Data;
}

void StackPrint(void)
{
	for(uint8_t i=0 ; i <= StackTop ; i++)
	{
		printf("%d ",MyStack[i]);
	}
	
	printf("\n");
}
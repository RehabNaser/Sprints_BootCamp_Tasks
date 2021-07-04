#include "BALANCED_PARENTHESES.h"

uint8_t* BalancedParentheses(uint8_t* Expression)
{
	uint8_t ExpressionSize = strlen(Expression);
	
	StackInit(ExpressionSize);
	for(uint8_t i=0; Expression[i]!= '\0'; i++)
	{
		if((Expression[i] == '(') || (Expression[i] == '{'))
		{
			StackPush(Expression[i]);
		}
		else if((Expression[i] == ')'))	
		{
			if(StackPop() != '(')
			{
				return NOT_BALANCED;
			}
		}
		else if((Expression[i]=='}'))
		{
			if(StackPop()!='{')
			{
				return NOT_BALANCED;
			}
		}
	}
	
	if(StackGetLength() == 0)
	{
		return BALANCED;
	}
	else
	{
		return NOT_BALANCED;
	}
}
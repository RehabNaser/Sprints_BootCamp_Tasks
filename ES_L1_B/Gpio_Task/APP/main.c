#include "Led_Control_System.h" 

int main()
{
	SystemInit();
	
	while(1)
	{
		SystemUpdate();
	}
}
#include"STRING.h"

//Write a C Function that converts any letter from lowercase to uppercase.
void StringToUpper(char* string)
{
	for(int i=0;string[i]!='\0';i++)
	{
		if((string[i]>=97)&&(string[i]<=122))
		{
			string[i]-=32;
		}
	}
}
//Write a C Function that converts any letter from uppercase to lowercase.
void StringToLower(char* string)
{
	for(int i=0;string[i]!='\0';i++)
	{
		if((string[i]>=65)&&(string[i]<=90))
		{
			string[i]+=32;
		}
	}
}
//Write a C program to find length of string using pointers.
unsigned int StringLength(const char* string)
{
	unsigned char length;
	for(length=0;string[length]!='\0';length++);
	return length;
}
//Write a C program to copy one string to another using pointers.
void StringCopy(char* destination,const char* source)
{
	for(int i=0;source[i]!='\0';i++)
	{
		destination[i]=source[i];
	}	
}
//Write a C program to concatenate two strings using pointers.
void StringConcatenate(char* destination,const char* source)
{
	unsigned char den_len=StringLength(destination);
	for(int i=0;source[i]!='\0';i++,den_len++)
	{
		destination[den_len]=source[i];
	}
}
//Write a C program to compare two strings using pointers.
int StringCompare(const char* string1,const char* string2)
{
	for(int i=0;((string1[i]!='\0')||(string2[i]!='\0'));i++)
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
void StringReverse(char* string)
{
	unsigned char str_len=StringLength(string)-1;
	char temp;	
	for(int i=0;i<str_len;i++,str_len--)
	{
		temp=string[i];
		string[i]=string[str_len];
		string[str_len]=temp;
	}

}

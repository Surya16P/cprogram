/* Replacing each tab by \t */

#include<stdio.h>

int main()
{
	char c;

	while ((c = getchar()) != EOF)
	{
		if(c == '\t') 
		{
			printf("\\t");
			continue; 
		}
		if(c == '\b')
		{
			printf("\\b");
			continue;
		}
		if(c == '\\')
		{
			printf("\\\\");
			continue;	
		}						
	putchar(c);
	}
	
	return 0;
}
		


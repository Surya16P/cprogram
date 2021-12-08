/* Replacing each string of one or more blanks by a single blank */

#include<stdio.h>

int main()
{
	char c ;
	char blanks = '@';

	while ((c=getchar()) != EOF)
	{
		if (c == ' ')
		{
			if(blanks != ' ')
				putchar(c);
		}
		else		
			putchar(c);
	blanks =c;
	}
	
	return 0;
}
	


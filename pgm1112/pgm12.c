/*one word per  line */

#define OUT 0
#define IN 1

#include <stdio.h>

int main()
{
	int n_word,state;
	char c;

	state = OUT;

	while( (c = getchar()) != EOF)
	{
		if( c == ' ' || c == '\t')
			state = OUT;

		else if(state == OUT)
		{
			state = IN;
		        printf("\n");
			putchar(c);	
		}
		else
			putchar(c);			
	}
	return 0;
}


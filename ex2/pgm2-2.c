/* Loop Equivalent to the For Loop without using && or || */


#include <stdio.h>

int main()
{
	int i,c;
	int lim = 1000;

	for (i = 0; i < lim-1 ;++i)
	{
		if ((c = getchar()) != EOF)
			//putchar(c);


			if (c == '\n') {
				putchar(c);
				continue;
			}
		 else
			 putchar(c);

	
	}
	return 0;
}


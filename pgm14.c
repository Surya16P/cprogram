/* frequencies Horizontal */

#include<stdio.h>

#define LOW 32
#define HIGH 128

int main()
{
	int c,i,j;
	char total[HIGH];

	c = i = j = 0;

	if (i <= HIGH )
	{
		for (i = 0 ; i < HIGH;++i)
		total[i] = 0; 

	while ((c = getchar() ) != EOF)
	{
		++total[c - LOW];
			if (c == '\n')
			{
			for (i = 0;i < HIGH ;++i)
				if (total[i] != 0)
				{
					printf("\n");
					printf("%c",i + LOW);
					for(j = 0;j <total[i]; ++j)
						printf("*");
					
					}
			}
	}
	}
return 0;
}

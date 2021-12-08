/* count blanks,tabs & newline */
#include<stdio.h>

int main()
{
	int b = 0, t = 0, n = 0;
	int a;

	while((a = getchar() )!= EOF)
	{
		if(a == ' ')
			++b;
		else if(a == '\t')
			++t;
		else if(a == '\n')
			++n ;

	}
	printf("Blank is :%d\nTabs is :%d\nNewline is :%d\n",b,t,n);

	return 0;
}



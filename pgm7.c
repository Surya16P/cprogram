/* Line Counting */
#include<stdio.h>
int main()
{
	int i = 0;
	long a = 0;

	while((a = getchar()) != EOF)
		if(a == '\n')
			++i;
	printf(" %d \n",i);
	return 0;
}

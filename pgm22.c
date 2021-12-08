/* celsius to fahrenheit */

#include<stdio.h>


int main()
{
	int fahr, celsius;
	int lower,upper,step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	printf("celsius\tfahr\n");

	while(celsius <= upper)
	{
		fahr = (celsius * 9 / 5 ) + 32;   //formula cel -fahren
		printf("%d\t%d\n",celsius,fahr);
		celsius  += step;
	}

	return 0;
}






/* temperature conversion function */

#include<stdio.h>

void temp(int lower,int upper,int step);

int main()
{
	
   temp(0,300,20);

return 0;

}

void temp(int x,int y,int z)
{
	int fahr,celsius;

	fahr = x;

	while (fahr <= y )
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n",fahr,celsius);
		fahr = fahr + z;
	}
}



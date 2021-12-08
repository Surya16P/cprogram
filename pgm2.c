/*print Fahrenheit-Celsius table
   for fahr = 0,20,....3000 */

#include<stdio.h>
int main()
{
	float fahr, celsius;
	int upper, lower, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr-32.0) ;	//celsius formula using 
		printf("%3.0f\t%6.1f\n", fahr, celsius);
	        fahr = fahr + step;
	}
	return 0;
}	



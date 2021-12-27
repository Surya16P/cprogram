/* binary Search loop */
\
#include <stdio.h>
/*
int main()
{
	int n = -1;
	int s[100] ={0,1,2,3} ;
	if (n > 0){
		for (int i = 0;i < n ; i++)
			if (s[i] > 0) {
				printf("...");
				return i;
			}
	}
	else
		printf("error --n is negative\n");
}

*/
int binary_search(int x,int v[], int n);

int main()
{
	int value;
	int balance[] = {1,2,3,4,5,6,7,8,9,10};

	value = binary_search(9,balance,10);
	printf("%d \n ", value);

	}


int binary_search(int x,int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;
	mid = (low + high ) / 2;

	while (low < high && x != v[mid]) 
	{
	
	//	mid = (low + high) /2;
		
		if (x < v[mid])
			high = mid -1;
		else
			low = mid + 1;
		
//
		mid = (low + high) /2;
		
	}
	if (x == v[mid])
		return mid;
	else
	
	return -1;

return 0;
}


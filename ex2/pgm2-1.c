#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
	/* floating  point calculation */

	
	printf("The Minimum signed char %d\n",-(char)((unsigned char)~0 >> 1) -1); // CHAR is 1BYTE
	printf("The Maximum signed char %d\n",(char)((unsigned char)~0 >> 1));

	printf("The Minimum signed int %d\n",-(int)((unsigned int)~0 >> 1) -1);   // INT is 4BYTE
	printf("The Maximum signed int %d\n",(int)((unsigned int)~0 >> 1));

	printf("The Minimum signed short %d\n",-(short)((unsigned short)~0 >>1) -1); // SHORT is 2BYTE
	printf("The Maximum signed short %d\n",(short)((unsigned short)~0 >>1)) ;

	printf("The Minimum signed long %ld\n",-(long)((unsigned long)~0 >>1) -1); // LONG is 8BYTE
	printf("The Maximum signed long %ld\n",(long)((unsigned long)~0 >>1));


	printf("\n");
	
	printf("The Unsigned char %d\n",(unsigned char)~0 );
	printf("The Unsigned int %u\n",(unsigned int)~0 );
	printf("The Unsigned short %u\n",(short)~0 );
	printf("The Unsigned long %lu\n",(unsigned long)~0 );


	/* header file using*/
	

	printf("\nThe Unsigned char %d\n",(UCHAR_MAX));
	printf("The Unsigned int  %u\n",(INT_MAX));
	printf("The Unsigned short %u\n",(USHRT_MAX));
	printf("The Unsigned long  %lu\n",(ULONG_MAX));

return 0;
}


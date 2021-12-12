/* detab */

#include <stdio.h>

#define TAB 8

int main()
{
	int c,base,size;

	base = 0;
	size = 1;

	while ((c = getchar())!= EOF)
	{
		if(c == '\t')
		{
	           base = TAB - ((size -1 )% TAB); 		
  			while(base > 0)	
				{
		  	    putchar('@');
			    ++size;
			    --base;
			}
		}
		else if(c == '\n'){
			putchar(c);
		 	size = 1;
		}
               	else{
		     	putchar(c);
    	       		++size;
		}		
	}
return 0;
	}
		

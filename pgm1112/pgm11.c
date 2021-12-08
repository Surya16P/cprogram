/*word counting  Ex 1.11 */

#include<stdio.h>

#define IN 1
#define OUT 0
int main()
{
	int c,state;
	int n_line,n_word,n_char;

	n_line = n_word = n_char = 0;

	state = OUT;


	while((c = getchar()) != EOF)
	{
		++n_char;
		if(c == '\n')
			++n_line;
		
		if(c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if(state == OUT && c >= 90 && c <= 122)
		{
			state = IN;
		        ++n_word;
		}
		else if(c >= 33 && c <= 64)
			continue;
				
				 			
	}
	printf("The total char is :%d\nThe total line is :%d\nThe word is : %d\n",n_char,n_line,n_word);
	
	return 0;
}

			


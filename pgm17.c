/* print  longer than 80 line */

#include <stdio.h>

#define MAXLINE 1000

int input(char line[] ,int maxline);
void copy(char to[], char from[]);

int main()
{
	int len,max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while ((len = input(line,MAXLINE)) > 0)
	{
        

          if(len > max)
	          max = len;
	          copy(longest,line);
	}
	
	if (max >= 80)
	    printf("the lenght is :%d string : %s",max,longest);
	
	else
		printf("All string is less 80 char");

return 0;
}

int input(char s[],int lim)
{
   int i,c;
   for(i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n';++i)
	   s[i] = c;
   if(c == '\n'){
	   s[i] = c;
           ++i;
   }

      s[i] = '\0';
      return i;
}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}

/* Escape function(s,t) */

#include "stdio.h"
#define MAXLINE 1000

int input(char line[],int maxline);
void  escape(char s[], char t[]);

int main()
{
	char s[MAXLINE], t[MAXLINE],line[MAXLINE];
	input(line,MAXLINE);


	escape(s,line);
	printf("%s",s);


	return 0;
}

int input(char s[],int len) // input form user function
{
	int c,i;

	for (i = 0; i < len-1 && (c =getchar())!= EOF;++i)
		s[i] = c;

	s[i] = '\0';
	
}
/* new line and tab  to  switch */


void escape(char s[], char t[]){
	int i,j;

	i = j = 0;
	while(t[i] != '\0')
	{
		switch(t[i])
		{
			case '\t':
				s[j] = '\\';
				++j;
				s[j] = 't';
				break;
			case '\n':
				s[j] = '\\';
				++j;
				s[j] = 'n';
				break;
			default:
				s[j] = t[i];
				break;
		}
		++i;
		++j;
	}
	s[j] = '\0';
}




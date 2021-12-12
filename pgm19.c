#include <stdio.h>
#define MAXLINE 1000
int input(char line[],int maxline);
int main()
{
	char line[MAXLINE];
	int len,max,i;
	max = 0;

	while((len = input(line, MAXLINE)) > 0)
	
		for(i=len ; i >= 0;i--)
			printf("%c",line[i]);
		
	

return 0;
}

int input(char s[],int lim)
{
	int i,c;

	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n';i++)
		s[i] = c;

	return i;
}


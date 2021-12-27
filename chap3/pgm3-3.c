/* function expand(s1,s2) */

#include "stdio.h"
#include "ctype.h" //atoi lib files
#include "string.h"

#define MAXLINE 1000

void expand(char s1[], char s2[]);
void reverse(char s[]);

int input(char line[],int maxline);
int atoi(char s[]);

int main()
{
	char line[MAXLINE],s2[MAXLINE];
	
        input(line,MAXLINE);

	expand(line,s2);
	printf("%s",s2);

//	printf("%d",atoi(line));

	// reverse(line);

	// printf("%s",line);
	
	return 0;
}

/* enter input */
int input(char s[],int lim) //input form user
{
    int i,c;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;

    if(c=='\n')
        s[i++]=c;
    
    s[i]='\0';
}
    
    

/* convert s to integer */

int atoi(char s[])
{
	int i,n, sign;

	for (i = 0; isspace(s[i]);i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n +(s[i] - '0');
	return sign * n;
}

/* reverse String */

void reverse(char s[])
{
	int c,i,j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, i--)
	{
		c = s[i];
		s[i] = s[j];

		s[j] = c;
		
	}
}

void expand(char s1[],char s2[])
{
    int i,j,c;

    i=j=0;

    while (( c = s1[i++]) != '\0')
        if (s1[i] == '-' && s1[i+1] >= c)
        {
            i++;
            while (c < s1[i])
            s2[j++] = c++;
        }
        else
            s2[j++] = c;

    s2[j]='\0';
}




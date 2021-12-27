/*  htoi program, character to integer program. */

#include<stdio.h>
#define MAXLINE 1000

#define YES 1
#define NO 0

int input(char line[], int maxline); //user given input funcion declr
int htoi(char s[]);

int main(void)
{
    char line[MAXLINE];
    int value;

    input(line, MAXLINE);
    value = htoi(line);

    printf("The value of %s is %d \n ",line,value);

    return 0;
}

int input(char s[],int lim) given user define function
{
    int c,i;

    for(i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] =c;

    if(c=='\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int htoi(char s[])
{
    int hexdigit,i,inhex,n;
    i = 0;

    /* incase user enter 0x or 0X */

    if( s[i] == '0')
    {
        ++i;
        if(s[i] == 'x' || s[i] == 'X')  
            ++i;
    }

    n = 0;
    inhex = YES;

    /* hexa value 0 to 9 and "A to F" or "a to f" */

    for(;inhex==YES;++i)
    {
        if(s[i] >='0' && s[i] <='9')
            hexdigit= s[i] - '0';
        else if(s[i] >='a' && s[i] <='f')
            hexdigit= s[i] -'a' + 10;
        else if(s[i] >='A' && s[i] <='F')
            hexdigit= s[i] -'A' + 10;
        else
            inhex = NO;

        if(inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}	





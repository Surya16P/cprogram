/* detete a match String */


#include<stdio.h>
#define MAXLINE 1000

int input(char line[],int maxline);

void squeeze(char num[],char num2[]);

int main()
{
    char num[MAXLINE],num2[MAXLINE];
    
    putchar('s');
    putchar('1');
    putchar(':');
    input(num,MAXLINE);

    putchar('s');
    putchar('2');
    putchar(':');
    input(num2,MAXLINE);

    squeeze(num,num2);

    printf("%s",num);

    return 0;
}

/* user enter a input */

int input(char s[],int lim)
{
    int i,c;
    
    for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n';++i)
        s[i] = c;

    if(c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
}

/* delete a match string function */

void squeeze(char num[],char num2[])
{
    int i,j,k;
    k=0;

    for(i=0; num[i] != '\0'; ++i)
    {
        for(j=0; (num[i] != num2[j]) && num2[j] != '\0' ;++j)
            ;
        if(num2[j] == '\0')
            num[k++] = num[i];
    }
    
     num[k] = '\0';
}






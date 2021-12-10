#include<stdio.h>
#define MAXLINE 1000

int input(char line[],int lim);

int main()
{
  int len,max;
  max = 0;
  char line[MAXLINE];
  
  while((len=input(line,MAXLINE))>0)

    if(len >= max)
    {
	    for( int i= 0 ;line[i] != '\0' ;++i)
	    {
		    if(line[i] == '\n' && line[i +1] == '\n')
			    line[i +1] = '\b';
		      
            printf("%c",line[i]);
	    }
    }
  return 0;
}


int input(char s[],int lim)
{
  int i,c;

  for(i = 0;i < lim-1 && (c=getchar()) != EOF ;++i)
  {
	  if(c != ' ' && c != '\t')
              s[i] = c;
	  else    
	      i--;
 }

  if( c == '\n')
  	s[i] = c;
    
    return i;
}

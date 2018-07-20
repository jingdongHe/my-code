#include<stdio.h>
int main()
{
    char a[100];
    int number=0,space=0,litter=0,others=0,i=0,j;
    
    while((a[i]=getchar())!='\n')
    i++;
    for(j=0;j<i;j++)
    {if(a[j]>'a'&&a[j]<'z'||a[j]>'A'&&a[j]<'Z')
      {litter++;if(

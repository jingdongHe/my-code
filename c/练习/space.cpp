#include<stdio.h>
int main()
{
    char a[100];
    int i=0,j;
    while((a[i]=getchar())!='\n')
    {i++;}
    for(j=0;j<=i;j++)
    putchar(a[j]);
     return 0;
}

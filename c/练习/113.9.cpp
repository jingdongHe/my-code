#include<stdio.h>
int main()
{
    int i=0,j=0,k;
    char a[5],d;
    
    while((a[i]=getchar())!='\n')
    {i++;}
    while(a[j]!='\0')
    {j++;}
    printf("%d\n",j-1);
    for(i=0;i<j-1;i++)
    printf("%c\n",a[i]);
    k=j/2;
    for(i=0;i<k;i++)
    {d=a[i];a[i]=a[j-1-i];a[j-1-i]=d;}
    for(i=0;i<j;i++)
    putchar(a[i]);
    return 0;
}
    

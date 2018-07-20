#include<stdio.h>
int main()
{
    char *p1,*p2,*p3,max,min,mid;
    char a[100],b[100],c[100];
    int i=0;
    p1=a;p2=b;p3=c;
    if(*p1>*p2)
    max=a[100];
    else
    min=b[100];
    while(*(p1+i)==*(p2+i))
    {i++;
    if(*(p1+i)>*(p2+i))
    max=a[100];
    else
    min=b[100];
    }
    i=0;
    while(*(p1+i)==*(p3+i))
    

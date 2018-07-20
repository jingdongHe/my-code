#include<stdio.h>
int main()
{
    int *p,i,*c,*d,*f;
    
    for(i=0;i<10;i++)
    scanf("%d",p+i);
    i=0;
    while(i<10)
    {*c=*(p+i);
    if(*(p+i)<*(p+i+1))
    *c=*(p+i+1);
    i++;}
    *f=*p;
    *p=*c;
    *c=*f;
    i=0;
    while(i<10)
    {*d=*(p+i);
    if(*(p+i)>*(p+i+1))
    *d=*(p+i+1);
    i++;}
    *f=*(p+9);
    *(p+9)=*d;
    *d=*f;
    for(i=0;i<10;i++)
    printf("%d",*(p+i));
    return 0;
}

    
    

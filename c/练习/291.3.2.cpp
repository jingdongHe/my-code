#include<stdio.h>
int main()
{
    int *p,i,c,d,*n,*m,k,j,a[10];
    
    p=a;
    for(i=0;i<10;i++)
    {scanf("%d",p+i);}
    i=1;c=*p;m=p;
    while(i<10)
    {if(c<*(p+i))
      {c=*(p+i);m=p+i;}
    i++;}
    i=1;d=*p;n=p;
    while(i<10)
    {if(d>*(p+i))
      {d=*(p+i);n=p+i;}
    i++;}
    k=*m;*m=*(p+9);*(p+9)=k;
    j=*n;*n=*p;*p=j;
    for(i=0;i<10;i++)
    {printf("%d",*(p+i));}
    return 0;
}


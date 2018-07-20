#include<stdio.h>
int main()
{
    int *p,i,c,d,*n,*m,k;
    
    for(i=0;i<10;i++)
    scanf("%d",p+i);
    i=0;c=*p;m=p;
    while(i<10)
    {if(c<*(p+i+1))
      {c=*(p+i+1);m=p+i+1;}
    i++;}
    for(i=0;i<10;i++)
    printf("%d",p+i);
    return 0;
}

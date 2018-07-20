#include<stdio.h>
int main()
{
    int *p,i,j,a,b,c,d[3];
    p=d;
    scanf("%d%d%d",p,(p+1),(p+2));

    a=*p;

    for(i=0;i<3;i++)
    {
    if(*p>*(p+i))
    {a=*(p+i);}
    }

    c=*p;
    for(j=2;j>=0;j--)
    {if(*p<*(p+j))
    {c=*(p+j);}
    }

    for(i=0;i<3;i++,p++)
    {if(*p>a&&*p<c)
    b=*p;
}
   
    printf("%d%d%d",a,b,c);
    return 0;
}

#include<stdio.h>
int main(void)
{
    int N,a,b,c,d;
    while((scanf("%d", &N))!=EOF)
    {
    a=N/100;
    b=(N%100)/10;
    c=(N%100)%10;
    d=a*a*a+b*b*b+c*c*c;
    if(d!=N)
      printf("NO\n");
    else
      printf("YES\n");
    }
    return 0;
}
    

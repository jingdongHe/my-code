#include<stdio.h>
int main(void)
{
    int a,b,c,d,e,f,t;
    
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    while(a!=0&&b!=0&&c!=0&&d!=0&&e!=0&&f!=0)
    {
      t=(d-a+12)*3600+(e-b)*60+(f-c);
      printf("%d\n",t);
      scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    }
    return 0;
}
       

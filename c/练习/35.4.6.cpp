#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    double m;
    
    for(n=100;n<=200;n++)
    {m=sqrt(n);
    for(i=2;i<=(m+1);i++)
      {if(n%i==0)
      break;}
    if(i>(m-1))
    printf("%d\n",n);
}
return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
    int m,i;
    double d,n;
    while(scanf("%lf%d",&n,&m)!=EOF){
    d=n;
    for(i=1;i<m;i++)
    {
      n=sqrt(n);
      d+=n;
    }
    printf("%0.2lf\n",d);}
   
}

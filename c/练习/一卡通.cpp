#include<stdio.h>
int main(void)
{
  int i,j,n,x,a,b,w=0,r=1,k,q;
  int t[10000];
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
   scanf("%d",&x);
   if(x<3)
   {
     printf("%d\n",x);
     continue;
   }
   t[10000]=1;
   for(j=1;j<=x;j++)
   t[10000]*=2;
   printf("%d\n",t[10000]);
   t[10000]=((t[10000]-2)/2+2)%10000;
   printf("%d\n",t[10000]);
  }
  return 0;
}

#include<stdio.h>
int main(void)
{
    int m,n,t,k,i;
    
    scanf("%d%d",&m,&n);
    if((m%10!=0)&&(n%10!=0))
    {
    while(m!=0&&n!=0)
    {
      t=m*n;
      if((t-1000)>0)
      {
      k=4;
      printf("%4d\nX%3d\n",m,n);
      }
      if((t-100)>0&&(t-1000)<0)
      {
      k=3;
      printf("%3d\nX%2d\n",m,n);
      }
      if((t-10)>0&&(t-100)<0)
      {
      k=2;
      printf("%2d\nX%1d\n",m,n);
      }
      if((t-1)>0&&(t-10)<0)
      {
      k=1;
      printf("%1d\nX%d\n",m,n);
      }
      for(i=0;i<k;i++)
      printf("-");
      printf("\n");
      printf("%d\n\n",t);
      scanf("%d%d",&m,&n);
      if((m%10==0)||(n%10==0))
        break;
    }
    }
    return 0;
}

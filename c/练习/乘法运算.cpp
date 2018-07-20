#include<stdio.h>
int main(void)
{
    int m,n;
    
    scanf("%d%d",&m,&n);
    if((m%10!=0)&&(n%10!=0))
    {
    while(m!=0&&n!=0)
    {
      if((m-10)>0||(n-10)>0)
      {
      printf("%3d\nX%2d\n",m,n);
      printf("---\n");
      printf("%3d\n\n",m*n);
      }
      else
      {
      printf("%2d\nX%d\n",m,n);
      printf("--\n");
      printf("%2d\n\n",m*n);
      }
      scanf("%d%d",&m,&n);
      if((m%10==0)||(n%10==0))
        break;
      return 0;
    }
    }
}

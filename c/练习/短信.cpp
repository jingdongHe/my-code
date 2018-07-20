#include<stdio.h>
int main(void)
{
    int f,m,n,i;
    float p,a,k=1000;
    float b[10000];
    scanf("%d%d",&n,&m);
    while(m!=0&&n!=0)
    {
    scanf("%f",&a); 
    for(i=0;i<n;i++)
    {
      scanf("%f%d",&p,&f);
      if(m>=f)
      b[i]=((m-f)*a)+p;
      else
      b[i]=p;
      if(b[i]<k)
      k=b[i];
    } 
    printf("%.2f\n",k);
    scanf("%d%d",&n,&m);
    }
}
    
   

#include<stdio.h>
int main()
{
    int n,i,a=0,b=0,c=0;
    float t[100];
    scanf("%d",&n);
    while(n!=0){
      for(i=0;i<n;i++)
      scanf("%f",&t[i]);
      for(i=0;i<n;i++)
      {
         if(t[i]<0)
         a++;
         if(t[i]==0)
         b++;
         if(t[i]>0)
         c++;
      }
      printf("%d %d %d\n",a,b,c);
      a=0;b=0;c=0;scanf("%d",&n);
      }

}
      

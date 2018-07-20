#include<stdio.h>
int main(void)
{
  int virus[10000];
  int dna[100000];
  int i,j,m,n,k=0,q=0,a,b,z;
  scanf("%d",&b);
  for(a=0;a<b;a++)
  {
  scanf("%s%s",virus,dna);
  for(i=0;virus[i]!=0;i++)
    m=i;
  for(j=0;dna[j];j++)
    n=j;
  for(j=0;j<n;j++)
  {
    if(virus[0]==dna[j])
    {
      z=0;
      while(z<m)
      {
        if(virus[i]==dna[j+i])
        {
        k++;
        z++;
        }
        else
        z=m+1;
      }
      if(z==m)
      q++;
    }
  }
   printf("%d",q);
   }
   return 0;
}
  

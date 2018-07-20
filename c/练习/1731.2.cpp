#include<stdio.h>
int main(void)
{
    int gift[10000];
    int sent[1000];
    int i=0,j=0,n,m,k=0;
    
    scanf("%d%d",&n,&m);
    while((scanf("%d%d",&gift[i],&sent[j]))!=EOF)
    {
      i++;
      j++;
      for(m=0;m<i;m++)
      {
      for(n=0;n<j;n++)
      {
      if(sent[n]==gift[m])
      {
        sent[n]=0;
        gift[m]=0;
        k++;
      }
      }
      }
      if(k<m)
        printf("NO");
      else
        printf("YES");
    }
}
    

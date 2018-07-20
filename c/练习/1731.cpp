#include<stdio.h>
int main(void)
{
    int gift[10000];
    int sent[1000];
    int n,m,i,j,k=0;
    
    scanf("%d%d",&n,&m);
    while(m!=0&&n!=0)
    {
    for(i=0;i<n;i++)
      scanf("%d",&gift[i]);
    for(j=0;i<m;j++)
      scanf("%d",&sent[j]);
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        if(sent[j]==gift[i])
        {
          sent[i]=0;
          gift[j]=0;
          k++;
        }
       }
    }
    if(k<m)
       printf("YES");
     else
       printf("NO");
     scanf("%d%d",&n,&m);
     }
     return 0;

}
      
      

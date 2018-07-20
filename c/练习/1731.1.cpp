#include<stdio.h>
int main(void)
{
    int gift[10000];
    int sent[10000];
    int n,m,i,j,k;
    
    scanf("%d%d",&n,&m);
    while(m!=0&&n!=0)
    {
    for(i=o;i<n;i++)
      scanf("%d",&gift);
    for(j=0;i<m;j++)
      scanf("%d",&sent);
    for(i=0;i<n;i++)
    {
    for(j=0;j<m;j++)
    {
      if(sent[j]==gift)
      {
        sent[i]=0;
        gift[j]=0;
        k++;
      }
     }
     }
     if(k<m)
       printf("No");
     else
       printf("YES");
     scanf("%d%d",&n,&m);
     return 0;
}
      
      

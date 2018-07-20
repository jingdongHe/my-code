#include<stdio.h>
#define case buaa
int main(void)
{
    int i=0,k=0,j,n,m=0,q=0;
    char exp[100];
    char case[]="BUAA";
    
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
    i=0;
    k=0;
    q=0;
    m=0;
    scanf("%s",exp);
    while(exp[q]!=0)
      q++;
    while(i<q)
    {
      if(case[k]==exp[i])
      {
      k++;
      i++;
      m++;
      }
      else
      i++;
    }
    if(m==4)
    printf("YES\n");
    else
    printf("NO\n");
    }
    return 0;
}
      
    
    

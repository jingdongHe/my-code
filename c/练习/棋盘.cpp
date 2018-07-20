#include<stdio.h>
void underneath(void);
void superior(void);
int main(void)
{
    int n,i,j,q,w,y,x,a,b,r,s;
    
    scanf("%d%d%d",&n,&i,&j);
    while(n!=0)
    {          
    for(q=1;q<=n;q++)
    printf("(%d,%d)",q,j);
    printf("\n");
    for(w=1;w<=n;w++)
    printf("(%d,%d)",i,w);
    printf("\n");
    a=i;
    b=j;
    while(a>1&&b>1)
    {
      a--;
      b--;
    }
    while((a<=n)&&(b<=n))
    {
      printf("(%d,%d)",a,b);
      a++;
      b++;
    }
    printf("\n");
    x=i;
    y=j;
    while((x>1)&&(y<n))
    {
      x--;
      y++;
    }
    while((y>0)&&(x<=n))
    {
      printf("(%d,%d)",x,y);
      y--;
      x++;
    }
    printf("\n");

    scanf("%d%d%d",&n,&i,&j);
    }
    return 0;
} 
    
    
    

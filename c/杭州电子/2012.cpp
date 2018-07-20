#include<stdio.h>
#include<math.h>
int main()
{
    int x,y,j,r=0,t=0,n,s;
    double k;
    long d;scanf("%d%d",&x,&y);getchar();if(x>y) {s=x;x=y;y=s;}
    while(x!=0||y!=0){
    for(n=x;n<=y;n++)
    {
      d=pow(n,2)+n+41;
      k=sqrt(d)+1;
      for(j=2;j<=k;j++)
      {
        if(d%j==0)
        r++;//不是素数
      }
      if(r==0) //r=0,为素数 
      t++;//有t个素数 
           r=0;
    }
       if(t==y-x+1)
    printf("OK\n");
    else
    printf("Sorry\n"); 
    scanf("%d%d",&x,&y);getchar();
    r=0;t=0;}
    return 0;
}  
    

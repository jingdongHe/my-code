#include<stdio.h>
#include<math.h>
int main(  )
{
    int t;
    scanf("%d",&t);
    while(t-- )
    {
       int m;
       scanf("%d",&m);
       int result=pow( 2,m )-1;
      printf("%d\n",result);
    }
    return 0;
}

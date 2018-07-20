#include<stdio.h>
int main()
{
    int x,y;
    
    scanf("%d,%d",&x,&y);
    if((x-2)*(x-2)+(y-2)*(y-2)>1&&(x-2)*(x-2)+(y+2)*(y+2)>1&&(x+2)*(x+2)+(y-2)*(y-2)>1&&(x+2)*(x+2)+(y+2)*(y+2)>1)
    printf("0");
    else
    printf("10");
    return 0;
}

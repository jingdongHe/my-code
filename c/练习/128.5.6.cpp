#include<stdio.h>
int main()
{
    int i,j;
    
    for(i=1;i<5;i++)
    {for(j=1;j<6;j++)
    {printf("%5.0d",i*j);if(j==5)printf("\n");}
    }
    printf("\n");
    return 0;
}

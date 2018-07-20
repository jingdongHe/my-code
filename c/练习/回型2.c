#include<stdio.h>
int main()
{
    int a[5][5];
    int i;
    int j;
    int n;
    int top;
    int botton;
    int left;
    int right;
    int d;
    
    n = 25;
    i = 0;
    j = 0;
    top = 0;
    botton = 5;
    left = -1;
    right = 5;
    d = 0;
    for(n=1;n<=25;n++)
    {
        if(d == 0)
        {
            if(j==right)
            {
                j--;
                right--;
                d = 1;
                i++;
                n--;
                continue;
            }
            else
            {
                a[i][j] = n;
                j++;
            }
        }
        
        if(d == 1)
        {
            if(i==botton)
            {
                i--;
                botton--;
                d = 2;
                j--;
                n--;
                continue;
            }
            else
            {
                a[i][j] = n;
                i++;
            }
        }
        
        if(d == 2)
        {
            if(j==left)
            {
                j++;
                left++;
                d = 3;
                i--;
                n--;
                continue;
            }
            else
            {
                a[i][j] = n;
                j--;
            }
        }
        
        if(d == 3)
        {
            if(i==top)
            {
                i++;
                top++;
                d = 0;
                j++;
                n--;
                continue;
            }
            else
            {
                a[i][j] = n;
                i--;
            }
        }
    }
    
    printf("the array is:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
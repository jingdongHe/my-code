#include<stdio.h>
int main()
{
    char now,last;
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        while(n--)
        {
            i=1;
            now=getchar();
            while(1)
            {
                last=getchar();
                if(now!=last)
                {
                    if(i==1)
                        printf("%c",now);
                    else
                        printf("%d%c",i,now);
                    i=1;
                    if(last=='\n')
                        break;
                }
                else
                    i++;
                now=last;
            }
            printf("\n");
        }
    }
    return 0;
}
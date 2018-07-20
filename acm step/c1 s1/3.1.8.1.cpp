#include <stdio.h>
#define N 1000001
#define M 30

char node[N][M];

void init()
{
    int i,j;
    for(i=1;i<=M;i++)
    {
        node[1][i]=2%i;
        node[2][i]=4%i;
        node[3][i]=6%i;
        node[4][i]=9%i;
        for (j=5;j<=N;j++)
        {
            node[j][i]=(node[j-1][i]+node[j-3][i]+node[j-4][i])%i;
        }
    }
}

int main()
{
    init();
    int n,m;
    while (~scanf("%d%d",&n,&m))
    {
        printf("%d\n",node[n][m]);
    }
    return 0;
}

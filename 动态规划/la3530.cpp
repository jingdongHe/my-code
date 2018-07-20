#include<stdio.h>
#include<string.h>
const int maxn=50+5;
int max(int a,int b)
{
	if(a>b) return a;
	return b;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
	{
		int a[maxn][maxn],b[maxn][maxn];
		int dp[maxn][maxn];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				scanf("%d",&b[i][j]);
		}
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=m+1;j++)
			{
				dp[i][j]=max(dp[i-1][j]+b[i-1][j],dp[i][j-1]+a[i][j-1]);
			}
		}
		for(int i=1;i<=n+1;i++)
		{
			for(int j=1;j<=m+1;j++)
			{
				printf("%3d ",dp[i][j]);
			}
			printf("\n");
		}
		printf("%d\n",dp[n+1][m+1]);
	}
	
}

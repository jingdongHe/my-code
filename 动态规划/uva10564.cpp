#include<stdio.h>
#include<string.h>
const int maxn=20+5;
int main()
{
	int n,s;
	while(scanf("%d%d",&n,&s)&&n&&s)
	{
		int map[maxn][maxn];
		int t[maxn];
		memset(map,0,sizeof(map));
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++)
		{
			int m=0;
			for(int j=1;j<=n-i+1;j++)
			{
				scanf("%d",&map[i][j]);
				m=m>map[i][j]?m:map[i][j];
			}
			t[i]=t[i-1]+m;
		}
		for(int i=2;i<=n;i++)
		{
			int m=0;
			for(int j=1;j<=i;j++)
			{
				scanf("%d",&map[i+n-1][j]);
				m=m>map[i+n-1][j]?m:map[i+n-1][j];
			}
			t[n+i-1]=t[n+i-2]+m;
		}
		
		for(int i=1;i<=2*n-1;i++)
		{
			printf("%3d...",t[i]);
			for(int j=1;j<=n;j++)
				printf("%d ",map[i][j]);
			printf("\n");
		}
		
		int dp[maxn][maxn][50];
		int dis[maxn][maxn][50];
		memset(dp,0,sizeof(dp));
		memset(dis,0,sizeof(dis));
		
		for(int i=1;i<=n;i++)
			dp[1][i][map[1][i]]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-i+1;j++)
			{
				for(int k=map[i][j];k<=t[i];k++)
				{
					dp[i][j][k]+=dp[i-1][j][k-map[i][j]]+dp[i-1][j+1][k-map[i][j]];
					if(dp[i-1][j][k-map[i][j]]) dis[i][j][k]=j*(-1);
					if(dp[i-1][j+1][k-map[i][j]]) dis[i][j][k]=j+1;
				}
			}
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				for(int k=map[i][j];k<=t[n+i-1];k++)
				{
					dp[n+i-1][j][k]+=dp[n+i-2][j][k-map[n+i-1][j]]+dp[n+i-2][j+1][k-map[n+i-1][j]];
					if(dp[n+i-2][j][k-map[n+i-1][j]]) dis[n+i-1][j][k]=j;
					if(dp[n+i-2][j+1][k-map[n+i-1][j]]) dis[n+i-1][j][k]=(j+1)*(-1);
				}		
			}
		}
		int m=0,k=-1;
		for(int i=1;i<=n;i++)
		{
			m+=dp[2*n-1][i][s];
			if(dp[2*n-1][i][s]) k=i;
		}
		if(k!=-1)
		{
			for(int i=2*n-1;i>1;i--)
			{
				int z=dis[i][k][s];
				if(z<0)
				{
					printf("R");
					k=z*(-1);
				}
				else
				{
					k=z;
					printf("L");
				}
				s-=map[i][k];
			}
			printf("\n");
			
		}
		printf("%d\n",m);
	}
	return 0;
}

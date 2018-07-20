#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(double a,double b)
{
	return a>b;
}
const int maxn=100+5;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,w;
		int u[maxn];
		double c[maxn];
		double sum_c[maxn];
		int sum=0;
		scanf("%d%d",&n,&w);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&u[i]);
			sum+=u[i];
		}
		sum_c[0]=0;
		double dp[maxn][maxn];
		for(int i=1;i<=n;i++)
			c[i]=u[i-1]*1.0/sum;
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			sum_c[i]=sum_c[i-1]+c[i];
			dp[i][1]=sum_c[i]*i;
			//printf("%lf  ",c[i]);
		}
		//printf("\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=w;j++)
			{
				if(i<j) break;
				double m=9999;
				for(int k=j;k<=i;k++)
				{
					double s=dp[k-1][j-1]+i*(sum_c[i]-sum_c[k-1]);
					//printf("%d  %d  %d  %lf\n",i,j,k,s);
					m=m>s?s:m;
					dp[i][j]=m;
				}
			}
		}
		printf("%lf\n",dp[n][w]);
		
	}
	return 0;
}

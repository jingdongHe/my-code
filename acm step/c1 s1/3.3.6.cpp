#include<stdio.h>
const int maxn=100+5;
int main()
{
	int a[maxn][maxn];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&m!=0&&n!=0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		}
		int f[maxn]={0};
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=0;j--)
			{
				for(int k=1;k<=j;k++)
					if(f[j]<f[j-k]+a[i][k])
						f[j]=f[j-k]+a[i][k];
			}
		}
		printf("%d\n",f[m]);
	}
	return 0;
}

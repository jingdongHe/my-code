#include<stdio.h>
const int maxn=100+5;
int main()
{
	int arr[maxn][maxn]={0},res[maxn][maxn]={0};
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				scanf("%d",&arr[i][j]);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				int k=res[i-1][j-1]>res[i-1][j]?res[i-1][j-1]:res[i-1][j];
				res[i][j]=arr[i][j]+k;
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
				printf("%3d",res[i][j]);
			printf("\n");
		}*/
		int max=0;
		for(int i=1;i<=n;i++)
			if(max<res[n][i]) max=res[n][i];
		printf("%d\n",max);
	}
	return 0;
}

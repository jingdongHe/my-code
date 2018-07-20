#include<stdio.h>
#include<string.h>
const int maxn=100+5;
int main()
{
	int A[2*maxn];
	int T;
	scanf("%d",&T);T++;
	while(T--)
	{
		int map[maxn][maxn];
		memset(map,0,sizeof(map));
		int change[2*maxn][maxn];
		memset(change,9999,sizeof(change));
		int n1,n2;
		scanf("%d%d",&n1,&n2);
		int a,b;
		for(int i=0;i<n2;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
		}
		for(int i=1;i<=n1;i++)
		{
			map[i][i]=1;
		}
		int n3;
		scanf("%d",&n3);
		for(int i=1;i<=n3;i++)
			scanf("%d",&A[i]);
		for(int i=1;i<=n1;i++)	change[1][i]=1;
		change[1][1]=0;
		for(int i=2;i<=n3;i++)
		{
			for(int j=1;j<=n1;j++)
			{
				int m=99999;
				for(int k=1;k<=n1;k++)
				{
					if(map[k][j])
					{
						if(A[i]==j) m=m<change[i-1][k]?m:change[i-1][k];
						else m=m<change[i-1][k]+1?m:change[i-1][k]+1;
					}
				}
				change[i][j]=m;
			}
		}
		/*for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=n1;j++)
				printf("%d ",map[i][j]);
			printf("\n");
		}
		printf("--------------------------------\n");
		for(int i=1;i<=n3;i++)
		{
			for(int j=1;j<=n1;j++)
				printf("%d ",change[i][j]);
			printf("\n");
		}*/
		int m=9999;
		for(int i=1;i<=n1;i++)
		{
			m=m<change[n3][i]?m:change[n3][i];
		}
		printf("%d\n",m);
	}
	return 0;
}

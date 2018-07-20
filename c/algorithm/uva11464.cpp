#include<stdio.h>
#include<string.h>
const int maxn=15;
int b[maxn];
int map[maxn][maxn];
int n,ans=999999;
int check()
{
	int i,j,k=0;
	int map1[maxn][maxn];
	for(i=0;i<n;i++)
	{
		if(map[0][i]==1&&b[i]==0)
			return 999999;//´íÎóÊ±·µ»Ø999999
	}
	for(i=0;i<n;i++)
		map1[0][i]=b[i];
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			k=0;
			if(i>0) k+=map1[i-1][j];
			if(j>0) k+=map1[i][j-1];
			if(j<n-1) k+=map1[i][j+1];
			map1[i+1][j]=k%2;
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j]==1&&map1[i][j]==0)
				return 999999;
			if(map1[i][j]!=map[i][j])
				k++;
		}
	}
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",map1[i][j]);
		printf("\n");
	}printf("-----------------------\n");*/
	return k;
}
void perm()
{
        
	int i,j,k;
	for(i=0;i<(1<<n);i++)
	{
		memset(b,0,sizeof(b));
		for(j=0;j<n;j++)
		{
			if(i&(1<<j)) b[j]=1;
		}
		k=check();
		ans=ans>k?k:ans;
	}
}
int main()
{
	int i,j,t,T;
	int k=0;
	scanf("%d",&T);
	while(T>=30)
		scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&map[i][j]);
			if(i==0&&map[i][j]==0)
				k++;
		}
	}
	perm();
	printf("Case %d: ",t);
	if(ans==999999)
		printf("-1\n");
	else
		printf("%d\n",ans);
	ans=999999;
	}
	return 0;
}

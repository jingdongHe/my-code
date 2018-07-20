#include<stdio.h>
const int maxn=100+5;
int seq[maxn];
int d[maxn][maxn],s[maxn]={0};
bool vis[maxn][maxn];
int deep(int i,int j)
{
	if(vis[i][j])
		return d[i][j];
	vis[i][j]=1;
	int m=0,res;
	for(int k=1;i+k<=j;k++)
	{
		res=deep(i+k,j);
		m=m<res?m:res;
	}
	for(int k=1;j-k>=i;k++)
	{
		res=deep(i,j-k);
		m=m<res?m:res;
	}
	d[i][j]=s[j]-s[i-1]-m;
	return d[i][j];
}
int main()
{
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
			vis[i][j]=false;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&seq[i]);
		s[i]=s[i-1]+seq[i];
	}
	printf("%d\n",2*deep(1,n)-s[n]);
	return 0;
}

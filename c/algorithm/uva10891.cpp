#include<stdio.h>
#include<string.h>
const int maxn=100+10;
int vis[maxn][maxn],seq[maxn],s[maxn],d[maxn][maxn];
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int dp(int i,int j)
{
	if(vis[i][j]) return d[i][j];
	vis[i][j]=1;
	int k;
	int m=0;
	for(k=i+1;k<=j;k++)
		m=min(dp(k,j),m);
	for(k=i;k<j;k++)
		m=min(dp(i,k),m);
	if(i<1)
		d[i][j]=s[j]-m;
	else
		d[i][j]=s[j]-s[i-1]-m;
	return d[i][j];
}
int main()
{
	int n,i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&seq[i]);
			s[i]=i==0?seq[i]:seq[i]+s[i-1];
		}
		memset(vis,0,sizeof(vis));
		printf("%d\n",2*dp(0,n-1)-s[n-1]);
	}
	return 0;
}
		
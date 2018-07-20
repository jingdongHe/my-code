#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int d[1000][2];
int vis[1000][2]={0};
vector<int> adj[1000];
int dp(int i,int j,int f)
{
	if(vis[i][j]==1)
		return d[i][j];//d[i][j]=dp(i,j);
	vis[i][j]=1;
	int ans=1000;
	int k;
	for(k=0;k<adj[i].size();k++)
	{
		if(adj[i][k]!=f)
			ans+=dp(adj[i][k],1,i);
	}
	if(j==0&&f>=0) ans++;
	if(j==1||f<0)
	{
		int sum=0;
		for(k=0;k<adj[i].size();k++)
		{
			if(adj[i][k]!=f)
				sum+=dp(adj[i][k],0,i);
		}
		if(f>=0)
			sum++;
		ans=min(ans,sum);
	}
	d[i][j]=ans;
	return ans;
}
int main()
{
	
	int i,n,m,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		adj[i].clear();
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(vis[i][0]==0)
			ans+=dp(i,0,-1);
	}
	printf("%d %d %d\n",ans/1000,m-ans%1000,ans%1000);
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=1000+10;
const int M=2000;
vector<int> adj[maxn];
int vis[maxn][2],d[maxn][2];
int dp(int i,int j,int f)
{
	if(vis[i][j]) return d[i][j];
	vis[i][j]=1;
	int ans;
	ans=2000;
	int k;
	for(k=0;k<adj[i].size();k++)
	{
		if(adj[i][k]!=f)
			ans+=dp(adj[i][k],1,i);
	}
	if(j==0&&f>=0) ans++;
	if(j||f<0)
	{
		int sum=0;
		for(k=0;k<adj[i].size();k++)
		{
			if(adj[j][k]!=f)
				sum+=dp(adj[i][k],0,i);
		}
		if(f>=0) sum++;
		if(ans>sum)
			ans=sum;
	}
	return d[i][j]=ans;
}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		adj[i].clear();
	for(i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(!vis[i][0])
			ans+=dp(i,0,-1);
		printf("%d...%d\n",i,ans);
	}
	printf("%d  %d %d %d\n",ans,ans/M,m-ans%M,ans%M);
	return 0;
}


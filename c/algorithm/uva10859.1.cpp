#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int M=2000;
const int maxn=1000+10;
vector<int> adj[maxn];
int vis[maxn][2],d[maxn][2];
int dp(int i,int j,int f)
{
	if(vis[i][j]==1)
		return d[i][j];
	vis[i][j]=1;
	int ans=M,k;
	for(k=0;k<adj[i].size();k++)
	{
		if(adj[i][k]!=f)
			ans+=dp(adj[i][k],1,i);
	}
	if(j==0&&f!=-1) ans++;
	if(j==1||f==-1)
	{
		int sum=0;
		for(k=0;k<adj[i].size();k++)
		{
			if(adj[i][k]!=f)
				sum+=dp(adj[i][k],0,i);
		}	
		if(f!=-1)
			sum++;
		ans=ans<sum?ans:sum;
	}
	d[i][j]=ans;
	return ans;
}
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while(T--)
	{
	scanf("%d%d",&n,&m);
		int x,y,i;
		for(i=0;i<n;i++)
			adj[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		int ans=0;
		for(i=0;i<n;i++)
		{
			if(vis[i][0]==0)
				ans+=dp(i,0,-1);
		}
		printf("%d %d %d\n",ans/M,m-ans%M,ans%M);
	}
	return 0;
}
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=1000+5;
vector<int> map[maxn];
bool vis[maxn][maxn];
int d[maxn][maxn];
int n,m;
int deep(int i,int j,int f)
{
	if(vis[i][j]) return d[i][j];
	vis[i][j]=true;
	int ans=maxn;
	//·ÅµÆ
	for(int k=0;k<map[i].size();k++)
	{
		if(map[i][k]!=f)
			ans+=deep(map[i][k],1,i);
	} 
	if(j==0&&f!=-1)
		ans++;
		
	if(f==-1||j==1)
	{
		int sum=0;
		for(int k=0;k<map[i].size();k++)
		{
			if(map[i][k]!=f)
				sum+=deep(map[i][k],0,i);
		}
		if(f!=-1) sum++;
		ans=ans<sum?ans:sum;
	}
	d[i][j]=ans;
	return d[i][j];
}
int main()
{
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{map[i].clear();for(int j=0;j<=n;j++ )vis[i][j]=false;}
	int a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(vis[i][0]==false)
			res+=deep(i,0,-1);
	}
	printf("%d  %d  %d\n",res/maxn,m-res%maxn,res%maxn);
	return 0;
}

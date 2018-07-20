//ÕýÈ·´ð°¸4.2.8 
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node {
	int x,y,k;
	bool take;
	int rx[64],ry[64];
};
int ans,dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[10][10][2];
char map[10][10];
int n,m,t;
node star;
queue<node> q;
void dfs(int deep)
{
	if(deep>ans) return;
	while(!q.empty()) q.pop();
	q.push(star);
	memset(vis,false,sizeof(vis));
	vis[star.x][star.y][0]=true;
	int tx,ty;bool is_ok=true;
	node temp;
	while(!q.empty())
	{
		temp=q.front();
		if(map[temp.x][temp.y]=='E'&&temp.take==true)
		{
			is_ok=false;break;
		}
		q.pop();
		node temp_push;
		for(int i=0;i<4;i++)
		{
			tx=temp.x+dir[i][0];
			ty=temp.y+dir[i][1];
			if(map[tx][ty]=='J') temp_push.take=true;
			else temp_push.take=temp.take;
			if(tx>=0&&ty>=0&&tx<n&&ty<m&&map[tx][ty]!='#'&&vis[tx][ty][temp_push.take]==false&&temp.k<t)
			{
				vis[tx][ty][temp_push.take]=true;
				temp_push.k=temp.k+1;
				for(int k=1;k<=temp.k;k++)
				{
					temp_push.rx[k]=temp.rx[k];
					temp_push.ry[k]=temp.ry[k];
				}
				temp_push.rx[temp_push.k]=tx;
				temp_push.ry[temp_push.k]=ty;
				q.push(temp_push);
			}
		}
	}
	if(is_ok)
	{if(deep<ans) ans=deep;return ;}
	for(int i=1;i<=temp.k;i++)
	{
		char c=map[temp.rx[i]][temp.ry[i]];
		if(c!='E'&&c!='S')
		{
			map[temp.rx[i]][temp.ry[i]]='#';
			dfs(deep+1);
			map[temp.rx[i]][temp.ry[i]]=c;
		}
	}
	return;
}
int main()
{
	int T;
	scanf("%d",&T);getchar();
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&t);getchar();
		ans=4;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{star.x=i;star.y=j;star.k=0;star.take=false;}
			}
			getchar();
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}*/
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

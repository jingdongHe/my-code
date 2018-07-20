#include<stdio.h>
#include<string.h>
int abs(int a)
{
	if(a<0) return a*-1;
	return a;
}
const int maxn=10;
int n,m,t;
int map[maxn][maxn];
bool use[maxn][maxn],k;
int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int ex,ey;
void dfs(int x,int y,int s)
{
	if(k) return;
	if(s>t) return;
	if(map[x][y]=='D'&&s==t)
	{k=true;return;}
	int f=t-(abs(ex-x)+abs(ey-y))-s;
	if(f&1) return;
	for(int i=0;i<4;i++)
	{
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(map[tx][ty]!='X'&&use[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<m)
		{
			use[tx][ty]=true;
			dfs(tx,ty,s+1);
			use[tx][ty]=false;
		}
	}
	return;
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&t)!=EOF&&n!=0&&m!=0&&t!=0)
	{
		int x,y;
		getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{x=i;y=j;}
				if(map[i][j]=='D')
				{ex=i;ey=j;}
			}
			getchar();
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}*/
		memset(use,false,sizeof(use));
		use[x][y]=true;k=false;dfs(x,y,0);
		if(k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

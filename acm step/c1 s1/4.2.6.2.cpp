#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
const int maxn=80+5;
struct node {
	int x,y,k;
	int d;
	node(){};
	node(int _x,int _y,int _k,int _d):x(_x),y(_y),k(_k),d(_d){}
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
char map[maxn][maxn];
bool use[maxn][maxn][4];
int n,m;
int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int BFS(node star)
{
	priority_queue<int,vector<node>,cmp> q;
	/*for(int i=0;i<4;i++)
		use[star.x][star.y][i]=true;
	for(int i=0;i<4;i++)
	{
		int tx=star.x+dir[i][0];
		int ty=star.y+dir[i][1];
		if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='#'&&use[tx][ty][i]==false)
		{
			q.push(node(tx,ty,star.k+1,i));
			use[tx][ty][i]=true;
		}
	}*/
	q.push(star);
	while(!q.empty())
	{
		node temp=q.top();
		//printf("(%d,%d,%d)  %d\n",temp.x,temp.y,temp.d,temp.k);
		if(temp.x==0||temp.x==n-1||temp.y==0||temp.y==m-1)
			return temp.k;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=temp.x+dir[i][0];
			int ty=temp.y+dir[i][1];
			if(temp.d%2==i%2)
			{
				if(temp.d==i)
				{
					if(temp.d%2==0&&map[temp.x][temp.y+1]=='#'&&map[temp.x][temp.y-1]=='#')
					if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='#'&&use[tx][ty][i]==false)
					{
						q.push(node(tx,ty,temp.k+1,i));
						use[tx][ty][i]=true;
					}
					if(temp.d%2==1&&map[temp.x+1][temp.y]=='#'&&map[temp.x-1][temp.y]=='#')
					if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='#'&&use[tx][ty][i]==false)
					{
						q.push(node(tx,ty,temp.k+1,i));
						use[tx][ty][i]=true;
					}
				}
			}
			else if(tx>=0&&tx<n&&ty>=0&&ty<m&&map[tx][ty]!='#'&&use[tx][ty][i]==false)
			{
				q.push(node(tx,ty,temp.k+1,i));
				use[tx][ty][i]=true;
			}
		}
	}
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);getchar();
	while(t--)
	{
		scanf("%d%d",&n,&m);getchar();
		node star;
		memset(use,false,sizeof(use));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{star.x=i;star.y=j;star.k=0;star.d=-1;}
			}
			getchar();
		}
		printf("%d\n",BFS(star));
	}
}

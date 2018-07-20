#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=80+5;
struct node {
	int x,y;
	int t,p;
	node(){};
	node(int _x,int _y,int _t,int _p):x(_x),y(_y),t(_t),p(_p){};
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		if(a.t==b.t)
			return a.p<b.p;
		return a.t>b.t;
	}
};
int n,m,t,p;
char map[maxn][maxn];
bool use[maxn][maxn][maxn];
int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int BFS(node star)
{
	memset(use,false,sizeof(use));
	priority_queue<int,vector<node>,cmp> q;
	q.push(star);use[star.x][star.y][star.p]=true;
	int tx,ty;
	while(!q.empty())
	{
		node temp=q.top();
		if(temp.t>t) return -1;
		if(map[temp.x][temp.y]=='L')
			return temp.t;
		q.pop();
		for(int i=0;i<4;i++)
		{
			tx=temp.x+dir[i][0];
			ty=temp.y+dir[i][1];
			if(tx>=0&&ty>=0&&tx<n&&ty<m&&map[tx][ty]!='#')
			{
				//fly
				if(temp.p>0&&use[tx][ty][temp.p-1]==false)
				{
					q.push(node(tx,ty,temp.t+1,temp.p-1));
					use[tx][ty][temp.p-1]=true;
				}
				//wark
				if(map[temp.x][temp.y]!='@'&&map[tx][ty]!='@'&&use[tx][ty][temp.p]==false)
				{
					q.push(node(tx,ty,temp.t+2,temp.p));
					use[tx][ty][temp.p]=true;
				}
			}
		}
	}
	return -1;
}
int main()
{
	int f=1;
	while(scanf("%d%d%d%d",&n,&m,&t,&p)!=EOF)
	{
		node star;
		getchar();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='Y')
				{star.x=i;star.y=j;star.p=p,star.t=0;}
			}
			getchar();
		}
		int k=BFS(star);
		if(k==-1)
			printf("Case %d:\nPoor Yifenfei, he has to wait another ten thousand years.\n",f++);
		else 
			printf("Case %d:\nYes, Yifenfei will kill Lemon at %d sec.\n",f++,k);
	}
	return 0;
}

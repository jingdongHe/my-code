#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=80+5;
char map[maxn][maxn];
bool use[maxn][maxn][maxn];
int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,ti,p;
struct node {
	int x,y,t,p;
	node (){};
	node (int _x,int _y,int _t,int _p){x=_x;y=_y;t=_t;p=_p;}
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		if(a.t==b.t)
			return a.p<b.p;
		return a.t>b.t;
	}
};
int BFS(node star)
{
	priority_queue<int,vector<node>,cmp> q;
	q.push(star);use[star.x][star.y][star.p]=true;
	int tx,ty;
	while(!q.empty())
	{
		node temp=q.top();
		if(temp.t>ti) return -1;
		if(map[temp.x][temp.y]=='L')
			return temp.t;
		q.pop();
		for(int i=0;i<4;i++)
		{
			tx=temp.x+dir[i][0];
			ty=temp.y+dir[i][1];
			if(use[tx][ty][temp.p]==false&&map[tx][ty]!='#'&&tx>=0&&tx<n&&ty>=0&&ty<m)
			{
				//fly
				if(temp.p>=1)
				{q.push(node(tx,ty,temp.t+1,temp.p-1));use[tx][ty][temp.p-1]=true;}
				//work
				if(map[tx][ty]!='@'&&map[temp.x][temp.y]!='@')
				{q.push(node(tx,ty,temp.t+2,temp.p));use[tx][ty][temp.p]=true;}
			}
		}
	}
	return -1;
}
int main()
{
	int t=1;
	while(~scanf("%d%d%d%d",&n,&m,&ti,&p))
	{
		getchar();
		memset(use,false,sizeof(use));
		node Y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='Y')
				{Y.x=i;Y.y=j;Y.t=0;Y.p=p;}
			}
			getchar();
		}
		int k=BFS(Y);
		if(k!=-1)
			printf("Case %d:\nYes, Yifenfei will kill Lemon at %d sec.\n",t++,k);
		else 
			printf("Case %d:Poor Yifenfei, he has to wait another ten thousand years.\n",t++);
	}
	return 0;
}

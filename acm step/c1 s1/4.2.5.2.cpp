#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct node {
	int x,y,k;
};
struct cmp{
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
const int maxn=200+5;
int n,m;
char map[maxn][maxn];
bool use[maxn][maxn];
int count_m[maxn][maxn],count_y[maxn][maxn];
void BFS(node s,int mark)//0-m  1-y
{
	priority_queue<int,vector<node>,cmp> q;
	q.push(s);use[s.x][s.y]=true;
	while(!q.empty())
	{
		node temp=q.top();
		q.pop();
		if(map[temp.x][temp.y]=='@')
		{
			if(mark==0)
				count_m[temp.x][temp.y]=temp.k;
			else 
				count_y[temp.x][temp.y]=temp.k;
		}
		int tx,ty;
		tx=temp.x;ty=temp.y-1;
		if(use[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<m)
		if(map[tx][ty]!='#'&&map[tx][ty]!='M'&&map[tx][ty]!='Y')
		{
			node T;
			T.x=tx;T.y=ty;T.k=temp.k+1;
			q.push(T);use[tx][ty]=true;
		}
		tx=temp.x;ty=temp.y+1;
		if(use[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<m)
		if(map[tx][ty]!='#'&&map[tx][ty]!='M'&&map[tx][ty]!='Y')
		{
			node T;
			T.x=tx;T.y=ty;T.k=temp.k+1;
			q.push(T);use[tx][ty]=true;
		}
		tx=temp.x-1;ty=temp.y;
		if(use[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<m)
		if(map[tx][ty]!='#'&&map[tx][ty]!='M'&&map[tx][ty]!='Y')
		{
			node T;
			T.x=tx;T.y=ty;T.k=temp.k+1;
			q.push(T);use[tx][ty]=true;
		}
		tx=temp.x+1;ty=temp.y;
		if(use[tx][ty]==false&&tx>=0&&tx<n&&ty>=0&&ty<m)
		if(map[tx][ty]!='#'&&map[tx][ty]!='M'&&map[tx][ty]!='Y')
		{
			node T;
			T.x=tx;T.y=ty;T.k=temp.k+1;
			q.push(T);use[tx][ty]=true;
		}
	} 
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		node point_m,point_y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='M')
				{point_m.x=i;point_m.y=j;point_m.k=0;}
				if(map[i][j]=='Y')
				{point_y.x=i;point_y.y=j;point_y.k=0;}
			}
			getchar();
		}
		memset(count_m,-1,sizeof(count_m));
		memset(use,false,sizeof(use));
		BFS(point_m,0);
		memset(count_y,-1,sizeof(count_y));
		memset(use,false,sizeof(use));
		BFS(point_y,1);
		int res=0xfffffff;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(count_m[i][j]!=-1&&count_y[i][j]!=-1&&res>count_m[i][j]+count_y[i][j])
					res=count_m[i][j]+count_y[i][j];
			}
		}
		printf("%d\n",res*11);
	}
	return 0;
}

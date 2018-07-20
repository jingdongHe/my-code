#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=200+5;
int n,m;
char map[maxn][maxn];
bool use[maxn][maxn];
int number_m[maxn][maxn],number_y[maxn][maxn];
struct node {
	int x,y;
	int k;
};
int dis[][2]={{0,-1},{0,1},{-1,0},{1,0}};
struct cmp {
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
void BFS(node s,int mark)
{
	priority_queue<int,vector<node>,cmp> q;
	q.push(s);use[s.x][s.y]=true;
	//printf("%d........\n",mark);
	while(!q.empty())
	{
		node temp=q.top();
		if(map[temp.x][temp.y]=='@')
		{
			if(mark==0)
			{
				if(number_m[temp.x][temp.y]==-1||(number_m[temp.x][temp.y]!=-1&&number_m[temp.x][temp.y]>temp.k))
					number_m[temp.x][temp.y]=temp.k;
			}
			else
			{
				if(number_y[temp.x][temp.y]==-1||(number_y[temp.x][temp.y]!=-1&&number_y[temp.x][temp.y]>temp.k))
					number_y[temp.x][temp.y]=temp.k;
			}
		}
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x=temp.x+dis[i][0],y=temp.y+dis[i][1];
			if(x>=0&&x<n&&y>=0&&y<n)
			if(use[x][y]==false&&map[x][y]!='#'&&map[x][y]!='M'&&map[x][y]!='Y')
			{
				node a;
				a.x=temp.x+dis[i][0];
				a.y=temp.y+dis[i][1];
				a.k=temp.k+1;
				q.push(a);use[a.x][a.y]=true;
			}
		}
	}
	return ;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		node M,Y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='M')
				{M.x=i;M.y=j;M.k=0;}
				if(map[i][j]=='Y')
				{Y.x=i;Y.y=j;Y.k=0;}
			}
			getchar();
		}
		int result=0xfffffff;
		memset(number_m,-1,sizeof(number_m));
		memset(number_y,-1,sizeof(number_y));
		memset(use,0,sizeof(use));
		BFS(M,0);
		/*printf("--------------------\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",number_m[i][j]);
			printf("\n");
		}
		printf("\n");*/
		memset(use,0,sizeof(use));
		BFS(Y,1);
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",number_y[i][j]);
			printf("\n");
		}
		printf("--------------------\n");*/
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(number_m[i][j]!=-1&&number_y[i][j]!=-1)
				{
					int temp=number_m[i][j]+number_y[i][j];
					if(result>temp) result=temp;
				}
			}
		}
		printf("%d\n",result*11);
	}
	return 0;
}

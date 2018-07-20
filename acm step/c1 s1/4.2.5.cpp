#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=200+5;
int n,m;
char map[maxn][maxn];
bool use[maxn][maxn];
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
int BFS(node s)
{
	priority_queue<int,vector<node>,cmp> q;
	int k=-1;
	q.push(s);use[s.x][s.y]=true;
	while(!q.empty())
	{
		node temp=q.top();
		if(map[temp.x][temp.y]=='M'||map[temp.x][temp.y]=='Y')
		{
			if(k==-1) k=temp.k;
			else 
			{
				k+=temp.k;
				return k;
			}
			//printf("%d.........\n",k);
		}
		q.pop();
		for(int i=0;i<4;i++)
		{
			if(temp.x+dis[i][0]>=0&&temp.x+dis[i][0]<n&&temp.y+dis[i][1]>=0&&temp.y+dis[i][1]<n)
			if(use[temp.x+dis[i][0]][temp.y+dis[i][1]]==false&&map[temp.x+dis[i][0]][temp.y+dis[i][1]]!='#')
			{
				node a;
				a.x=temp.x+dis[i][0];
				a.y=temp.y+dis[i][1];
				a.k=temp.k+1;
				q.push(a);use[a.x][a.y]=true;
			}
		}
	}
	return 9999;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		getchar();
		queue<node> q;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{node a;a.x=i;a.y=j;a.k=0;q.push(a);}
			}
			getchar();
		}
		/*printf("------------------\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",map[i][j]);
			printf("\n");
		}
		/*while(!q.empty())
		{
			node i=q.front();
			q.pop();
			printf("%d %d\n",i.x,i.y);
		}
		printf("------------------\n");*/
		int result=9999;
		while(!q.empty())
		{
			memset(use,0,sizeof(use));
			int temp=BFS(q.front());
			//printf("%d\n",temp);
			q.pop();
			if(temp<result) result=temp;
		}
		printf("%d\n",result*11);
	}
	return 0;
}

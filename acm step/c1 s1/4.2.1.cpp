#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
const int maxn=200+5;
int localx,localy;
int n,m;
char matrix[maxn][maxn];
bool use[maxn][maxn];
struct node {
	int x,y;
	int k;
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
bool is_ok(int i,int j)
{
	if(matrix[i][j]!='#'&&use[i][j]==false&&i>=0&&j>=0&&i<n&&j<m)
		return true;
	return false;
}
int BFS()
{
	node temp;
	temp.x=localx;temp.y=localy;
	temp.k=0;
	priority_queue<int,vector<node>,cmp> q;
	q.push(temp);
	use[temp.x][temp.y]=true;
	while(!q.empty())
	{
		node a=q.top();
		//printf("(%d,%d) %d\n",a.x,a.y,a.k);
		//getchar();
		q.pop();
		
		
		if(matrix[a.x][a.y]=='r')
			return a.k;
		if(is_ok(a.x,a.y-1))
		{
			node s;
			s.x=a.x;s.y=a.y-1;
			s.k=a.k+1;
			if(matrix[s.x][s.y]=='x') s.k++;
			q.push(s);
			use[s.x][s.y]=true;
		}
		if(is_ok(a.x,a.y+1))
		{
			node s;
			s.x=a.x;s.y=a.y+1;
			s.k=a.k+1;
			if(matrix[s.x][s.y]=='x') s.k++;
			q.push(s);
			use[s.x][s.y]=true;
		}
		if(is_ok(a.x-1,a.y))
		{
			node s;
			s.x=a.x-1;s.y=a.y;
			s.k=a.k+1;
			if(matrix[s.x][s.y]=='x') s.k++;
			q.push(s);
			use[s.x][s.y]=true;
		}
		if(is_ok(a.x+1,a.y))
		{
			node s;
			s.x=a.x+1;s.y=a.y;
			s.k=a.k+1;
			if(matrix[s.x][s.y]=='x') s.k++;
			q.push(s);
			use[s.x][s.y]=true;
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{getchar();
		memset(use,false,sizeof(use));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%c",&matrix[i][j]);
				if(matrix[i][j]=='a')
				{localx=i;localy=j;}
			}getchar();
		}
		/*for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",matrix[i][j]);
			printf("\n");
		}
		printf("%d  %d.....\n",localx,localy);*/
		int k=BFS();
		if(k!=-1)
			printf("%d\n",k);
		else 
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}
	return 0;
}

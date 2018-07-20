#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=80+5;
struct node {
	int x,y,k;
	int dir;
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
int h,w;
char map[maxn][maxn];
bool use[maxn][maxn];
bool put(int tx,int ty,priority_queue<int,vector<node>,cmp> &q,int k,int dir)
{
	if(tx>0&&tx<h-1&&ty>0&&ty<w-1&&use[tx][ty]==false&&map[tx][ty]!='#')
	{
		node t_node;
		t_node.x=tx;t_node.y=ty;t_node.k=k+1;t_node.dir=dir;
		q.push(t_node);
		use[tx][ty]=true;
		return true;
	}
	return false;
}
void put_head(int tx,int ty,priority_queue<int,vector<node>,cmp> &q,int k)
{
	if(tx>0&&tx<h-1&&ty>0&&ty<w-1&&use[tx][ty]==false&&map[tx][ty]!='#')
	{
		node head;
		head.x=tx;head.y=ty;head.dir=k;head.k=1;
		q.push(head);use[head.x][head.y]=true;
	}
}
int BFS(node s)
{
	priority_queue<int,vector<node>,cmp> q;
	
	use[s.x][s.y]=true;
	put_head(s.x,s.y-1,q,3);
	put_head(s.x,s.y+1,q,1);
	put_head(s.x-1,s.y,q,0);
	put_head(s.x+1,s.y,q,2);
	
	while(!q.empty())
	{
		node temp=q.top();
		printf("(%d,%d)  ->%d,%d\n",temp.x,temp.y,temp.dir,temp.k);
		getchar();
		if(temp.x==0||temp.x==h-1||temp.y==0||temp.y==w-1)
			return temp.k;
		q.pop();
		if(temp.dir%2==1)
		{
			printf("right\n");
			int tx,ty;
			bool straight=false;
			tx=temp.x+1;ty=temp.y;
			straight|=put(tx,ty,q,temp.k,2);
			tx=temp.x-1;ty=temp.y;
			straight|=put(tx,ty,q,temp.k,0);
			if(straight==false)
			{
				tx=temp.x;ty=temp.y+1;
				straight=put(tx,ty,q,temp.k,1);
				tx=temp.x;ty=temp.y-1;
				straight=put(tx,ty,q,temp.k,3);
			}
		}
		else
		{
			printf("up\n");
			int tx,ty;
			bool straight=false;
			tx=temp.x;ty=temp.y+1;
			straight|=put(tx,ty,q,temp.k,1);
			tx=temp.x;ty=temp.y-1;
			straight|=put(tx,ty,q,temp.k,3);
			if(straight==false)
			{
				tx=temp.x+1;ty=temp.y;
				straight=put(tx,ty,q,temp.k,2);
				tx=temp.x-1;ty=temp.y;
				straight=put(tx,ty,q,temp.k,0);
			}
		}
	}  
	return -1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);getchar();
		node star;
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{star.x=i;star.y=j;star.k=0;}
			}
			getchar();
		}
		printf("%d\n",BFS(star));
	}
	return 0;
}

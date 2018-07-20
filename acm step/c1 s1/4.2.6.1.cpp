#include<stdio.h>
#include<string.h>
#define INF 0xfffffff
struct node {
	int x,y,k;bool hor;
};
const int maxn=80+5;
int res;
char map[maxn][maxn];
bool use[maxn][maxn];
int h,w;
bool is_ok(node temp)
{
	if(temp.x>0&&temp.x<h&&temp.y>0&&temp.y<w&&use[temp.x][temp.y]==false&&map[temp.x][temp.y]!='#')
		return true;
	return false;
}
int BFS(node a)
{
	if(a.x==0||a.x==h-1||a.y==0||a.y==w-1)
	if(map[a.x][a.y]=='.')
		return a.k;
	if(a.hor==true)
	{
		int k,k1=INF,k2=INF;
		node temp;
		bool mark=false;
		temp.x=a.x+1;temp.y=a.y;
		if(is_ok(temp))
		{
			mark=true;temp.hor=false;temp.k=a.k+1;
			use[temp.x][temp.y]=true;
			k1=BFS(temp);
			use[temp.x][temp.y]=false;
		}
		
		temp.x=a.x-1;
		if(is_ok(temp))	
		{
			mark=true;temp.hor=false;temp.k=a.k+1;
			use[temp.x][temp.y]=true;
			k2=BFS(temp);
			use[temp.x][temp.y]=false;
		}
		
		k=k1<k2?k1:k2;
		if(mark==false)
		{
			k1=k2=INF;
			temp.x=a.x;temp.y=a.y+1;
			if(is_ok(temp))
			{
			temp.hor=true;temp.k=a.k+1;
			use[temp.x][temp.y]=true;
			k1=BFS(temp);
			use[temp.x][temp.y]=false;
			}
				
			temp.y=a.y-1;
			if(is_ok(temp))
			{
				temp.hor=true;temp.k=a.k+1;
				use[temp.x][temp.y]=true;
				k2=BFS(temp);
				use[temp.x][temp.y]=false;
			}
			
			k=k1<k2?k1:k2;
		}
		if(res>k) res=k;
	}
	else
	{
		int k,k1=INF,k2=INF;
		node temp;
		bool mark=false;
		k1=k2=INF;
		temp.x=a.x;temp.y=a.y+1;
		if(is_ok(temp))
		{
			mark=true;temp.hor=true;temp.k=a.k+1;
			use[temp.x][temp.y]=true;
			k1=BFS(temp);
			use[temp.x][temp.y]=false;
		}
				
		temp.y=a.y-1;
		if(is_ok(temp))
		{
			mark=true;temp.hor=true;temp.k=a.k+1;
			use[temp.x][temp.y]=true;
			k2=BFS(temp);
			use[temp.x][temp.y]=false;
		}
		
		k=k1<k2?k1:k2;
		if(mark==false)
		{
			temp.x=a.x+1;temp.y=a.y;
			if(is_ok(temp))
			{
				temp.hor=false;temp.k=a.k+1;
				use[temp.x][temp.y]=true;
				k1=BFS(temp);
				use[temp.x][temp.y]=false;
			}
			
			temp.x=a.x-1;
			if(is_ok(temp))
			{
				temp.hor=false;temp.k=a.k+1;
				use[temp.x][temp.y]=true;
				k2=BFS(temp);
				use[temp.x][temp.y]=false;
			}
			
			k=k1<k2?k1:k2;
		}
		if(res>k) res=k;
	}
	return INF;
}
int main()
{
	int t;
	scanf("%d",&t);getchar();
	while(t--)
	{
		memset(use,0,sizeof(use));res=INF;
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
		node star1,star2,star3,star4;
		star1=star;star1.x--;star1.hor=false;star1.k=1;
		star2=star;star2.x++;star2.hor=false;star2.k=1;
		star3=star;star3.y--;star3.hor=true;star3.k=1;
		star4=star;star4.y++;star4.hor=true;star4.k=1;
		use[star.x][star.y]=true;
		if(is_ok(star1))BFS(star1);
		if(is_ok(star2))BFS(star2);
		if(is_ok(star3))BFS(star3);
		if(is_ok(star4))BFS(star4);
		if(res==INF)
			printf("-1\n");
		else
			printf("%d\n",res);
	}
	return 0;
}

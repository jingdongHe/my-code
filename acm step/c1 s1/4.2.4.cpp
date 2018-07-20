#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=20+5;
char map[maxn][maxn];
bool use[maxn][maxn];
int w,h,k;
int starx,stary;
struct node {
	int x,y;
};
void BFS()
{
	queue<node> q;
	node temp;
	temp.x=starx;temp.y=stary;
	q.push(temp);use[temp.x][temp.y]=true;
	k++;
	while(!q.empty())
	{
		temp=q.front();
		q.pop(); 
		int tx,ty;
		for(int i=0;i<4;i++)
		{
			switch(i){
				case 0:tx=temp.x;ty=temp.y-1;break;
				case 1:tx=temp.x+1;ty=temp.y;break;
				case 2:tx=temp.x;ty=temp.y+1;break;
				case 3:tx=temp.x-1;ty=temp.y;break;
			}
			if(tx>=0&&tx<h&&ty>=0&&ty<w&&use[tx][ty]==false&&map[tx][ty]!='#')
			{
				k++;
				node s;
				s.x=tx;s.y=ty;
				//printf("%d  %d....%d\n",s.x,s.y,k);
				q.push(s);
				use[s.x][s.y]=true;
			}
		}
	}
	return ;
}
int main()
{
	while(scanf("%d%d",&w,&h)!=EOF&&w!=0&&h!=0)
	{
		getchar();k=0;
		memset(use,0,sizeof(use));
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@'){starx=i;stary=j;}
			}
			getchar();
		}
		BFS();
		printf("%d\n",k);
	}
	return 0;
}

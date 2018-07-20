#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=10;
bool use[maxn][maxn];
int starx,stary,localx,localy;
struct node {
	int x,y,k;
};
struct cmp {
	bool operator () (node &a,node &b)
	{
		return a.k>b.k;
	}
};
int BFS()
{
	node temp;
	temp.x=starx;temp.y=stary;
	temp.k=0;
	use[temp.x][temp.y]=true;
	priority_queue<int,vector<node>,cmp> q;
	q.push(temp);
	while(!q.empty())
	{
		temp=q.top();
		if(temp.x==localx&&temp.y==localy)
			return temp.k;
		q.pop();
		int tx,ty;
		for(int i=0;i<8;i++)
		{
			switch(i){
				case 0:tx=temp.x+1;ty=temp.y-2;break;
				case 1:tx=temp.x+2;ty=temp.y-1;break;
				case 2:tx=temp.x+2;ty=temp.y+1;break;
				case 3:tx=temp.x+1;ty=temp.y+2;break;
				case 4:tx=temp.x-1;ty=temp.y+2;break;
				case 5:tx=temp.x-2;ty=temp.y+1;break;
				case 6:tx=temp.x-2;ty=temp.y-1;break;
				case 7:tx=temp.x-1;ty=temp.y-2;break;
			}
			if(tx>0&&tx<=8&&ty>0&&ty<=8&&use[tx][ty]==false)
			{
				node s;
				s.x=tx;s.y=ty;s.k=temp.k+1;
				q.push(s);
				use[tx][ty]=true;
			}
		}
	}
	return -1;
}
int main()
{
	char a,b,c;
	while(scanf("%c%d%c%c%d",&a,&stary,&b,&c,&localy)!=EOF)
	{
		getchar();
		memset(use,0,sizeof(use));
		starx=a-'a'+1;
		localx=c-'a'+1;
		//printf("(%d,%d)=>(%d,%d)\n",starx,stary,localx,localy);
		printf("To get from %c%d to %c%d takes %d knight moves.\n",a,stary,c,localy,BFS());
	}
	return 0;
}

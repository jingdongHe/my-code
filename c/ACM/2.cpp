#include<stdio.h>
#include<queue>
using namespace std;
typedef struct node {
	int x,y;
	bool operator < (const node& L) const{
		if(x==L.x)
			return y<L.y;
		return x<L.x;
	}
}node;
int main()
{
	int t;
	int map[105][105];
	int n,x,y;
	int i,k;
	int f;
	node A,B;
	priority_queue<node>q;
	for(t=0;t<15;t++)
	{
	scanf("%d",&n);
	if(n==-1)
		break;
	while(!q.empty())
		q.pop();
	f=0;
	memset(map,0,sizeof(map));
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		A.x=x;A.y=y;
		map[x][y]+=1;
		q.push(A);
	}
	while(!q.empty())
	{
		A=q.top();
		q.pop();
		for(k=1;k<=100;k++)
		{
			B.x=A.x+k;
			B.y=A.y+k;
			if(B.x>100||B.y>100)
				break;
			//printf("%d  %d:%d\n",B.x,B.y,k);
			if(map[B.x][B.y-k]>=1&&map[B.x-k][B.y]>=1&&map[B.x][B.y]>=1&&map[A.x][A.y]>=1)//如果成立，则a为正方形的左下角，b为右上角
			{
				f+=4;
				map[B.x][B.y-k]-=1;
				map[B.x-k][B.y]-=1;
				map[B.x][B.y]-=1;
				map[A.x][A.y]-=1;
				/*for(i=A.x;i<=A.x+k;i++)
				{
					for(j=A.y;j<=A.y+k;j++)
					{
						if(map[i][j]==1)
							f++;
					}
				}
				if(f>maxn)
					maxn=f;*/
			}
		}
	}
	printf("%d\n",f);
	}
	return 0;
}

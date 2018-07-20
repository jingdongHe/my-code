#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
const int maxs=1000000+10;
typedef struct node {
	int x,y;
	double L,R;
}node;
int n,w,v,s;
bool cmp(node a,node b)
{
	return a.y<b.y;
}
double min(double a,double b)
{
	if(a>b)
		return b;
	return a;
}
double max(double a,double b)
{
	if(a>b)
		return a;
	return b;
}
bool is_ok(int s,node door[])
{
	int i;
	door[n-1].L=door[n-1].x;door[n-1].R=door[n-1].x+w;
	for(i=n-1;i>0;i--)
	{
		int dis=door[i].y-door[i-1].y;
		double time=dis*1.0/s;
		double lev_dis=v*time;
		door[i].L=door[i].L-lev_dis;door[i].R=door[i].R+lev_dis;
		//printf("%d:%lf     %lf    %lf\n",i,door[i].L,door[i].R,lev_dis);
		door[i-1].L=max(door[i-1].x,door[i].L);
		door[i-1].R=min(door[i-1].x+w,door[i].R);
		if(door[i-1].L>door[i-1].R)
			return false;
	}
	return true;
}
int main()
{
	
	int i,T,S;
	node door[maxn];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&w,&v,&n);
		for(i=0;i<n;i++)
		{scanf("%d%d",&door[i].x,&door[i].y);}
		scanf("%d",&s);sort(door,door+n,cmp);
		int maxs=0;
		for(i=0;i<s;i++)
		{
			scanf("%d",&S);
			if(is_ok(S,door))
			{
				if(S>maxs)
					maxs=S;
			//	printf("%d\n",S);
			}
			//printf("----------------------------\n");
		}
		if(maxs==0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",maxs);
	}
	return 0;
}
		
		


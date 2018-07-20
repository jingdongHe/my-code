#include<stdio.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int xl,yl,xr,yr,i;
	int x,y;
}node;
const int maxn=5000+10;
bool cmpy(node a,node b)
{
	if(a.yl==b.yl)
		return a.yr<b.yr;
	return a.yl<b.yl;
}
bool cmpx(node a,node b)
{
	if(a.xl==b.xl)
		return a.xr<b.xr;
	return a.xl<b.xl;
}
bool cmpi(node a,node b)
{
	return a.i<b.i;
}
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int main()
{
	int n;
	node car[maxn];
	while(scanf("%d",&n)&&n)
	{
		int down=1,left=1,k=1,i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&car[i].xl,&car[i].yl,&car[i].xr,&car[i].yr);
			car[i].i=i;
		}
		sort(car,car+n,cmpy);
		for(i=0;i<n&&k;i++)
		{
			
			if(down>n+1)
			{k=0;break;}
			if(car[i].yl>down)
			{car[i].y=car[i].yl;down=car[i].y;}
			else
				car[i].y=down;
			down++;
		}
		sort(car,car+n,cmpx);
		for(i=0;i<n&&k;i++)
		{
			
			if(left>n+1)
			{k=0;break;}
			if(car[i].xl>left)
			{car[i].x=car[i].xl;left=car[i].x;}
			else
				car[i].x=left;
		}
		if(k)
		{
			sort(car,car+n,cmpi);
			for(i=0;i<n;i++)
				printf("%d %d\n",car[i].x,car[i].y);
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
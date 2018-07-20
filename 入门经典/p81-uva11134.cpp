#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=5000+5;
typedef struct node {
	int xl,yl,xr,yr;
	int x,y;
	int id;
}node;
bool cmpx(node a,node b)
{
	if(a.xl==b.xl)
		return a.xr<b.xr;
	return a.xl<b.xl;
}
bool cmpy(node a,node b)
{
	if(a.yl==b.yl)
		return a.yr<b.yr;
	return a.yl<b.yl;
}
bool cmpid(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	int n;
	scanf("%d",&n);
	node car[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&car[i].xl,&car[i].yl,&car[i].xr,&car[i].yr);
		car[i].id=i;
	}
	sort(car,car+n,cmpx);
	int curx=1;
	for(int i=0;i<n;i++)
	{
		if(curx<car[i].xl) curx=car[i].xl;
		//curx=curx>car[i].xl?curx:car[i].xl;
		if(curx>car[i].xr) {printf("INPOSSIBLE\n");return 0;}
		car[i].x=curx++;
	}
	for(int i=0;i<n;i++)
		printf("%d  %d  %d\n",car[i].xl,car[i].xr,car[i].x);
	sort(car,car+n,cmpy);
	int cury=1;
	for(int i=0;i<n;i++)
	{
		if(cury<car[i].yl) cury=car[i].yl;
		//cury=cury>car[i].yl?cury:car[i].yl;
		if(cury>car[i].yr) {printf("INPOSSIBLE\n");return 0;}
		car[i].y=cury++;
	}
	sort(car,car+n,cmpid);
	for(int i=0;i<n;i++)
		printf("%d,%d\n",car[i].x,car[i].y);
	return 0;
}

#include<stdio.h>
#include<math.h>
typedef struct node {
	int x,y;
}node;
const int maxn=50000+5;
double dis(node a,node b)
{
	double x=a.x-b.x;
	double y=a.y-b.y;
	return sqrt(x*1.0*x+y*1.0*y);
}
double dis2(node a,int x,double r)
{
	return sqrt(r*r-(a.x-x)*1.0*(a.x-x));
}
double min(double a,double b)
{
	if(a>b)
		return b;
	return a;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int main()
{
	int m,n;
	node point[maxn];
	double ra=60000,rb=60000;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&point[i].x,&point[i].y);
		if(i!=0)
			ra=min(dis(point[i],point[0]),ra);
		if(i!=1)
			rb=min(dis(point[i],point[1]),rb);
	}
	int k=0;
	for(int i=0;i<m;i++)
	{
		double hight=dis2(point[0],i,ra);
		int h=hight;
		int up=min(point[0].y+h,m-1);
		int down=max(point[0].y-h,0);
		k+=up-down;
		hight=dis2(point[1],i,rb);
		h=hight;
		up=min(point[1].y+h,m-1);
		down=max(point[1].y-h,0);
		k+=up-down;
	}
	printf("%d\n",k);
	return 0;
}
		

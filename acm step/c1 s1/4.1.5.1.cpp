#include<stdio.h>
#include<math.h>
typedef struct {
	double x,y;
}point;
point a,b,c,d;
int p,q,r;
double dis(point A,point B)
{
	return pow(pow(A.x-B.x,2)+pow(A.y-B.y,2),1.0/2);
}
double getcd(point s)
{
	point min,max;
	point mid,mid2;
	double k1,k2;
	min=c;max=d;
	do
	{
		mid.x=(min.x+max.x)/2;
		mid.y=(min.y+max.y)/2;
		mid2.x=(mid.x+max.x)/2;
		mid2.y=(mid.y+max.y)/2;
		k1=dis(mid,s)/r+dis(d,mid)/q;
		k2=dis(mid2,s)/r+dis(d,mid2)/q;
		if(k1>k2) min=mid;
		else max=mid2;
	}while(fabs(k1-k2)>1e-4);
	return k1;
}
double getab()
{
	point min=a,max=b;
	point mid,mid2;
	double k1,k2;
	do
	{
		mid.x=(min.x+max.x)/2;
		mid.y=(min.y+max.y)/2;
		mid2.x=(mid.x+max.x)/2;
		mid2.y=(mid.y+max.y)/2;
		
		k1=dis(a,mid)/p+getcd(mid);
		k2=dis(a,mid2)/p+getcd(mid2);
		if(k1>k2) min=mid;
		else max=mid2;
	}while(fabs(k1-k2)>1e-4);
	return k1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
		scanf("%d%d%d",&p,&q,&r);
		printf("%.2lf\n",getab());
	}
	return 0;
}

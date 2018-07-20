#include<stdio.h>
#include<math.h>
#include<algorithm>
#include <iostream>
using namespace std;
//using namespace std;
//using std::sort;
typedef struct node {
	double x,y;
}node;
bool cmp(node a,node b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
} 
bool cmp1(node a,node b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	else
		return a.x<b.x;
}
double find(node a[],int m,int n)
{
	int i,mid,d1=0,d2=0,j;
	double mindis;
	double mindis1,mindis2;
	node b1[5000],b2[5000];
	if(m==n)
		return 0;
	if(m+1==n)
	{
		double t1=sqrt((a[m].x-a[n].x)*(a[m].x-a[n].x)+(a[m].y-a[n].y)*(a[m].y-a[n].y));
		//printf("%lf,,,,2222,\n",t1);
		return t1;
	}
	if(m+2==n)
	{
		double t1,t2,t3;
		t1=sqrt((a[m].x-a[n].x)*(a[m].x-a[n].x)+(a[m].y-a[n].y)*(a[m].y-a[n].y));
		t2=sqrt((a[m+1].x-a[n].x)*(a[m+1].x-a[n].x)+(a[m+1].y-a[n].y)*(a[m+1].y-a[n].y));
		t3=sqrt((a[m].x-a[m+1].x)*(a[m].x-a[m+1].x)+(a[m].y-a[m+1].y)*(a[m].y-a[m+1].y));
		//printf("%lf,,,,,%lf,,,,,,,,%lf\n",t1,t2,t3);
		if(t1<=t2&&t1<=t3)
			return t1;
		if(t2<=t1&&t2<=t3)
			return t2;
		if(t3<=t1&&t3<=t2)
			return t3;
	}
	mid=(m+n)/2;
	mindis1=find(a,m,mid);
	mindis2=find(a,mid+1,n);
	//printtf("%lf--------%lf\n",mindis1,mindis2);
	mindis=mindis1<mindis2?mindis1:mindis2;
	i=mid-1;
	while(abs(a[i].x-a[mid].x)<mindis)
	{
		b1[d1++]=a[i];
		i--;
	}
	i=mid+1;
	while(abs(a[i].x-a[mid].x)<mindis)
	{
		b2[d2++]=a[i];
		i++;
	}
	sort(b1,b1+d1,cmp1);
	sort(b2,b2+d2,cmp1);
	for(i=0;i<d1;i++)
	{
		for(j=0;j<d2;j++)
		{
			if(abs(b1[i].y-b2[j].y)>mindis)
				break;
			mid=sqrt((b1[i].x-b2[j].x)*(b1[i].x-b2[j].x)+(b1[i].y-b2[j].y)*(b1[i].y-b2[j].y));
			if(mid<mindis)
				mindis=mid;
		}
	}
	//sort(b,b+d,cmp1);
	/*for(i=0;i<d;i++)
	{
		for(j=i+1;j<d;j++)
		{
		mid=sqrt((a[i].x-a[i+1].x)*(a[i].x-a[i+1].x)+(a[i].y-a[i+1].y)*(a[i].y-a[i+1].y));
		if(mid<mindis)
			mindis=mid;
		}
	}*/
	return mindis;
}
void main()
{
	int n,i;
	double d;
	node a[100005];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			return;
		memset(a,'\0',sizeof(a));
	for(i=0;i<n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a,a+n,cmp);
	//for(i=0;i<n;i++)
	//	printf("%lf.......%lf\n",a[i].x,a[i].y);
	d=find(a,0,n-1);
	if((int)(d*1000)%10<5)
		d=d;
	else
		d=d+0.01;
	printf("%.2lf\n",d);
	}
}
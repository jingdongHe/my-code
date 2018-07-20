#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int l,r,d;
}node;
const int maxn=5000+5;
int w,n;
node targe[maxn];
bool cmp(node a,node b)
{
	return a.d<b.d;
}
int is_ok(double k)
{
	double f1,f2;
	int r=targe[n-1].r;
	int l=targe[n-1].l;
	if(k<=targe[n-1].r&&k>=targe[n-1].l)
	{
		double q1,q2;
		q1=(r-k)*targe[n-1].d;
		q2=(k-l)*targe[n-1].d;
		for(int i=0;i<n-1;i++)
		{
			f1=k+q1*1.0/targe[i].d;
			f2=k-q2*1.0/targe[i].d;
			if(targe[i].l>f1) return 1;
			else if(targe[i].r<f2) return -1;
		}
	}
	else if(k<targe[n-1].l)
	{
		double q1,q2;
		q1=(r-k)*targe[n-1].d;
		q2=(l-k)*targe[n-1].d;
		for(int i=0;i<n-1;i++)
		{
			f1=k+q1*1.0/targe[i].d;
			f2=k+q2*1.0/targe[i].d;
			if(targe[i].l>f1) return 1;
			else if(targe[i].r<f2) return -1;
		}
	}
	else if(k>targe[n-1].r)
	{
		double q1,q2;
		q1=(k-r)*targe[n-1].d;
		q2=(k-l)*targe[n-1].d;
		for(int i=0;i<n-1;i++)
		{
			f1=k-q1*1.0/targe[i].d;
			f2=k-q2*1.0/targe[i].d;
			if(targe[i].l>f1) return 1;
			else if(targe[i].r<f2) return -1;
		}
	}
	return 0;
}
int main()
{
	
	scanf("%d",&w);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d",&targe[i].d,&targe[i].l,&targe[i].r);
	sort(targe,targe+n,cmp);
	double L=0,R=w;
	while(R-L>1e-3)
	{
		double m=(R+L)*1.0/2;
		if(!is_ok(m))
		{
			printf("YES\n");return 0;
		}
		else if(is_ok(m)==1)
		{
			L=m;
		}
		else if(is_ok(m)==-1)
		{
			R=m;
		}
	}
	printf("NO\n");
	return 0;
}

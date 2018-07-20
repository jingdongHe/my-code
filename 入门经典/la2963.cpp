#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=100+5;
const int maxe=maxn*(maxn-1)/2;
typedef struct node {
	int x,y,z,p;
}point;
typedef struct {
	int s,e;
	double l;
}edge;
bool cmp(edge a,edge b)
{
	return a.l<b.l;
}
int main()
{
	int n;
	scanf("%d",&n);
	point a[maxn];
	int c[maxn];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].z,&a[i].p);
		c[i]=1;
	}
	edge e[maxe];
	int k=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			e[k].s=i;
			e[k].e=j;
			e[k++].l=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z));
		}
	}
	sort(e,e+k,cmp);
	int cur=0,ans=0;double L=0;
	for(int i=0;i<k;i++)
	{
		int E=e[i].e,S=e[i].s;
		double length=e[i].l;
		if(a[E].p!=a[S].p)
		{
			c[E]--;
			c[S]--;
			if(c[E]==-1) cur++;
			if(c[S]==-1) cur++;
		}
		else 
		{
			c[E]++;
			c[S]++;
			if(c[E]==0) cur--;
			if(c[S]==0) cur--; 
		}
		if(cur>ans)
		{
			ans=cur;
			L=length;
		}
	}
	printf("%d\n%.4lf\n",ans,L);
	return 0;
}

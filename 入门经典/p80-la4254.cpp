#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef struct node {
	int r,d,w;
}node;
typedef struct temp_node {
	int d,w;
	int *r;
}temp_node;
const int maxn=10000+5;
int n;
node seq[maxn];
bool cmp(node a,node b)
{
	if(a.r==b.r)
		return a.d<b.d;
	return a.r<b.r;
}
bool cmp1(temp_node a,temp_node b)
{
	if(*a.r==*b.r)
		return a.d<b.d;
	return *a.r<*b.r;
}
bool is_ok(int c)
{
	temp_node temp[maxn];
	for(int i=0;i<n;i++)
	{
		temp[i].r=(int *)malloc(sizeof(int));
		*temp[i].r=seq[i].r;
		temp[i].d=seq[i].d;
		temp[i].w=seq[i].w;
	}
	
	for(int i=0;i<n;i++)
	{
		if(i+1<n&&temp[i].r<temp[i+1].r&&temp[i].d>temp[i+1].d)
		{
			temp[i].w-=(seq[i+1].r-seq[i].r)*c;
			*temp[i].r=*temp[i+1].r;
			temp[i].r=temp[i+1].r;
		}
	}
	sort(temp,temp+n,cmp1);
	/*printf("-----------------\n");
	for(int i=0;i<n;i++)
		printf("%d:%d  %d  %d\n",temp[i].r,*temp[i].r,temp[i].d,temp[i].w);
	printf("-----------------\n");*/
	double L=0;
	for(int i=0;i<n;i++)
	{
		//printf("%d:%d  %d  %d\n",temp[i].r,*temp[i].r,temp[i].d,temp[i].w);
		L=L>*temp[i].r?L:*temp[i].r;
		//printf("%lf....\n",L);
		if(temp[i].w>0)
			L+=temp[i].w*1.0/c;
		if(L>temp[i].d)
			return false;
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	int k=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&seq[i].r,&seq[i].d,&seq[i].w);
		k+=seq[i].w;
	}
	sort(seq,seq+n,cmp);
	/*printf("%d\n",is_ok(6));*/
	int L=0,R=k;
	while(L<R)
	{
		int m=(L+R)/2;
		//printf("%d\n",m);
		if(is_ok(m)) R=m;
		else L=m+1;
	}
	printf("%d\n",L);
	}
	return 0;
}

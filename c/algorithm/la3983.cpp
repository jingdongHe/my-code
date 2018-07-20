#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int x[maxn],y[maxn];
int total_dis[maxn],total_weight[maxn],dist2[maxn];
int q[maxn],d[maxn];
int func(int i)
{
	return d[i]-total_dis[i+1]+dist2[i+1];
}
int main()
{
	int T,c,n,w,front,rear;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&c,&n);
		total_dis[0]=total_weight[0]=x[0]=y[0]=0;
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&w);
			dist2[i]=abs(x[i])+abs(y[i]);
			total_dis[i]=total_dis[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			total_weight[i]=total_weight[i-1]+w;
		}
		front=rear=1;
		for(i=1;i<=n;i++)
		{
			while(front<=rear&&total_weight[i]-total_weight[q[front]]>c)
				front++;
			d[i]=func(q[front])+total_dis[i]+dist2[i];
			while(front<=rear&&func(i)<=func(q[rear])) rear--;
			q[++rear]=i;
		}
		printf("%d\n",d[n]);
	}
	return 0;
}
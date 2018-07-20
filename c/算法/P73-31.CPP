#include<stdio.h>
#include<math.h>
int main()
{
	int c,n,w,i;
	int x[100+1]={0},y[100+1]={0},q[100+1]={0},d[100+1]={0};
	int dis2[100+1]={0},dis[100+1]={0},weight[100+1]={0};
	scanf("%d%d",&c,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&w);
		dis2[i]=abs(x[i])+abs(y[i]);
		dis[i]=dis[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		weight[i]=weight[i-1]+w;
	}
	int rear,front;
	rear=front=1;
	for(i=1;i<=n;i++)
	{
		while(front<=rear&&weight[i]-weight[q[front]]>c)
			front++;//·Ö¶Ñ
		d[i]=d[q[front]]-dis[q[front]+1]+dis2[q[front]+1]+dis[i]+dis2[i];
		while(front<=rear&&d[i]-dis[i+1]+dis2[i+1]<=dis[q[rear]]-dis[q[rear]+1]+dis2[q[rear]+1])
			rear--;
		q[++rear]=i;
	}
	printf("%d\n",d[n]);
	return 0;
}
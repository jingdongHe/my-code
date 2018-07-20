#include<stdio.h>
#include<string.h>
const int maxn=100000+5;
int sum[maxn];
double getk(int i,int j)
{
	return (sum[j]-sum[i-1])*1.0/(j-i+1);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[maxn];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int q[maxn];
	int front=0,rear=0,s,e;
	int l=99999;double ans=0;
	for(int i=1;i<=n;i++)
	{
		while(front<rear&&getk(q[rear],i)<=getk(q[rear-1],q[rear]))
			rear--;
		q[rear++]=i;
		while(front<rear&&getk(q[front],i)<=getk(q[front+1],i))
			front++;
		double temp=getk(q[front],i);
		if((temp>ans)||(temp==ans&&i-q[front]<l))
		{
			l=i-q[front];
			ans=temp;
			s=q[front];
			e=i;
		}
	}
	printf("%d  %d\n",s,e);
}

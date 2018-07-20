#include<stdio.h>
const int maxn=150000+5;
int main()
{
	char A[maxn],B[maxn];
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
		scanf("%c",&A[i]);
	for(int i=1;i<=n;i++)
		scanf("%c",&B[i]);
	
	int d[maxn];
	d[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(A[i]==B[i])
			d[i]=d[i-1]+1;
		else
			d[i]=d[i-1];
	}
	
	int queue[maxn];
	int head=0,rear=0;
	int max=0;
	for(int i=2;i<=n;i++)
	{
		int s=100*d[i]-p*i;
		if(head==rear)
			queue[rear++]=s;
		while(head!=rear&&s>queue[head])
			head++;
		queue[rear++]=s;
		max=max>rear-head?max:rear-head;
	}
	printf("%d\n",max);
	return 0;
}

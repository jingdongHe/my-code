#include<stdio.h>
const int maxn=100000+5;
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int a[maxn],sum[maxn]={0};
		int max=-9999,head=1,last=1,Head,Last;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(sum[i-1]+a[i]>=a[i])
			{sum[i]=sum[i-1]+a[i];last=i;}
			else
			{sum[i]=a[i];head=i;last=i;}
			if(sum[i]>=max)
			{
				max=sum[i];
				Head=head;
				Last=last;
			}
		}
		printf("Case %d:\n%d %d %d\n",t,max,Head,Last);
		if(t!=T) printf("\n");
	}
	return 0;
}

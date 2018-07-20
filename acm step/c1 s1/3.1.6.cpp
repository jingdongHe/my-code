#include<stdio.h>
const int maxn=25;
int main()
{
	int l[maxn],h[maxn],sum[maxn];
	l[1]=2;h[1]=1;sum[1]=3;
	l[2]=4;h[2]=3;sum[2]=7;
	for(int i=3;i<=20;i++)
	{
		h[i]=sum[i-1];
		l[i]=h[i-1]*2+l[i-1];
		sum[i]=h[i]+l[i];
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",sum[n]);
	}
	return 0;
}

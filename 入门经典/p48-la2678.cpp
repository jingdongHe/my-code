#include<stdio.h>
const int maxn=100000+5;
int main()
{
	int n,s;
	unsigned array[maxn],sum[maxn];
	scanf("%d%d",&n,&s);
	sum[0]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		if(array[i]>=s)
		{
			printf("1\n");
			return 0;
		}
		sum[i+1]=sum[i]+array[i];
	}
	int end,star=1,ans=n+1;
	for(end=1;end<n;end++)
	{
		if(sum[star-1]>sum[end]-s)//B（i）<=B(j)-s
			continue;
		while(sum[star-1]+s<=sum[end]) star++;//执行完这步之后，star-end的子序列和<s 
		ans=ans<end-star+2?ans:end-star+2;
	}
	if(ans==n+1)
		printf("0\n");
	else
		printf("%d\n",ans);
	return 0;
}

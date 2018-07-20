#include<stdio.h>
int next(int n,int k)
{
	if(k==0)
		return 0;
	_int64 k1=(_int64)k*k;
	int bty[10],i=0,j;
	while(k1>0)
	{
		bty[i++]=k1%10;
		k1/=10;
	}
	if(i<n) n=i;
	int digits=0;
	for(j=0;j<n;j++)
		digits=digits*10+bty[--i];
	return digits;
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int maxn=k;
		int k1,k2;
		k1=k2=k;
		/*k1=next(n,k1);
		k2=next(n,k2);if(k2>maxn) maxn=k2;
		k2=next(n,k2);if(k2>maxn) maxn=k2;*/
		do
		{
			k1=next(n,k1);
			k2=next(n,k2);if(k2>maxn) maxn=k2;
			k2=next(n,k2);if(k2>maxn) maxn=k2;
		}
		while(k1!=k2);
		printf("%d\n",maxn);
	}
	return 0;
}


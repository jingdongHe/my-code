#include<stdio.h>
int d;int a[10000];
bool have(int k)
{
	int i;
	for(i=0;i<d;i++)
	{
		if(a[i]==k)
			return true;
	}
	return false;
}
int next(int n,int k)
{
	int b[10],c=0;
	long k1=k*k;
	while(k1!=0)
	{
		b[c++]=k1%10;
		k1/=10;
	}
	int ans=0;
	int i;
	if(c<n)n=c;
	for(i=0;i<n;i++)
		ans+=ans*10+b[--c];
	return ans;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=k;
	while(!have(k))
	{
		a[d++]=k;
		if(k>ans)ans=k;
		k=next(n,k);
	}
	printf("%d\n",ans);
	return 0;
}
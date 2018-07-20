#include<stdio.h>
int main()
{
	int n,i,k;
	_int64 f[100]={0};
	f[2]=f[3]=1;
	for(i=4;i<=35;i++)
	{
		for(k=2;k<i;k++)
			f[i]+=f[k]*f[i-k+1];
	}
	while(scanf("%d",&n))
	{
		printf("%I64d\n",f[n]);
	}
	return 0;
}
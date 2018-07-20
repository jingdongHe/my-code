#include<stdio.h>
int main()
{
	int i,n;
	int f[10000];
	int k,m;
	scanf("%d%d%d",&n,&k,&m);
	f[1]=0;
	for(i=2;i<=n;i++)
	{
		f[i]=(f[i-1]+k)%i;
		//printf("%d:%d\n",i,f[i]+1);
	}
	printf("%d\n",(f[i-2]+m)%n+1);
	return 0;
}
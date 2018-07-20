#include<stdio.h>
const int maxn=10000+5;
int main()
{
	int n,k,m,i;
	int f[maxn];
	while(scanf("%d%d%d",&n,&k,&m)&&n)
	{
		f[1]=0;
		for(i=2;i<=n;i++)
			f[i]=(f[i-1]+k)%i;
		printf("%d\n",(m-k+1+f[n]+n)%n);
	}
	return 0;
}
#include<stdio.h>
#define maxn 10005
int main()
{
	int n,k,m;
	while(scanf("%d%d%d",&n,&k,&m)&&n&&k&&m)
	{
		int f[maxn];
		f[1]=0;
		for(int i=2;i<=n;i++)
			f[i]=(f[i-1]+k)%i;
		int res=(f[n]+m-k+1)%n;
		if(res<0) res+=n;
		printf("%d\n",res);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n,m,k;
	int f[10000+5];
	scanf("%d%d%d",&n,&k,&m);
	f[1]=0;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+k)%i;
	printf("%d\n",(m-k+1+f[n]+n)%n);
	return 0;
}

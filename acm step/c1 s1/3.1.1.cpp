#include<stdio.h>
const int maxn=50;
int main()
{
	int n,t;
	int f[maxn];
	f[1]=f[2]=1;
	for(int i=3;i<=40;i++)
		f[i]=f[i-1]+f[i-2];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",f[n]);
	}
	return 0;
}

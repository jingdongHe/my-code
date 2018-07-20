#include<stdio.h>
const int maxn=55;
int main()
{
	int n;
	__int64 f[maxn];
	f[1]=1;f[2]=2;
	for(int i=3;i<=50;i++)
		f[i]=f[i-1]+f[i-2];
	while(scanf("%d",&n)!=EOF)
		printf("%I64d\n",f[n]);
	return 0;
}

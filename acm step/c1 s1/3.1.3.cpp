#include<stdio.h>
const int maxn=60;
int main()
{
	int n;
	int f[maxn];
	f[1]=1;f[2]=2;f[3]=3;f[4]=4;
	for(int i=5;i<=55;i++)
		f[i]=f[i-1]+f[i-3];
	while(scanf("%d",&n)!=EOF&&n!=0)
		printf("%d\n",f[n]);
	return 0;
}

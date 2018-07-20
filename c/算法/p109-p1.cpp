#include<stdio.h>
int main()
{
	int i,n;
	int f[100]={0};
	scanf("%d",&n);
	f[0]=f[1]=1;
	for(i=2;i<n;i++)
		f[i]=f[i-1]+f[i-2];
	printf("%d\n",f[n-1]);
	return 0;
}
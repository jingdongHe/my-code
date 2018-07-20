#include<stdio.h>
#include<math.h>
const int maxn=1000000;
int a[maxn+5];
int main()
{
	a[1]=2;a[2]=4;
	a[3]=6;a[4]=9;
	
	int l,M;
	while(scanf("%d%d",&l,&M)!=EOF)
	{
		for(int i=5;i<=l;i++)
		{
			a[i]=a[i-1]+a[i-3]+a[i-4];
			a[i]%=M;
		}
		printf("%d\n",a[l]);
	}
	return 0;
}

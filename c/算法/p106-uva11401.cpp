#include<stdio.h>
int f(int x)
{
	int d,k;
	k=(x-1)/2;
	d=((x-1)*(x-2)/2-k)/2;
	return d;
}
int main()
{
	int n,i,d;
	while(scanf("%d",&n))
	{
		d=0;
		for(i=4;i<=n;i++)
			d+=f(i);
		printf("%d\n",d);
	}
	return 0;
}
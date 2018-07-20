#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int k=1;
		while(k<n)
		{
			int a,b,c;
			c=(n/k)/11;
			b=(n/k)%11;
			a=n-b-c;
			printf("%d  %d  %d  %d\n",a,b,c,a+b*k+c*k*10);
			k*=10;
		}
	}
	return 0;
}

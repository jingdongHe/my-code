#include<stdio.h>
#include<math.h>
int main()
{
	long d;
	double i,n;
	while(scanf("%lf",&n)!=EOF)
	{
		if(n<=0)
			break;
		d=0;
		i=(double)(n*(n+1)*(n+2)/6);
		d=log10(i);
		i=i/pow(10,d);
		printf("%.2fE%ld\n",i,d);
	}
	return 0;
}
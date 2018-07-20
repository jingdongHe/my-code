#include<stdio.h>
#include<math.h>
int main()
{
	int k,a;
	double f,n;
	a=1;
	while(scanf("%lf",&n)==1&&n>=0)
	{
		f=log(n)/log(2);
		k=(int)f;
		if(k==f)
			printf("Case %d: %d\n",a++,k);
		else
			printf("Case %d: %d\n",a++,k+1);
	}
	return 0;
}
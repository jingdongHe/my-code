#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	long  m;
	while(scanf("%d",&n)!=EOF)
	{
		m=3*pow(2,(n))-3*pow(2,(n-1));
		printf("%ld\n",m);
	}
	return 0;
}

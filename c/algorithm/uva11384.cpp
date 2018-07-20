#include<stdio.h>
long f(long n)
{
	return n==1?1:f(n/2)+1;
}
int main()
{
	long n;
	while(scanf("%ld",&n)!=EOF)
		printf("%ld\n",f(n));
	return 0;
}
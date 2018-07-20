#include<stdio.h>
int main()
{
	unsigned int n,m,s;
	while(scanf("%u%u",&n,&m)!=EOF&&(n||m))
	{
		s=m+n-2;
		printf("%u\n",s);
	}
	return 0;
}
#include<stdio.h>
int num(int n)
{
	return n==1?1:num(n/2)+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",num(n));
	return 0;
}
#include<stdio.h>
int main()
{
	int n,k;
	scanf("%d",&n);
	k=n&0x8;
	printf("%d",k);
	return 0;
}

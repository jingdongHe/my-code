#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<4) printf("1\n");
	else if(n==4) printf("2\n");
	else if(n>4) printf("%d\n",n);
	return 0;
}

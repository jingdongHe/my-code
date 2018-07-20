#include<stdio.h>
int ride(int n);
int ride(int n){
	if(n==1)
		return 1;
	else
		return n*ride(n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",ride(n));
	return 0;
}

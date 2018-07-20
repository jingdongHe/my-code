#include<stdio.h>
int k=0;
void f(double n)
{
	
	if(n<=1)
		return;
	k++;
	f(n*1.0/2);
}
int main()
{
	int n;
	int t=0;
	while(scanf("%d",&n)&&n>=0)
	{
		k=0;
		f(n);
		printf("Case %d: %d\n",++t,k);
	}
	return 0;
}
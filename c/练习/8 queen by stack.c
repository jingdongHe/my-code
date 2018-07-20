#include<stdio.h>
#include<stack.h>
int main()
{
	int n,s[10];
	Initstack(s);
	scanf("%d",&n);
	while(n)
	{
		push(s,n);
		n/=10;
	}
	while(!empty(s))
	{
		printf("%d",top(s));
		pop(s);
	}
	return 0;
}

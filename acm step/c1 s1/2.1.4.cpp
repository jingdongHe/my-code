#include<stdio.h>
int gcd(int a,int b)
{
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int p,q;
	while(scanf("%d%d",&p,&q)!=EOF)
	{
		printf("%d\n",p+q-gcd(p,q));
	}
	return 0;
}

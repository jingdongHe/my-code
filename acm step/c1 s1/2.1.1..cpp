#include<stdio.h>
int gcd(int a,int b)
{
	if(a<b)
	{int temp=a;a=b;b=temp;}
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",a*b/gcd(a,b));
	}
	return 0;
}

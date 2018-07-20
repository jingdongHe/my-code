#include<stdio.h>
int gcd(__int64 a,__int64 b)
{
	if(a<b)
	{
		__int64 temp;
		temp=a;a=b;b=temp;
	}
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int p;
	scanf("%d",&p);
	while(p--)
	{
		__int64 m,n;
		scanf("%I64d%I64d",&m,&n);
		if(gcd(m,n)==1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

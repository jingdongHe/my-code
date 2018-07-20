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
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF&&n!=-1&&m!=-1)
	{
		if(gcd(n,m)==1) printf("YES\n");
		else printf("POOR Haha\n");
	}
	return 0;
}

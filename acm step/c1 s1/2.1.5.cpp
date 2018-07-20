#include<stdio.h>
int gcd(int a,int b)
{
	if(a<b){int temp=a;a=b;b=temp;}
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int temp=a/b;
		for(int i=2;;i++)
		{
			if(gcd(temp,i)==1)
			{
				printf("%d\n",i*b);
				break;
			}
		}
	}
	return 0;
}

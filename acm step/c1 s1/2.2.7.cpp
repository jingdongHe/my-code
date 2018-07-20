#include<stdio.h>
int main()
{
	__int64 n;
	while(scanf("%I64d",&n)&&n!=0)
	{
		__int64 k=0;
		do
		{
			k=0;
			while(n!=0)
			{
				k+=n%10;
				n/=10;
			}
			n=k;
		}while(k/10>0);
		printf("%I64d\n",k);
	}
	return 0;
}

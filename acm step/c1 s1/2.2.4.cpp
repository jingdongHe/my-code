#include<stdio.h>
int main()
{
	int p;
	scanf("%d",&p);
	while(p--)
	{
		__int64 m,n;
		scanf("%I64d%I64d",&m,&n);
		long a=0,b=0,k=0;
		printf("%I64d......%I64d\n",m,n);
		do
		{
			a+=m;
			a%=n;
			b+=2*m;
			b%=n;
			k++;
			//printf("%I64d  %I64d\n",a,b);
			if(k>n) break;
		}while(a!=b);
		if(k>=n)printf("NO\n");
		else printf("YES\n");
	}
}

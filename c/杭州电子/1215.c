#include<stdio.h>
#include<math.h>
int main()
{
	int t,n;
	unsigned sum;
	int i,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
			sum=1;
			for(i=2;i<=sqrt((double)n);i++)
			{
				if(n%i==0)
				{
					if(i!=n/i)
						sum+=n/i+i;
					else
						sum+=i;
				}
			}
			printf("%u\n",sum);
	}
	return 0;
}
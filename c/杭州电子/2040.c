#include<stdio.h>
#include<math.h>
int main()
{
	int n,a,b,i,j,sum1=0,sum2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		for(j=1;j<(a/2)+1;j++)
		{
			if(a%j==0)
				sum1+=j;
		}
		for(j=1;j<(b/2)+1;j++)
		{
			if(b%j==0)
				sum2+=j;
		}
		if(sum2==a&&sum1==b)
			printf("YES\n");
		else
			printf("NO\n");
		sum1=0;sum2=0;
	}
	return 0;
}
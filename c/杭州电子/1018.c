#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,m,j;
	double sum;
	while(scanf("%d",&m)!=EOF)
	{
	for(j=0;j<m;j++)
	{
		scanf("%d",&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=log10((double)i);
		}
		if((int)(sum/0.1)%10>0)
			sum+=1;
		printf("%d\n",(int)sum);
	}
	}
	return 0;
}
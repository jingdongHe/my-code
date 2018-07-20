#include<stdio.h>
#include<math.h>
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double k=0;
		for(int i=1;i<=n;i++)
			k+=log10(i*1.0);
		printf("%d\n",int(k)+1);
	}
	return 0;
}

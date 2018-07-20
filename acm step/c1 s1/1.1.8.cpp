#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int k,d,s=0;
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d",&d);
			s+=d;
		}
		printf("%d\n",s);
		if(n>=1)
			printf("\n");
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		int d,s=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&d);
			s+=d;
		}
		printf("%d\n",s);
	}
	return 0;
}

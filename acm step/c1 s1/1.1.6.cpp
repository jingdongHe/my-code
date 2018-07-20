#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int s=0,d;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&d);
			s+=d;
		}
		printf("%d\n",s);
	}
	return 0;
}

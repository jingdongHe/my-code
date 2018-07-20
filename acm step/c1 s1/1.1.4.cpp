#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0)
	{
		int d,s=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&d);
			s+=d;
		}
		printf("%d\n",s);
	}
	return 0;
}

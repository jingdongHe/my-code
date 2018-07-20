#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		int a=0,b;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b);
			a^=b;
		}
		printf("%d\n",a);
	}
	return 0;
}

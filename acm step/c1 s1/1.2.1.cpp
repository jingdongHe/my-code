#include<stdio.h>
int main()
{
	int n,u,d;
	while(scanf("%d%d%d",&n,&u,&d)!=EOF&&n!=0)
	{
		int k=0;
		while(n>0)
		{
			k++;
			n-=u;
			if(n<=0)
				break;
			k++;
			n+=d;
		}
		printf("%d\n",k);
	}
	return 0;
}

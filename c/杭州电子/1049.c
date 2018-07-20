#include<stdio.h>
int main()
{
	int n,u,d,i,time;
	while(scanf("%d%d%d",&n,&u,&d)!=EOF&&d<u&&d>0&&n<100&&n>0)
	{
		i=0;time=0;
		while(i<n)
		{
			i+=u;
			time++;
			if(i<n)
			{
				i-=d;
				time++;
			}
		}
		printf("%d\n",time);
	}
	return 0;
}



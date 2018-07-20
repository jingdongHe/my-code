#include<stdio.h>
int main()
{
	int n,m,time=0,floor=0;
	while(scanf("%d",&n)!=EOF&&n>0)
	{
		while(n)
		{
			scanf("%d",&m);
			if(m-floor>0)
				time+=(m-floor)*6+5;
			else
				time+=(floor-m)*4+5;
			floor=m;
			n--;
		}
		printf("%d\n",time);
		time=0;floor=0;
	}
	return 0;
}

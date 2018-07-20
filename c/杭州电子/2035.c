#include<stdio.h>
int main()
{
	int a,b,c,i;
	scanf("%d%d",&a,&b);
	while(a!=0&&b!=0)
	{
		c=1;
		for(i=0;i<b;i++)
		{
			c*=a;
			c=c%1000;
		}
		printf("%d\n",c);
		scanf("%d%d",&a,&b);
	}
	return 0;
}

#include<stdio.h>
int main()
{
	double d,s=0;
	for(int i=0;i<12;i++)
	{
		scanf("%lf",&d);
		s+=d;
		
	}
	printf("$%.2lf\n",s/12.0);
	return 0;
}

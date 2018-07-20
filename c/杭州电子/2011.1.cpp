#include<stdio.h>
int main()
{
	int m,n,a,f;
	double s;
	scanf("%d",&m);
	while(m--)
	{	
		scanf("%d",&n);
		a=1;s=0;f=1;
		while(n--)
		{
			
			s+=f*(double)1/(a++);
			f=-f;
		}
		printf("%.2lf\n",s);
	}
	return 0;
}

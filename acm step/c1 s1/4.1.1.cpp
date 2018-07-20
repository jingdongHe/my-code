#include<stdio.h>
#include<math.h>
double f(double a)
{
	return 8*pow(a,4)+7*pow(a,3)+2*pow(a,2)+3*a+6;
}
int main()
{
	double min,max,mid;
	int t;double n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		if(f(100)<n||f(0)>n)
		{printf("No solution!\n");continue;}
		min=0;max=100;
		while(max-min>1e-8)
		{
			mid=(max+min)/2.0;
			double result=f(mid);
			if(result>n) max=mid;
			else if(result<n) min=mid;
			else break;
		}
		printf("%.4lf\n",mid);
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
double r,R,H,v;
double f(double h)
{
	double u=r+(R-r)*h/H;
	return acos(-1.0)*h*(r*r+r*u+u*u)/3.0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&r,&R,&H,&v);
		double min=0,max=100;
		double mid;
		while(max-min>1e-8)
		{
			mid=(min+max)/2.0;
			double temp=f(mid);
			if(temp>v) max=mid;
			else if(temp<v) min=mid;
			else break;
		}
		printf("%.6lf\n",mid);
	}
	return 0;
}

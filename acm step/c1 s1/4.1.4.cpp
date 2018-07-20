#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)
double x,y,l,w;
double f(double corner)
{
	double s=w*sin(corner)+l*cos(corner)-x;
	return w*cos(corner)+s*tan(corner);
}
int main()
{
	while(scanf("%lf%lf%lf%lf",&x,&y,&l,&w)!=EOF)
	{
		double min=0,max=PI/2.0;
		double mid,mid2;
		while(max-min>1e-4)
		{
			mid=(min+max)/2.0;
			mid2=(mid+max)/2.0;
			double k=f(mid),k2=f(mid2);
			if(k<k2) min=mid;
			else if(k>k2) max=mid2;
		}
		if(f(mid)>y) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}

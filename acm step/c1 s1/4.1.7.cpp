#include<stdio.h>
#include<math.h>
const int maxn=10000+5;
typedef struct {
	double r,z;
}point;
int n;double H;
point arr[maxn];
double f(double h)
{
	double r=0;
	for(int i=0;i<n;i++)
	{
		if(r<h*arr[i].r/(h-arr[i].z))
			r=h*arr[i].r/(h-arr[i].z);
	}
	return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			double a,b;
			scanf("%lf%lf%lf",&a,&b,&arr[i].z);
			arr[i].r=sqrt(a*a+b*b);
			if(arr[i].z>H) H=arr[i].z;
		}
		double min=H,max=1e6;
		double mid,mid2;
		while(max-min>1e-4)
		{
			mid=(max+min)/2.0;
			mid2=(mid+min)/2.0;
			double v1=f(mid),v2=f(mid2);
			v1=v1*v1*mid;v2=v2*v2*mid2;
			if(v1>v2) max=mid;
			else min=mid2;
		}
		printf("%.3lf %.3lf\n",mid,f(mid));
	}
	return 0;
}

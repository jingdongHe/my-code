#include<stdio.h>
#include<math.h>
const double PI=acos(-1);
int F,N;
bool ok(double area[],double x)
{
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		cnt+=(int)(area[i]/x);
	}
	if(cnt>=F+1)
		return true;
	else
		return false;
}
int main()
{
	scanf("%d%d",&N,&F);
	int r;double area[10000];
	double max=0,min;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&r);
		area[i]=PI*r*r;
		max=max>area[i]?max:area[i];
	}
	while(max-min>1e-4)
	{
		double mid=(max+min)/2;
		if(ok(area,mid))
			min=mid;
		else
			max=mid; 
	}
	printf("%.3lf\n",max);
	return 0;
}

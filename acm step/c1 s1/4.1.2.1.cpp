#include<stdio.h>
#include<math.h>
double f(double x,double y)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*x*x-y*x;
}
double fuction(double x)
{
	return 42*pow(x,6)+48*pow(x,5)+21*x*x+10*x;
}
double find_zore(double y)
{
	double min=0,max=100;
	double mid;
	while(max-min>1e-6)
	{
		mid=(min+max)/2.0;
		double k=fuction(mid);
		/*printf("%lf..%lf\n",y,mid);
		printf("%lf...%lf...%lf\n",min,mid,max);*/
		
		if(k<y) min=mid;
		else if(k>y) max=mid;
		else break;
	}
	//printf("%lf\n",mid);
	return mid;
}
int main()
{
	int t;double y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&y);
		//printf("%lf,%lf\n",fuction(100),y);
		if(fuction(100)<y)
			printf("%.4lf\n",f(100,y));
		else
		{
			double k=find_zore(y);
			printf("%.4lf\n",f(k,y));
		}
	}
	return 0;
}

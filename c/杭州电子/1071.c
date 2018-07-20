#include<stdio.h>
#include<math.h>
int main()
{
	double x1,y1,x2,y2,x3,y3,area;
	int t,i;
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
		{
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		area=(y2-y1)*pow(x3-x1,3)/(3*pow(x2-x1,2))-(y2-y1)*(x2-x1)/3+(y1-y2)*(x3-x2)-(y3-y2)*(x3-x2)/2;
		printf("%.2f\n",area);
		}
	}
	return 0;
}
#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		double space_n,space_m;
		space_n=10000*1.0/n;
		space_m=10000*1.0/(n+m);
		
		double ans=0;
		int j=0;
		for(int i=0;i<n;i++)
		{
			double pos=10000;
			for(;j<m+n;j++)
			{
				if(fabs(j*space_m-i*space_n)<pos)
					pos=fabs(j*space_m-i*space_n);
				else
					break;
			}
			ans+=pos;
		}
		if(ans-(int)ans==0)
			printf("%d.0\n",(int)ans);
		else
			printf("%.4lf\n",ans);
	} 
	return 0; 
}

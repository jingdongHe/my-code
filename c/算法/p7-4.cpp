#include<stdio.h>
#include<math.h>
#define k 99999
int main()
{
	int n,m;
	double ave_n,ave_m;
	double N[1000],M[1000];
	int i,j,r;
	double ans,a;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ave_n=10000.0/n;
		ave_m=10000.0/(n+m);
		for(j=0;j<m+n;j++)
		{
			if(j<n)
				N[j]=j*ave_n;//得出第全部n的坐标
			M[j]=j*ave_m;//得出加入m之后的全部坐标
		}
		/*printf("%.5lf........%.5lf\n",ave_n,ave_m);
		
		for(j=0;j<n;j++)
			printf("%.4lf ",N[j]);
		printf("\n");
		for(i=0;i<m+n;i++)
			printf("%.4lf ",M[i]);
		printf("\n");*/
		ans=0;
		for(i=0;i<n;i++)
		{
			a=k*1.0;
			for(j=0;j<m+n;j++)
			{
				
				//printf("%d: %.4lf %.4lf\n",i,fabs(N[i]-M[j]),a);
				if(fabs(N[i]-M[j])<a)
				{
					a=fabs(N[i]-M[j]);
					r=j;//用r来记录距离最短的位置
					//printf("%.4lf ",a);
				}
				
			}
			M[r]=k*1.0;
			ans+=a;
			//printf("\n");
		}
		printf("%.4lf\n",ans);
		
	}
	return 0;
}

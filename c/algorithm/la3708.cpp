#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	double begin[1000],end[2000];
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
	{
		double k;
		int i,j;
		double ans=0;
		begin[0]=end[0]=0;
		k=10000*1.0/n;
		for(i=1;i<n;i++)
		{
			begin[i]=begin[i-1]+k;
			//printf("%.4lf ",begin[i]);
		}
		//printf("\n");
		k=10000*1.0/(m+n);
		for(i=1;i<n+m;i++)
		{
			end[i]=end[i-1]+k;
			//printf("%.4lf ",end[i]);
		}
		//printf("\n");
		for(i=0;i<n;i++)
		{
			k=9999;
			j=(i+n+m-1)%(n+m);
			while(fabs(begin[i]-end[j])<k)
			{k=fabs(begin[i]-end[j]);j=(j+n+m+1)%(n+m);}
			//printf("%d   %d:%lf...\n",i,j,k);
			ans+=k;
		}
		printf("%.4lf\n",ans);
	}
	return 0;
}
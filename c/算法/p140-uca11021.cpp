#include<stdio.h>
#include<math.h>
int main()
{
	int T,n,k,m;
	double p[1000],f[1000];
	scanf("%d",&T);
	while(T--)
	{
		int i,j;
		scanf("%d%d%d",&n,&k,&m);
		for(i=0;i<n;i++)
			scanf("%lf",&p[i]);
		printf("%d  %d  %d  \n",n,k,m);
		f[0]=0;f[1]=p[0];
		for(i=2;i<=m;i++)
		{
			f[i]=0;
			for(j=0;j<n;j++)
				f[i]+=p[j]*pow(f[i-1],j);
		}
		printf("%.7lf\n",pow(f[m],k));
	}
	return 0;
}
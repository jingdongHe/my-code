#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,k,j[1000],f[1000];
	double a[1000],bean=0,max;
	while(scanf("%d%d",&n,&m)!=EOF&&m>=0&&n>=0)
	{
		bean=0;
		if(m==0)
		{
			printf("%.3lf\n",bean);
			continue;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j[i],&f[i]);
			if(f[i]==0)
			{
				bean+=j[i];
				f[i]=100000;
			}
			a[i]=(double)j[i]/f[i];
		}
		max=0;
		for(i=0;i<m;i++)
		{
			if(max<a[i])
			{
				max=a[i];
				k=i;
			}
		}
		a[k]=0;
		while(n-f[k]>=0)
		{
			bean+=j[k];
			n-=f[k];
			
			max=0;
			for(i=0;i<m;i++)
			{
				if(max<a[i])
				{
					max=a[i];
					k=i;
				}
			}a[k]=0;
		}
		bean+=j[k]*((double)n/f[k]);
		printf("%.3lf\n",bean);
		memset(a,'\0',m+1);
		memset(f,'\0',m+1);
		memset(j,'\0',m+1);
	}
	return 0;
}


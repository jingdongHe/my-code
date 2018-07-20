#include<stdio.h>
#include<math.h>
int h(int n)
{
	int d;
	d=n*(n-1)/2;
	return (int)pow(2,d);
}
int c(int n,int m)
{
	double ans=1;
	int i;
	for(i=0;i<m;i++)
		ans*=n-i;
	for(i=0;i<m;i++)
		ans/=i+1;
	return (int)ans;
}
int main()
{
	int n,i,j;
	int f[100]={0},g[100]={0};
	g[0]=f[0]=f[1]=g[1]=f[2]=g[2]=1;
	while(scanf("%d",&n))
	{
		for(i=3;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				g[i]+=c(i-1,j-1)*f[j]*h(i-j);
			}
			f[i]=h(i)-g[i];
		}
		for(i=1;i<=n;i++)
			printf("%d.....%d\n",f[i],g[i]);
	}
	
	return 0;
}

#include<stdio.h>
#include<string.h>
int c(int n,int m)
{
	double ans=1,i;
	for(i=0;i<=m;i++)
		ans*=n-i;
	for(i=0;i<m;i++)
		ans/=i+1;
	return (int)(ans+0.5);
}
int main()
{
	int d[33][33],f[33];
	int i,j,p;
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	f[1]=1;
	int n=30;
	for(i=0;i<=n;i++)
		d[i][0]=1;
	for(i=1;i<=n;i++)
	{d[i][1]=1;d[0][i]=0;}
	for(i=1;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			d[i][j]=0;
			for(p=0;p*i<=j;p++)
				d[i][j]+=c(f[i]+p-1,p)*d[i-1][j-p*i];
		}
		f[i+1]=d[i][i+1];
	}
	for(i=0;i<10;i++)
		printf("%d\n",f[i]);
	return 0;
}

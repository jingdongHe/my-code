#include<stdio.h>
int d[300][300]={0};
int cut(int m,int n)//mÐÐnÁÐ
{
	if(d[m][n]!=0)
		return d[m][n];
	if(n==m&&n==1)
		return d[m][n]=0;
	if(m==1)
		return d[m][n]=n-1;
	if(n==1)
		return d[m][n]=m-1;
	if(n&2==0)
		return d[m][n]=cut(n/2,m)*2+1;
	else if(m%2==0)
		return d[m][n]=cut(n,m/2)*2+1;
	else if(n>1)
		return d[m][n]=cut(n-1,m)+cut(1,m)+1;
	else
		return d[m][n]=cut(n,m-1)+cut(n,1)+1;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m))
		printf("%d\n",cut(m,n));
	return 0;
}
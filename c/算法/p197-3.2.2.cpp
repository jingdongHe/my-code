#include<stdio.h>
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
int main()
{
	int a[10]={4,7,3,8,3,7,5,3,1,6};
	int d[20][20];
	int i,j,n=11;
	for(i=0;i<n;i++)
		d[i][0]=a[i];
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=0;i+(1<<j)<n;i++)
			d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
	}
	int l,r;
	scanf("%d%d",&l,&r);
	int k=0;
	while((1<<(k+1))<=r-l+1) 
		k++;
	printf("%d\n",min(d[l][k],d[r-(1<<k)+1][k]));
	return 0;
}
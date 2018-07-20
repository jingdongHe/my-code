#include<stdio.h>
int a[100],c[100]={0},n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int d)
{
	while(x<=n)
	{
		c[x]+=d;
		x+=lowbit(x);
	}
}
int query(int l,int r)
{
	int sum1=0,sum2=0;
	int x=l,y=r;
	while(x>0)
	{
		sum1+=c[x];
		x-=lowbit(x);
	}
	while(y>0)
	{
		sum2+=c[y];
		y-=lowbit(y);
	}
	return sum2-sum1;
}
int main()
{
	int i,j;
	n=16;
	for(i=0;i<n;i++)
		a[i]=i;
	for(i=0;i<n;i++)
	{
		for(j=i-lowbit(i)+1;j<=i;j++)
			c[i]+=a[j];
	}
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\n");
	add(11,2);
	printf("%d\n",query(7,12));
	return 0;
}
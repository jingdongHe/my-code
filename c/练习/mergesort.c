#include<stdio.h>
#define n 10
int a[n]={0,1,2,3,4,5,6,7,8,9};
int c[n];
int paixu(int i,int j,int a[],int c[]);
int mergesort(int i,int j,int a[],int c[]);
int paixu(int i,int j,int a[],int c[])
{
	int m,p,q,r;//p为前数组，q为后数组，m为分割点,r为数组c的下标
	m=(i+j)/2;
	p=i;q=m+1;r=i;
	if(m==0)
	{
		if(a[p]>=a[q])
		{a[r++]=a[p];a[r]=a[q];}
		else
		{a[r++]=a[q];a[r]=a[q];}
	}
	else
	{
	while(p<m&&q<j)
	{
		if(a[p]>=a[q])
		{
			c[r]=a[p];
			p++;
		}
		else
		{
			c[r]=a[q];
			q++;
		}
		r++;
	}
	while(p<m)
	{
		c[r]=a[p];
		r++;p++;
	}
	while(q<j)
	{
		c[r]=a[q];
		r++;q++;
	}
	}
	for(r=i;r<=j;r++)
		a[r]=c[r];
	for(r=i;r<=j;r++)
		printf("%d",c[r]);
	printf("\n");
	return c;
}
int mergesort(int i,int j,int a[],int c[])
{
	int m;
	if(i==j)
		return 0;
	m=(i+j)/2;
	mergesort(i,m,a,c);
	//paixu(i,m,a);
	mergesort(m+1,j,a,c);
	//paixu(m+1,j,a);
	paixu(i,j,a,c);
	return c;
}
int main()
{
	int i=0,j=n-1;
	mergesort(i,j,a,c);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

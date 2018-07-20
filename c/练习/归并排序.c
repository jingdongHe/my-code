#include<stdio.h>
#include<string.h>
void merge(int a[],int i,int mid,int j)
{
	int c[9]={'\0'};
	int p=i,q=mid+1,r=i,s=i;
	while(p<=mid&&q<=j)
	{
		if(a[i]<=a[q])
			c[r++]=a[i++];
		else
			c[r++]=a[q++];
	}
	while(p<=mid)
		c[r++]=a[p++];
	while(q<=j)
		c[r++]=a[q++];
	for(;s<=j;s++)
	{
		//printf("%d ",c[s]);
		a[s]=c[s];
	}
//	printf("\n");
}
void mergesort(int a[],int i,int j)
{
	int mid;
	if(i==j)
		return;
	mid=(i+j)/2;
	mergesort(a,i,mid);
	mergesort(a,mid+1,j);
	merge(a,i,mid,j);
	return;
}
void main()
{
	int a[9]={9,8,7,6,5,4,3,2,1};
	int k=9;
	int i;
	mergesort(a,0,k-1);
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	return;
}
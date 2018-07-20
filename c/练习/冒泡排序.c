#include<stdio.h>
#define n 4
int main()
{
	int a[n]={1,2,3,4};
	int i,j,t;
	
	for(i=n;i>0;i--)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{t=a[j];a[j]=a[j+1];a[j+1]=t;}
		}
	}
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

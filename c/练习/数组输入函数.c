#include<stdio.h>
#define n 9
int *rank(int a[n]);
int *rank(int a[n])
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}}
	}
	return a;
}
		
int main()
{
	int i;
	int a[n]={1,2,3,4,5,6,7,8,9};
	a[n]=rank(a);
	for(i=0;i<9;i++)
		printf("%d    ",a[i]);
	return 0;
}
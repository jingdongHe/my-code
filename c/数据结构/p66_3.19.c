#include<stdio.h>
int a[]={0,1,2,3,4,55,6,7,8,9};
int n=10;
int max(int i)
{
	if(i<n-1)
	{
		if(a[i]>a[i+1])
			a[i+1]=a[i];
		i++;//确保了a[i+1]比前面的都大
		return max(i);
	}
	if(i==n-1)
		return a[i];
	return -1;
}
void main()
{
	printf("%d\n",max(0));
}

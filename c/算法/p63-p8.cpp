#include<stdio.h>
int A[100];
int max(int n)
{
	if(n-1<0)
		return A[n];
	if(max(n-1)>0)
		return max(n-1)+A[n];
	else
		return A[n];
}
int main()
{
	int i,n;
	
	int Max=0,d;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		d=max(i);
		if(d>Max)
			Max=d;
	}
	printf("%d\n",Max);
	return 0;
}
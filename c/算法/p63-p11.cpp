#include<stdio.h>
int A[100],n;
int min(int i,int j,int f)
{
	int k;
	int m=999999,d;
	if(i==j)
		return A[i]*f;
	if(j<i)
		return 0;
	for(k=i;k<=j;k++)
	{
		d=min(i,k-1,f+1)+min(k+1,j,f+1)+A[k]*f;
		if(d<m)
			m=d;
	}
	return m;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("%d\n",min(0,n-1,1));
	return 0;
}

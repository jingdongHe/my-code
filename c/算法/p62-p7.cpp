#include<stdio.h>
int a[100][100];
int A[100],B[100];
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int Max(int i,int j)
{
	if(i<0||j<0)
		return 0;
	if(A[i]==B[j])
		return Max(i-1,j-1)+1;
	else
		return max(Max(i-1,j),Max(i,j-1));
}
int main()
{
	
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(i=0;i<n;i++)
		scanf("%d",&B[i]);
	printf("%d\n",Max(n-1,n-1));
	return 0;
}
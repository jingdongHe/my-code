#include<stdio.h>
int main()
{
	int A[100000+5];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	int maxi=0,max=0;
	for(int i=1;i<n;i++)
	{
		maxi=maxi>A[i-1]?maxi:A[i-1];
		max=max>maxi-A[i]?max:maxi-A[i];
	}
	printf("%d\n",max);
	return 0;
}

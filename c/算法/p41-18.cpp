#include<stdio.h>
int main()
{
	int A[100000];
	int i,n;
	int max,ans;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	ans=A[0]-A[1];
	max=A[0];
	for(i=1;i<n;i++)
	{
		ans=ans<max-A[i]?max-A[i]:ans;
		max=max<A[i]?A[i]:max;
	}
	printf("%d\n",ans);
	return 0;
}

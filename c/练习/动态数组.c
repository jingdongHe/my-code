#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*a,i;
	scanf("%d",&n);
	a=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
		a[i]=i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	free(a);
	return 0;
}

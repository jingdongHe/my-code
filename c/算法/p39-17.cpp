#include<stdio.h>
#include<string.h>
int main()
{
	int a[101],d;
	int n,i,j;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&d);
		a[d]++;
	}
	for(i=1;i<101;i++)
	{
		for(j=0;j<a[i];j++)
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
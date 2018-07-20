#include<stdio.h>
int main()
{
	int n,m=3,i,a,j;
	scanf("%d",&a);
	for(j=0;j<a;j++)
	{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		m=(m-1)*2;
	}
	printf("%d\n",m);
	m=3;
	}
	return 0;
}
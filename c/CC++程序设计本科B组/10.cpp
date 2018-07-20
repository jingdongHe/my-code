#include<stdio.h>
#include<algorithm>
using namespace std;
int check(int b[],int k)
{
	int i;
	sort(b,b+k);
	for(i=0;i<k-1;i++)
	{
		if(b[i+1]-b[i]!=1)
			return 0;
	}
	return 1;
}
void Break(int a[],int n)
{
	int i,j,k,d=0;
	int b[50000];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n-i+1;j++)
		{
			for(k=0;k<i;k++)
			{
				b[k]=a[k+j];
				//printf("%d ",a[k+j]);
			}
			/*for(k=0;k<i;k++)
				printf("%d ",b[k]);
			printf("\n");*/
			if(check(b,i))
				d++;
		}
	}
	printf("%d\n",d);
}
int main()
{
	int a[50000];
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	/*for(i=0;i<n;i++)
		printf("%d ",a[i]);*/
	Break(a,n);
	return 0;
}
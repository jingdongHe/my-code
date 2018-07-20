#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	int b[10];
	for(i=0;i<(1<<n);i++)
	{
		memset(b,0,sizeof(b));
		for(j=0;j<n;j++)
		{
			if(i&(1<<j)) b[j]=1;
		}
		for(j=0;j<n;j++)
			printf("%d ",b[j]);
		printf("\n");
	}
	return 0;
}
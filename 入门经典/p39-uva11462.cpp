#include<stdio.h>
int main()
{
	int age[101]={0};
	int n;
	scanf("%d",&n);
	int d;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d);
		age[d]++;
	}
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<age[i];j++)
		{
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}

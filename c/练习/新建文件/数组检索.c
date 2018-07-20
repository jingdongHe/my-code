#include<stdio.h>
#define row 2
#define list 2
int main()
{
	int a[row][list];
	int i,j;
	for(j=0;j<row;j++)
	{
		for(i=0;i<list;i++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<list;j++)
		{
			printf("%d",a[i][j]);
			if(j!=list-1)
				printf(" ");
			if(j==list-1)
				printf("\n");
		}
	}
	return 0;
}
	
	
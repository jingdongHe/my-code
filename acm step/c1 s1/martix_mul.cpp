#include<stdio.h>
void martix_mul(int a[][4])  
{
	int c[4][4]={0};
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				c[i][j]+=a[i][k]*a[k][j];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			a[i][j]=c[i][j];
	}
}
int main()
{
	int a[4][4]={{1,0,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
	martix_mul(a);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
}

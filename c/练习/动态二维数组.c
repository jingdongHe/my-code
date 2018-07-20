#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,i,j;
	int m,n,d=0;
	scanf("%d%d",&m,&n);//相当于输入数组的横纵
	a=(int **)calloc(m,sizeof(int*));
	for(i=0;i<m;i++)
	{
		a[i]=(int *)calloc(n,sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]=d;
			d++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
	return 0;
}
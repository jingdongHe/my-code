#include<stdio.h>
const int N=15+3;
const int INF=9999;
int Matrix[N][N];
int n;
int bulid(int a[])
{
	/*for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n..............\n");*/
	int matrix[N][N];
	for(int i=0;i<n;i++)
		matrix[0][i]=a[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int k=0;
			if(j>0&&j<n-1) k+=matrix[i-1][j-1]+matrix[i-1][j+1];
			else if(j==0) k+=matrix[i-1][j+1];
			else if(j==n-1) k+=matrix[i-1][j-1];
			if(i>1) k+=matrix[i-2][j];
			matrix[i][j]=k%2;
		}
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
	printf("..................\n");*/
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]!=Matrix[i][j])
			{
				if(Matrix[i][j]==0)
					k++;
				else if(Matrix[i][j]==1){return INF;}//
			}
		}
	}
	//printf("%d---------\n",k);
	return k;
}
int find(int a[],int k)
{
	if(k>=n)
		return bulid(a);
	a[k]=0;
	int f1=find(a,k+1);
	a[k]=1;
	int f2=find(a,k+1);
	if(f1<f2) return f1;
	else
		return f2;
}
int main()
{
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&Matrix[i][j]);
			}
		}
		int a[N];
		int k=find(a,0);
		printf("Case %d: ",t);
		if(k==INF)
			printf("-1\n");
		else 
			printf("%d\n",k);
	}
	return 0;
}

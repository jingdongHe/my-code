#include<stdio.h>
#define N 10
int n,k;
int C[N][N];
int A[N][N];
void find(int i,int B[])
{
	int r,s,j;
	if(i<n)
	{
		for(j=0;j<2;j++)
		{
			B[i]=j;
			find(i+1,B);
		}
	}
	else
	{
		for(j=0;j<n;j++)
			C[0][j]=B[j];
		int sum=0;
		for(r=0;r<n-1;r++)
		{
			for(s=0;s<n;s++)
			{
				if(s>0)sum+=C[r][s-1];
				if(s<n-1)sum+=C[r][s+1];
				if(r>0)sum+=C[r-1][s];
				C[r+1][s]=sum%2;
				sum=0;
			}
		}
		sum=0;
		for(s=0;s<n;s++)
		{
			if(s>0)sum+=C[r][s-1];
			if(s<n-1)sum+=C[r][s+1];
			sum+=C[r-1][s];
			if(sum%2!=0)
				return;
			sum=0;
		}
		sum=0;
		
		for(r=0;r<n;r++)
		{
			for(s=0;s<n;s++)
			{
				if(C[r][s]!=A[r][s])
				{
					if(C[r][s]==1)
						sum++;
					else
						return;
				}
			}
		}
		if(sum<k&&sum!=0)
			k=sum;
	}
}
int main()
{
	int i,j;
	int B[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	k=101;
	find(0,B);
	if(k==101)
		printf("-1\n");
	else
		printf("%d\n",k);
	return 0;
}
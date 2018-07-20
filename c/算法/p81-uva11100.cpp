#include<stdio.h>
int n;
int  find(int A[])
{
	int i,ans=1,max=1;;
	for(i=1;i<n;i++)
	{
		if(A[i]==A[i-1])
			ans++;
		else
			ans=1;
		if(ans>max)
			max=ans;
	}
	printf("%d\n",max);
	return max;
}
bool full(int B[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(B[i]==0)
			return false;
	}
	return true;
}
void order(int A[],int max)
{
	int i;
	int B[10000]={0};
	while(!full(B))
	{
		for(i=0;i<n;i++)
		{
			if(!B[i])
				break;
		}
		while(i<n)
		{
			printf("%d",A[i]);
			B[i]=1;
			i+=max;
		}
		printf("\n");
	}
	return;
}
int main()
{
	int i;int A[10000];
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&A[i]);
		order(A,find(A));
	}
	return 0;
}
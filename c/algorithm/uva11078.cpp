#include<stdio.h>
#include<string.h>
const int maxn=100000+10;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int x[maxn],A[maxn];
	int n,i;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(A,0,sizeof(A));
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		A[0]=0;A[1]=x[0];
		int k=A[1]-x[1];
		for(i=2;i<n;i++)
		{
			A[i]=max(A[i-1],x[i-1]);
			k=max(k,A[i]-x[i]);
		}
		printf("%d\n",k);
	}
	return 0;
}
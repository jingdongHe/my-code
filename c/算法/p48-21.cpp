#include<stdio.h>
#define Maxn 1000000
int main()
{
	int A[Maxn],B[Maxn];
	int s,n,i,j;
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(i>0)
			B[i]=B[i-1]+A[i];
		else
			B[i]=A[i];
	}
	int k,ans;
	for(i=1;i<n;i++)
	{
		//B[j]<=B[i]-s//j+1~i
		k=B[i]-s;
		for(j=0;j<i;j++)
		{
			if(B[j]>k)
			{
				ans=i-j;
				break;
			}
		}
		if(B[j]>k)
			break;
	}
	for(;i<n;i++)
	{
		k=B[i]-s;
		while(B[j]<=k)
			j++;
		j--;
		if(ans>i-j)
			ans=i-j;
	}
	printf("%d\n",ans);
	return 0;
}

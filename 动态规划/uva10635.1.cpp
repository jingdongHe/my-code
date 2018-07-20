#include<stdio.h>
#include<string.h>
const int maxn=250*250+5;
int find(int s[],int length,int k)
{
	if(length==0)
		return 0;
	int l=0,r=length;
	int mid=(l+r)/2;
	while(l!=r)
	{
		
	}
}
int main()
{
	int T;
	int n,p,q,s;
	int A[maxn],B[maxn],num[maxn];
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		memset(num,0,sizeof(num));
		scanf("%d%d%d",&n,&p,&q);
		int temp;
		for(int i=0;i<p+1;i++)
		{
			scanf("%d",&temp);
			num[temp]=i+1;
		}
		s=0;
		for(int i=0;i<q+1;i++)
		{
			scanf("%d",&temp);
			if(num[temp])
				B[s++]=num[temp];
		}
		
		for(int i=0;i<s;i++)
		{
			f
		}
	}
}

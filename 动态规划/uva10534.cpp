#include<stdio.h>
#include<string.h>
#define maxn 10000+5
int s;
int find(int a[],int n,int x)
{
	if(x>a[n-1])
	{s=1;return n;}
	if(n==0)
	{s=1;return 0;}
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<x)
			l=mid+1;
		else if (a[mid]>x)
			r=mid;
		else
			return mid;
	}
	if(a[l]<x)
	{s=1;return l+1;}
	else
		return l;
}
int main()
{
	int seq[maxn];
	int left[maxn],right[maxn],a[maxn],b[maxn];
	int k=0,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&seq[i]);
	for(int i=0;i<n;i++)
	{
		s=0;
		int f=find(a,k,seq[i]);
		a[f]=seq[i];
		if(s==1)
			k++;
		left[i]=f;
	}
	k=0;
	for(int i=n-1;i>=0;i--)
	{
		s=0;
		int f=find(b,k,seq[i]);
		b[f]=seq[i];
		if(s==1)
			k++;
		right[i]=f;
	}
	int max=0,res;
	for(int i=0;i<n;i++)
	{
		int m=left[i]>right[i]?right[i]:left[i];
		if(m>max)
			max=m;
	}
	/*for(int i=0;i<n;i++)
		printf("%d ",left[i]);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",right[i]);*/
	printf("%d\n",max);
	return 0;
}


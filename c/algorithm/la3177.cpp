#include<stdio.h>
const int maxn=100000+10;int n;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}
bool ok(int m,int r[])
{
	int x=r[0],y=m-r[0];
	int left[maxn],right[maxn];
	left[0]=x;right[0]=0;
	int i;
	for(i=1;i<n;i++)
	{
		if(i%2==0)
		{
			right[i]=min(y-right[i-1],r[i]);
			left[i]=r[i]-right[i];
		}
		else
		{
			left[i]=min(x-left[i-1],r[i]);
			right[i]=r[i]-left[i];
		}
		if(left[i]+left[i-1]>x||right[i]+right[i-1]>y)
			return false;
	}
	if(left[n-1]+left[0]>x||right[n-1]+right[0]>y)
		return false;
	return true;
	/*if(left[n-1]==0)
		return true;
	return false;*/
}
int main()
{
	int r[maxn];
	int i;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&r[i]);
		r[n]=r[0];
		if(n%2==0)
		{
			int max_r=0,k=0;
			for(i=0;i<=n;i++)
			{
				k=r[i]+r[(i+1)];
				max_r=max(max_r,k);
			}
			printf("%d\n",max_r);
		}
		else
		{
			int L=0,R=0;
			for(i=0;i<n;i++)
				R=max(R,r[i]*3);
			while(L<R)
			{
				int M=L+(R-L)/2;
				if(ok(M,r)) R=M;
				else L=M+1;
			}
			printf("%d\n",L);
		}
	}
	return 0;
}
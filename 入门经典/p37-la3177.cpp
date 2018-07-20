#include<stdio.h>
const int maxn=100000+5;
int n;
bool ok(int r[],int k)
{
	int left[maxn],right[maxn];
	int x=r[0],y=k-r[0];
	left[0]=x;right[0]=0;
	for(int i=1;i<n;i++)
	{
		if(i%2==0)
		{
			right[i]=y-right[i-1]<r[i]?y-right[i-1]:r[i];
			left[i]=r[i]-right[i];
		}
		else
		{
			left[i]=x-left[i-1]<r[i]?x-left[i-1]:r[i];
			right[i]=r[i]-left[i];
		}
	}
	if(left[n-1]==0)
		return true;
	else
		return false;
}
int main()
{
	int result=0;
	int r[maxn];
	scanf("%d",&n);
	if(n%2==0)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
			if(i>0)
				result=result>r[i]+r[i-1]?result:r[i]+r[i-1];
		}
		result=result>r[n-1]+r[0]?result:r[n-1]+r[0];
	}
	else 
	{
		int min=0,max=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
			max+=r[i];
		}
		while(max>min)
		{
			int mid=(min+max)/2;
			//printf("%d    %d    %d\n",min,max,mid);
			//getchar();
			if(ok(r,mid))
			{ 
				max=mid;
				//printf("OK........%d\n",mid);
			}
			else
			{
				min=mid+1;
				//printf("false.....%d\n",mid);
			}
		}
		result=max;
	}
	printf("%d\n",result);
	return 0;
}

#include<stdio.h>
int res[15];
bool is_ok(int k,int m)
{
	int sum=2*k;
	int index=m%sum;
	if(index==0) index=sum;
	if(index<=k) return false;
	for(int i=0;i<k-1;i++)
	{
		sum--;
		index=(index+m-1)%sum;
		if(index==0) index=sum;
		
		if(index<=k) return false;
	}
	return true;
}

int main()
{
	res[1]=2;
	for(int i=2;i<=14;i++)
	{
		for(int j=i+1;;j++)
		{
			if(is_ok(i,j))
			{
				res[i]=j;
				break;
			}
		}
	}
	/*for(int i=1;i<14;i++)
		printf("%d  %d\n",i,res[i]);*/
	int k;
	while(scanf("%d",&k)!=EOF&&k!=0)
	{
		printf("%d\n",res[k]);
	}
	return 0;
}

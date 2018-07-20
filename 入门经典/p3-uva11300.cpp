#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int *array;
	int *temp;
	while(scanf("%d",&n)!=EOF)
	{
		array=(int *)malloc(sizeof(int)*n);
		temp=(int *)malloc(sizeof(int)*n);//创建temp数组用于存储a1-M之类的数 
		
		for(int i=0;i<n;i++)
			temp[i]=0;
		
		int sum=0,average;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			sum+=array[i];
		}
		average=sum/n;
		
		
		temp[0]=array[0]-average;
		for(int i=1;i<n-1;i++)
		{
			temp[i]+=temp[i-1]+array[i]-average;
		}
		
		sort(temp,temp+n);
		int x=(n-1)/2;
		
		long long k=0;
		for(int i=0;i<n-1;i++)
		{
			k+=abs(temp[x]-temp[i]);
		}
		k+=abs(temp[x]);
		printf("%lld\n",k);
	}
	return 0;
}

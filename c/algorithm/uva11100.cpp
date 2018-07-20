#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int main()
{
	int n,i;
	int seq[maxn];
	while(scanf("%d",&n)&&n)
	{
		int sum=1,max=0;
		for(i=0;i<n;i++)
			scanf("%d",&seq[i]);
		sort(seq,seq+n);
		for(i=0;i<n;i++)
		{
			if(i>0&&seq[i-1]==seq[i])
				sum++;
			else
				sum=1;
			if(sum>max)
				max=sum;
		}
		printf("%d\n",max);
		for(i=0;i<max;i++)
		{
			int j;
			for(j=i;j<n;j+=max)
				printf("%d ",seq[j]);
			printf("\n");
		}
	}
	return 0;
}
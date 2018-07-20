#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[100000];//由于整数小于等于10w，此处用int类型
	int n,i,d,k=0;
	int M,N;
	char c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		while(1)
		{
			scanf("%d",&d);a[k++]=d;
			c=getchar();
			if(c=='\n')
				break;
			
		}
	}
	sort(a,a+k);
	for(i=0;i<k-1;i++)
	{
		if(a[i]==a[i+1])
			N=a[i];
		if((a[i+1]-a[i])!=1&&(a[i+1]-a[i])!=0)
		{
			M=(a[i+1]+a[i])/2;
		}
	}
		printf("%d........%d\n",M,N);
	return 0;
}
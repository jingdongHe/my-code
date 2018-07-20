#include<stdio.h>
const int maxn=100+5;
int main()
{
	int a[maxn],b[maxn];
	int d,count=0;char c;
	while(1)
	{
		scanf("%d%c",&d,&c);
		a[count++]=d;
		if(c=='\n')
			break;
	}
	for(int i=1;i<count;i++)
		b[i-1]=a[i]-a[i-1]-1;
	b[count-1]=0;
		for(int i=0;i<count;i++)
			printf("%d ",b[i]);
		printf("\n");
	int sum=0;
	for(int i=0;i<count;i++)
		sum^=b[i];
	if(sum==0)
	{
		printf("-1");
		return 0;
	}
	else
	{
		for(int i=0;i<count;i++)
		{
			for(int j=1;j<=b[i];j++)
			{
				sum=0;
				b[i]+=j;
				for(int k=0;k<count;k++)
					sum^=b[k];
				b[i]-=j;
				if(sum==0)
				{
					printf("%d  %d\n",b[i],b[i]+j);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}

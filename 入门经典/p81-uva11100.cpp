#include<stdio.h>
const int maxn=10000+5;
int main()
{
	int n;
	int seq[maxn];
	scanf("%d",&n);
	int cnt=0,k=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&seq[i]);
		if(i!=0&&seq[i]!=seq[i-1])
			k=1;
		else k++;
		cnt=cnt>k?cnt:k;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
	{
		for(int j=i;j<n;j+=cnt)
		{
			printf("%d ",seq[j]);
		}
		printf("\n");
	}
	return 0;
}

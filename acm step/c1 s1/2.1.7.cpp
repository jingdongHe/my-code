#include<stdio.h>
const int maxn=32768+2;
int table[maxn]={0};
int main()
{
	for(int i=2;i<maxn;i++)
		table[i]=i-1;
	for(int i=2;i<maxn/2;i++)
	{
		for(int j=i+i;j<maxn;j+=i)
			table[j]--;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",table[n]);
	}
	return 0;
}

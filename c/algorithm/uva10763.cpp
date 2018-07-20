#include<stdio.h>
const int maxn=500000+10;
int main()
{
	int n,i;
	int school[maxn];
	scanf("%d",&n);
	for(i=0;i<maxn;i++)
		school[i]=i;
	for(i=0;i<n;i++)
	{
		int a,b,temp;
		scanf("%d%d",&a,&b);
		temp=school[a];school[a]=school[b];school[b]=temp;
	}	
	int k=1;
	for(i=0;i<maxn;i++)
	{
		if(school[i]!=i)
		{
			k=0;
			printf("NO\n");
			break;
		}
	}
	if(k)
		printf("YES\n");
	return 0;
}

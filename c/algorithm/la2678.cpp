#include<stdio.h>
const int maxn=100000+10;
int main()
{
	int n,s;
	int seq[maxn];
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		int i,j,k=9999,Min=9999;
		for(i=0;i<n;i++)
			scanf("%d",&seq[i]);
		int F=0;
		i=0;j=0;
		while(j<n&&F<s)
			F+=seq[j++];
		if(j==n)
		{printf("0\n");continue;}
		j--;
		k=j-i+1;
		Min=Min<k?Min:k;
		while(j<n)
		{
			while(i<=j&&F>=s)
				F-=seq[i++];
			i--;
			if(F+seq[i]>=s)
			{
			k=j-i+1;
			Min=Min<k?Min:k;
			}
			if(j>=n-1)
				break;
			i++;
			while(j<n-1&&F<s)
				F+=seq[++j];
			if(F>s)
			{
			k=j-i+1;
			Min=Min<k?Min:k;
			}
		}
		if(i>j||k==9999)
			printf("0\n");
		else
			printf("%d\n",Min);
	}
	return 0;
}
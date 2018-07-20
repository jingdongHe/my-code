#include<stdio.h>
int main()
{
	int i,j,n;
	int l[100],d[100],g[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
		g[i]=999;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(g[j]>l[i])
				break;
		}
		d[i]=j+1;
		g[j]=l[i];
	}
	printf("%d\n",d[i-1]);
	return 0;
}

#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	int i,j,n,f[100];
	int v,w;
	int c;
	memset(f,0,sizeof(f));
	scanf("%d%d",&n,&c);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&v,&w);
		for(j=c;j>=0;j--)
		{
			if(j>=v)
				f[j]=max(f[j],f[j-v]+w);
		}
	}
	for(i=0;i<=c;i++)
		printf("%d:%d\n",i,f[i]);
	return 0;
}
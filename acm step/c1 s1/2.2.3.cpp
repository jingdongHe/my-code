#include<stdio.h>
bool hanio(int n,int a[],int b[],int c[],int m,int p,int q)
{
	if(n<=0) return true;
	for(int i=0;i<p;i++)
	{
		if(b[i]==n) return false;
	}
	for(int i=0;i<m;i++)
	{
		if(a[i]==n) return hanio(n-1,a,c,b,m,q,p);
	}
	for(int i=0;i<p;i++)
	{
		if(c[i]==n) return hanio(n-1,b,a,c,p,m,q);
	}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int a[70],b[70],c[70];
		int m,p,q;
		scanf("%d",&n);
		scanf("%d",&m);
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		scanf("%d",&p);
		for(int i=0;i<p;i++)
			scanf("%d",&b[i]);
		scanf("%d",&q);
		for(int i=0;i<q;i++)
			scanf("%d",&c[i]);
		if(hanio(n,a,b,c,m,p,q)) printf("true\n");
		else printf("false\n");
	}
}

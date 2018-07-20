#include<stdio.h>
#include<string.h>
#include<math.h>
int p[10000]={0},s[100000]={0};
double f[10000];
void gen(int n)
{
	int vis[100000];
	int m=(int)sqrt(n+0.5),i,j;
	memset(vis,0,sizeof(vis));
	for(i=2;i<=m;i++)
	{
		if(!vis[i])
		{
			for(j=i*i;j<n;j+=i)
				vis[j]=1;
		}
	}
	int c=1;
	p[0]=1;p[1]=2;
	for(i=2;i<n;i++)
		if(vis[i]==0)
			p[c++]=i;
	return;
}
double dp(int i)
{
	int k;
	double ans=0;
	if(i==1)
		return 1;
	if(f[i]!=-1)
		return f[i];
	for(k=0;p[k]<=i;k++)
	{
		if(i%p[k]==0)
			ans+=dp(i/p[k])/s[i];
	}
	printf("%d........%lf......%d\n",i,ans,s[i]);
	return f[i]=ans;
}
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	gen(100000);
	int k=0;
	i=0;
	while(p[i++]!=0)
	{
		k++;
		if(p[i+1]==0)
		{s[p[i]]=k;i++;break;}
		for(j=p[i];j<p[i+1];j++)
			s[j]=k;
	}
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<10000;i++)
			f[i]=-1;
		dp(n);
		printf("%lf\n",f[n]);
	}
	return 0;
}
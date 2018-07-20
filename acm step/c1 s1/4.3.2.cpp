#include<stdio.h>
#include<string.h>
int arr[25];
bool prime[50];
bool use[25];
int n;
void dfs(int s)
{
	if(s==n&&prime[arr[s-1]+arr[0]])
	{
		for(int i=0;i<n-1;i++)
			printf("%d ",arr[i]);
		printf("%d\n",arr[n-1]);
		return;
	}
	if(s>=n) return;
	for(int i=2;i<=n;i++)
	{
		if(use[i]==false&&prime[arr[s-1]+i])
		{
			use[i]=true;
			arr[s]=i;
			dfs(s+1);
			use[i]=false;
		}
	}
	return;
}
void init()
{
	memset(prime,false,sizeof(prime));
	memset(use,false,sizeof(use));
	prime[2]=true;prime[3]=true;
	prime[5]=true;prime[7]=true;
	prime[11]=true;prime[13]=true;
	prime[17]=true;prime[19]=true;
	prime[23]=true;prime[29]=true;
	prime[31]=true;prime[37]=true;
	prime[41]=true;
}
int main()
{
	init();int t=1;
	while(scanf("%d",&n)!=EOF)
	{
		arr[0]=1;
		printf("Case %d:\n",t++);
		dfs(1);
		printf("\n");
	}
	return 0;
}

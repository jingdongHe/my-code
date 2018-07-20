#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n;
int a[15];
int res[15];
bool use[15],flag;
bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int deep,int sum,int s)
{
	if(sum==t)
	{
		flag=true;
		printf("%d",res[0]);
		for(int j=1;j<deep;j++)
			printf("+%d",res[j]);
		printf("\n");
		return;
	}
	if(sum>t) return;
	int last=-1;
	for(int i=s;i<n;i++)
	{
		while(last==a[i]&&i<n) i++;
		if(i==n) break;
		if(use[i]==false)
		{
			use[i]=true;
			res[deep]=a[i];
			last=a[i];
			dfs(deep+1,sum+a[i],i+1);
			use[i]=false;
		}
	}
	return;
}
int main()
{
	while(scanf("%d%d",&t,&n)!=EOF&&t!=0&&n!=0)
	{
		memset(use,false,sizeof(use));
		flag=false;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n,cmp);
		printf("Sums of %d:\n",t);
		dfs(0,0,0);
		if(flag==false)
			printf("NONE\n");
	}
	return 0;
}

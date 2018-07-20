#include<stdio.h>
#include<string.h>
const int maxn=15;
int n,k;
bool ver[maxn];
bool a[2*maxn],b[2*maxn];//ÕýÐ±£¬·´Ð± 
bool is_ok(int x,int y)
{
	if(a[x+y]==true||b[y-x+n-1]==true||ver[y]==true)
		return false;
	return true;
} 
void dfs(int deep)
{
	if(deep==n)
	{
		k++;return;
	}
	for(int i=0;i<n;i++)
	{
		if(is_ok(deep,i))
		{
			ver[i]=true;
			a[deep+i]=true;b[i-deep+n-1]=true;
			dfs(deep+1);
			ver[i]=false;
			a[deep+i]=false;b[i-deep+n-1]=false;
		}
	}
	return ;
}
int main()
{
	int arr[maxn];
	for(int i=1;i<=13;i++)
	{
		k=0;n=i;
		memset(ver,false,sizeof(ver));
		memset(a,false,sizeof(a));
		memset(b,false,sizeof(b));
		dfs(0);
		arr[i]=k;
		//printf("%d......\n",k);
	}
	int m;
	while(scanf("%d",&m)!=EOF&&m!=0)
	{
		printf("%d\n",arr[m]);
	}
	return 0;
}

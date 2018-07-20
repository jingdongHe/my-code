#include<stdio.h>
#include<string.h>
const int maxn=500510;
int a[1000+5];
int n,head[maxn],next[maxn];
struct Sum{
	int sum;
	int x,y;
}b[maxn];
int Hash(int s)
{
	int seed=(s>>1)+(s<<1);
	return (seed&0x7FFFFFFF)%500503;
}
bool insert(int s)
{
	int h=Hash(b[s].sum);
	int u=head[h];
	while(u)
	{
		if(b[u].sum==b[s].sum)
			return false;
		u=next[u];
	}
	next[s]=head[h];
	head[h]=s;
	return true;
}
bool search(int x,int y)
{
	int h=Hash(a[x]-a[y]);
	int u=head[h];
	while(u)
	{
		if(a[x]-a[y]==b[u].sum&&x!=b[u].x&&x!=b[u].y&&y!=b[u].y&&y!=b[u].x)
			return true;
		u=next[u];
	}
	return false;
}
int main()
{
	int num,max;
	num=1;max=-0x7FFFFFFF;
	memset(head,0,sizeof(head));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			b[num].sum=a[i]+a[j];
			if(insert(num))
			{
				b[num].x=i;
				b[num++].y=j;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(search(i,j)&&max<a[i])
					max=a[i];
			}
		}
	}
	printf("%d\n",max);
	return 0;
}

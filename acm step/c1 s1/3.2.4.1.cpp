#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000+5;
typedef struct node {
	int w,s;
	int k;
}mouse;
bool cmp(mouse a,mouse b)
{
	if(a.w==b.w)
		return a.s<b.s;
	return a.w>b.w;
}
int find(mouse a[],int k,int min,int max)
{
	int mid=(min+max)/2;
	while(min<max)
	{
		if(a[mid].s>k)
			max=mid-1;
		else 
			min=mid+1;
		mid=(min+max)/2;
	//	printf("%d....%d....%d....%d\n",k,a[mid].s,min,max);
	}
	return mid;
}
void solve(mouse a[],int n)
{
	int length[maxn],locat[maxn];
	for(int i=0;i<n;i++)
	{length[i]=1;locat[i]=-1;}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i].s>a[j].s&&length[i]<=length[j]+1)
			{
				length[i]=length[j]+1;
				locat[i]=j;
			}
		}
	}
	int max=0,locat_max;
	for(int i=0;i<n;i++)
	{
		//printf("%d...%d..%d\n",a[i].s,length[i],locat[i]);
		if(length[i]>max)
		{
			max=length[i];
			locat_max=i;
		}
	}
	printf("%d\n",max);
	int arr[maxn],k=0;
	while(locat[locat_max]!=-1)
	{
		arr[k++]=locat_max;
		locat_max=locat[locat_max];
	}
	arr[k]=locat_max;
	for(int i=k;i>=0;i--)
		printf("%d\n",a[arr[i]].k);
	return ;
}

int main()
{
	mouse a[maxn];
	int n=0;
	while(scanf("%d %d",&a[n].s,&a[n].w)!=EOF)
	{a[n].k=n+1;n++;}
	sort(a,a+n,cmp);
	
	solve(a,n);
	return 0;
}

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
	mouse temp[maxn];
	int index_max[maxn];
	/*for(int i=0;i<n;i++)
		printf("%d:%d  %d\n",a[i].k,a[i].s,a[i].w);*/
	int i=0,j=-1;
	for(int k=0;k<n;k++)
	{
		//printf("%d:%d  %d......\n",a[k].k,a[k].s,a[k].w);
		/*printf("\n--------------\n");
		for(int f=i;f<=j;f++)
			printf("%d..%d\n",temp[f].k,temp[f].s);
		printf("\n");
		for(int f=i;f<=j;f++)
			printf("%d\n",index_max[f]);
		printf("\n--------------\n");getchar();*/
		if(j==-1)//empty
		{
			temp[++j]=a[k];
			index_max[j]=a[k].k;
			continue;
		}
		if(temp[j].s<a[k].s&&temp[j].w!=a[k].w)
		{
			temp[++j]=a[k];
			index_max[j]=a[k].k;
			continue;
		}
		
		/*printf("%d  %d  %d\n",a[k].s,i,j);*/
		int s=find(temp,a[k].s,i,j);
		//printf("%d.....\n",s);
		if(s==j)
		{
			temp[j]=a[k];
			if(index_max[j]<a[k].k)
				index_max[j]=a[k].k;
			continue;
		}
		else 
		{
			temp[s]=a[k];
			continue;
		}
	}
	printf("%d\n",j+1);
	for(i=0;i<=j;i++)
		printf("%d\n",index_max[i]);
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

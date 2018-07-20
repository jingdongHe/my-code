#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
using namespace std;
const int maxn=1000+5;
typedef struct node {
	int p;
	struct node *next;
}node;
int a[maxn],cn=0;
void mix(int b[],int d)
{
	
	if(cn==0)
	{
		for(int i=0;i<d;i++)
			a[i]=b[i];
		cn=d;
		return;
	}
	int B[maxn];
	for(int i=0;i<d;i++)
		B[i]=b[i];
	sort(a,a+cn);
	sort(B,B+d);
	int i=0,j=0;
	int k[maxn],f=0;
	while(i<cn&&j<d)
	{
		if(a[i]==B[j])
		{
			k[f++]=a[i];
			i++;j++;
		}
		else if(a[i]>B[j])
			j++;
		else if(a[i]<B[j])
			i++;
	}
	for(i=0;i<f;i++)
		a[i]=k[i];
	cn=f;
	return;
}
bool vis[maxn];
void dfs(node a[],int start,int end,int s[],int d)
{
	node *p=a[start].next;
	if(start==end)
	{
		mix(s,d);
		
		return ;
	}
	while(p!=NULL)
	{
		if(vis[p->p]==false)
		{
		
		s[d++]=p->p;vis[p->p]=true;
		dfs(a,p->p,end,s,d);
		d--;vis[p->p]=false;
		}
		p=p->next;
	}
	return ;
}
int main()
{
	int n,m;
	int x,y;
	node point[maxn];
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		node *p,*p1;
		p=(node *)malloc(sizeof(node));
		p1=(node *)malloc(sizeof(node));
		p->p=x;p->next=point[y].next;point[y].next=p;
		p1->p=y;p1->next=point[x].next;point[x].next=p1;
	}
	for(int i=0;i<=n;i++)
		vis[i]=false;
	int s[maxn];
	int s1,s2;
	scanf("%d%d",&s1,&s2);
	dfs(point,s1,s2,s,0);
	printf("%d\n",cn-1);
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 10
typedef struct {
	int a[maxnum][maxnum];
	int num,edge;
	char k[maxnum];
}graph;
int q=0,k;
int locat(graph *g,char x)
{
	int i,j=-1;
	for(i=0;i<g->num;i++)
	{
		if(g->k[i]==x)
		{j=i;return j;}
	}
	return j;
}
void b_link(graph *g)
{
	int i;
	int x,y;
	memset(g->a,0,sizeof(g->a));
	memset(g->k,0,sizeof(g->k));
	for(i=0;i<g->num;i++)
	{
		printf("please entry the title\n");
		scanf("%c",&g->k[i]);getchar();
	}
	for(i=0;i<g->edge;i++)
	{
		printf("please entry the information about side\n");
		scanf("%c%c",&x,&y);getchar();
		g->a[locat(g,x)][locat(g,y)]=1;
	}
	return ;
}
void output(graph *g)
{
	int i,j;
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			printf("%-3d",g->a[i][j]);
		}
		printf("\n");
	}
}
void find(graph *g,char x,char y,int p[],int d)
{
	int i,j;
	p[locat(g,x)]=1;
	if(x==y&&k==d)
	{q++;p[locat(g,x)]=0;return;}
	for(i=0;i<g->num;i++)
	{
		if(g->a[locat(g,x)][i]!=0&&p[i]==0)
			find(g,g->k[i],y,p,d+1);
	}
	p[locat(g,x)]=0;
}
void main()
{
	int n,e;
	graph *g;
	char x,y;
	int p[maxnum]={0};
	g=(graph *)malloc(sizeof(graph));
	printf("please entry the quantity of the peak and side\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;g->edge=e;
	b_link(g);
	output(g);
	printf("please entry the pead of the way what you checking\n");
	scanf("%c%c",&x,&y);getchar();
	printf("please entry the dream of the length\n");
	scanf("%d",&k);getchar();
	find(g,x,y,p,0);
	printf("%d............\n",q);
	return;
}
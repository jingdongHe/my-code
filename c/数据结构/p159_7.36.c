#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 11
typedef struct node {
	char data;
	struct node *next;
}node;
typedef struct {
	node *a[maxnum];
	int num,edge;
}graph;
int q=0,a[maxnum]={0};
int locat(graph *g,char x)
{
	int i,j=-1;
	for(i=0;i<g->num;i++)
	{
		if(g->a[i]->data==x)
		{j=i;return j;}
	}
	return j;
}
void b_link(graph *g)
{	
	int i;
	node *p,*px;
	char x,y;
	for(i=0;i<g->num;i++)
	{
		printf("plesae entry the title of the graph\n");
		px=(node *)malloc(sizeof(node));
		px->data=getchar();getchar();
		px->next=NULL;
		g->a[i]=px;
	}
	for(i=0;i<g->edge;i++)
	{
		printf("please entry the informations about the edge\n");
		scanf("%c%c",&x,&y);getchar();
		p=g->a[locat(g,x)];
		while(p->next!=NULL)
			p=p->next;
		px=(node *)malloc(sizeof(node));
		px->data=y;
		px->next=NULL;
		p->next=px;
	}
}
void output(graph *g)
{
	int i;
	node *p;
	for(i=0;i<g->num;i++)
	{
		p=g->a[i]->next;
		printf("%c",g->a[i]->data);
		while(p!=NULL)
		{
			printf("->%c",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
void dfs(graph *g,char x,char y)
{
	node *p;
	a[locat(g,x)]=1;
	if(x==y)
	{
		q=1;
		return;
	}
	p=g->a[locat(g,x)]->next;
	while(p!=NULL)
	{
		if(a[locat(g,p->data)]==0)
			dfs(g,p->data,y);
		p=p->next;
	}
	a[locat(g,x)]=0;
	return;
}
void main()
{
	int n,e;
	graph *g;
	char x,y;
	g=(graph *)malloc(sizeof(graph));
	printf("please entry the informations of the graph\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;g->edge=e;
	b_link(g);
	output(g);
	printf("please entry the way what you want to find\n");
	scanf("%c%c",&x,&y);getchar();
	dfs(g,x,y);
	if(q==1)
		printf("YES\n");
	else
		printf("NO\n");
}
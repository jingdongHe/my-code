#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
int visit[maxnum]={0};
int d=0;
typedef struct node {
	char data;
	struct node *next;
}node;
typedef struct {
	node *a[maxnum];
	int num;
}graph;
void b_link(graph *g)
{
	int i;
	node *px;
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点信息\n");
		px=(node *)malloc(sizeof(node));
		scanf("%c",&px->data);getchar();
		px->next=NULL;
		g->a[i]=px;
	}
}
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
void push(graph *g,char x,char y)
{
	int i;
	node *p,*px;
	i=locat(g,x);
	p=g->a[i];
	while(p->next!=NULL)
		p=p->next;
	px=(node *)malloc(sizeof(node));
	px->data=y;
	px->next=NULL;
	p->next=px;
	i=locat(g,y);
	p=g->a[i];
	while(p->next!=NULL)
		p=p->next;
	px=(node *)malloc(sizeof(node));
	px->data=x;
	px->next=NULL;
	p->next=px;
}
void output(graph *g)
{
	int i;
	node *p;
	for(i=0;i<g->num;i++)
	{
		printf("%c",g->a[i]->data);
		p=g->a[i]->next;
		while(p!=NULL)
		{
			printf("->%c",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
void DFS(graph *g,char a)
{
	int k;
	node *p;
	k=locat(g,a);
	if(visit[k]!=1)
	{
		visit[k]=1;
		printf("%-2c",g->a[k]->data);d++;
		if(d==g->num)
			return;
		p=g->a[k]->next;
		while(p!=NULL)
		{
			DFS(g,p->data);
			p=p->next;
		}
	}
	else
		return;
	return;
}
void main()
{
	int k,n,e,h=0;
	char i,j;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("请输入顶点及弧的数目\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;
	b_link(g);
	for(k=0;k<e;k++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&i,&j);getchar();
		push(g,i,j);
	}
	for(k=0;k<g->num;k++)
	{
		n=locat(g,g->a[k]->data);
		if(visit[n]==0)
		{
			DFS(g,g->a[k]->data);
			printf("\n***************\n");
			h++;
		}
	}
	printf("有%d个连通分量\n",h);
	output(g);
	return;
}
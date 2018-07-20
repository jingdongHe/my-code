#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
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
	node *p;
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点信息\n");
		p=(node *)malloc(sizeof(node));
		scanf("%c",&p->data);getchar();
		p->next=NULL;
		g->a[i]=p;
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
	node *px,*p;
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
void del(graph *g,char x,char y)
{
	int i;
	node *p,*pp;
	i=locat(g,x);
	pp=g->a[i];
	p=g->a[i]->next;
	while(p!=NULL)
	{
		if(p->data==y)
		{pp->next=p->next;free(p);break;}
		pp=pp->next;
		p=p->next;
	}
	i=locat(g,y);
	pp=g->a[i];
	p=g->a[i]->next;
	while(p!=NULL)
	{
		if(p->data==x)
		{pp->next=p->next;free(p);break;}
		pp=pp->next;
		p=p->next;
	}
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
void main()
{
	int i,n,e;
	graph *g;
	char x,y;
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点数及弧数\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;
	b_link(g);
	for(i=0;i<e;i++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&x,&y);getchar();
		push(g,x,y);
	}
	output(g);
	printf("请输入要删除的弧\n");
	scanf("%c%c",&x,&y);getchar();
	del(g,x,y);
	output(g);
	return;
}


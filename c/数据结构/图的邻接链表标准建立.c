#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
typedef struct node {
	char data;
	struct node *next;
}node;
typedef struct {
	node *a[maxnum];
	int num,edge;
}graph;
typedef struct {
	char a[maxnum];
	int d;
}stack;
int f[maxnum]={0};
stack *b_stack()
{
	stack *q;
	q=(stack *)malloc(sizeof(stack));
	q->d=0;//i随增加移动，j随减少移动
	return q;
}
void push(stack *q,char x)
{
	if(q->d>=maxnum)
	{
		printf("full\n");
		return;
	}
	q->a[q->d++]=x;
	return;
}
void pop(stack *q)
{
	if(q->d<=0)
	{
		printf("empty\n");
		return ;
	}
	q->a[q->d]='\0';
	q->d--;
}
void output_stack(stack *q)
{
	int i;
	for(i=0;i<q->d;i++)
		printf("%c ",q->a[i]);
	printf("\n");
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
void b_link(graph *g)
{
	int i;
	char x,y;
	node *p,*px;
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点信息\n");
		px=(node *)malloc(sizeof(node));
		scanf("%c",&px->data);getchar();
		px->next=NULL;
		g->a[i]=px;
	}
	for(i=0;i<g->edge;i++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&x,&y);getchar();
		p=g->a[locat(g,x)];
		while(p->next!=NULL)
			p=p->next;
		px=(node *)malloc(sizeof(node));
		px->data=y;
		px->next=NULL;
		p->next=px;
	}
	return;
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
	return;
}
void dfs(graph *g,char x,char y,stack *q)
{
	node *p;
	f[locat(g,x)]=1;
	push(q,x);
	if(x==y)
	{
		output_stack(q);
		f[locat(g,x)]=0;
		pop(q);
		return ;
	}
	p=g->a[locat(g,x)]->next;
	while(p!=NULL)
	{
		if(f[locat(g,p->data)]==0)
			dfs(g,p->data,y,q);
		p=p->next;
	}
	f[locat(g,x)]=0;
	pop(q);
	return;
}
void main()
{
	int n,e;
	graph *g;
	stack *q;
	q=b_stack();
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点数及弧数\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;g->edge=e;
	b_link(g);
	output(g);
	dfs(g,'a','d',q);
	return;
}
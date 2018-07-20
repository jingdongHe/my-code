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
typedef struct {
	char a[maxnum];
	int d;
}stack;
void b_stack(stack *q)
{
	q->d=0;
	memset(q->a,'\0',sizeof(q->a));
}
void push(stack *q,char d)
{
	q->a[q->d++]=d;
}
char pop(stack *q)
{
	char d;
	q->d--;
	d=q->a[q->d];
	q->a[q->d]='\0';
	return d;
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
void top(graph *g)
{
	int a[maxnum];
	int i;
	node *p;
	char d;
	stack *q;
	memset(a,0,sizeof(a));
	q=(stack *)malloc(sizeof(stack));
	b_stack(q);
	//printf("111111111111\n");
	for(i=0;i<g->num;i++)
	{
		p=g->a[i]->next;
		while(p!=NULL)
		{
			a[locat(g,p->data)]++;
			p=p->next;
		}
	}//此处结束后可知各定点的入度
	//printf("2222222222222222\n");
	for(i=0;i<g->num;i++)
	{
		if(a[i]==0)
			push(q,g->a[i]->data);
	}
	//printf("33333333333333\n");
	while(q->d!=0)
	{
		d=pop(q);
		printf("%c ",d);
		p=g->a[locat(g,d)]->next;
		while(p!=NULL)
		{
			a[locat(g,p->data)]--;
			if(a[locat(g,p->data)]==0)
				push(q,p->data);
			p=p->next;
		}
	}
	//printf("44444444444444\n");
}
void main()
{
	int n,e;
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("please entry the informations of the graph\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;g->edge=e;
	b_link(g);
	output(g);
	top(g);
}

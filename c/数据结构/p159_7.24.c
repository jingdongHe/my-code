#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
typedef struct node{
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
	char d;
	node *p;
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点信息\n");
		d=getchar();getchar();
		p=(node *)malloc(sizeof(node));
		p->data=d;
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
		{j=i;break;}
	}
	return j;
}
void push(graph *g,char x,char y)
{
	int i;
	node *p,*px;
	px=(node *)malloc(sizeof(node));
	px->next=NULL;
	px->data=y;
	i=locat(g,x);
	if(i==-1)
		b_link(g);
	else
	{
		p=g->a[i];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=px;
	}
}
void output(graph *g)
{
	int i;
	node *p;
	for(i=0;i<g->num;i++)
	{
		if(g->a[i]!=NULL)
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
		else
			break;
	}
}
void rb_link(graph *g,graph *g1)
{
	int i,j;
	node *px,*p,*pq,*pi,*py;
	g1->num=g->num;
	for(i=0;i<g1->num;i++)
	{
		py=(node *)malloc(sizeof(node));
		py->data=g->a[i]->data;
		py->next=NULL;
		g1->a[i]=py;
		
	}
	for(i=0;i<g->num;i++)
	{
		px=g->a[i];p=g->a[i]->next;
		while(p!=NULL)
		{
			pq=(node *)malloc(sizeof(node));
			pq->data=px->data;
			pq->next=NULL;
			j=locat(g1,p->data);
			pi=g1->a[j];
			while(pi->next!=NULL)
				pi=pi->next;
			pi->next=pq;
			p=p->next;
		}
	}
}
void main()
{
	int i;
	int n,e;//n顶点，e弧数目
	char x,y;
	graph *g,*g1;
	g=(graph *)malloc(sizeof(graph));
	g1=(graph *)malloc(sizeof(graph));
	printf("请输入顶点及弧的数目\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;
	b_link(g);
	for(i=0;i<e;i++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&x,&y);getchar();
		push(g,x,y);
	}
	
	output(g);rb_link(g,g1);
	printf("===============================\n");
	output(g1);
	return;
}

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
	node *px;
	int i;
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
	int j;
	node *p,*px;
	px=(node *)malloc(sizeof(node));
	j=locat(g,x);
	p=g->a[j];
	px->data=y;
	px->next=NULL;
	while(p->next!=NULL)
		p=p->next;
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
void cal(graph *g,int f[])
{
	int i,k;
	node *p;
	for(i=0;i<g->num;i++)
	{
		p=g->a[i]->next;
		while(p!=NULL)
		{
			k=locat(g,p->data);
			f[k]++;
			p=p->next;
		}
	}
}
void main()
{
	int k,n,e;
	int f[maxnum]={0};
	graph *g;
	char i,j;
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点及弧数\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;
	b_link(g);
	for(k=0;k<e;k++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&i,&j);getchar();
		push(g,i,j);
	}
	output(g);
	cal(g,f);
	for(k=0;k<n;k++)
		printf("%c:%d\n",g->a[k]->data,f[k]);
	return;
}
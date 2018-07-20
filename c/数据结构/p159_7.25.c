#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 10
typedef struct node {
	char data;
	struct node *next;
}node;
typedef struct {
	int num;
	node *a[maxnum];
}graph;
void b_link(graph *g)
{
	int i;
	node *px;
	//printf("%d........\n",g->num);
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点数据\n");
		px=(node *)malloc(sizeof(node));
		px->next=NULL;scanf("%c",&px->data);getchar();
		g->a[i]=px;
	}
	return ;
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
	i=locat(g,x);
	px=(node *)malloc(sizeof(node));
	px->data=y;
	px->next=NULL;
	p=g->a[i];
	while(p->next!=NULL)
		p=p->next;
	p->next=px;
}
void change(graph *g,int k[][maxnum])
{
	int i,j;
	node *p;
	for(i=0;i<g->num;i++)
	{
		p=g->a[i]->next;
		while(p!=NULL)
		{
			j=locat(g,p->data);
			k[i][j]=1;
			p=p->next;
		}
	}
}
void outputmatrix(graph *g,int k[][maxnum])
{
	int i,j;
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			printf("%3d",k[i][j]);
		}
		printf("\n");
	}
	return;
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
	return;
}
void main()
{
	int i;
	char n,e;
	char a,b;
	int k[maxnum][maxnum];
	graph *g;
	memset(k,0,sizeof(k));
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点及弧数\n");
	scanf("%d%d",&n,&e);getchar();
	g->num=n;
	b_link(g);
	for(i=0;i<e;i++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&a,&b);getchar();
		push(g,a,b);
	}
	output(g);
	change(g,k);
	printf("=========================\n");
	outputmatrix(g,k);
	return;
}

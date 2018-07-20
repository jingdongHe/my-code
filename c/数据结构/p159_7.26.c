#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void change(graph *g,int k[][maxnum])
{
	int i,j;
	node *p,*px;
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			if(k[i][j]!=0)
			{
				px=(node *)malloc(sizeof(node));
				px->data=g->a[j]->data;
				px->next=NULL;
				p=g->a[i];
				while(p->next!=NULL)
					p=p->next;
				p->next=px;
			}
		}
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
	return;
}
void main()
{
	graph *g;
	int i,j,n;
	int k[maxnum][maxnum];
	memset(k,0,sizeof(k));
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点数\n");
	scanf("%d",&n);getchar();
	g->num=n;
	printf("请输入图的矩阵\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&k[i][j]);getchar();
		}
	}
	
	b_link(g);
	change(g,k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%-2d",k[i][j]);
		}
		printf("\n");
	}
	output(g);
	return;
}
	
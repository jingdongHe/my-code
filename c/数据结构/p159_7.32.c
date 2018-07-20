#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
int q=0,k;
typedef struct node {
	char data;
	struct node *next;
}node;
typedef struct {
	node *a[maxnum];
	int n;
}graph;
void b_link(graph *g)
{
	int i;
	node *p;
	for(i=0;i<g->n;i++)
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
	for(i=0;i<g->n;i++)
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
	px=(node *)malloc(sizeof(node));
	px->data=y;
	px->next=NULL;
	//printf("1111111111111111\n");
	i=locat(g,x);
	p=g->a[i];
	//printf("2222222222222\n");
	while(p->next!=NULL)
		p=p->next;
	p->next=px;
}
void output(graph *g)
{
	int i;
	node *p;
	for(i=0;i<g->n;i++)
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
int cal(int f[])
{
	int k=0,d=0;
	for(k=0;k<maxnum;k++)
		if(f[k]!=0)
			d++;
	return d;
}
void DFS(graph *g,char a,char b,int f[])
{
	int i;
	node *p;
	if(a==b)
		return;
	i=locat(g,a);
	f[i]=1;
	p=g->a[i]->next;
	while(p!=NULL)
	{
		if(p->data==b&&cal(f)==k)
		{q=1;return;}
		if(f[locat(g,p->data)]!=1)
			DFS(g,p->data,b,f);
		p=p->next;
	}
}
void main()
{
	int i,n,e;
	char x,y;
	int f[maxnum]={0};
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("请输入图的顶点数及弧数\n");
	scanf("%d%d",&n,&e);getchar();
	g->n=n;
	b_link(g);
	for(i=0;i<e;i++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&x,&y);getchar();
		push(g,x,y);
	}
	output(g);
	printf("请输入想要判断是否存在简单路径的顶点\n");
	scanf("%c%c",&x,&y);getchar();
	printf("请输入理想长度\n");
	scanf("%d",&k);getchar();
	DFS(g,x,y,f);
	if(q==0)
		printf("NO\n");
	else
		printf("YES\n");
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 20
typedef struct arcbox{
	char tailvex,headvex;
	struct arcbox *hlink,*tlink;
	int weight;
}arcbox;
typedef struct vexnode {
	char data;
	arcbox *firstin,*firstout;
}vexnode;
typedef struct {
	vexnode list[maxnum];
	int vexnum,arcnum;
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
int locatvex(graph *g,char d)
{
	int k,j=-1;
	for(k=0;k<g->vexnum;k++)
	{
		if(g->list[k].data==d)
		{
			j=k;return j;
		}
	}
	return j;
}
void create(graph *g)
{
	int i,j,k;
	char vt,vh;
	arcbox *p;
	printf("输入图的顶点数和弧的数目\n");
	scanf("%d%d",&g->vexnum,&g->arcnum);getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("输入顶点信息\n");
		scanf("%c",&g->list[i].data);getchar();
		g->list[i].firstin=g->list[i].firstout=NULL;
	}
	//getchar();
	for(k=0;k<g->arcnum;k++)
	{
		printf("请输入弧的信息(尾，头，权值)\n");
		scanf("%c%c",&vt,&vh);getchar();
		i=locatvex(g,vt);j=locatvex(g,vh);
		//printf("....%c......%c\n",vt,vh);
		p=(arcbox *)malloc(sizeof(arcbox));
		p->tailvex=vt;p->headvex=vh;
		p->hlink=g->list[j].firstin;p->tlink=g->list[i].firstout;
		g->list[j].firstin=g->list[i].firstout=p;
	}
}
void output(graph *g)
{
	int i;
	arcbox *pi,*po;
	for(i=0;i<g->vexnum;i++)
	{
		pi=g->list[i].firstin;
		po=g->list[i].firstout;
		while(pi!=NULL)
		{
			printf("<%c,%c> ",pi->tailvex,pi->headvex);
			pi=pi->hlink;
		}
		printf("\n--------------\n");
		while(po!=NULL)
		{
			printf("<%c,%c> ",po->tailvex,po->headvex);
			po=po->tlink;
		}
		printf("\n*************************************\n");
	}
}
int circle(graph *g)
{
	int a[maxnum]={0};
	int i,k=0;
	char d;
	arcbox *p;
	stack *q;
	q=(stack *)malloc(sizeof(stack));
	b_stack(q);
	//printf("%d........%d\n",g->arcnum,g->vexnum);
	for(i=0;i<g->vexnum;i++)
	{
		p=g->list[i].firstin;//printf("222222222222\n");
		while(p!=NULL)
		{a[i]++;p=p->hlink;}//printf("333333333333\n");
	}//结束后每个顶点的入度可以求出
	//for(i=0;i<g->vexnum;i++)
	//		printf("%3d",a[i]);
	for(i=0;i<g->vexnum;i++)
	{
		if(a[i]==0)
			push(q,g->list[i].data);
	}//结束后入度为0的顶点入栈
	
	while(q->d!=0)
	{
		//printf("44444444444\n");
		d=pop(q);k++;//printf("%c ",d);
		p=g->list[locatvex(g,d)].firstout;
		
		while(p!=NULL)
		{
			//printf("%d.......\n",locatvex(g,p->headvex));
			a[locatvex(g,p->headvex)]--;
			if(a[locatvex(g,p->headvex)]==0)
				push(q,p->headvex);
			p=p->tlink;
		//	printf("%d..........\n",q->d);
		}
	//	printf("2222222222222222222\n");
		/*for(i=0;i<g->vexnum;i++)
			printf("%3d",a[i]);*/
	}
	//printf("%d............\n",k);
	if(k==g->vexnum)
		return 1;
	else
		return 0;
}
void main()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	create(g);
	output(g);
	if(circle(g))
		printf("不存在环\n");
	else
		printf("存在环\n");
	return;
}
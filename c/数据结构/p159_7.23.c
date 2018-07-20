#include<stdio.h>
#include<stdlib.h>
#define num 10
typedef struct arc{
	int tailvex,headvex;
	struct arc *hlink,*tlink;
}arcnode;
typedef struct {
	char data;
	arcnode *firstin,*firstout;
}vernode;
typedef struct {
	vernode *vertex[num];
	int vexnum,arcnum;
}graph;
int locver(graph *g,char d)
{
	int k,j=-1;
	for(k=0;k<g->vexnum;k++)
	{
		if(g->vertex[k]->data==d)
		{
			j=k;break;}
	}
	return j;
}
graph *b_crosslink()
{
	graph *g;
	int n,e,i,j,k;
	char vt,vh,d;
	arcnode *p;
	g=(graph *)malloc(sizeof(graph));
	printf("输入图的顶点数和弧的数目\n");
	scanf("%d%d",&n,&e);getchar();
	g->vexnum=n;
	g->arcnum=e;
	printf("111111111\n");
	for(i=0;i<n;i++)
	{
		printf("输入顶点信息\n");
		d=getchar();
		printf("1111111111\n");
		g->vertex[i]->data=d;
		printf("2222222\n");
		scanf("%c",g->vertex[i]->data);getchar();
		printf("111111122\n");
		g->vertex[i]->firstin=NULL;g->vertex[i]->firstout=NULL;
	}
	for(k=0;k<e;k++)
	{
		printf("请输入弧的信息\n");
		scanf("%c%c",&vt,&vh);getchar();
		i=locver(g,vt);j=locver(g,vh);
		p=(arcnode *)malloc(sizeof(arcnode));
		p->tailvex=i;p->headvex=j;
		p->tlink=g->vertex[i]->firstout;
		g->vertex[i]->firstout=p;
		p->hlink=g->vertex[j]->firstin;
		g->vertex[j]->firstin=p;
	}
	return g;
}
void output(graph *g)
{
	int i;
	arcnode *pi,*po;
	for(i=0;i<g->vexnum;i++)
	{
		pi=g->vertex[i]->firstin;
		po=g->vertex[i]->firstout;
		while(pi!=NULL)
		{
			printf("<%d,%d> ",pi->tailvex,pi->headvex);
			pi=pi->hlink;
		}
		printf("\n--------------\n");
		while(po!=NULL)
		{
			printf("<%d,%d> ",po->tailvex,po->headvex);
			po=po->tlink;
		}
		printf("\n*************************************\n");
	}
}
void main()
{
	graph *g;
	g=b_crosslink();
	output(g);
}

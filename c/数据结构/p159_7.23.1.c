#include<stdio.h>
#include<stdlib.h>
#define maxnum 20
typedef struct arcbox{
	int tailvex,headvex;
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
int locatvex(graph *g,char d)
{
	int k,j=-1;
	for(k=0;k<g->vexnum;k++)
	{
		if(g->list[k].data==d)
		{
			//printf("%c.....%c...%d\n",g->list[k].data,d,k);
			j=k;
			break;
		}
	}
	return j;
}
void create(graph *g)
{
	int i,j,k,w;
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
		scanf("%c%c%d",&vt,&vh,&w);getchar();
		i=locatvex(g,vt);j=locatvex(g,vh);
		//printf("....%c......%c\n",vt,vh);
		p=(arcbox *)malloc(sizeof(arcbox));
		p->tailvex=i;p->headvex=j;p->weight=w;
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
			printf("<%d,%d,%d> ",pi->tailvex,pi->headvex,pi->weight);
			pi=pi->hlink;
		}
		printf("\n--------------\n");
		while(po!=NULL)
		{
			printf("<%d,%d,%d> ",po->tailvex,po->headvex,po->weight);
			po=po->tlink;
		}
		printf("\n*************************************\n");
	}
}
void main()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	create(g);
	output(g);
	return;
}
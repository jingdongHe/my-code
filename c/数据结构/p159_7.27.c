#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
typedef struct node {
	char ivex,jvex;
	struct node *ilink,*jlink;
}node;
typedef struct {
	char vertex;
	node *firstedge;
}headnode;
typedef struct  {
	headnode *a[maxnum];
	int num;
	int edg;
}graph;
void b_link_head(graph *g)
{
	int i;
	headnode *p;
	for(i=0;i<g->num;i++)
	{
		printf("请输入顶点信息\n");
		p=(headnode *)malloc(sizeof(headnode));
		scanf("%c",&p->vertex);getchar();
		p->firstedge=NULL;
		g->a[i]=p;
	}
}
int locat(graph *g,char x)
{
	int i,j=-1;
	for(i=0;i<g->num;i++)
	{
		//printf("%c.........\n",g->a[i]->vertex);
		if(g->a[i]->vertex==x)
		{j=i;break;}
	}
	//printf("88888888888\n");
	return j;
}
void b_link(graph *g)
{
	char iv,jv;
	int k,i,j;
	node *p;
	for(k=0;k<g->edg;k++)
	{
		printf("请输入边的两个顶点\n");
		scanf("%c%c",&iv,&jv);getchar();
		//printf("%c.........%c\n",iv,jv);
		i=locat(g,iv);
		//printf("000000000\n");
		j=locat(g,jv);
		//printf("333333333333\n");
		p=(node *)malloc(sizeof(node));
		p->ivex=iv;p->jvex=jv;
		//printf("000000000000\n");
		p->ilink=p->jlink=NULL;
		//printf("2222222222222222\n");
		p->ilink=g->a[i]->firstedge;
		g->a[i]->firstedge=p;
		p->jlink=g->a[j]->firstedge;
		g->a[j]->firstedge=p;
	}
}
void output(graph *g)
{
	int i;
	node *p;
	/*node *p1,*p2;
	for(i=0;i<g->num;i++)
	{
		p1=p2=g->a[i]->firstedge;
		while(p1!=NULL)
		{
			printf("<%c,%c>",p1->ivex,p1->jvex);
			p1=p1->ilink;
		}
		printf("\n------------------------------------\n");
		while(p2!=NULL)
		{
			printf("<%c,%c>",p2->ivex,p2->jvex);
			p2=p2->jlink;
		}
		printf("\n***********************************************\n");
	}*/
	for(i=0;i<g->num;i++)
	{
		p=g->a[i]->firstedge;
		while(p!=NULL)
		{
			if(p==NULL)
				break;
			printf("<%c,%c>",p->ivex,p->jvex);
			if(p->ivex==g->a[i]->vertex)
			{
				p=p->ilink;
				if(p==NULL)
					break;
			}
			if(p->jvex==g->a[i]->vertex)
			{
				p=p->jlink;
				if(p==NULL)
					break;
			}
		}
		printf("\n******************\n");
	}
}
void main()
{
	int n,e;
	graph *g;
	printf("请输入图的顶点数及弧数\n");
	g=(graph *)malloc(sizeof(graph));
	scanf("%d%d",&n,&e);getchar();
	g->num=n;g->edg=e;
	b_link_head(g);
	b_link(g);
	output(g);
	return;
}

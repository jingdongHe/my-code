#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxnum 10
typedef struct {
	int a[maxnum][maxnum];
	char b[maxnum];
	int edge,num;
}graph;
int locat(graph *g,char x)
{
	int i,j=-1;
	for(i=0;i<g->num;i++)
	{
		if(g->b[i]==x)
		{j=i;return j;}
	}
	return j;
}
void b_graph(graph *g)
{
	int i,j;
	char x,y;
	for(i=0;i<g->num;i++)
		for(j=0;j<g->num;j++)
			g->a[i][j]=99;
	for(i=0;i<g->num;i++)
		g->a[i][i]=0;
	for(i=0;i<g->num;i++)
	{
		printf("please entry the informationg of vex\n");
		scanf("%c",&g->b[i]);getchar();
	}
	for(i=0;i<g->edge;i++)
	{
		int d;
		printf("please entry the information of edge\n");
		scanf("%c%c%d",&x,&y,&d);getchar();
		g->a[locat(g,x)][locat(g,y)]=d;
	}
}
void output(graph *g)
{
	int i,j;
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			printf("%-3d",g->a[i][j]);
		}
		printf("\n");
	}
	return ;
}
void floyd(graph *g)
{
	int i,j,k;
	int a[maxnum][maxnum];
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			a[i][j]=g->a[i][j];
		}
	}
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			for(k=0;k<g->num;k++)
			{
				if(a[j][i]+a[i][k]<a[j][k])
					a[j][k]=a[j][i]+a[i][k];
			}
		}
	}
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			printf("%-3d",a[i][j]);
		}
		printf("\n");
	}
	return;
}
void main()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	printf("please entry the information about the garph\n");
	scanf("%d%d",&g->num,&g->edge);getchar();
	b_graph(g);
	output(g);
	floyd(g);
}
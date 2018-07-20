#include<stdio.h>
#include<stdlib.h>
#define maxnum 10
typedef struct {
	int a[maxnum][maxnum];
	int num,edge;
	char b[maxnum];
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
	printf("please entry the information about garph(num&&edge)\n");
	scanf("%d%d",&g->num,&g->edge);getchar();
	for(i=0;i<g->num;i++)
	{
		printf("please entry the title of graph\n");
		scanf("%c",&g->b[i]);getchar();
	}
	
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			g->a[i][j]=99;
		}
		g->a[i][i]=0;
	}
	for(i=0;i<g->edge;i++)
	{
		printf("please entry the information of edge\n");
		scanf("%c%c",&x,&y);getchar();
		g->a[locat(g,x)][locat(g,y)]=1;
	}
}
void output(graph *g)
{
	int i,j;
	for(i=0;i<g->num;i++)
	{
		for(j=0;j<g->num;j++)
		{
			if(g->a[i][j]==99)
				printf("M  ");
			else
				printf("%-3d",g->a[i][j]);
		}
		printf("\n");
	}
}
int empty(char b[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(b[i]!='\0')
			return 0;
	}
	return 1;
}
void bfs(graph *g,char a)
{
	char b[maxnum],d;
	int i,j,r,s,c[maxnum]={0};
	s=r=0;
	b[s++]=a;c[locat(g,a)]=1;
	while(empty(b,g->num)==0)
	{
		d=b[r];
		b[r]='\0';r++;
		printf("%c ",d);
		i=locat(g,d);
		for(j=0;j<g->num;j++)
		{
			if(c[j]==0&&g->a[i][j]==1)
			{
			//if(i<j)
				b[s++]=g->b[j];
			//if(i>j)
			//	b[s++]=g->b[i];
			}
		}
	}
	
}
void main()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	b_graph(g);
	output(g);
	bfs(g,'d');
	return;
}
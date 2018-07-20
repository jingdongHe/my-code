#include<stdio.h>
#include<stdlib.h>
#define maxnum 20
typedef struct node {
	char data;
	int way;
	struct node *next;
}node;
typedef struct {
	node *a[maxnum];
	int num,edge;
}graph;
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
void b_link(graph *g)
{
	int i,d;
	node *p,*px;
	char x,y;
	printf("pleas entry the informaton of the graph\n");
	scanf("%d%d",&g->num,&g->edge);getchar();
	for(i=0;i<g->num;i++)
	{
		printf("please entry the head of the graph\n");
		p=(node *)malloc(sizeof(node));
		scanf("%c",&p->data);getchar();
		p->way=0;
		p->next=NULL;
		g->a[i]=p;
	}
	for(i=0;i<g->edge;i++)
	{
		printf("please entry the information of the edge\n");
		p=(node *)malloc(sizeof(node));
		scanf("%c%c%d",&x,&y,&d);getchar();
		px=g->a[locat(g,x)];
		while(px->next!=NULL)
			px=px->next;
		p->data=y;
		p->way=d;
		p->next=NULL;
		px->next=p;
	}
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
}
int panduan(int c[],int n)
{
	int i;
	/*for(i=0;i<n;i++)
		printf("%-2d",c[i]);
	printf("\n");*/
	for(i=0;i<n;i++)
	{
		if(c[i]==0)
			return 0;
	}
	return 1;
}//返回1表示全部的顶点以遍历完
int find_min(int b[],int c[],int n)
{
	int i,j=999,k;
	for(i=0;i<n;i++)
	{
		if(b[i]<j&&c[i]==0)
		{j=b[i];k=i;}
	}
	return k;
}//返回第k个数是最小的数
int loc(char a[],char x)
{
	int j=-1,d=0;
	while(a[d]!='\0')
	{
		if(a[d]==x)
		{j=d;return j;}
		d++;
	}
	return j;
}
void fmw(graph *g,char x)
{
	char a[maxnum]={'\0'};
	int b[maxnum];
	int c[maxnum]={0};//a表示第i个位置存的是什么字符，b表示最短距离，c表示是否使用过
	int d=0,i;
	node *p;
	for(i=0;i<g->num;i++)
		b[i]=999;
	a[d++]=x;
	b[d-1]=0;
	while(panduan(c,g->num)==0)
	{
		i=find_min(b,c,g->num);
		c[i]=1;
		p=g->a[i]->next;
		while(p!=NULL)
		{
			if(loc(a,p->data)==-1)
				a[d++]=p->data;
			if(b[i]+p->way<b[loc(a,p->data)])
				b[loc(a,p->data)]=b[i]+p->way;
			p=p->next;
		}
	}
	for(i=0;i<g->num;i++)
		printf("to[%c]:%-2d\n",a[i],b[i]);
}
void main()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	b_link(g);
	output(g);
	fmw(g,'a');
}


	
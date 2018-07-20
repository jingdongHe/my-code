#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxnum 100
int m,n,p=999;
typedef struct node {
	int x,y;
}node;
typedef struct 
{
	node *a[maxnum];
	int r,s;
}stack;
void b_stack(stack *q)
{
	q=(stack *)malloc(sizeof(stack));
	q->r=q->s=0;
}
void push(stack *q,node *a)
{
	q->a[q->s++]=a;
}
void pop(stack *q)
{
	//node *a;
	//a=q->a[s-1];
	q->s--;
	q->a[q->s]='\0';
}
void output_stack(stack *q)
{
	int i;
	for(i=q->r;i<q->s;i++)
		printf("(%d,%d)",q->a.x,q->a->y);
}
void b_graph(char a[][maxnum])
{
	int i,j;
	printf("«Î ‰»Îæÿ’Û¥Û–°\n");
	scanf("%d%d",&n,&m);getchar();
	printf("«Î ‰»Îæÿ’Û\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%c",&a[i][j]);
		}
		getchar();
	}
}
void search(char a[][maxnum],int x,int y,int d,stack *q)
{
	node *a;
	if(d>q)
		return;
	if(x>=n||x<0||y>=m||y<0)
		return;
	if(a[x][y]=='X')
		return;
	if(x==n-1&&y==m-1)
	{if(d<p)p=d;return;}
	if(a[x][y]=='.')
	{a[x][y]='X';a=(node *)malloc(sizeof(node));a->x=x;a->y=y;push(q,a);}
	//if(a[x][y]<='9'&&a[x][y]>'0')
	//	d+=(a[x][y]-48);
	search(a,x,y+1,d+1,q);
	search(a,x,y-1,d+1,q);
	search(a,x+1,y,d+1,q);
	search(a,x-1,y,d+1,q);
	a[x][y]='.';pop(q);
	return;
}
void main()
{
	char a[maxnum][maxnum];
	stack *q;
	b_graph(a);
	b_stack(q);
	search(a,0,0,0,q);
	printf("%d.........\n",p);
	output(q);
}
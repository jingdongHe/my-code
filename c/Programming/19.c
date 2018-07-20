#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int x;
	int y;
}point;
typedef struct {
	point *a[20];
}way;
typedef struct {
	int n,m;
	int a[10][10];
	point *b,*e;//begin end
}array;
int q=1,p=0,k=0,d;
way *temp,*f;
void input(array *a)
{
	int i,j;
	printf("«Î ‰»Îæÿ’Û¥Û–°\n");
	scanf("%d%d",&a->n,&a->m);getchar();
	printf("«Î ‰»Îæÿ’Û\n");
	for(i=0;i<a->n;i++)
	{
		for(j=0;j<a->m;j++)
		{
			scanf("%d",&a->a[i][j]);getchar();
			if(a->a[i][j]==-1)
			{a->b=(point *)malloc(sizeof(point));a->b->x=i;a->b->y=j;}
			if(a->a[i][j]==-2)
			{a->e=(point *)malloc(sizeof(point));a->e->x=i;a->e->y=j;}
			
		}
	}
}
void copy()
{
	int i;
	for(i=0;i<d;i++)
		f->a[i]=NULL;
	for(i=0;i<k;i++)
		f->a[i]=temp->a[i];
	d=k;
}
void put()
{
	int i;
	//printf("%d.....%d",d,k);
	for(i=0;i<d;i++)
		printf("(%d,%d)",f->a[i]->x,f->a[i]->y);
	printf("\n");
}
void DFS(array *a,int x,int y)
{
	int d;
	point *t;
	/*  7   0   4  18
°°		4   0   1   1
		15   7  11   -1
		0  12  -2   0*/
	if(a->a[x][y]==0)
		return;
	if(x>=a->n||x<0||y<0||y>=a->m)
		return;
	t=(point *)malloc(sizeof(point));
	t->x=x;t->y=y;
	temp->a[k++]=t;
	if(a->a[x][y]==-2)
	{
		if(q>p)
		{p=q;copy();}
	}
	d=a->a[x][y];
	a->a[x][y]=0;
	q+=d;
	DFS(a,x+1,y);
	DFS(a,x-1,y);
	DFS(a,x,y+1);
	DFS(a,x,y-1);
	a->a[x][y]=d;
	q-=d;
	temp->a[k--]=NULL;
}
void main()
{
	array *a;
	a=(array *)malloc(sizeof(array));
	input(a);
	//output(a);
	//printf("%d,%d\n%d,%d\n",a->b->x,a->b->y,a->e->x,a->e->y);
	temp=(way *)malloc(sizeof(way));
	f=(way *)malloc(sizeof(way));
	DFS(a,a->b->x,a->b->y);
	put();
	printf("%d......\n",p);
}

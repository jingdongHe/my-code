/*用图的邻接表实现图的深度优先搜索和广度优先搜索。*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
typedef struct {
	node *a[100];
	int n;
}head_node;
typedef struct node1 {
	int data;
	struct node1 *next;
}queue;
queue *b_queue()
{
	queue *p;
	p=(queue *)malloc(sizeof(queue));
	p->next=NULL;
	return p;
}
int pop(queue *head)
{
	queue *p;
	int d;
	p=head->next;
	if(p==NULL)
	{
		printf("empty\n");
		return '\0';
	}
	else
	{
		d=p->data;
		head->next=p->next;
		free(p);
	}
	return d;
}
void push(queue *head,int data)
{
	queue *p,*px;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	px=(queue *)malloc(sizeof(queue));
	px->data=data;
	px->next=NULL;
	p->next=px;
}
int empty(queue *head)
{
	if(head->next==NULL)
		return 1;
	return 0;
}
head_node *b_greap()
{
	int i,a,b,n;
	head_node *hp;
	node *p,*px;
	//为简化代码，顶点以int类型表示,且默认命名为0-n
	printf("please entry the vertex number\n");
	hp=(head_node *)malloc(sizeof(head_node));
	scanf("%d",&hp->n);
	for(i=0;i<hp->n;i++)
	{
		hp->a[i]=(node *)malloc(sizeof(node));
		hp->a[i]->data=i;
		hp->a[i]->next=NULL;
	}
	printf("please entry the way number and way(a,b)\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		p=hp->a[a];
		while(p->next!=NULL)
			p=p->next;
		px=(node *)malloc(sizeof(node));
		px->data=b;
		px->next=NULL;
		p->next=px;
	}
	return hp;
}
void output(head_node *head)
{
	int i;
	node *p;
	for(i=0;i<head->n;i++)
	{
		p=head->a[i];
		printf("%d:",p->data);
		p=p->next;
		while(p!=NULL)
		{
			printf(" %d",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
void DFS(head_node *head,int d,int b[])
{
	node *p;
	p=head->a[d]->next;
	while(p!=NULL&&b[p->data]==0)//0表示未使用
	{
		printf("%d ",p->data);
		b[p->data]=1;
		DFS(head,p->data,b);
		p=p->next;
	}
}
void BFS(head_node *head,int a,int b[])
{
	node *p;
	queue *q;
	int d;
	q=b_queue();
	push(q,a);b[a]=1;
	while(!empty(q))
	{
		d=pop(q);
		printf("%d ",d);
		p=head->a[d]->next;
		while(p!=NULL)
		{
			if(b[p->data]==0)
				push(q,p->data);
			p=p->next;
		}
	}
}
int main()
{
	head_node *p;
	int b[100]={0};
	int d,i;
	p=b_greap();
	output(p);
	printf("please entry the star\n");
	scanf("%d",&d);
	printf("%d ",d);
	DFS(p,d,b);
	printf("\n");
	for(i=0;i<100;i++)
		b[i]=0;
	BFS(p,d,b);
	return 0;
}

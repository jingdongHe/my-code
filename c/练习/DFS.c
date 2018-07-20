#include<stdio.h>
#include<stdlib.h>
#define k 8
struct node
{
	int d;
	struct node *next;
};
struct node Head[k];
int visit[k]={0};
void b_graph(int a,int b)
{
	struct node *p,*head;
	p=(struct node *)malloc(sizeof(struct node));
	p->d=b;
	p->next=NULL;
	head=&Head[a];
	while(head->next!=NULL)
		head=head->next;
	head->next=p;
}
void DFS(int i)
{
	struct node *p;
	visit[i]=1;
	printf("[%d]==>",i);
	p=Head[i].next;
	while(p!=NULL)
	{
		if(visit[p->d]==0)
			DFS(p->d);
		p=p->next;
	}
}
void main()
{
	int a[20][2]={1,2,2,1,1,3,3,1,2,4,4,2,2,5,5,2,3,6,6,3,3,7,7,3,4,8,8,4,5,8,8,5,6,8,8,6,7,8,8,7};
	int i;
	struct node *p;
	for(i=1;i<=k;i++)
	{
		Head[i].d=i;
		Head[i].next=NULL;
	}
	for(i=0;i<20;i++)
	{
		b_graph(a[i][0],a[i][1]);
	}
	for(i=1;i<=k;i++)
	{
		printf("[%d]",Head[i].d);
		p=Head[i].next;
		while(p!=NULL)
		{
			printf("==>%d",p->d);
			p=p->next;
		}
		printf("\n");
	}
	DFS(1);
	printf("[end]\n");
	return;
}

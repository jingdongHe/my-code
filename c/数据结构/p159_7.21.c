#include<stdio.h>
#include<stdlib.h>
#define n 6
struct node {
	int data;
	struct node *next;
};
struct node *b_link(int i)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=++i;
	p->next=NULL;
	return p;
}
void push(struct node *head,int d)
{
	struct node *p,*px;
	p=head;
	px=(struct node *)malloc(sizeof(struct node));
	px->data=d;
	px->next=NULL;
	while(p->next!=NULL)
		p=p->next;
	p->next=px;
}
void put(struct node *head)
{
	struct node *p;
	p=head;
	printf("%d",p->data);
	while(p->next!=NULL)
	{
		if(p->next->data!=0)
			printf("->%d",p->next->data);
		p=p->next;
	}
}
int g[n][n]={{0,2,999,999,999,3},
			{999,0,3,2,999,999},
			{4,999,0,999,4,999},
			{1,999,999,0,1,999},
			{999,1,999,999,0,3},
			{999,999,2,5,999,0}};
void main()
{
	int i,j;
	struct node *a[n];
	for(i=0;i<n;i++)
	{
		a[i]=b_link(i);
		for(j=0;j<n;j++)
		{
			if(g[i][j]==999)
				printf("*");
			else
			{
				if(g[i][j]!=0)
					push(a[i],j+1);
				printf("%d",g[i][j]);
			}
			printf(" ");
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		put(a[i]);
		printf("\n");
	}
	return ;
}
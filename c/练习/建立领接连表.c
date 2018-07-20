#include<stdio.h>
#include<stdlib.h>
#define k 5
struct node
{
	int d;
	struct node *next;
};
struct node Head[k];//测试指针是否可行
void bgraph(int i,int j)
{
	struct node *p,*head;
	p=(struct node *)malloc(sizeof(struct node));
	p->d=j;
	p->next=NULL;
	head=&Head[i];
	while(head->next!=NULL)
		head=head->next;
	head->next=p;
}
void main()
{
	int i;
	int m,n;
	struct node *p;
	for(i=1;i<=k;i++)
	{
		Head[i].d=i;
		Head[i].next=NULL;
	}
	while(1)
	{
		printf("Please entry the origin:(entry -1 break)\n");
		scanf("%d",&m);
		if(m==-1)
			break;
		printf("Please entry the end:\n");
		scanf("%d",&n);
		bgraph(m,n);
	}
	for(i=1;i<=k;i++)
	{
		p=Head[i].next;
		printf("Head[%d]",Head[i].d);
		while(p!=NULL)
		{
			printf("->%d",p->d);
			p=p->next;
		}
		printf("\n");
	}
	return;
}




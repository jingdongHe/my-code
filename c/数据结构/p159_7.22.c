#include<stdio.h>
#include<stdlib.h>
#define n 4
struct node {
	int data;
	struct node *next;
};
struct node *b_link(int d)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=d;
	p->next=NULL;
	return p;
}
void push(struct node *head,int d)
{
	struct node *p,*px;
	p=head;
	while(p->next!=NULL)
		p=p->next;
	px=(struct node *)malloc(sizeof(struct node));
	px->data=d;
	px->next=NULL;
	p->next=px;
	return;
}
void put(struct node *a[])
{
	int i;
	struct node *p;
	for(i=0;i<n;i++)
	{
		p=a[i];
		printf("%d",p->data);
		while(p->next!=NULL)
		{
			printf("->%d",p->next->data);
			p=p->next;
		}
		printf("\n");
	}
	return;
}
void main()
{
	int i,j,k;
	struct node *a[n]={NULL};
	printf("Please entry the arc\n");
	scanf("%d,%d",&i,&j);
	
	while(i!=0||j!=0)
	{
		for(k=0;k<n;k++)
		{
			if(a[k]==NULL)
			{a[k]=b_link(i);}
			//printf("%d11111111111111111\n",a[k]->data);
			if(a[k]!=NULL&&a[k]->data==i)
			{
				
				push(a[k],j);
				break;
			}//printf("11111111\n");
		}
		/*if(k==n)
		{
			for(k=0;k<n;k++)
			{
				if(a[k]==NULL)
				{
					a[k]=b_link(i);
					break;
				}
			}
		}*/
		printf("Please entry anthor arc\n");
		scanf("%d,%d",&i,&j);
	}
	put(a);
	return;
}


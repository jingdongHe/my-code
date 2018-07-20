#include<stdio.h>
#include<stdlib.h>
struct node{
	int v1,v2,w;
	struct node *next;
};
struct node *head=NULL;
int visit[5]={0};
int graph[10][3]={1,2,7,1,3,6,1,4,5,1,5,12,2,3,14,2,4,8,2,5,8,3,4,3,3,5,9,4,5,2};
void b_list()
{
	struct node *p,*current,*point,*p1;
	int i;
	for(i=0;i<10;i++)
	{
	current=(struct node *)malloc(sizeof(struct node));
	current->v1=graph[i][0];
	current->v2=graph[i][1];
	current->w=graph[i][2];
	current->next=NULL;
	if(head==NULL)
		head=current;
	else
	{
		
		p=head;point=head;
		while(current->w>p->w)
		{	
			point=p;
			p=p->next;
			if(p==NULL)
				break;
		}
		if(point==head)
		{
			if(current->w>head->w)
			{
				p1=head;
				current->next=p1->next;
				head->next=current;
			}
			else
			{
				p1=head;
				current->next=p1;
				head=current;
			}
		}
		else
		{
			p1=point->next;
			current->next=p1;
			point->next=current;
		}
	}
	}
}
void kruskal()
{
	struct node *p;
	int weight=0,linked=0;
	p=head;
	while(linked!=5-1)
	{
		if(visit[p->v1]==0||visit[p->v2]==0)
		{
			weight+=p->w;
			linked++;
			visit[p->v1]=visit[p->v2]=1;
		}
		p=p->next;
		if(p==NULL)
			break;
	}
	printf("%d",weight);
}

int main()
{
	struct node *p;
	b_list();
	p=head;
	while(p!=NULL)
	{
		printf("%d==",p->w);
		p=p->next;
	}
	printf("\n");
	kruskal();
	return 0;
}
	
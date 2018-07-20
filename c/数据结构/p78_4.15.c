#include<stdio.h>
#include<stdlib.h>
struct node 
{
	char d;
	struct node *next;
};
struct node *b_list()
{
	char d;
	struct node *head,*p,*current;
	printf("Please entry the list\n");
	head=(struct node *)malloc(sizeof(struct node));
	p=head;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node*)malloc(sizeof(struct node));
		current->d=d;
		current->next=NULL;
		p->next=current;
		p=current;
		d=getchar();
	}
	return head;
}
void insert(struct node *s,struct node *t,int pos)
{
	int i;
	struct node *ps,*pt;
	ps=s;pt=t->next;
	for(i=0;i<pos;i++)
	{
		ps=ps->next;
	}
	while(pt->next!=NULL)
		pt=pt->next;
	pt->next=ps->next;
	ps->next=t->next;
	ps=s->next;
	while(ps!=NULL)
	{
		printf("%c",ps->d);
		ps=ps->next;
	}
	printf("\n");
}
void main()
{
	struct node *s,*t;
	int n;
	s=b_list();
	t=b_list();
	printf("Please entry the location\n");
	scanf("%d",&n);
	insert(s,t,n);
}

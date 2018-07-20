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
	head=(struct node *)malloc(sizeof(struct node));
	p=head;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->next=NULL;
		p->next=current;
		p=current;
		d=getchar();
	}
	return head;
}
void output(struct node *head)
{
	struct node *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%c",p->d);
		p=p->next;
	}
	printf("\n");
}
void del(struct node *head,int i,int j)
{
	struct node *p,*px;
	int k;
	p=head->next;
	for(k=1;k<i-1;k++)
	{p=p->next;}
	for(k=i;k<=j;k++)
	{
		px=p->next;
		p->next=p->next->next;
		free(px);
	}
}
void main()
{
	struct node *s;
	s=b_list();
	output(s);
	del(s,3,5);
	output(s);
}
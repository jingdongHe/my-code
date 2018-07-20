#include<stdio.h>
#include<stdlib.h>
struct node
{
	char d;
	struct node *next;
};
struct node *b_list()
{
	struct node *head,*p,*current;char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;p=head;
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
	return;
}
struct node *up(struct node *head)
{
	struct node *p,*pn;
	char d;
	p=head->next;
	while(p!=NULL)
	{
		pn=p->next;
		while(pn!=NULL)
		{
			if(pn->d<p->d)
			{
				d=pn->d;pn->d=p->d;p->d=d;
			}
			pn=pn->next;
		}
		p=p->next;
	}
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	output(L);
	L=up(L);
	output(L);
	return;
}

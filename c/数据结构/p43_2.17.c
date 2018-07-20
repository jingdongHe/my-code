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
	struct node *head,*current,*p;
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
	return ;
}
struct node *put_min(struct node *head)
{
	struct node *p,*px,*parent;
	p=px=head->next;parent=head;
	while(p!=NULL)
	{
		if(px->next->d>p->d)
			px=parent;
		parent=p;
		p=p->next;
	}
	p=px->next;
	px->next=p->next;
	p->next=head->next;
	head->next=p;
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	L=put_min(L);
	output(L);
	return;
}
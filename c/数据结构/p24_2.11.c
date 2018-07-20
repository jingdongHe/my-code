#include<stdio.h>
#include<stdlib.h>
struct node
{
	char d;
	struct node *next;
};
struct node *b_list()
{
	struct node *head,*current,*p;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;p=head;
	printf("Please entry the list\n");
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
struct node *del(struct node *head)//删除第二个节点
{
	struct node *p,*parent,*pd;
	parent=head;
	p=head->next;
	parent=p;
	p=p->next;pd=p;
	parent->next=p->next;
	p=p->next;
	free(pd);
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	output(L);
	L=del(L);
	output(L);
	return;
}

	
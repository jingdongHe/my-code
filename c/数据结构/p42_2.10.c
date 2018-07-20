#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *pre,*next;
	char d;
};
struct node *b_list()
{
	struct node *head,*current,*p;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	head->pre=NULL;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->pre=head;
		current->next=head->next;
		if(head->next!=NULL)
			head->next->pre=current;//printf("11111111111111\n");
		head->next=current;
		if(current->next==NULL)
			p=current;
		d=getchar();
	}
	p->next=head;
	head->pre=p;
	return head;
}
void output(struct node *head)
{
	struct node *p;
	p=head->pre;
	while(p!=head)
	{
		printf("%c",p->d);
		p=p->pre;
	}
	printf("\n");
}
struct node *add(struct node *head,char d)
{
	struct node *current,*p;
	current=(struct node *)malloc(sizeof(struct node));
	current->d=d;
	p=head->pre;
	while(p->d<current->d)//插在p的前面
	{
		if(p->pre==head)
			break;
		p=p->pre;
	}
	p->pre->next=current;
	current->pre=p->pre;
	current->next=p;
	p->pre=current;
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	output(L);
	L=add(L,'5');
	output(L);
}


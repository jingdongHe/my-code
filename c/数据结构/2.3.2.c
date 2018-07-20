#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *pre,*next;
	char d;
};
struct node *b_list()
{
	struct node *current,*head,*p;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->pre=NULL;
	head->next=NULL;
	d=getchar();
	p=head;
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->pre=NULL;
		current->next=NULL;
		p->next=current;
		p=current;
		d=getchar();
	}
	p->next=head;
	return head;
}
struct node *bothway(struct node *p)
{
	while(p->next->pre==NULL)
	{
		p->next->pre=p;
		p=p->next;
	}
	return p;
}
void output(struct node *head)
{
	struct node *p;
	int d=0;
	p=head->pre;
	while(1)
	{
		if(p==head)
			p=head->pre;
		printf("%c",p->d);
		p=p->pre;
		if(p==head)
			d++;
		if(d==2)
			break;
	}
	printf("\n");
}
int main()
{
	struct node *L;
	L=b_list();
	L=bothway(L);
	output(L);
	return 0;
}

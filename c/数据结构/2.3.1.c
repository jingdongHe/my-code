#include<stdio.h>
#include<stdlib.h>
struct node {
	char d;
	struct node *next;
};
struct node *b_link()
{
	struct node *head,*current;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->next=head->next;
		head->next=current;
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
void divide(struct node *head,struct node *L1,struct node *L2)
{
	struct node *p,*p1,*pre,*l1;//
	int i=1;
	pre=head;
	l1=L1;
	p=head->next;
	while(p!=NULL)
	{
		p1=p;
		pre=p;
		p=p->next;
		if(i%2==1)
		{	l1->next=p1;p1->next=NULL;l1=p1;
		}
		else
		{	p1->next=L2->next;L2->next=p1;
		}
		
		i++;
	}
}
int main()
{
	struct node *L,*L1,*L2;
	L1=(struct node *)malloc(sizeof(struct node));
	L1->next=NULL;
	L2=(struct node *)malloc(sizeof(struct node));
	L2->next=NULL;
	L=b_link();
	output(L);
	divide(L,L1,L2);
	output(L1);
	output(L2);
	return 0;
}
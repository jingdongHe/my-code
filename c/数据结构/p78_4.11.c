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
	struct node *current,*p,*head;
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
}
int size(struct node *head)
{
	int n=0;
	struct node *p;
	p=head->next;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
struct node *reb_list(struct node *head1,struct node *head2)
{
	struct node *p1,*p2,*parent,*current,*px;
	p1=head1->next;parent=head1;p2=head2->next;
	while(p1!=NULL&&p2!=NULL)
	{
		p1->d=p2->d;
		parent=p1;
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==NULL&&p2==NULL)
		return head1;
	if(p1==NULL)
	{
		while(p2!=NULL)
		{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=p2->d;
		current->next=NULL;
		parent->next=current;
		parent=parent->next;
		p2=p2->next;
		}
		return head2;
	}
	if(p2==NULL)
	{
		current=parent->next;
		px=current->next;
		parent->next=NULL;
		free(current);
		current=px;
		while(current!=NULL)
		{
			current=px->next;
			free(px);
		}
		return head1;
	}
	return head1;
}
void equal(struct node *head1,struct node *head2)
{
	struct node *p1,*p2;
	p1=head1->next;p2=head2->next;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->d!=p2->d)
		{
			printf("NO\n");
			return;
		}
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==NULL&&p2==NULL)
	{
		printf("YES\n");
		return ;
	}
	else
	{
		printf("NO\n");
		return;
	}
}
struct node *link(struct node *head1,struct node *head2)
{
	struct node *p1,*p2;
	p1=head1;p2=head2->next;
	while(p1->next!=NULL)
		p1=p1->next;
	p1->next=p2;
	return head1;
}
void FL(struct node *head1,struct node *head2)
{
	struct node *p1,*p2,*px;
	int n=1;
	p1=head1->next;p2=head2->next;
	px=p1;
	while(px!=NULL)
	{
		if(px->d==p2->d)
		{px=px->next;p2=p2->next;
		if(p2==NULL)
		{
			printf("%d\n",n);
			return ;
		}
		if(px==NULL)
		{
			printf("no\n");
			return;
		}
		}
		if(px->d!=p2->d)
		{
			px=p1->next;
			p1=p1->next;
			n++;
			p2=head2->next;
		}
	}
	printf("no\n");
}
void main()
{
	struct node *p1,*p2;
	p1=b_list();
	p2=b_list();
	output(p1);
	output(p2);
	FL(p1,p2);
}

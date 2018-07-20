#include<stdio.h>
#include<stdlib.h>
struct node
{
	char d;
	int freq;
	struct node *pre,*next;
};
struct node *b_list()
{
	char d;
	struct node *head,*current,*p;
	head=(struct node *)malloc(sizeof(struct node));
	head->pre=NULL;head->next=NULL;p=head;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->freq=0;
		current->next=p->next;
		if(p->next!=NULL)
			p->next->pre=current;
		current->pre=p;
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
struct node *listlocate(struct node *head,char x)
{
	struct node *p,*px;
	p=head->next;px=head;
	while(p!=NULL)
	{
		if(p->d==x)
		{px=p;px->freq++;break;}
		p=p->next;
	}
	if(px!=head)
	{
		px->pre->next=px->next;
		px->next->pre=px->pre;//px已被提出
		p=head->next;
		while(p->freq>px->d)
		{
			p=p->next;
			if(p==NULL)
				break;
		}
		if(p==NULL)
		{
			p->pre->next=px;
			px->next=NULL;
			px->pre=p->pre;
		}
		else
		{
			p->pre->next=px;
			px->pre=p->pre;
			p->pre=px;
			px->next=p;
		}
	}
	else
	{
		px=(struct node *)malloc(sizeof(struct node));
		px->d=x;
		px->freq=0;
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=px;
		px->pre=p;
		px->next=NULL;
	}
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	output(L);
	L=listlocate(L,'8');
	output(L);
	return;
}

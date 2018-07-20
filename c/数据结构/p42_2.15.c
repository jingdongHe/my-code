#include<stdio.h>
#include<stdlib.h>
struct node {
	int d;
	struct node *next;
};
struct node *b_list()
{
	char d;
	struct node *head,*current,*p;
	head=(struct node *)malloc(sizeof(struct node));
	p=head;
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
	return;
}
struct node *mix(struct node *a,struct node *b)
{
	struct node *pa,*pb,*pd,*parent_a,*parent_b;
	pa=a->next;pb=b->next;parent_a=a;parent_b=b;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->d>pb->d)//pb移动
		{
			pd=pb;
			parent_b->next=pb->next;
			pb=pb->next;
			free(pd);
		}
		if(pa->d<pb->d)//pa移动
		{
			pd=pa;
			parent_a->next=pa->next;
			pa=pa->next;
			free(pd);
		}
		if(pa->d==pb->d)//pa,pb同时移动
		{
			parent_a=pa;
			pa=pa->next;
			parent_b=pb;
			pb=pb->next;
		}
	}
	while(pa!=NULL)
	{
		pd=pa;
		parent_a->next=pa->next;
		pa=pa->next;
		free(pd);
	}
	return a;
}
struct node *sum(struct node *a,struct node *b)
{
	struct node *pa,*pb,*p,*head,*pd,*current;
	pa=a->next;pb=b->next;
	head=(struct node *)malloc(sizeof(struct node));
	p=head;
	while(pa!=NULL&&pb!=NULL)
	{
		current=(struct node *)malloc(sizeof(struct node));
		if(pa->d==pb->d)
		{
			current->d=pa->d;
			p->next=current;
			p=current;
			pd=pa;
			pa=pa->next;
			free(pd);
			current=(struct node *)malloc(sizeof(struct node));
			current->d=pb->d;
			p->next=current;
			p=current;
			pd=pb;
			pb=pb->next;
			free(pd);
			continue;
		}
		if(pa->d<pb->d)
		{
			current->d=pa->d;
			p->next=current;
			p=current;
			pd=pa;
			pa=pa->next;
			free(pd);
			continue;
		}
		if(pa->d>pb->d)
		{
			current->d=pb->d;
			p->next=current;
			p=current;
			pd=pb;
			pb=pb->next;
			free(pd);
			continue;
		}
	}
	if(pa==NULL)
		p->next=pb;
	if(pb==NULL)
		p->next=pa;
	return head;
}
void main()
{
	struct node *a,*b,*c,*L;
	a=b_list();
	b=b_list();
	c=b_list();
	printf("----------------------------\n");
	output(a);
	output(b);
	output(c);
	printf("----------------------------\n");
	L=sum(c,mix(a,b));
	output(L);
	return;
}

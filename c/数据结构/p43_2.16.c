#include<stdio.h>
#include<stdlib.h>
struct node {
	int d;
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
struct node *sum(struct node *a,struct node *b)
{
	struct node *pa,*pb,*p,*px;
	p=a;pa=a->next;pb=b->next;
	while(pb->d>p->d&&pb->d<=p->next->d)
	{
		px=pb;
		pb=pb->next;
		px->next=p->next;
		p->next=px;
		p=px;
		if(pb==NULL)
			break;
	}//经历了循环后，pb已大于最小的pa
	while(1)
	{
		if(pb==NULL||pa==NULL)
			break;
		while(pa->next!=NULL&&pb->d>pa->d&&pb->d<=pa->next->d)
		{
			
			px=pb;
			pb=pb->next;
			px->next=pa->next;
			pa->next=px;
			p=pa;
			pa=px;
			if(pb==NULL)
				break;
		}
		if(pb==NULL)
			break;
		while(pa->d<pb->d)
		{
			p=pa;
			pa=pa->next;
			if(pa==NULL)
				break;
		}
		if(pa==NULL)
			break;
		if(pa->next==NULL)
		{pa->next=pb;break;}
	}
	if(pa==NULL)
	{
		p->next=pb;
	}
	return a;
}
void main()
{
	struct node *a,*b,*L;
	a=b_list();
	b=b_list();
	output(a);
	output(b);
	L=sum(a,b);
	output(L);
	return;
}
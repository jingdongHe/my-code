#include<stdio.h>
#include<stdlib.h>
struct node {
	char a;
	struct node *next;
};
struct node *b_list()
{
	struct node *current,*head,*p;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;
	p=head;
	printf("Please entry the list\n");
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->a=d;
		current->next=NULL;
		p->next=current;
		p=p->next;
		d=getchar();
	}
	return head;
}
struct node *merge(struct node *ha,struct node *hb)
{
	struct node *pa,*pb,*p,*px;
	pa=ha->next;pb=hb->next;p=ha;//p为pa的前指针
	while(pa->next!=NULL&&pb!=NULL)//指向尾部
	{
		if(pa->a==p->a)
		{
			px=pa;
			p->next=pa->next;
			pa=pa->next;
			free(px);
			continue;
		}
		if(pa->a>pb->a)
		{
			if(pb->a==p->a)
			{
				px=pb;
				pb=pb->next;
				free(px);
			}
			else
			{
				px=pb;
				pb=pb->next;
				px->next=pa;
				p->next=px;
				p=p->next;
				
			}
		}
		else
		{
			p=pa;
			pa=pa->next;
		}
	}
	if(pa->next==NULL)
	{
		while(p->a==pb->a&&pb->next!=NULL)
			pb=pb->next;
		while(pa->a==pb->a&&pb->next!=NULL)
			pb=pb->next;
		if(pa->a!=pb->a)
			pa->next=pb;
		else
			pa->next=NULL;
	}
	
	return ha;
}
void output(struct node *head)
{
	struct node *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%c",p->a);
		p=p->next;
	}
	printf("\n");
}
void main()
{
	struct node *ha,*hb,*hc;
	ha=b_list();
	hb=b_list();
	output(ha);
	output(hb);
	hc=merge(ha,hb);
	
	output(hc);
	return;
}



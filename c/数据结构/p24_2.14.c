#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *pre,*next;
	char d;
};
struct node *b_list()
{
	struct node *head,*current,*p;char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;head->pre=NULL;p=head;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		if(p->next!=NULL)
			p->next->pre=current;
		current->next=p->next;
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
	return;
}
struct node *remake(struct node *head)
{
	struct node *ph,*pr,*px,*pe;
	int i=1;
	ph=pr=head->next;
	while(pr->next!=NULL)
	{
		pr=pr->next;
	}
	pe=pr;
	while(ph!=pe)
	{
		if(i%2==0)
		{
			printf("%c  ",ph->d);
			px=ph;
			ph->pre->next=ph->next;
			ph->next->pre=ph->pre;
			ph=ph->next;
			i++;//½«phÌá³ö
			px->next=pr->next;
			px->pre=pr;
			if(pr->next!=NULL)
				pr->next->pre=px;
			pr->next=px;
		}
		else
		{
			i++;
			ph=ph->next;
		}
	}
	return head;
}
void main()
{
	struct node *L;
	L=b_list();
	output(L);
	L=remake(L);
	output(L);
	return;
}

			


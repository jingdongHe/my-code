#include<stdio.h>
#include<stdlib.h>
struct node
{
	char d;
	struct node *next;
};
struct node *b_link()
{
	char d;
	struct node *current,*head;
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
struct node *d_same(struct node *head)
{
	struct node *p,*pre,*sign,*u;
	sign=head->next;
	while(sign!=NULL)
	{
		pre=sign;
		p=pre->next;
		while(p!=NULL)
		{
			if(p->d==sign->d)
			{pre->next=p->next;u=p;p=p->next;free(u);}
			else
			{pre=p;p=p->next;}
		}
		sign=sign->next;
	}
	return head;
}
int main()
{
	struct node *L;
	L=b_link();
	output(L);
	L=d_same(L);
	output(L);
	return 0;
}


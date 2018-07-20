#include<stdio.h>
#include<stdlib.h>
struct node {
	char d;
	struct node *pre,*next;
};
struct node *b_list()
{
	struct node *current,*head,*p;
	char d;
	head=(struct node *)malloc(sizeof(struct node));
	head->next=NULL;head->pre=NULL;
	p=head;
	d=getchar();
	while(d!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=d;
		current->next=p->next;
		current->pre=p;
		p->next=current;
		p=p->next;
		d=getchar();
	}
	/*while(p!=head)
	{
		printf("%c",p->d);
		p=p->pre;
	}*/
	return head;
}
struct node *d_increase(struct node *head)
{
	struct node *p,*p1;
	while(head->next!=NULL)
	{
		p=p1=head->next;
		while(p!=NULL)
		{
			if(p1->d>p->d)
				p1=p;
			p=p->next;
		}//经循环后p1指向最小的位置
		p1->pre->next=p1->next;
		if(p1->next!=NULL)
			p1->next->pre=p1->pre;
		printf("%c ",p1->d);
		free(p1);
		
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
int main()
{
	struct node *L;
	L=b_list();
	//output(L);
	L=d_increase(L);
	return 0;
}

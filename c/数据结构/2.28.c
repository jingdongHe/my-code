#include<stdio.h>
#include<stdlib.h>
struct node {
	int d;
	struct node *next;
};
struct node *b_link()
{
	char a;
	struct node *l,*current;
	l=(struct node *)malloc(sizeof(struct node));
	l->next=NULL;
	a=getchar();
	while(a!='\n')
	{
		current=(struct node *)malloc(sizeof(struct node));
		current->d=a;
		current->next=l->next;
		l->next=current;
		a=getchar();
	}
	return l;
}
void output(struct node *l)
{
	struct node *p;
	p=l->next;
	while(p!=NULL)
	{
		printf("%c",p->d);
		p=p->next;
	}
	printf("\n");
}
struct node *invert(struct node *l)
{
	struct node *p,*p1;
	p=l->next;
	l->next=NULL;
	while(p!=NULL)
	{
		p1=p->next;
		p->next=l->next;
		l->next=p;
		p=p1;
	}
	return l;
}
int main()
{
	struct node *L;
	L=b_link();
	output(L);
	L=invert(L);
	output(L);
	L=invert(L);
	output(L);
	return 0;
}
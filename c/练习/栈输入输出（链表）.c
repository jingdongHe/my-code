#include<stdio.h>
#include<stdlib.h>
struct node{
	int d;
	struct node *next;
};
struct node *head=NULL,*p,*current;
void push()
{
	current=(struct node *)malloc(sizeof(struct node));
	current->next=NULL;
	printf("please entry push number:\n");
	scanf("%d",&current->d);
	getchar();
	if(head==NULL)
		head=current;
	else 
		p->next=current;
	p=current;
}
void output()
{
	p=head;
	while(p!=NULL)
	{
		printf("%d  ",p->d);
		p=p->next;
	}
	printf("\n");
}
void pop()
{
	p=head;
	while(p->next->next!=NULL)
		p=p->next;
	current=p->next;
	p->next=NULL;
	free(current);
}
void top()
{
	p=head;
	while(p->next!=NULL)
		p=p->next;
	printf("%d\n",p->d);
}
int main()
{
	push();
	push();
	push();
	push();
	output();
	top();
	pop();
	top();
	output();
	return 0;
}

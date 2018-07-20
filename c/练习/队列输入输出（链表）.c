#include<stdio.h>
#include<stdlib.h>
struct node
{
	int i;
	struct node *next;
};
struct node *current,*p,*head=NULL;
void enqueue()
{
	current=(struct node *)malloc(sizeof(struct node));
	printf("please entry number:\n");
	scanf("%d",&current->i);
	current->next=NULL;
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
		printf("%d ",p->i);
		p=p->next;
	}
	printf("\n");
}
void dequeue()
{
	current=head;
	head=head->next;
	free(current);
}
void front()
{
	printf("%d\n",head->i);
}
int main()
{
	enqueue();
	enqueue();
	enqueue();
	enqueue();
	output();
	dequeue();
	output();
	front();
	return 0;
}
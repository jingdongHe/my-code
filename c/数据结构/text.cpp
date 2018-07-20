#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node {
	int number;
	struct node *next;
}node;
class Link{
private:
	node *head,*p;
public:
	void init()
	{
		head=(node *)malloc(sizeof(node));
		head->next=NULL;head->number=0;
		p=head;
	}
	void insert()
	{
		node *temp=(node *)malloc(sizeof(node));
		temp->next=NULL;
		scanf("%d",&temp->number);
		p->next=temp;
		p=p->next;
		return ;
	}
	void print()
	{
		node *temp=head;
		while(temp->next!=NULL)
		{
			printf("%d->",temp->number);
			temp=temp->next;
		}
		printf("%d\n",temp->number);
		return;
	}
};
int main()
{
	Link l;
	l.init();
	l.insert();
	l.insert();
	l.insert();
	l.print();
	return 0;
}
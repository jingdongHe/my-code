#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
const int maxn=1500+5;
int main()
{
	node head[maxn];
	int n;
	scanf("%d",&n);getchar();
	for(int i=0;i<n;i++)
	{
		int d;
		char ch=' ';
		head[i].next=NULL;
		while(ch!='\n')
		{
			scanf("%d",&d);ch=getchar();
			node *temp;
			temp=(node *)malloc(sizeof(node));
			temp->data=d;
			temp->next=head[i].next;
			head[i].next=temp;
		}
		
	}
	
	for(int i=0;i<n;i++)
	{
		node *temp;
		temp=head[i].next;
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	return 0;
}

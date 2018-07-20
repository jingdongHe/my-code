#include<stdio.h>
#include<malloc.h>
typedef struct array{
	char i;
	struct array *next;
}array;
int main()
{
	struct array *head=NULL,*prve,*h;
	h=(array*)malloc(sizeof(array));
	while(h!=NULL)
	{
		h=(array*)malloc(sizeof(array));
		h->i=getchar();
		if(head==NULL)
		{
			head=h;
			h->next=NULL;
		}
		else
		{
			h->next=h;
			h->next=NULL;
		}
	}
	prve=head;
	while(prve!=NULL)
	{
		printf("%c",prve->i);
		prve=prve->next;
	}
	return 0;
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct array{
	int a;
	struct array *next;
};
int main()
{
	int a,b,n,j;
	struct array*head=NULL,*p,*now,*c1,*c2;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF)
	{
		getchar();
		for(j=0;j<2;j++)
		{
			now=(struct array *)malloc(sizeof(struct array));
			now->a=1;
			if(head==NULL)
				head=now;
			else
				p->next=now;
			now->next=NULL;
			p=now;
		}
		c1=head;c2=p;
		for(j=2;j<n;j++)
		{
			now=(struct array *)malloc(sizeof(struct array));
			p->next=now;
			now->a=(a*(c1->a)+b*(c2->a))%7;
			c1=c1->next;
			c2=c2->next;
			now->next=NULL;
		//	printf("%d   %d",c1->a,c2->a);
		}
		printf("%d\n",now->a);
		now=head;
		while(now!=NULL)
		{
			p=now;
			now=now->next;
			free(p);
		}
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct node {
	int m,w;
	char name[20];
	struct node *next;
}player;
void output(player *p)
{
	player *px;
	px=p->next;
	if(px==NULL)
		printf("NULL\n");
	else
	{
		printf("%s",px->name);
		px=px->next;
		while(px!=NULL)
		{
			printf("->%s",px->name);
			px=px->next;
		}
		printf("\n");
	}
}
void push(player *p)
{
	player *px,*p1;
	p1=p;
	while(p1->next!=NULL)
		p1=p1->next;
//	
	px=(player *)malloc(sizeof(player));
	//
	scanf("%s%d%d",&px->name,&px->m,&px->w);getchar();
	//printf("3333333333\n");
	px->next=NULL;
	
	p1->next=px;//
	output(p);
}
void out(player *p,char a[])
{
	player *px,*pp;
	pp=p;
	px=p->next;
	while(px!=NULL)
	{
		//printf("%s....%s\n",px->name,a);
		if(strcmp(px->name,a)==0)
		{
			pp->next=px->next;
			free(px);
			output(p);
			return;
		}
		pp=px;
		px=px->next;
	}
	output(p);
}
int cal(player *p)
{
	int d=0;
	player *pi,*pj;
	if(p->name==NULL)
		return -1;
	else
		pi=p->next;
	if(pi==NULL)
	{return -1;}
	else
	{
		if(pi->next==NULL)
		{return 0;}
		else
		{
			while(pi!=NULL)
			{
				pj=pi->next;
				while(pj!=NULL)
				{
					if(d<(abs(pi->m-pj->m)+abs(pi->w-pj->w)))
						d=abs(pi->m-pj->m)+abs(pi->w-pj->w);
					pj=pj->next;
				}
				pi=pi->next;
			}
		}
	}
	return d;
}
void main()
{
	int n,i;
	int a;
	int k=0,d;
	char name[20]={'\0'};
	player *p;
	printf("please entry the AARP\n");
	scanf("%d",&n);getchar();
	p=(player *)malloc(sizeof(player));
	p->next=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);getchar();
		if(a==1)
		{
			push(p);
		}
		if(a==2)
		{
			scanf("%s",&name);
			out(p,name);
		}
		d=cal(p);
		if(k<d)
			k=d;
		printf("%d.....\n",d);
	}
	printf("\n%d\n",k);
}
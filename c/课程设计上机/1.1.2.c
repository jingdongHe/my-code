/*　分别实现顺序表和单链表完成线性表的基本操作：
　　　初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、遍历线性表、从线性表中查找元素、
从线性表中查找与给定元素值相同的元素在线性表中的位置、插入元素、删除元素。*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node *next;
}node;
node *Initialization()
{
	node *p,*px,*head;
	char d;
	p=(node *)malloc(sizeof(node));
	p->next=NULL;
	head=p;
	printf("please entry the link(end for \'\\n\')\n");
	d=getchar();
	while(d!='\n')
	{
		px=(node *)malloc(sizeof(node));
		px->next=NULL;
		px->data=d;
		p->next=px;
		p=p->next;
		d=getchar();
	}
	return head;
}
void Empty(node *head)
{
	node *px,*pd;
	px=head->next;
	head->next=NULL;
	while(px!=NULL)
	{
		pd=px;
		px=px->next;
		free(pd);
	}
}
int getlength(node *head)
{
	node *p;
	int d=0;
	p=head->next;
	while(p!=NULL)
	{
		d++;
		p=p->next;
	}
	return d;
}
void Traversal(node *head)
{
	node *p;
	p=head->next;
	if(p==NULL)
	{
		printf("empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
int is_empty(node *head)
{
	if(head->next==NULL)
		return 1;
	return 0;
}
int find(node *head,char a)
{
	node *p;
	int d=0;
	p=head->next;
	while(p!=NULL)
	{
		d++;
		if(p->data==a)
			return d;
		p=p->next;
	}
	return -1;
}
void insert(node *head,char a,int d)
{
	int i;
	node *p,*px;
	if(d>getlength(head))
	{
		printf("no enough space\n");
		return;
	}
	px=(node *)malloc(sizeof(node));
	px->data=a;
	p=head->next;
	for(i=1;i<d;i++)
		p=p->next;
	px->next=p->next;
	p->next=px;
}
void del(node *head,char a)
{
	node *p,*pd,*pp;
	p=head->next;
	pp=head;
	while(p!=NULL)
	{
		if(p->data==a)
		{
			pp->next=p->next;
			pd=p;
			p=p->next;
			free(pd);
		}
		else
		{
			pp=p;
			p=p->next;
		}
	}
}
int main()
{
	node *p;
	char a;
	int d;
	p=Initialization();
	//Empty(p);
	printf("%d\n",getlength(p));
	Traversal(p);
	if(is_empty(p))
		printf("empty\n");
	else
		printf("noempty\n");
	printf("please entry the element for find\n");
	a=getchar();
	d=find(p,a);getchar();
	if(d!=-1)
		printf("%c in %d\n",a,d);
	else
		printf("the element is not in this array\n");
	printf("please entry the \'a\' and the loca where insert the \'a\' \n");
	a=getchar();scanf("%d",&d);getchar();
	insert(p,a,d);
	Traversal(p);
	printf("please entry the element for delete\n");
	a=getchar();
	del(p,a);
	Traversal(p);
	return 0;
}
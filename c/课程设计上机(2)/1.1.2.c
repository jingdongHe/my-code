/*���ֱ�ʵ��˳���͵�����������Ա�Ļ���������
��������ʼ�����Ա�������Ա������Ա��ȡ�������Ա��Ƿ�Ϊ�ա��������Ա������Ա��в���Ԫ�ء�
�����Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա��е�λ�á�����Ԫ�ء�ɾ��Ԫ�ء�*/
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
	printf("����������,�Ե�һ�Ŀո����\n");
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
	int d,k;
	while(1)
	{
	p=Initialization();
	if(p->next->data==' '&&p->next->next==NULL)
		break;
	while(1)
	{
		printf("���������\n1����˳���ĳ���\n2���ж�˳����Ƿ�Ϊ��\n3������˳���\n4������Ԫ��\n5������Ԫ��\n6��ɾ��Ԫ��\n7��������Ա�\n����0����\n");
		scanf("%d",&k);getchar();
		if(k==0)
			break;
		switch(k)
		{
			case 7:Empty(p);break;
			case 1:
				    printf("%d\n",getlength(p));
					Traversal(p);
			case 2:
					if(is_empty(p))
						printf("��\n");
					else
						printf("����\n");
					break;
			case 3: Traversal(p);break;
			case 4:
					printf("��������Ҫ���ҵ�Ԫ��\n");
					a=getchar();
					d=find(p,a);getchar();
					if(d!=-1)
						printf("%c in %d\n",a,d);
					else
						printf("�����Ԫ�ز���������\n");
					break;
			case 5:
					printf("������Ԫ�� \'a\' ��Ԫ�� \'a\'�����λ�� \n");
					a=getchar();scanf("%d",&d);getchar();
					insert(p,a,d);
					Traversal(p);
					break;
			case 6:
					printf("��������Ҫɾ����Ԫ��\n");
					a=getchar();
					del(p,a);
					Traversal(p);
					break;
		}
	}
	}
	return 0;
}
/*2��Լɪ�����⣺�θ�������N��K���������������Եõ�1,2, ��,n��һ���û���
������1,2,��,n�������У���˳ʱ�뷽����1��ʼ����������Kʱ�����λ���ϵ����֣�
��ʹ����С�Ȼ�������˳ʱ�뷽�����һ�����ּ��������������ȥ��
ֱ�����е�����ȫ������Ϊֹ������N=10��K=3������ȷ�ĳ���˳��ӦΪ3��6��9��2��7��1��8��5��10��4��*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
node *b_circl(int d)
{
	node *p,*px,*head;
	int i;
	px=(node *)malloc(sizeof(node));
	px->data=1;
	head=p=px;
	for(i=2;i<=d;i++)
	{
		px=(node *)malloc(sizeof(node));
		px->data=i;
		p->next=px;
		p=p->next;
	}
	p->next=head;
	return head;
}
void print(node *head,int k)
{
	int i=0;
	node *p,*pp,*pd;
	pp=head;
	while(pp->next!=head)
		pp=pp->next;
	p=head;
	while(p->next!=p)
	{
		i++;
		if(i==k)
		{
			printf("%d ",p->data);
			pp->next=p->next;
			pd=p;
			p=p->next;
			free(pd);
			i=0;
		}
		else
		{
			pp=p;
			p=p->next;
		}
	}
	printf("%d\n",p->data);
}
int main()
{
	int n,k;
	node *p;
	scanf("%d%d",&n,&k);
	p=b_circl(n);
	print(p,k);
}

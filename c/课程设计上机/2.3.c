/*����3�����������͹��������룺ĳͨ�ŵ����ɣ����¡��á��ġ��š��������ַ���ɣ�
�����ڵ����г��ֵĴ����ֱ���40��12��17��8��20��3���������������������Ӧ�Ĺ��������롣*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node *lchild,*rchild;
}node;
typedef struct {
	char data;
	int d;
}num;
void Sort(num a[])
{
	num k;
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=i+1;j<6;j++)
		{
			if(a[i].d<a[j].d)
			{k=a[i];a[i]=a[j];a[j]=k;}
		}
	}
}
void build(node *head,num a[])
{
	node *p,*px,*py;
	int i;
	p=head;
	for(i=0;i<5;i++)
	{
		px=(node *)malloc(sizeof(node));
		px->data=a[i].data;
		px->lchild=px->rchild=NULL;
		py=(node *)malloc(sizeof(node));
		py->lchild=py->rchild=NULL;
		p->lchild=px;p->rchild=py;
		p=p->rchild;
	}
	p->data=a[i].data;
}
void print(node *head)
{
	char a[10]={'\0'};
	int i=0;
	node *p=head;
	while(p->rchild!=NULL)
	{
		printf("%c:",p->lchild->data);
		a[i]='0';puts(a);a[i]='\0';
		p=p->rchild;
		a[i++]='1';
	}
	printf("%c:",p->data);puts(a);
}
void main()
{
	num a[]={{'A',40},{'B',12},{'C',17},{'D',8},{'E',20},{'F',3}};
	//a[0].d=40;a[0].data=
	node *p;int i;
	p=(node *)malloc(sizeof(node));
	p->lchild=p->rchild=NULL;
	Sort(a);
	printf("Huffman tree preorder traversal is :\n");
	for(i=0;i<6;i++)
		printf("%c",a[i].data);
	printf("\n");
	build(p,a);
	print(p);
	
}
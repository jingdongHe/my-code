/*��1������һ�������ַ�������������ȶ���г����
��1��������һ���ж������ַ����Ƿ�Ϊ�����ַ����ĺ�����
���ڳ�n���ַ������䳤Ϊs���Ӵ���n-s+1����
��1���Ӵ�n����Ȼ���룬�ٶ�s��2��n���������Ӵ�������*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 10
typedef struct node{
	char data;
	struct node *next;
}node;
int huiwei(char a[])
{
	int i,k;
	k=strlen(a);
	for(i=0;i<k/2+1;i++)
	{
		if(a[i]!=a[k-1-i])
			return 0;
	}
	return 1;
}
int Break(char a[])
{
	int i,j,k,r,d=0;
	char b[n]={'\0'};
	k=strlen(a);
	for(i=1;i<=k;i++)//�������ַ������ȣ���ÿ���ִ��Ĵ���Ϊi
	{
		for(j=0;j<k-i+1;j++)//�ӵ�j��λ�ÿ�ʼ����
		{
			for(r=0;r<i;r++)//�ַ�������
				b[r]=a[j+r];
			if(huiwei(b)==1)
			{
				d++;
				//puts(b);
			}
			memset(b,'\0',sizeof(b));
		}
	}
	return d;
}
int in(node *p,char a)
{
	node *px;
	px=p->next;
	//printf("%c......",p->data);
	while(px!=NULL)
	{
		
		if(px->data==a)
			return 1;
		//printf("00000000\n");
		if(px->next==NULL)
			return 0;
	//	printf("999999999999\n");
		px=px->next;
		//printf("88888888\n");
	}
	return 0;
}
void push(node *p,char a)
{
	node *px,*p1;
	p1=p;
	px=(node *)malloc(sizeof(node));
	px->next=NULL;
	px->data=a;
	while(p1->next!=NULL)
		p1=p1->next;
	p1->next=px;
}
int max_break(char a[])
{
	int k,i,d=0;
	char t;
	node *p,*head;
	p=(node *)malloc(sizeof(node));
	p->next=NULL;
	k=strlen(a);
	for(i=0;i<k;i++)
	{
		if(in(p,a[i])==0)
			push(p,a[i]);
	}
	//;//
	head=p;
	/*while(p->next!=NULL)
	{
		printf("%c ",p->next->data);
		p=p->next;
	}*/
	for(i=0;i<k;i++)
	{
		//printf("22222222\n");
		p=head->next;
		while(p!=NULL)
		{
			//printf("%c\n",p->data);
			if(a[i]==p->data)
			{p=p->next;continue;}
			t=a[i];
			a[i]=p->data;
			d=d>Break(a)?d:Break(a);
			a[i]=t;
			p=p->next;
		}
	}
	return d;
}
void main()
{
	char a[n];
	int d,k;
	printf("�������ַ���\n");
	scanf("%s",&a);getchar();
	while(a!=EOF)
	{
	d=Break(a);
	printf("�ȶ���г��Ϊ%d\n",d);
	k=max_break(a);
	printf("�޸ĺ��ȶ���г��Ϊ%d\n",k);
	printf("�������ַ���\n");
	scanf("%s",&a);getchar();
	}
}
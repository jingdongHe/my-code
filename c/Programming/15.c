#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	char english[10];
	char china[20];
}node;
typedef struct {
	node *a[7];
}keyword;
void intialize(keyword *k)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"int");
	strcpy(p->china,"���ͱ���");
	k->a[0]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"auto");
	strcpy(p->china,"�����Զ�����");
	k->a[1]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"long");
	strcpy(p->china,"������");
	k->a[2]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"double");
	strcpy(p->china,"˫����");
	k->a[3]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"unsigned");
	strcpy(p->china,"�޷���");
	k->a[4]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"break");
	strcpy(p->china,"������ǰѭ��");
	k->a[5]=p;
	p=(node *)malloc(sizeof(node));
	strcpy(p->english,"continue");
	strcpy(p->china,"��ʼ��һ��ѭ��");
	k->a[6]=p;
}
void translat(keyword *k,char a[])
{
	
	int i;
	if(a[0]>='a'&&a[0]<='z')//ΪӢ���ַ�
	{
		for(i=0;i<7;i++)
		{
			//printf("%s",k->a[i]->english);
			if(strcmp(a,k->a[i]->english)==0)
			{puts(k->a[i]->china);return;}
		}
	}
	else
	{
		for(i=0;i<7;i++)
		{
			if(strcmp(a,k->a[i]->china)==0)
			{puts(k->a[i]->english);return;}
		}
	}
}
void main()
{
	char a[20]={'\0'};
	int i;
	keyword *k;
	k=(keyword *)malloc(sizeof(keyword));
	intialize(k);	
	printf("��������Ҫ����Ĺؼ���,����bye����\n");
	scanf("%s",&a);getchar();
	while(strcmp(a,"bye")!=0)
	{
		translat(k,a);
		printf("��������Ҫ����Ĺؼ���,����bye����\n");
		for(i=0;i<20;i++)
			a[i]='\0';
		gets(a);
	}
}
/*���ֱ�ʵ��˳���͵�����������Ա�Ļ���������
��������ʼ�����Ա�������Ա������Ա��ȡ�������Ա��Ƿ�Ϊ�ա��������Ա�
�����Ա��в���Ԫ�ء������Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա��е�λ�á�����Ԫ�ء�ɾ��Ԫ�ء�*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
//˳���ʵ�����Ա�Ļ�������,�������ַ�����Ϊ��
void Initialization(char *p)
{
	memset(p,'\0',sizeof(p));
	printf("���������ݣ��Ե�һ�Ŀո����\n");
	gets(p);
}
void Empty(char *p)
{
	memset(p,'\0',sizeof(p));
}
int getlength(char *p)
{
	return strlen(p);
}
int is_empty(char *p)
{
	int i;
	for(i=0;i<getlength(p);i++)
		if(p[i]!='\0')
			return 0;
	return 1;
}
void Traversal(char *p)
{
	int i;
	for(i=0;i<getlength(p);i++)
		printf("%c",p[i]);
	printf("\n");
}
int find(char *p,char a)
{
	int i;
	for(i=0;i<getlength(p);i++)
		if(p[i]==a)
			return i+1;
	return -1;
}
void insert(char *p,char a,int d)
{
	char data;
	if(d>getlength(p))
	{
		printf("û���㹻�Ŀռ�\n");
		return;
	}
	for(;d<=getlength(p);d++)
	{
		data=p[d];
		p[d]=a;
		a=data;
	}
}
void del(char *p,char a)
{
	int i,d;
	for(i=0;i<getlength(p);i++)
	{
		if(p[i]==a)
		{
			for(d=i;d<getlength(p)-1;d++)
				p[d]=p[d+1];
			p[d]='\0';
			i--;
		}
	}
}
int main()
{
	char *p;
	char array[M];
	char a;
	char d;
	int k;
	p=array;
	while(1)
	{
		Initialization(p);
		if(p[0]==' '&&p[1]=='\0')
			break;
		while(1)
		{
			printf("���������\n1����˳���ĳ���\n2���ж�˳����Ƿ�Ϊ��\n3������˳���\n4������Ԫ��\n5������Ԫ��\n6��ɾ��Ԫ��\n7��������Ա�\n����0����\n");
			scanf("%d",&k);getchar();
			if(k==0)
				break;
			switch(k)
			{
				case 1:printf("˳���ĳ���Ϊ %d\n",getlength(p));break;
				case 2:
					if(is_empty(p))
						printf("��\n");
					else
						printf("����\n");
					break;
				case 3:
					printf("�����Ľ��Ϊ:");
					Traversal(p);
					break;
				case 4:
					printf("����������Ѱ�ҵ�Ԫ��\n");
					a=getchar();getchar();
					d=find(p,a);
					if(d!=-1)
						printf("%c �ڵ� %dλ\n",a,d);
					else
						printf("Ԫ�ز���˳�����\n");
					break;
				case 5:
					printf("������Ԫ�� \'a\' ��Ԫ�� \'a\' Ӧ�ò����λ��\n");
					a=getchar();scanf("%d",&d);
					insert(p,a,d);
					puts(p);getchar();
					break;
				case 6:
					printf("����������ɾ����Ԫ��\n");
					a=getchar();getchar();
					del(p,a);
					puts(p);
					break;
				case 7:
					Empty(p);
					break;
			}
		}
	}
	return 0;
}
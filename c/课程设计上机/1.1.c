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
	printf("please entry the content\n");
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
		printf("not enough space\n");
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
	p=array;
	Initialization(p);
	//puts(p);
	//Empty(p);
	//puts(p);
	printf("the length of the array is %d\n",getlength(p));
	if(is_empty(p))
		printf("empty\n");
	else
		printf("noempty\n");
	printf("the result of traversal is:");
	Traversal(p);
	printf("please entry the element for find\n");
	a=getchar();getchar();
	d=find(p,a);
	if(d!=-1)
		printf("%c in %d\n",a,d);
	else
		printf("the element is not in this array\n");
	printf("please entry the \'a\' and the loca where insert the \'a\' \n");
	a=getchar();scanf("%d",&d);
	insert(p,a,d);
	puts(p);getchar();
	printf("please entry the element for delete\n");
	a=getchar();
	del(p,a);
	puts(p);
	return 0;
}
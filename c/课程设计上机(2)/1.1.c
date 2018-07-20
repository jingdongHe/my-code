/*　分别实现顺序表和单链表完成线性表的基本操作：
　　　初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、遍历线性表、
从线性表中查找元素、从线性表中查找与给定元素值相同的元素在线性表中的位置、插入元素、删除元素。*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
//顺序表实现线性表的基本操作,以下以字符数组为例
void Initialization(char *p)
{
	memset(p,'\0',sizeof(p));
	printf("请输入内容，以单一的空格结束\n");
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
		printf("没有足够的空间\n");
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
			printf("请输入操作\n1、求顺序表的长度\n2、判断顺序表是否为空\n3、遍历顺序表\n4、查找元素\n5、插入元素\n6、删除元素\n7、清空线性表\n输入0结束\n");
			scanf("%d",&k);getchar();
			if(k==0)
				break;
			switch(k)
			{
				case 1:printf("顺序表的长度为 %d\n",getlength(p));break;
				case 2:
					if(is_empty(p))
						printf("空\n");
					else
						printf("不空\n");
					break;
				case 3:
					printf("遍历的结果为:");
					Traversal(p);
					break;
				case 4:
					printf("请输入你想寻找的元素\n");
					a=getchar();getchar();
					d=find(p,a);
					if(d!=-1)
						printf("%c 在第 %d位\n",a,d);
					else
						printf("元素不在顺序表中\n");
					break;
				case 5:
					printf("请输入元素 \'a\' 和元素 \'a\' 应该插入的位置\n");
					a=getchar();scanf("%d",&d);
					insert(p,a,d);
					puts(p);getchar();
					break;
				case 6:
					printf("请输入你想删除的元素\n");
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
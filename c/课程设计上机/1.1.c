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
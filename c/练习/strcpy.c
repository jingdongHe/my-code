#include<stdio.h>
#include<string.h>
#define n 10
int main()
{
	char a[9],b[1];//����b�����󣬶��ܰ�aȫ��¼�룬����'\0'����a���������'\0'һ������ռ�
	gets(a);
	strcpy(b,a);
	puts(b);
	return 0;
}
#include<stdio.h>
main()
{
int x;
scanf("%d",&x);
while(0!=x)
{
switch(x)
{
case 1: printf("1");break;
case 2: printf("2");break;
case 3: printf("3");break;
default :printf("4");break;
}
scanf("%d",&x);   //�����һ���û���ѡ������û�����0���˳���
}
}

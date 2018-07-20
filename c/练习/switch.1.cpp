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
scanf("%d",&x);   //获得下一次用户的选择，如果用户输入0则退出。
}
}

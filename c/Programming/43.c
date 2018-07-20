#include<stdio.h>
#include<time.h>
#include<windows.h>
void main()
{
	time_t timer;
	struct tm *p;
	while(1)
	{
	timer=time(NULL);
	p=localtime(&timer);
	printf("%d:%d:%d\n",p->tm_hour,p->tm_min,p->tm_sec);Sleep(1000);
	system("cls");
	
	}
}
#include<stdio.h>
#include<time.h>
void main()
{
	time_t t;
	struct tm *tm;
	time(&t);
	tm=localtime(&t);
	printf("year:%ld  moon:%d   day:%d    week:%d",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_wday);
}
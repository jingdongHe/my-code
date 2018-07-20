#include<stdio.h>
int main()
{
	short a=1;
	for(int i=1;i<20 ;i++,a*=2)
		printf("%d:%d\n",i,a*2-1);
	unsigned short b=1;
	for(int i=1;i<20;i++)
	{
		printf("%d:%hd\n",i,b*2-1);
		b*=2;b%=10;
	}
	return 0;
}

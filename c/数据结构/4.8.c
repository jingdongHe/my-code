#include<stdio.h>
long atoi(char a[])
{
	long n=0,i=1;
	if(a[0]!='-')
	n+=(a[0]-48);
	while(a[i]!='\0')
	{
		n=a[i]-48+n*10;;
		i++;
	}
	if(a[0]=='-')
		n=n*(-1);
	return n;
}
void main()
{
	char a[20];
	gets(a);printf("11111111\n");
	printf("%ld\n",atoi(a));
	
}
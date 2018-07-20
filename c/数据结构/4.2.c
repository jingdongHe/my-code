#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *assign(char *a,char *b)
{
	int nb,i,na;
	nb=strlen(b);na=strlen(a);
	printf("%d......%d\n",na,nb);
	//printf("%c",a[0]);
	/*free(a);
	a=(char *)malloc((nb+1)*sizeof(char));*/
	for(i=0;i<nb;i++)
	{
		printf("%c...%c\n",a[i],b[i]);
		a[i]=b[i];
	}
	printf("111111111111");
	for(;i<na;i++)
		a[i]='\0';
	return a;
}
void main()
{
	char *a,*b;
	a="12346789";
	b="23456";
	puts(a);
	a=assign(a,b);
	puts(a);
}

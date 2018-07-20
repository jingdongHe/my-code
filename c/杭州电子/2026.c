#include<stdio.h>
int main()
{
	char a[100];
	int i=0,j;
	gets(a);
	while(a[0]!='\0'){
		i=0;j=0;
	while(a[i]!='\0')
		i++;
	if(a[0]>=97)
		a[0]-=32;
	for(j=0;j<i;j++)
	{
		if((a[j]==' ')&&(a[j+1]>='a'&&a[j+1]<='z'))
		  a[j+1]-=32;
	}
	for(j=0;j<i;j++)
	{
		printf("%c",a[j]);
		a[j]='\0';
	}
	printf("\n");
	gets(a);
	}
	return 0;
}
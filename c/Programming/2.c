#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void main()
{
	FILE *p1=NULL,*p2=NULL;
	int d;
	int i=0,j=0,i1,i2;
	char a[100][100];
	char b[100][100];
	memset(a,'\0',sizeof(a));
	memset(b,'\0',sizeof(b));
	p1=fopen("2.1.txt","r");
	p2=fopen("2.2.txt","r");
	i1=0;
	while(fgets(a[i1++],100,p1));
	i2=0;
	while(fgets(b[i2++],100,p2));
	i=i1>i2?i1:i2;
	for(d=0;d<i;d++)
	{
		for(j=0;j<34;j++)
		{
			if(a[d][j]=='\0'||a[d][j]=='\n'||a[d][j]==' ')
				printf(" ");
			else
				printf("%c",a[d][j]);
		}
		for(j=0;j<34;j++)
		{
			if(b[d][j]=='\0'||b[d][j]=='\n'||b[d][j]==' ')
				printf(" ");
			else
				printf("%c",b[d][j]);
		}
		printf("%3d\n",d+1);
		if(d%20==0&&d!=0)
			system("cls");
		Sleep(500);
	}
	fclose(p1);
	fclose(p2);
}
/*��Ŀ14����Ӣ�ĵ���ģ����ѧ���㣺��������С��100��������A��B������A+B��
��Ҫע����ǣ�A��B��ÿһλ�����ɶ�Ӧ��Ӣ�ĵ��ʸ����� 
��������������ʽ�涨���£� 
�����ʽ����������������ɲ���������ÿ����������ռһ�У�
��ʽΪ "A   +   B   = "���������ַ�����һ���ո�����
��A��BͬʱΪzeroʱ�����������Ӧ�Ľ����Ҫ����� 
�����ʽ����ÿ�������������1�У���A+B��ֵ�� 
���������� 
one   +   two   = 
three   four   +   five   six   = 
zero   seven   +   eight   nine   = 
zero   +   zero   = 
���������
three
nine zero 
nine six��
*/
#include<stdio.h>
#include<string.h>
int change(char a[])
{
	int i,d=0,f;
	char c[5]={'\0'};
	f=strlen(a);
	for(i=0;i<f;i++)
	{
		if(a[i]!=' ')
			c[d++]=a[i];
	}
	if(strcmp(c,"one")==0)
		return 1;
	if(strcmp(c,"two")==0)
		return 2;
	if(strcmp(c,"three")==0)
		return 3;
	if(strcmp(c,"five")==0)
		return 5;
	if(strcmp(c,"six")==0)
		return 6;
	if(strcmp(c,"seven")==0)
		return 7;
	if(strcmp(c,"eight")==0)
		return 8;
	if(strcmp(c,"nine")==0)
		return 9;
	if(strcmp(c,"four")==0)
		return 4;
	if(strcmp(c,"zero")==0)
		return 0;
	return -1;
}
int Break(char k[])
{
	int j,i=0,a1=0,b1=0,c1=0,d1=0,q=0;
	char a[5]={'\0'},b[5]={'\0'},c[5]={'\0'},d[5]={'\0'};
	j=0;
	while(k[i]!=' ')
	{
		a[j]=k[i];
		i++;j++;
	}
	i++;
	if(k[i]!='+')
	{
		j=0;
		while(k[i]!=' ')
			b[j++]=k[i++];
		i++;
	}
	if(k[i]=='+')
	{
		i+=2;
		j=0;
		while(k[i]!=' ')
			c[j++]=k[i++];
		i++;
		if(k[i]!='=')
		{
			j=0;
			while(k[i]!=' ')
				d[j++]=k[i++];
		}
	}
	if(a[0]!='\0')
		a1=change(a);
	if(b[0]!='\0')
		b1=change(b);
	if(c[0]!='\0')
		c1=change(c);
	if(d[0]!='\0')
		d1=change(d);
	if(a==0&&b==0)
		return 0;
	if(b1==0)
		q+=a1;
	else
		q+=a1*10+b1;
	if(d1==0)
		q+=c1;
	else
		q+=c1*10+d1;
	return q;
}
void rebreak(int d)
{
	int a[3],i,k;
	if(d>=100)
	{
		a[0]=d/100;
		a[1]=d/10;
		a[2]=d%10;
		k=3;
	}
	if(d>=10&&d<100)
	{
		a[0]=d/10;
		a[1]=d%10;
		k=2;
	}
	if(d<10)
	{a[0]=d;k=1;}
	for(i=0;i<k;i++)
	{
		if(a[i]==1)
			printf("one ");
		if(a[i]==2)
			printf("two ");
		if(a[i]==3)
			printf("three ");
		if(a[i]==4)
			printf("four ");
		if(a[i]==5)
			printf("five ");
		if(a[i]==6)
			printf("six ");
		if(a[i]==7)
			printf("seven ");
		if(a[i]==8)
			printf("eight ");
		if(a[i]==9)
			printf("nine ");
		if(a[i]==0)
			printf("zero ");
	}
	
}
void output(int b[])
{
	int d=0;
	while(b[d]!='\0')
	{
		rebreak(b[d]);
		printf("\n");
		d++;
	}
}
void main()
{
	char a[30]={'\0'};
	int m,b[100]={'\0'},d=0,i;
	while(1)
	{
		gets(a);
	//puts(a);
	//printf("==============================\n");
		m=Break(a);
		if(m==0)
			break;
		else
			b[d++]=m;
		for(i=0;i<30;i++)
			a[i]='\0';
	}
	//for(i=0;i<d;i++)
	//	printf("%d ",b[i]);
	output(b);
}

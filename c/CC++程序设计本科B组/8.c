#include<stdio.h>
#include<string.h>
//����ֻ����һ�����ɣ������Ĳ�����ָ������
char change(char a)
{
	if(a=='*')
		return 'o';
	else
		return '*';
}
int main()
{
	char a[1000];
	char b[1000];
	int d=0;
	int i,k;
	gets(a);gets(b);
	k=strlen(a);
	for(i=0;i<k;)
	{
		if(a[i]==b[i])
			i++;
		else
		{
			d++;
			a[i]=change(a[i]);
			if(i+1<k)
				a[i+1]=change(a[i+1]);
			i++;
		}
	}
	printf("%d\n",d);
}
			
/*��Ŀ24�������ַ���S��T���ư����ֵ���S > T, 
���T��S��ǰ׺�����ߴ�������i��ʹ����j < i��S[j]=T[j],
 ��S[i] > T[i]�������ַ���"abcd" >"abc" >"abbd"��
 ���д��������һ��������ַ�����������İ����ֵ��������Ӵ�
 ��������Ӵ���������Ŀ13�����������ַ���dcbadcbbd, 
 Ӧ���dcbbd������abbasd, Ӧ���sd��������Ϊ2011��ACM������Ŀ����
��ʾ���������ڱȽ����ף�ֱ�ӽⷨ�Ǽ�������Ӵ�������Ȼ�������ȿ��ǽϴ��ַ�������ַ�����*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define n 20
int sp(char a[],char b[])
{
	int k1,k2,k,i,d=0;
	k1=strlen(a);
	k2=strlen(b);
	k=k1>k2?k1:k2;
	for(i=0;i<k;i++)
	{
		if(a[i]<b[i])
			return -1;
		if(a[i]==b[i])
			d++;
	}
	if(d==k)
		return 0;
	return 1;
}
void output(char a[])
{
	int k,i;
	k=strlen(a);
	for(i=0;i<k;i++)
		printf("%c",a[i]);
	printf("\n");
}
void Break(char a[])
{
	char b[n]={'\0'},c[n];
	int i,j,k,r,f;
	k=strlen(a);
	memset(c,'\0',sizeof(c));
	for(i=1;i<=k;i++)//�Ӵ�����Ϊi
	{
		//printf("22222\n");
		for(j=0;j<k-i+1;j++)//�Ӵ���ʼλ��Ϊj
		{
			for(r=0;r<i;r++)
			{b[r]=a[j+r];}
			//output(b);
			if(sp(b,c)>0)//cС��b
			{
				memset(c,'\0',sizeof(c));
				strcpy(c,b);
			}
		}
	}
	puts(c);
}
void main()
{
	char a[n]={'\0'};
	printf("�������ַ���\n");
	scanf("%s",&a);getchar();
	Break(a);
}
/*������10������ͷ
����������·��A���У���n����ͷ����ͼ����ʾ��˳����Ϊ1��2��...��n��
ÿ����ͷ����������·�϶�����ʻ����Լ������B�λ�C�����г�ͷʱ��
�½�������εĳ�ͷ�ű���ȸö������еĳ�ͷ��С�����һ�����򣬵��õݹ���̣���A���г�ͷ��˳��ߵ�������*/
#include<stdio.h>
int hannuota(int a,int b,int c,int n)
{
	if(n==1)
	{printf("%d->%d\n",a,c);return 1;}
	int d=0;
	d+=hannuota(a,c,b,n-1);
	d+=1;printf("%d->%d\n",a,c);
	d+=hannuota(b,a,c,n-1);
	return d;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",hannuota(1,2,3,n));
	return 0;
}

#include<stdio.h>
void main()
{
	int x1,x2,x3,x4,x5;//���ʣ��x��
	int a[5];
	int i=0,x;
	while(1)
	{
		i++;
		x=4*i;
		x5=x*5/4+1;//��5ֻ���ӿ�����ô������
		if(x5%4!=0)
			continue;
		x4=x5*5/4+1;
		if(x4%4!=0)
			continue;
		x3=x4*5/4+1;
		if(x3%4!=0)
			continue;
		x2=x3*5/4+1;
		if(x2%4!=0)
			continue;
		x1=x2*5/4+1;
		break;
	}
	for(i=0;i<5;i++)
	{
		a[i]=(x1-1)/5+1;
		x1-=a[i];
	}
	for(i=0;i<5;i++)
		printf("��%dֻ��������%d������\n",i+1,a[i]);
	printf("���ʣ��%dֻ����\n",x1);
}

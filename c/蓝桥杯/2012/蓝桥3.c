#include<stdio.h>
int main()
{
	int x0,x1,x2,x3;
	double z;//xΪ���ж����ˣ�zΪ�����ȵ�����
	for(x0=20;x0>=7;x0--)//�տ�ʼ
	{
		for(x1=1;x1<x0;x1++)//��һ�ֵ���
		{
			for(x2=1;x2<x0-x1;x2++)//�ڶ��ֵ���
			{
				for(x3=1;x3<x0-x1-x2;x3++)//�����ֵ���
				{
					z=1.0/x0+1.0/(x0-x1)+1.0/(x0-x1-x2)+1.0/(x0-x1-x2-x3);
					if(z==1)
						printf("%d  %d  %d  %d  %d\n",x0,x0-x1,x0-x1-x2,x0-x1-x2-x3);
				}
			}
		}
	}
	return 0;
}




#include<stdio.h>
void main()
{
	//���ҳ��������1��1�յ��ܼ���Ȼ���12���õ�1��13�յ��ܼ����ٷֱ����ÿ���µ��������ó���һ���µ�
	//13�ŵ��ܼ��������k=1���������������������һ��
	int week,year,day=1,a[12],i,k=0;//����һ���������洢ÿ���µ�13�����ڼ�,��k������Ƿ������һ��
	printf("Please entry the year\n");
	scanf("%d",&year);
	week=(year-1+(year-1)/4-(year-1)/100+(year-1)/400+day)%7;//�ó����weekΪ�ܼ�������0Ϊ����
	week+=12;
	a[0]=week%7;//1��
	week+=31;
	a[1]=week%7;//2��printf("%d",a[1]);
	if((year%4==0&&year%4!=0)||year%400==0)
		week+=29;
	else
		week+=28;
	a[2]=week%7;
	week+=31;
	a[3]=week%7;
	week+=30;
	a[4]=week%7;
	week+=31;
	a[5]=week%7;
	week+=30;
	a[6]=week%7;
	week+=31;
	a[7]=week%7;
	week+=31;
	a[8]=week%7;
	week+=30;
	a[9]=week%7;
	week+=31;
	a[10]=week%7;
	week+=30;
	a[11]=week%7;//����Ϊ1��12��ÿ���µ�13�ŵ��ܼ�
	for(i=0;i<12;i++)
	{
		if(a[i]==5)
		{printf("%d/%d/13\n",year,i+1);k=1;}
	}
	if(k==0)
		printf("no\n");

}

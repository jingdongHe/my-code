#include<stdio.h>
#include<math.h>
#define m 100
struct node {
	double l,r;
}p[m];
void main()
{
	double a,b;
	int n,d;//n�����죬�״︲�ǰ뾶d
	int i,j;
	struct node q;
	printf("�����뵺�����\n");
	scanf("%d",&n);getchar();
	printf("�������״︲�ǰ뾶\n");
	scanf("%d",&d);getchar();
	for(i=0;i<n;i++)
	{
		printf("�����뵺���λ��\n");
		scanf("%lf%lf",&a,&b);getchar();
		if(b>d)
		{
			printf("�����ܴ����ܸ���ȫ������ķ���\n");
			return;
		}
		p[i].l=a-sqrt(d*d-b*b);
		p[i].r=a+sqrt(d*d-b*b);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].l>p[j].l)
			{
				q=p[j];
				p[j]=p[i];
				p[i]=q;
			}
		}
	}
	a=p[0].r;
	for(i=1;i<n;i++)
	{
		if(p[i].l>a)
		{
			if(p[i-1].l==a)
				printf("��%lf���ɽ���һ���״�վ\n",a);
			else
				printf("��%lf,%lf֮��ɽ���һ���״�վ\n",p[i-1].l,a);
			a=p[i].r;
		}
		else
		{
			a=a>p[i].r?p[i].r:a;
		}
	}
	if(p[i-1].l==a)
		printf("��%lf���ɽ���һ���״�վ\n",a);
	else
		printf("��%lf,%lf֮��ɽ���һ���״�վ\n",p[i-1].l,a);
	return;
}
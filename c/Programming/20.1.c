#include<stdio.h>
#include<math.h>
#define m 100
struct node {
	double l,r;
}p[m];
void main()
{
	double a,b;
	int n,d;//n个岛屿，雷达覆盖半径d
	int i,j;
	struct node q;
	printf("请输入岛屿个数\n");
	scanf("%d",&n);getchar();
	printf("请输入雷达覆盖半径\n");
	scanf("%d",&d);getchar();
	for(i=0;i<n;i++)
	{
		printf("请输入岛屿的位置\n");
		scanf("%lf%lf",&a,&b);getchar();
		if(b>d)
		{
			printf("不可能存在能覆盖全部岛屿的方案\n");
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
				printf("在%lf处可建立一个雷达站\n",a);
			else
				printf("在%lf,%lf之间可建立一个雷达站\n",p[i-1].l,a);
			a=p[i].r;
		}
		else
		{
			a=a>p[i].r?p[i].r:a;
		}
	}
	if(p[i-1].l==a)
		printf("在%lf处可建立一个雷达站\n",a);
	else
		printf("在%lf,%lf之间可建立一个雷达站\n",p[i-1].l,a);
	return;
}
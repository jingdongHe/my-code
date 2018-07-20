#include<stdio.h>
void main()
{
	//先找出输入年的1月1日的周几，然后加12，得到1月13日的周几，再分别加上每个月的天数，得出下一个月的
	//13号的周几，最后用k=1来标记输入年中有这样的一天
	int week,year,day=1,a[12],i,k=0;//定义一个数组来存储每个月的13号星期几,用k来标记是否存在这一天
	printf("Please entry the year\n");
	scanf("%d",&year);
	week=(year-1+(year-1)/4-(year-1)/100+(year-1)/400+day)%7;//得出结果week为周几，其中0为周日
	week+=12;
	a[0]=week%7;//1月
	week+=31;
	a[1]=week%7;//2月printf("%d",a[1]);
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
	a[11]=week%7;//以上为1到12月每个月的13号的周几
	for(i=0;i<12;i++)
	{
		if(a[i]==5)
		{printf("%d/%d/13\n",year,i+1);k=1;}
	}
	if(k==0)
		printf("no\n");

}

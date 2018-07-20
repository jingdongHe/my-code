#include<stdio.h>
#include<time.h>
#include<math.h>
int week(int n)//计算输入年份的一月一日的周几
{
	int k,z;
	k=(n-1940)/4;
	if((n-1940)%4!=0)
		k++;
	z=1+(365*(n-1940)+k)%7;
	return z;
}
int leap(int n)
{
	if(n%4==0&&n%100!=0)
		return 1;
	if(n%400==0)
		return 1;
	return 0;
}
void print_year(int n)
{
	int z,i,d=1,k,f;
	//int a[5][7];//从日历可知，每月的日历的大小
	z=week(n);
	while(d<=12)
	{
		//printf("11111111111\n");
		printf("%d月:\n",d);f=0;
		printf("周一 周二 周三 周四 周五 周六 周日\n");
		if(d==1||d==3||d==5||d==7||d==8||d==10||d==12)
			k=31;
		if(d==4||d==6||d==9||d==11)
			k=30;
		if(d==2)
		{
			if(leap(n))
				k=29;
			else
				k=28;
		}
		for(i=0;i<z-1;i++)
		{printf("     ");f++;}
		for(i=1;i<=k;i++)
		{
			printf("%-5d",i);
			f++;
			if(f%7==0)
				printf("\n");
		}
		printf("\n\n");
		z=(z+k)%7;d++;
	}
}
void print_moon(int year,int moon)
{
	int z,d,k,n=0,f,i;//此处声明z==0时，为周日
	z=week(year);
	for(d=1;d<moon;d++)
	{
		if(d==1||d==3||d==5||d==7||d==8||d==10||d==12)
			k=31;
		if(d==4||d==6||d==9||d==11)
			k=30;
		if(d==2)
		{
			printf("%d.......\n",leap(n));
			if(leap(year))
				k=29;
			else
				k=28;
		}
		n+=k;
	}
		if(moon==1||moon==3||moon==5||moon==7||moon==8||moon==10||moon==12)
			k=31;
		if(moon==4||moon==6||moon==9||moon==11)
			k=30;
		if(moon==2)
		{
			if(leap(n))
				k=29;
			else
				k=28;
		}
	z=(z+n)%7;f=0;
	printf("周一 周二 周三 周四 周五 周六 周日\n");
	for(i=0;i<z-1;i++)
	{printf("     ");f++;}
	for(i=1;i<=k;i++)
		{
			printf("%-5d",i);
			f++;
			if(f%7==0)
				printf("\n");
		}
	printf("\n\n");
}
int from_the_first(int year,int moon,int day)
{
	int i,d=0,k;
	for(i=1;i<=moon;i++)
	{
		if(i==1)
			k=0;
		if(i==2||i==4||i==6||i==8||i==9||i==11)
			k=31;
		if(i==5||i==7||i==8||i==12)
			k=30;
		if(i==3)
		{
			if(leap(year))
				k=29;
			else
				k=28;
		}
		d+=k;
	}
	d+=day;
	return d;
}
void ago(int year,int moon,int day)
{
	time_t t;
	struct tm *tm;
	int locat_year,locat_moon,locat_day,locat_week;
	int k=0,f;//k==1输入时间较大,f表示这年共有多少条
	int x,y,z;
	int m=0;//用于记录相差天数
	time(&t);
	tm=localtime(&t);
	locat_year=tm->tm_year+1900;
	locat_moon=tm->tm_mon+1;
	locat_day=tm->tm_mday;
	locat_week=tm->tm_wday;
	//开始先判断输入日期和今天的大小
	y=from_the_first(year,moon,day)-1;
	z=week(year);
	z+=y;
	z=z%7;
	if(z==0)
		printf("周日\n");
	else
		printf("周%d\n",z);
	if(year>locat_year)
	{
		k=1;
		if(year==locat_year)
		{
			if(moon>locat_moon)
			{
				k=1;
				if(moon==locat_moon)
				{
					if(day>locat_day)
						k=1;
					if(day==locat_day)
					{printf("Is today\n");k=2;}
				}
			}
		}
	}
	if(leap(year))
		f=366;
	else
		f=365;
	if(year==locat_year)
	{
		m=abs(from_the_first(year,moon,day)-from_the_first(locat_year,locat_moon,locat_day));
		printf("There are %d day ago\n",m);
		return;
	}
	if(k==0)
	{
		m+=(f-from_the_first(year,moon,day));
		x=(locat_year-year)/4;
		if((locat_year-year)%4!=0)
			x++;
		m+=(locat_year-year)*365+x+from_the_first(locat_year,locat_moon,locat_day);
		printf("There are %d day ago\n",m);
		return ;
	}
	
	if(leap(locat_year))
		f=366;
	else
		f=365;
	if(k==1)
	{
		m+=(f-from_the_first(locat_year,locat_moon,locat_day));
		x=(year-locat_year)/4;
		if((year-locat_year)%4!=0)
			x++;
		m+=(year-locat_year)*365+x+from_the_first(year,moon,day);
		printf("There are %d day ago\n",m);
		return ;
	}
	
	return;
}
void fish_or_rest(int year,int moon,int day)
{
	int k,z,i;
	k=(year-1990)/4;
	if((year-1990)%4!=0)
		k++;
	z=365*(year-1990)+k+day;
	for(i=1;i<=moon;i++)
	{
		if(i==1)
			k=0;
		if(i==2||i==4||i==6||i==8||i==9||i==11)
			k=31;
		if(i==5||i==7||i==8||i==12)
			k=30;
		if(i==3)
		{
			if(leap(year))
				k=29;
			else
				k=28;
		}
		z+=k;
	}
	if(z%5==0||z%5==4)
		printf("rest\n");
	else
		printf("fish\n");
}
void main()
{
	int n,year,moon,day;
	
	printf("请输入年份\n");
	scanf("%d",&n);getchar();//1940的1月1日为周一，1940闰年
	print_year(n);
	printf("==============================\n");
	printf("please entry the year and moon\n");
	scanf("%d%d",&year,&moon);getchar();
	print_moon(year,moon);
	printf("==============================\n");
	printf("please entry the year,moon and day\n");
	scanf("%d%d%d",&year,&moon,&day);getchar();
	ago(year,moon,day);
	printf("==============================\n");
	printf("please entry the year,moon and day\n");
	scanf("%d%d%d",&year,&moon,&day);getchar();
	fish_or_rest(year,moon,day);
}
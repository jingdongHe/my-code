#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include <iostream.h>
#include<time.h>
#include<string>
using namespace std;

class DateFormatter {
private:
	int day;
	int mon;
	int year;
public:
	//判断是否为闰年
	inline bool IsLeapYear() {
		float rem = year%4;
		if(rem == 0.0) {
			return true;
		}else {
			return false;
		}
	}
	inline int GetDay(){return day;}
	inline int GetYear(){return year;}
	inline int GetMonth(){return mon;}
	char* Today() {
		const time_t curr = time(0);
		tm *dt = localtime(&curr);
		int d = dt->tm_mday;
		int y = (dt->tm_year+1900);
		int m = dt->tm_mon;
		char mn[4];
		strcpy(mn,FindMonth(m));
		char ret[25];
		strcpy(ret,FormatDate(d,mn,y));
		return ret;
	}
	//获取当地时间
	DateFormatter() {
		const time_t curr = time(0);
		tm *dt = localtime(&curr);
		this->day = dt->tm_mday;
		this->mon = dt->tm_mon;
		this->year = (dt->tm_year+1900);
	}
	//定义时间
	DateFormatter(int day,int mon,int year) {
		this->day = day;
		this->mon = mon;
		this->year = year;
	}
	//从字符串中得出一个日期
	DateFormatter(char* date) {
		if(strlen(date) > 8) {
			string s1 = date;
			int p = s1.find_first_of('-');
			string day;
			string month;
			string year;
			if(p == 2) {
				day = s1.substr(0,2);
				month = s1.substr(3,3);
				year = s1.substr(7,4);
			}
			else if(p==1)
			{
				day = s1.substr(0,1);
				month = s1.substr(2,3);
				year = s1.substr(6,4);
			}
			char cday[5];
			strcpy(cday,day.c_str());
			char cyear[5];
			strcpy(cyear,year.c_str());
			this->day = atoi(cday);
			this->mon = FindMonthInNumber(month);
			this->year = atoi(cyear);
		}
		else if(strlen(date) == 8 || strlen(date) == 7 || strlen(date) == 6)
		{
			int len = strlen(date);
			string str = date;
			string day;
			string month;
			string year;
			int p1 = str.find_first_of('-');
			if(p1 <= 0) p1 = str.find_first_of('/');
			int p2 = str.find_last_of('-');
			if(p2 <= 0) p2 = str.find_last_of('/');
			if(len == 8) 
			{
				day = str.substr(0,2);
				month = str.substr(3,2);
				year = str.substr(6,2);
			}
			else if(len == 7) 
			{
				if(p1 == 1) 
				{
					day = str.substr(0,1);
					if(p2 == 3)
					{
						month = str.substr(2,1);
						year = str.substr(4,2);
					}
					else 
					{
						month = str.substr(2,2);
						year = str.substr(5,2);
					}
				}
				else
				{
					day = str.substr(0,2);
					if(p2 == 3) {
						month = str.substr(2,1);
						year = str.substr(4,2);
					}
					else 
					{
						month = str.substr(3,2);
						year = str.substr(5,2);
					}
				}		  
			}
			else if(len == 6) 
			{
				day = str.substr(0,1);
				month = str.substr(2,1);
				year = str.substr(4,2);
			}
			int m = atoi((month.c_str()));
			m -= 1;
			int yr = atoi((year.c_str()));
			char y[5];
			if(yr >= 0 && yr <= 70) 
			{
				strcpy(y,"20");
				strcat(y,year.c_str());
			} 
			else 
			{
				strcpy(y,"19");
				strcat(y,year.c_str());
			}
			this->day = atoi((day.c_str()));
			this->mon = m;
			this->year = atoi(y);
		}
	}
	//从英文字母变数字（月份）
	int FindMonthInNumber(string m) {
		if(to_lower(m)=="jan") {
			return 0;
		}else if(to_lower(m)=="feb") {
			return 1;
		}else if(to_lower(m)=="mar") {
			return 2;
		}else if(to_lower(m)=="apr") {
			return 3;
		}else if(to_lower(m)=="may") {
			return 4;
		}else if(to_lower(m)=="jun") {
			return 5;
		}else if(to_lower(m)=="jul") {
			return 6;
		}else if(to_lower(m)=="aug") {
			return 7;
		}else if(to_lower(m)=="sep") {
			return 8;
		}else if(to_lower(m)=="oct") {
			return 9;
		}else if(to_lower(m)=="nov") {
			return 10;
		}else if(to_lower(m)=="dec") {
			return 11;
		}else {
			return -1;
		}
	}
	//数字转字符串
	char* FindMonth(int m) {
		if(m ==0) {
		return "JAN";
	}else if(m == 1) {
		return "FEB";
	}else if(m == 2) {
		return "MAR";
	}else if(m == 3) {
		return "APR";
	}else if(m == 4) {
		return "MAY";
	}else if(m == 5) {
		return "JUN";
	}else if(m == 6) {
		return "JUL";
	}else if(m == 7) {
		return "AUG";
	}else if(m == 8) {
		return "SEP";
	}else if(m == 9) {
		return "OCT";
	}else if(m == 10) {
		return "NOV";
	}else if(m == 11) {
		return "DEC";
	}else {
		return "NUL";
	}
	}
	//大写变小写
	string to_lower(string s) {
		int len = s.length();
		for(int i=0;i<len;i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = tolower(s[i]);
			}
		}
		return s;
	}
	//数字转字符串
	char* GetDate() {
		char* d = new char[25];
		char* m = new char[5];
		char* y = new char[5];
		//讲数字转换为字符串
		d = itoa(day,d,10);
		m = itoa((mon+1),m,10);
		y = itoa(year,y,10);
		//链接字符串
		strcat(d,"/");
		strcat(d,m);
		strcat(d,"/");
		strcat(d,y);
		char ret[25];
		strcpy(ret,d);
		delete[] d;
		delete[] m;
		delete[] y;
		return ret;
	}
	char* FormatDate(int d,char* m,int y) {
    	char* dy = new char[25];
		char* yr = new char[25];
		dy = itoa(d,dy,10);
		yr = itoa(y,yr,10);
		strcat(dy,"-");
		strcat(dy,m);
		strcat(dy,"-");
		strcat(dy,yr);
		return dy;
	}
	//第m月有多少天
	int FindDaysInMonth(int m) {
		if(m == 0) {
			return 31;
		}else if(m == 1) {
			if(IsLeapYear()) {
				return 29;
			}else {
				return 28;
			}
		}else if(m == 2) {
			return 31;
		}else if(m == 3) {
			return 30;
		}else if(m == 4) {
			return 31;
		}else if(m == 5) {
			return 30;
		}else if(m == 6) {
			return 31;
		}else if(m == 7) {
			return 31;
		}else if(m == 8) {
			return 30;
		}else if(m == 9) {
			return 31;
		}else if(m == 10) {
			return 30;
		}else if(m == 11) {
			return 31;
		}
		return -1;
	}
	//标准化
	char* GetFormattedDate() {
		char mn[5];
		strcpy(mn,FindMonth(mon));
		char ret[25];
		strcpy(ret,FormatDate(day,mn,year));
		return ret;
	}
	//增加天数
	void operator + (int days) {
		int day_in_mon=FindDaysInMonth(this->mon);
		this->day+=days;
		//cout<<this->mon+1<<"　"<<day_in_mon<<endl;
		while(this->day>day_in_mon)
		{
			this->day-=day_in_mon;
			this->mon++;
			if(this->mon>12)
			{
				this->year++;
				this->mon-=12;
			}
			day_in_mon=FindDaysInMonth(this->mon);
		}

	}
	/*void AddDays(int days) {
		if(days <= 0) return;
		int curr_day = this->day;
		int curr_mon = this->mon;
		int days_in_mon = FindDaysInMonth(curr_mon);
		if(this->mon == 11 && days_in_mon == curr_day) {
			this->year++;
		}
		if(days_in_mon == curr_day) {
			this->mon++;
			if(this->mon > 11) {
				this->mon = 0;
			}
		}
		if(days <= days_in_mon) {
			this->day += days;
			if(this->day > days_in_mon) {
				this->day = 1;
			}
			return;
		}else {
			int days_to_add = days_in_mon - curr_day;
			this->day += days_to_add;
			if(this->day > days_in_mon) {
				this->day = 1;
			}
			int rem_days = days - days_to_add;
			AddDays(rem_days);
			return;
		}
	}*/
	//月份增加
	void IncrementMonth() {
		mon++;
		if(mon > 11) {
			mon = 0;
			year++;
		}
	}
	//找到不同的月份
	int FindDifferenceInMonths(DateFormatter dft) {
		int diff = 0;
		if(dft > *this) {
			return -1;
		}else if(dft == *this) {
			return 0;
		}else {
			while(1) {
				dft.IncrementMonth();
				diff++;
				if((dft.GetYear() == this->year) && (dft.GetMonth() == this->mon)) {
					break;
				}
			}
		}
		if(this->GetDay() < dft.GetDay()) {
			diff--;
		}
		return diff;
	}
	//找到不同的天数
	int operator - (DateFormatter dft) {
		if(*this < dft) {
			return -1;
		}else if(*this == dft) {
			return 0;
		}else {
			int ret = 0;
			while(1) {
				if(dft == *this) {
					break;
				}
				dft+1;
				ret++;
			}
			return ret;
		}
	}
	//重载运算符
	void operator --()
	{
		this->day--;
		int day_in_mon=FindDaysInMonth(this->mon-1);
		if(this->day<=0)
		{
			this->mon--;
			this->day+=day_in_mon;
		}
		if(this->mon<=0)
		{
			this->year--;
			this->mon+=12;
		}
	}
	void operator ++()
	{
		this->day++;
		int day_in_mon=FindDaysInMonth(this->mon);
		if(this->day>day_in_mon)
		{
			this->day-=day_in_mon;
			this->mon++;
		}
		if(mon>12)
		{
			this->mon-=12;
			this->year++;
		}
	}
	int operator < (DateFormatter df) {
		if(df.year > this->year) {
			return 1;
		}else if(df.year == this->year && df.mon > this->mon) {
			return 1;
		}else if(df.mon == this->mon && df.day > this->day) {
			return 1;
		}else {
			return 0;
		}
	}

	int operator > (DateFormatter df) {
		if(df.year < this->year) {
			return 1;
		}else if(df.year == this->year && df.mon < this->mon) {
			return 1;
		}else if(df.mon == this->mon && df.day < this->day) {
			return 1;
		}else {
			return 0;
		}
	}

	int operator == (DateFormatter df) {
		if( (df.year == this->year)
			&& (df.mon == this->mon) && (df.day == this->day)) {
			return 1;
		}else {
			return 0;
		}
	}
};

int main() {
	
	//Dateformatter class supports 2 formats of dates :- DD-MON-YYYY & DD/MM/YY
	cout<<"请输入操作："<<endl<<"1、输出日期        2、输出两个日期相差的时间    3、输出两个日期相差的月份    "<<endl;
	cout<<"4、某天加上天数    5、自增                      6、自减   "<<endl<<"7、输出今天的日期  8、比较两个日期              9、增加月份"<<endl;
	cout<<"0、退出"<<endl<<"注释：所有单目运算符的操作均在dft1上操作   dft1(1-MAR-2001)  dft2(15/4/02)"<<endl;
	DateFormatter dft1("1-MAR-2001");
	DateFormatter dft2("15/4/02");
	char tmp[25];
	int f;
	while(1)
	{
	cin>>f;
	switch(f)
	{
	case 1:strcpy(tmp,dft1.GetFormattedDate());
	cout<<"First date : "<<tmp<<endl;
	strcpy(tmp,dft2.GetFormattedDate());
	cout<<"Second date: "<<tmp<<endl; break;
	case 2:
	cout<<"Diif in days: "<<dft2-dft1<<endl;break;
	case 3:
	cout<<"Diif in months: "<<dft2.FindDifferenceInMonths(dft1)<<endl;break;
	case 4:dft2+35;
	strcpy(tmp,dft2.GetFormattedDate());
	cout<<"Added 35 days to date 2: "<<tmp<<endl;break;
	case 5:dft1++;
	strcpy(tmp,dft1.GetFormattedDate());
	cout<<"Second date: "<<tmp<<endl; break;
	case 6:dft1--;
	strcpy(tmp,dft1.GetFormattedDate());
	cout<<"Second date: "<<tmp<<endl; break;
	case 7:
	strcpy(tmp,dft1.Today());
	cout<<"Today is: "<<tmp<<endl;break;
	case 8:
	cout<<"Date1 < Date2: "<<(dft1 < dft2)<<endl;
	cout<<"Date1 == Date2: "<<(dft1 == dft2)<<endl;
	cout<<"Date1 > Date2: "<<(dft1 > dft2)<<endl;break;
	case 9:
	dft1.IncrementMonth();
	strcpy(tmp,dft1.GetDate());
	cout<<"Incremented first date's month: "<<tmp<<endl;break;
	case 0:exit(0);
	}
	}
	return 0;
}
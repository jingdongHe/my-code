// dateformatter.cpp. implements DateFormatter class. Author: Vijay Mathew Pandyalakal
// Date: 12/23/2001 11:36:48 AM

#include <stdlib.h>
#include "DateFormatter.h"

//~~~~~ function default constructor ~~~~~~~~~~~~~~~~~~
//  Default constuctor that creates a DateFormatter Object with system date  arguments: 0 0
// returns 0
DateFormatter::DateFormatter() {
	const time_t curr = time(0);
	tm *dt = localtime(&curr);
	this->day = dt->tm_mday;
	this->mon = dt->tm_mon;
	this->year = (dt->tm_year+1900);
}
//~~~~~~ end of function default constructor~~~~~~~~~~~~~~~~~
//~~~~~ function overloaded constructor ~~~~~~~~~~~~~~~~~~
// Constuctor that creates a DateFormatter Object with arguments as date values
// arguments: int,int,int
// arg1 is day,arg2 month & arg3 is year
// returns 0
DateFormatter::DateFormatter(int day,int mon,int year) {
	this->day = day;
	this->mon = mon;
	this->year = year;
}
//~~~~~~ end of function overloaded constructor~~~~~~~~~~~~~~~~~
//~~~~~ function overloaded constructor - 2 ~~~~~~~~~~~~~~~~~~
// This constuctor takes a string in the format DD-MON-YYYY or DD-MM-YY & creates a date from // that
// arguments: char*
// arg is a string in the format dd-mon-yyyy
// returns 0
DateFormatter::DateFormatter(char* date) {
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
		}else if(p==1){
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
	}else if(strlen(date) == 8 || strlen(date) == 7 || strlen(date) == 6) {
		int len = strlen(date);
		string str = date;
		string day;
		string month;
		string year;
		int p1 = str.find_first_of('-');
		if(p1 <= 0) p1 = str.find_first_of('/');
		int p2 = str.find_last_of('-');
		if(p2 <= 0) p2 = str.find_last_of('/');
		if(len == 8) {
			day = str.substr(0,2);
			month = str.substr(3,2);
			year = str.substr(6,2);
		}else if(len == 7) {
			if(p1 == 1) {
				day = str.substr(0,1);
				if(p2 == 3) {
					month = str.substr(2,1);
					year = str.substr(4,2);
				}else {
					month = str.substr(2,2);
					year = str.substr(5,2);
				}
			}else {
				day = str.substr(0,2);
				if(p2 == 3) {
					month = str.substr(2,1);
					year = str.substr(4,2);
				}else {
					month = str.substr(3,2);
					year = str.substr(5,2);
				}
			}		  
		}else if(len == 6) {
			day = str.substr(0,1);
			month = str.substr(2,1);
			year = str.substr(4,2);
		}
		int m = atoi((month.c_str()));
		m -= 1;
		int yr = atoi((year.c_str()));
		char y[5];
		if(yr >= 0 && yr <= 70) {
			strcpy(y,"20");
			strcat(y,year.c_str());
		} else {
			strcpy(y,"19");
			strcat(y,year.c_str());
		}
		this->day = atoi((day.c_str()));
		this->mon = m;
		this->year = atoi(y);
	}
}
//~~~~~~ end of function overloaded constructor - 2~~~~~~~~~~~~~~~~~
//~~~~~ function FindMonthInNumber ~~~~~~~~~~~~~~~~~~
// Private function that take a string in the format MON (like JAN) & returns
// arguments: string
// arg specifies a month in format mmm
// returns the month in a number (0-11)
int DateFormatter::FindMonthInNumber(string m) {
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
//~~~~~~ end of function FindMonthInNumber~~~~~~~~~~~~~~~~~
//~~~~~ function to_lower ~~~~~~~~~~~~~~~~~~
// Utility function that converts a string to lower case
// arguments: string
// arg is the string to be changed to lower case
// returns lower cased string
string DateFormatter::to_lower(string s) {
	int len = s.length();
	for(int i=0;i<len;i++) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = tolower(s[i]);
		}
	}
	return s;
}
//~~~~~~ end of function to_lower~~~~~~~~~~~~~~~~~
							/* PUBLIC FUNCTIONS */
//~~~~~ function GetDate ~~~~~~~~~~~~~~~~~~
// Returns date in format DD/MM/YYYY
// arguments: 0
// 0
// returns date as a string in the format dd/mm/yyyy
char* DateFormatter::GetDate() {
	char* d = new char[25];
	char* m = new char[5];
	char* y = new char[5];
	d = itoa(day,d,10);
	m = itoa((mon+1),m,10);
	y = itoa(year,y,10);
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
//~~~~~~ end of function GetDate~~~~~~~~~~~~~~~~~

//~~~~~ function GetFormattedDate ~~~~~~~~~~~~~~~~~~
// Returns date in format DD-MON-YYYY
// arguments: 0
// 0
// returns date as string

char* DateFormatter::GetFormattedDate() {
	char mn[5];
	strcpy(mn,FindMonth(mon));
	char ret[25];
	strcpy(ret,FormatDate(day,mn,year));
	return ret;
}
//~~~~~~ end of function GetFormattedDate~~~~~~~~~~~~~~~~~

//~~~~~ function AddDays ~~~~~~~~~~~~~~~~~~
// adds a number of days to the date
// arguments: int
// arg is the no. of days to add
// returns void
void DateFormatter::AddDays(int days) {
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
}
//~~~~~~ end of function AddDays~~~~~~~~~~~~~~~~~

//~~~~~ function IncrementMonth ~~~~~~~~~~~~~~~~~~
// increments by 1 month
// arguments: 
// 
// returns void
void DateFormatter::IncrementMonth() {
	mon++;
	if(mon > 11) {
		mon = 0;
		year++;
	}
}
//~~~~~~ end of function IncrementMonth~~~~~~~~~~~~~~~~~

//~~~~~ function FindDifferenceInMonths ~~~~~~~~~~~~~~~~~~
// find diff between 2 dates in months
// arguments: DateFormatter 2nd_date
// 
// returns no of months
int DateFormatter::FindDifferenceInMonths(DateFormatter dft) {
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
//~~~~~~ end of function FindDifferenceInMonths~~~~~~~~~~~~~~~~~

//~~~~~ function FindDifferenceInDays ~~~~~~~~~~~~~~~~~~
// finds diff of two dates in days
// arguments: Dateformatter
// 
// returns No of days,-1 if argument date in less than this
int DateFormatter::FindDifferenceInDays(DateFormatter dft) {
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
			dft.AddDays(1);
			ret++;
		}
		return ret;
	}
}
//~~~~~~ end of function FindDifferenceInMonths~~~~~~~~~~~~~~~~~


/* Overloaded comparison operators */

int DateFormatter::operator < (DateFormatter df) {
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

int DateFormatter::operator > (DateFormatter df) {
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

int DateFormatter::operator == (DateFormatter df) {
	if( (df.year == this->year)
		&& (df.mon == this->mon) && (df.day == this->day)) {
		return 1;
	}else {
		return 0;
	}
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// end of dateformatter.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

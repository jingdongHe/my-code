// dateformatter.h
// defines a date datatype class.   Author: Vijay Mathew Pandyalakal.  Date: 10/02/2001 

#ifndef DATEFORMATTER_H
#define DATEFORMATTER_H
#include <time.h>
#include <string>
using namespace std;
class DateFormatter {
private:
	int day;
	int mon;
	int year;
public:
	DateFormatter();
	DateFormatter(int day,int mon,int year);
	DateFormatter(char* date);
	inline int GetDay() {  return day; } // Returns Day Value
	inline int GetMonth() { return mon; } // Returns Month
	inline int GetYear() { return year; } // Returns Year
	inline void SetDay(int d) { day = d; } // Sets new value for day
	inline void SetMonth(int m) { mon =m; } // Sets new value for month
	inline void SetYear(int y) { year = y; } // Sets new value for year
	inline bool IsLeapYear() {// Checks if current year is leap
		float rem = year%4;
		if(rem == 0.0) {
			return true;
		}else {
			return false;
		}
	}
	void AddDays(int days); // Adds a number of days to the current date
	void IncrementMonth();// Increments current date by one month
	char* GetDate();
	int FindDifferenceInMonths(DateFormatter);//finds diff between 2 dates in months
	int FindDifferenceInDays(DateFormatter);//finds diff between 2 dates in days
	
	/* Static function that returns system date in format DD-MON-YYYY */
	static char* Today() {
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
	/**/
	char* GetFormattedDate();
	int operator < (DateFormatter df);
	int operator > (DateFormatter df);
	int operator == (DateFormatter df);
private:
	static char* FindMonth(int m) {
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
	int FindMonthInNumber(string m);
	static char* FormatDate(int d,char* m,int y) {
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
	string to_lower(string s);
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
};
#endif

// end of dateformatter.h
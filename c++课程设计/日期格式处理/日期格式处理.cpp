/*第2题	日期格式理--源代码及关键源代码注解如下：*/

#include <iostream.h>
#include <stdlib.h>
#include "dateformatter.h"

int main() {
	
	//Dateformatter class supports 2 formats of dates :- DD-MON-YYYY & DD/MM/YY
	DateFormatter dft1("1-MAR-2001");
	DateFormatter dft2("15/4/02");
	char tmp[25];

	//Prints First & second dates
	strcpy(tmp,dft1.GetFormattedDate());
	cout<<"First date : "<<tmp<<endl;
	strcpy(tmp,dft2.GetFormattedDate());
	cout<<"Second date: "<<tmp<<endl;
	
	//Prints difference in days
	cout<<"Diif in days: "<<dft2.FindDifferenceInDays(dft1)<<endl;
	//Prints difference in months
	cout<<"Diif in months: "<<dft2.FindDifferenceInMonths(dft1)<<endl;
exit(0);
	//Prints current date
	strcpy(tmp,dft1.Today());
	cout<<"Today is: "<<tmp<<endl;

	//Adds 35 days to dft2
	dft2.AddDays(35);
		
	//& prints its current value in the format DD-MON-YYYY
	strcpy(tmp,dft2.GetFormattedDate());
	cout<<"Added 35 days to date 2: "<<tmp<<endl;

	//Increments dft1 by 1 month
	dft1.IncrementMonth();

	//& prints its current value in the format DD/MM/YY
	strcpy(tmp,dft1.GetDate());
	cout<<"Incremented first date's month: "<<tmp<<endl;

	//Performs comparison operations on the two DateFormatter objects
	//& prints result
	cout<<"Date1 < Date2: "<<(dft1 < dft2)<<endl;
	cout<<"Date1 == Date2: "<<(dft1 == dft2)<<endl;
	cout<<"Date1 > Date2: "<<(dft1 > dft2)<<endl;
	
	return 0;
}

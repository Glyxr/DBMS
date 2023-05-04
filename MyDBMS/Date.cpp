#include "Date.h"
date::date(int a[])
{
	year = a[0];
	month = a[1];
	day = a[2];
}

int date::getMaxday()
{
	int isleapyear = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) isleapyear = 1;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (isleapyear == 0)
		return 28;
	else
		return 29;
}
ostream& operator <<(ostream& out, date& d)
{
	out << d.year << "-" << d.month << "-" << d.day;
	return out;
}
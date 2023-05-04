#pragma once
#include<map>
#include"table.h"
#include"Database.h"
#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<stdlib.h>
#include<io.h>
#pragma warning(disable:4996)
class date{
public:
	int year;
	int month;
	int day;
public:
	date(int a[]);
	date(int ye, int mo, int da)
	{
		this->year = ye;
		this->month = mo;
		this->day = da;
	}
	~date() {}
	void setdate(int y, int m, int d)
	{
		this->year = y;
		this->month = m;
		this->day = d;
	}
	int getMaxday();   //得到该年月的最大天数
	friend ostream& operator <<(ostream& out, date& d);
};



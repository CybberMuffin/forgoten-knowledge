#pragma once
#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <iomanip>

class Date {
protected:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int date_day, int date_month, int date_year);
	Date(const Date& d);
	//~Date();
	bool operator<(const Date &t);
	bool operator==(const Date &t);
	Date &operator=(const Date &t);
	

	void set_date(int date_day, int date_month, int date_year);
	int* get_date();
	virtual void Show();
	void print();

	void set_day();
	void set_month();
	void set_year();

	int checkDay();
	int checkMonth();
	int checkYear();

	void randomDate();

	inline void wait();
};

class DateEmp : public Date {
public:
	DateEmp();
	DateEmp(int ed, int em, int ey) : Date(ed, em, ey){ }
	DateEmp(const DateEmp& p) : Date(p) { }

	DateEmp &operator=(const DateEmp &t);

};


#include "Date.h"

void Date::set_date(int date_day, int date_month, int date_year) {
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	if (date_year >= 1990 && date_year < tim->tm_year + 1900) {
		year = date_year;
		date_month >= 1 && date_month <= 12 ? month = date_month : month = 1;
		if (year % 4 == 0) {
			if (month == 2)
				date_day >= 1 && date_day <= 29 ? day = date_day : day = 1;
			else if (month % 2 == 1)
				date_day >= 1 && date_day <= 31 ? day = date_day : day = 1;
			else
				date_day >= 1 && date_day <= 30 ? day = date_day : day = 1;
		}
		else {
			if (month == 2)
				date_day >= 1 && date_day <= 28 ? day = date_day : day = 1;
			else if (month % 2 == 1)
				date_day >= 1 && date_day <= 31 ? day = date_day : day = 1;
			else
				date_day >= 1 && date_day <= 30 ? day = date_day : day = 1;
		}
	}
	else {
		year = tim->tm_year + 1900;
		if (date_month >= 1 && date_month < tim->tm_mon + 1) {
			month = date_month;
			if (year % 4 == 0) {
				if (month == 2)
					date_day >= 1 && date_day <= 29 ? day = date_day : day = 1;
				else if (month % 2 == 1)
					date_day >= 1 && date_day <= 31 ? day = date_day : day = 1;
				else
					date_day >= 1 && date_day <= 30 ? day = date_day : day = 1;
			}
			else {
				if (month == 2)
					date_day >= 1 && date_day <= 28 ? day = date_day : day = 1;
				else if (month % 2 == 1)
					date_day >= 1 && date_day <= 31 ? day = date_day : day = 1;
				else
					date_day >= 1 && date_day <= 30 ? day = date_day : day = 1;
			}
		}
		else {
			month = tim->tm_mon + 1;
			date_day >= 1 && date_day < tim->tm_mday ? day = date_day : day = tim->tm_mday;
		}
	}
}
int* Date::get_date() {
	int arr[] = { day, month, year };
	return arr;
}
void Date::Show() {
	printf("%02d/%02d/%d", day, month, year); //print
}
void Date::print() {
	printf("Date::print\n");
}

void Date::set_day() {
	day = checkDay();
}
void Date::set_month() {
	month = checkMonth();
}
void Date::set_year() {
	year = checkYear();
}

int Date::checkDay() {
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	int d_day;
	char mas[20];
	do {
		scanf("%20s", mas);
		d_day = atoi(mas);
		wait();

		if (!d_day || d_day < 1 || (year % 4 == 0 && month == 2 && d_day > 29)
			|| ((year % 4 == 1 || year % 4 == 2 || year % 4 == 3) && month == 2 && d_day > 28) ||
			(month % 2 == 1 && d_day > 31) || (month % 2 == 0 && d_day > 30)
			|| (year == tim->tm_year + 1990 && month == tim->tm_mon + 1 && d_day > tim->tm_mday))
			printf("Wrong data! Enter new data:\n");
	} while (!d_day || d_day < 1 || (year % 4 == 0 && month == 2 && d_day > 29)
		|| ((year % 4 == 1 || year % 4 == 2 || year % 4 == 3) && month == 2 && d_day > 28) ||
		(month % 2 == 1 && d_day > 31) || (month % 2 == 0 && d_day > 30)
		|| (year == tim->tm_year + 1990 && month == tim->tm_mon + 1 && d_day > tim->tm_mday));

	return d_day;
}
int Date::checkMonth() {
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	int d_month;
	char mas[20];
	do {
		scanf("%20s", mas);
		d_month = atoi(mas);
		wait();

		if (!d_month || d_month < 1 || d_month > 12 ||
			(year == tim->tm_year && d_month > tim->tm_mon + 1))
			printf("Wrong data! Enter new data:\n");
	} while (!d_month || d_month < 1 || d_month > 12 ||
		(year == tim->tm_year && d_month > tim->tm_mon + 1));

	return d_month;
}
int Date::checkYear() {
	int d_year;
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	char mas[20];
	do {
		scanf("%20s", mas);
		d_year = atoi(mas);
		wait();

		if (!d_year || d_year < 1990 || d_year > tim->tm_year + 1990)
			printf("Wrong data! Enter new data:\n");
	} while (!d_year || d_year < 1990 || d_year > tim->tm_year + 1990);

	return d_year;
}

void Date::randomDate() {
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);

	year = ((tim->tm_year + 1840) + rand() % 43);
	month = 1 + rand() % 12;
	int tempd = 1 + rand() % 31;
	if ((year % 4 == 0 && month == 2 && tempd > 29) || (month % 2 == 0 && tempd > 30)) 
		tempd = 1 + rand() % 28;
	day = tempd;
}

inline void Date::wait() {
	while (getchar() != '\n');
}

Date::Date() {
	randomDate();
}
DateEmp::DateEmp() {
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	srand(time(NULL));

	year = (2007 + rand() % ((tim->tm_year + 1900) - 2005));
	month = 1 + rand() % 12;
	int tempd = 1 + rand() % 31;
	if ((year % 4 == 0 && month == 2 && tempd > 29) || (month % 2 == 0 && tempd > 30))
		tempd = 1 + rand() % 28;
	day = tempd;
}
Date::Date(int date_day, int date_month, int date_year) {
	set_date(date_day, date_month, date_year);
}
Date::Date(const Date& d) {
	year = d.year;
	month = d.month;
	day = d.day;
}
//Date::~Date() {
//	printf("destr data...");
//}
bool Date::operator<(const Date &t) {
	if (year < t.year) return true;
	else if (year == year) {
		if (month < t.month) return true;
		else if (month == t.month) {
			if (day < t.day) return true;
			else return false;
		}
		else return false;
	}
	else return false;
}
bool Date::operator==(const Date &t) {
	if ((day == t.day) && (month == t.month) && (year == t.year))
		return true;
	return false;
}
Date& Date::operator=(const Date &t) {
	year = t.year;
	month = t.month;
	day = t.day;
	return *this;
}
DateEmp& DateEmp::operator=(const DateEmp &t) {
	year = t.year;
	month = t.month;
	day = t.day;
	return *this;
}

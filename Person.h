#pragma once
#include "Date.h"

class Person : public Date {
protected:
	char* surname;
	char* name;
public:
	Person();
	Person(char* sn, char* n, int date_day, int date_month, int date_year);
	Person(const Person& p);
	~Person();

	Person &operator=(const Person &p);

	void setSurname();
	void inputSurname(char* sur);
	char* getSurname();
	void setName();
	void inputName(char* nam);
	const char* getName();

	char* randomSurname();
	char* randomName();

	void Show();
	char* checkString();
	inline void wait();
};

class strPerson : public Date {
protected:
	std::string surname;
	std::string name;
public:
	strPerson();
	strPerson(std::string surn, std::string nam, int dday, int dmonth, int dyear);
	strPerson(const strPerson& p);


	std::string getSurname();
	void inputSurname(std::string sur);
	std::string randomSurn();
	std::string randomName();
	void Show();
};

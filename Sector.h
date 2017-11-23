#pragma once
#include "Employee.h"

class Sector : public Person {
private:
	char* title;
	Employee* list;
	int size;
public:
	Sector();
	Sector(char* ttl, Employee* list, int size, char* surn, char* nam, int day, int month, int year);
	Sector(const Sector& p);

	char* randomSector();
	void Show();

	Employee& operator[](int size);
};

class strSector : public strPerson {
private:
	std::string title;
	strEmployee* list;
	int size;
public:
	strSector();
	strSector(std::string ttl, strEmployee* list, int size, std::string surn, std::string nam, int day, int month, int year);
	strSector(const strSector& p);

	std::string randomSector();
	void Show();
	strEmployee& operator[](int size);
};

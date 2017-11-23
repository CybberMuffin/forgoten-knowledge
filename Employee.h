#pragma once

#include "Person.h"
#include "Position.h"
#include "Date.h"

class Employee : public Person, public Position, public DateEmp {
public:
	Employee();
	Employee(char* sn, char* n, int bd, int bm, int by, char* ttl, int slr, bool vc, int wd, int wm, int wy);
	Employee(const Employee& p);

	const Employee& operator=(const Employee& p);

	void Show();
};

class strEmployee : public strPerson, public Position, public DateEmp {
public:
	strEmployee();
	strEmployee(std::string snam, std::string nam, int bd, int bm, int by, char* ttl, int slr, bool vc, int wd, int wm, int wy);
	strEmployee(const strEmployee& p);

	void Show();
};

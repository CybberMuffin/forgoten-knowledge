#include "Employee.h"

Employee::Employee() : Person(), Position(), DateEmp(){ }

Employee::Employee(char* sn, char* n, int bd, int bm, int by, char* ttl, int slr, bool vc, int wd, int wm, int wy)
	: Person(sn, n, bd, bm, by), Position(ttl, slr, vc), DateEmp(wd, wm, wy){ }

Employee::Employee(const Employee& p) : Person(p), Position(p), DateEmp(p) { }

const Employee& Employee::operator=(const Employee& p) {
	if (this == &p) {
		return *this;
	}

	Person::operator=(p);
	Position::operator=(p);
	DateEmp::operator=(p);

	return *this;
}

void Employee::Show() {
	Person::Show();
	Position::Show();
	DateEmp::Show();
}

strEmployee::strEmployee() : strPerson(), Position(), DateEmp() { }

strEmployee::strEmployee(std::string snam, std::string nam, int bd, int bm, int by, 
	char* ttl, int slr, bool vc, int wd, int wm, int wy) : strPerson(snam, nam, bd, bm, by),
	Position(ttl, slr, vc), DateEmp(wd, wm, wy) { }

strEmployee::strEmployee(const strEmployee& p) : strPerson(p), Position(p), DateEmp(p) { }

void strEmployee::Show() {
	strPerson::Show();
	Position::Show();
	DateEmp::Show();
}

#include "Person.h"
void Person::setSurname() {
	char * newName = checkString();
	if (surname)
		delete surname;
	surname = new char[strlen(newName) + 1];
	strcpy(surname, newName);
}
void Person::inputSurname(char* sur) {
	surname = new char[strlen(sur) + 1];
	strcpy(surname, sur);
}
char* Person::getSurname() {
	return surname;
}
void Person::setName() {
	char * newName = checkString();
	if (name)
		delete name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}
void Person::inputName(char* nam) {
	name = new char[strlen(nam) + 1];
	strcpy(name, nam);
}
const char* Person::getName() {
	return name;
}

char* Person::randomSurname() {
	char* strSurn[] = { "Tiagai", "Movchan", "Kobzar", "Shevchenko", "Kyrylenko", "Parhomenko", "Ivanenko", "Kovalenko",
	"Stezenko", "Bydula", "Moskal", "Burulia", "Gumeniuk", "Levytskyi", "Sirko" };
	return strSurn[rand() % 15];
}
char* Person::randomName() {
	char* strName[] = { "Dmytro", "Kyrylo", "Bohdan", "Oleksyi", "Oleksandr", "Evgen", "Grygoryi", "Ivan", "Andryi",
	"Denys", "Danylo", "Stephan", "Petro", "Vasylyi", "Volodymyr", "Sergyi" };
	return strName[rand() % 16];
}
void Person::Show() {
	printf("%s %s ", surname, name); //ShowPerson
	Date::Show();
}
char* Person::checkString() {
	char mas[50];
	scanf("%s", mas);
	wait();
	char* val = new char[strlen(mas) + 1];
	strcpy(val, mas);

	return val;
}

inline void Person::wait() {
	while (getchar() != '\n');
}

Person &Person::operator=(const Person &p) {
	if (this == &p) {
		return *this;
	}

	Date::operator=(p);

	delete[] surname;
	delete[] name;
	surname = new char[strlen(p.surname) + 1];
	strcpy(surname, p.surname);
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);

	return *this;
}

Person::Person() : Date() {
	surname = new char[12];
	strcpy(surname, randomSurname());
	name = new char[12];
	strcpy(name, randomName());
}
Person::Person(char* sn, char* n, int date_day, int date_month, int date_year) : Date(date_day, date_month, date_year) {
	surname = new char[strlen(sn) + 1];
	strcpy(surname, sn);
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}
Person::Person(const Person& p) : Date(p) {
	surname = new char[strlen(p.surname) + 1];
	strcpy(surname, p.surname);
	name = new char[strlen(p.name) + 1];
	strcpy(name, p.name);
}
Person::~Person() {
	if (surname) delete[] surname;
	if (name) delete[] name;
}

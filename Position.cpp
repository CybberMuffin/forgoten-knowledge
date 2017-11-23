#include "Position.h"

Position::Position() {
	srand(time(NULL));
	title = new char[14];
	strcpy(title, randomTitle());
	salary = randomSalary();
	vacant = rand() % 2;
}

Position::Position(char* ttl, int slr, bool vcnt) {
	title = new char[strlen(ttl) + 1];
	strcpy(title, ttl);

	(slr < 10000 && slr > 1000) ? salary = slr : salary = 5000;
	
	vacant = vcnt;
}

Position::Position(const Position& p) {
	title = new char[strlen(p.title) + 1];
	strcpy(title, p.title);

	salary = p.salary;
	vacant = p.vacant;
}

Position::~Position() {
	if (title)
	delete[] title;
}

int Position::randomSalary() {
	int salary;
	salary = 100 * (10 + rand() % 90);

	return salary;
}
char* Position::randomTitle() {
	char* strTitles[] = { "Director", "Manager", "Programmer", "Engineer", "Administrator", "HR" };
	return strTitles[rand() % 6];
}
int Position::getSalary() {
	return salary;
}

Position &Position::operator=(const Position &p) {
	delete[] title;

	title = new char[strlen(p.title) + 1];
	strcpy(title, p.title);
	salary = p.salary;
	vacant = p.vacant;

	return *this;
}

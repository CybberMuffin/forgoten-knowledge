#include "Sector.h"
/*template<typename T>
inline int arrlen(T* arr)
{
	return static_cast<int>(_msize(arr) / sizeof(T));
}*/

Sector::Sector() : Person() {
	title = new char[24];
	strcpy(title, randomSector());
	size = 10;
	list = new Employee[size];
	
}

Sector::Sector(char* ttl, Employee* list, int size, char* surn, char* nam, int day, int month, int year) 
	: Person(surn, nam, day, month, year) {
	if (strlen(ttl) < 24) {
		title = new char[strlen(ttl) + 1];
		strcpy(title, ttl);
	}
	else {
		title = new char[24];
		strcpy(title, randomSector());
	}
	this->size = size;
	this->list = new Employee[this->size];
	for (size_t i = 0; i < this->size; i++)
		this->list[i] = list[i];
}

Sector::Sector(const Sector& p) : Person(p) {
	title = new char[strlen(p.title) + 1];
	strcpy(title, p.title);

	for (size_t i = 0; i < size; i++)
		list[i] = p.list[i];
}

char* Sector::randomSector() {
	char* title[] = { "IT", "Managing", "Commercial", "Finance", "Client Administration", "Engine Sector" };
	return title[rand() % 6];
}


Employee& Sector::operator[](int size) {
	
	if (size >= 0 && size < this->size)
		return list[size];
	else {
		printf("Array bounds violation.\n Incorrect index is %d", size);
		exit(0);
	}
}



/////////////////////////////////////////////////////////////////////////


strSector::strSector() : strPerson() {
	title = randomSector();
	list = new strEmployee[10];
}

strSector::strSector(std::string ttl, strEmployee* list, int size, std::string surn, std::string nam, int day, int month, int year)
	: strPerson(surn, nam, day, month, year) {
	if (ttl.size() < 24) title = ttl;
	else title = randomSector();
	this->size = size;
	this->list = new strEmployee[this->size];
	for (size_t i = 0; i < this->size; i++)
		this->list[i] = list[i];
}

strSector::strSector(const strSector& p) : strPerson(p) {
	title = p.title;
	for (size_t i = 0; i < size; i++)
		list[i] = p.list[i];
}

std::string strSector::randomSector() {
	std::string titles[] = { "IT", "Managing", "Commercial", "Finance", "Client Administration", "Engine Sector" };
	return titles[rand() % 6];
}


	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Used time: %lf seconds\n\n", duration);
}
strEmployee& strSector::operator[](int size) {

	if (size >= 0 && size < this->size)
		return list[size];
	else {
		printf("Array bounds violation.\n Incorrect index is %d", size);
		exit(0);
	}
}

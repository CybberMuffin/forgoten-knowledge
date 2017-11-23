#pragma once
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>

class Position {
protected:
	char* title;
	int salary;
	bool vacant;
public:
	Position();
	Position(char* ttl, int slr, bool vcnt);
	Position(const Position& p);
	~Position();

	Position &operator=(const Position &p);


	int randomSalary();
	char* randomTitle();
	int getSalary();

	void Show();
};
© 2017 GitHub, Inc.

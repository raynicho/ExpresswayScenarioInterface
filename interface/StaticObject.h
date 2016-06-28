#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Helpers.h"

using std::string;
using std::ostream;
using std::ifstream;

class StaticObject {
private:
	bool isNewObject;
	int colorIndex;
	int audioState;
	int option;
	int visualState;
	double orientation;
	string solName;
	string name;
	string longComment;
	string shortComment;
	position pos;

public:
	StaticObject();

	StaticObject(bool, int, int, int, int, double, string, string, string,
		string, position);

	void print(ostream &);

	void readFromFile(ifstream &);
};

#endif

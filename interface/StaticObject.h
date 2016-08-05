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
	//Default constructor.
    StaticObject();
    
    //Overloaded constructor.
	StaticObject(bool, int, int, int, int, double, string, string, string,
		string, position);

    /*
    Requires:   ostream is a valid ostream.
    Modifies:   ostream.
    Effects:    Prints the static object to ostream.
    */
	void print(ostream &);

    /*
    Requires:   ifstream is a valid input file stream.
    Modifies:   ifstream.
    Effects:    Reads the static object from the ifstream.
    */
	void readFromFile(ifstream &);
};

#endif

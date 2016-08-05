#ifndef VIRTUALOBJECT_H
#define VIRTUALOBJECT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Helpers.h"

using std::string;
using std::ifstream;
using std::ostream;
using std::vector;

class VirtualObject {
private:
	/*
	unused
	string TargetName ""
	double BlinkOff 1.0000000E+000
	double BlinkOn 1.0000000E+000
	bool IsBlinking 0
	int DrawType 0
	*/

	//optional
	string groupName;

	//common
	int option;
	double orientation;
	string solName;
	string name;
	string iconName;
	string longComment;
	string shortComment;
	position pos;
	position drawPosition;
	color fillColor;
	color boarderColor;
	drawSize draw;
	vector <state> states;

public:
    //Default constructor.
	VirtualObject();

    //Overloaded constructor.
	VirtualObject(string, int, double, string, string, string, string, 
		string, position, position, color, color, drawSize, vector<state> &);

    /*
    Requires:   ifstream is a valid input stream.
    Modifies:   ifstream.
    Effects:    Reads the VirtualObject from the ifstream.
    */
	void readFromFile(ifstream &);

    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Prints the states vector to ostream.
    */
	void printStates(ostream &);

    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Prints the VirtualObject vector to ostream.
    */
	void print(ostream &);
};

#endif

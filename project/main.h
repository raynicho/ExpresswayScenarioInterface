#pragma once
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using std::ostream;
using std::ifstream;
using std::string;
using std::vector;

string getFilePath() {
	string path = "C:\\Users\\raynicho\\Desktop\\SCNHighwayTemplate\\SCNExampleFiles\\base.scn";
	return path;
}

double stringToDouble(string scientificNotation) {
	return 0;
}

struct position {
	double x;
	double y;
	double z = 0;
	position(double X, double Y) : x(X), y(Y) {
	}
	position() : x(0), y(0) {}
	position (double X, double Y, double Z) : x(X), y(Y), z(Z) {}
};

struct trajectory {
	double x;
	double y;
	double speed;
	double xDir;
	double yDir;
};

struct color {
	double a;
	double b;
	double c;
	double d;
};

struct drawSize {
	double width;
	double heighth;
};

struct state {
	vector<double> stateVector;
	int stateOne;
	int stateTwo;
	string stateString;
};
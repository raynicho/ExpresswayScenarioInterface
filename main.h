#pragma once
#include <string>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>

using std::ostream;
using std::ifstream;
using std::string;

string getFilePath() {
	string path = "C:\\Users\\raynicho\\Desktop\\ExpresswayCreationInterface\\SCNExampleFiles\\ke.scn";
	return path;
}

string changeToScn(string filePath) {
	return filePath.substr(0, filePath.find_last_of('.')) + ".txt";
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
};

struct trajectory {
	double x;
	double y;
	double speed;
	double xDir;
	double yDir;
};
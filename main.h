#pragma once
#include <string>
#include <cassert>
#include <iostream>

using std::string;

string getFilePath() {
	string path = "C:\\Users\\raynicho\\Desktop\\ExpresswayCreationInterface\\SCNExampleFiles\\base.scn";
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
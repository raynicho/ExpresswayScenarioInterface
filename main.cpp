#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include "expresswayClass.h"
#include <exception>
#include <cassert>

using namespace std;

int main() {
	string filePath = getFilePath();

	ExpresswayScenario expressway;

	try {
		expressway.readFile(filePath);
	}

	catch (exception &e) {
		cout << e.what() << '\n';
		return 0;
	}

	//string s;
	//ifstream input;
	//input.open("C:\\Users\\raynicho\\Desktop\\ExpresswayCreationInterface\\SCNExampleFiles\\test.txt");
	//input >> s;
	//getline(input, s);
	//cout << s << endl;
	//input >> s;
	//cout << s << endl;

	return 0;
}
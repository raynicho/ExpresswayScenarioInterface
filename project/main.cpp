#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include "SCNHighwayTemplate.h"
#include <exception>
#include <cassert>

using namespace std;

int main() {
	string filePath = getFilePath();

	SCNHighwayTemplate expressway;

	try {
		expressway.readFile(filePath);
	}

	catch (exception &e) {
		cout << e.what() << '\n';
		return 0;
	}

	expressway.writeFile("C:\\Users\\raynicho\\Desktop\\SCNHighwayTemplate\\SCNExampleFiles\\test.scn");

	return 0;
}
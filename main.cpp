#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include "expresswayClass.h"
#include <exception>

using namespace std;

int main() {
	string filePath = getFilePath ();
	string txtFilePath = changeToScn(filePath);

	int result = rename (filePath.c_str (), txtFilePath.c_str ());

	ExpresswayScenario expressway;
	
	try {
		expressway.readFile(txtFilePath);
	}

	catch (exception &e){
		cout << e.what() << '\n';
		return 0;
	}

	result = rename(txtFilePath.c_str (), filePath.c_str ());

	return 0;
}
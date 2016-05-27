#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "main.h"
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "triggers.h"

using std::string;
using std::vector;
using std::cout;

class ExpresswayScenario {
private:
	const int trialLength = 4000;
	double endOfRoad;
	double startingYPosition;
	double startingXPosition;
	double roadwayStartX = 0;
	double roadwayStartY = 0;
	char ownHeading;
	vector <trigger*> triggers;
	vector <vehicle*> vehicles;
	std::ofstream out;

public:

	//reads in the file: header, triggers, vehicles, etc.
	void readFile(string filePathAsTxt) {
		//open the filestream
		std::ifstream inputStream;
		inputStream.open(filePathAsTxt);

		//if its not open
		if (!inputStream.is_open()) {
			//throw an error to be caught in main
			std::exception e("Filename not entered correctly. Exiting program.");
			inputStream.close();
			throw e;
		}

		out.open("C:\\Users\\raynicho\\Desktop\\ExpresswayCreationInterface\\SCNExampleFiles\\test.txt");

		//begin  g the file by reading the header
		this->parseHeader(inputStream);

		//begin reading everything else
		this->readRest(inputStream);

		//close the file when done
		inputStream.close();
		return;
	}

	//responsible for reading in information from the header
	void parseHeader(std::ifstream &txtFileStream) {
		//check to make sure that the user has put the external driver in the simulation
		string posOrOrientation = this->checkForExternalDriver(txtFileStream);
		int endOfXString = 0;

		//if the position comes first
		if (posOrOrientation.substr(2, 18) == "OwnVehiclePosition") {
			//write the positions first
			this->startingXPosition = getStartingXPos(posOrOrientation, endOfXString);
			this->startingYPosition = getStartingYPos(posOrOrientation, endOfXString);

			//then retreive the orientation and write it
			string ownOrientation;
			getline(txtFileStream, ownOrientation);
			this->setHeading(ownOrientation);
		}

		//must be that the orientation comes first
		else {
			//write the orientation
			this->setHeading(posOrOrientation);

			//then retrieve the position and write it
			string ownPosition;
			getline(txtFileStream, ownPosition);
			this->startingXPosition = getStartingXPos(ownPosition, endOfXString);
			this->startingYPosition = getStartingYPos(ownPosition, endOfXString);
		}

		string findEnd;
		getline(txtFileStream, findEnd);
		while (findEnd != "&&&&End&&&&") {
			getline(txtFileStream, findEnd);
		}
		return;
	}

	//responsible for checking that the external driver is in the scenario
	//returns the string that contains the 
	string checkForExternalDriver(std::ifstream &txtFileStream) {
		string find;
		txtFileStream >> find;

		//search over the file until the vehicle position is reached
		while (find != "CabType") {
			txtFileStream >> find;
		}
		txtFileStream >> find;
		getline(txtFileStream, find);
		getline(txtFileStream, find);

		//if the position is not found
		if (find.substr(2, 18) != "OwnVehiclePosition" && find.substr(2, 21) != "OwnVehicleOrientation") {
			std::exception e("Please place the external driver in the scenario and re-run the interface.");
			txtFileStream.close();
			throw e;
		}
		return find;
	}

	//responsible for parsing the position string for the x position
	double getStartingXPos(string vehiclePosition, int &endOfXString) {
		//find the whitespace after the beginning of the x position
		int i = 21;
		int spacesTillEmpty = 0;
		while (vehiclePosition[i] != ' ') {
			i++;
			spacesTillEmpty++;
		}
		endOfXString = i;

		//compose the string to hold the scientific notation double
		string xDouble = vehiclePosition.substr(21, spacesTillEmpty);

		//find the 'E' and make it a 'e'
		std::size_t found = xDouble.find('E');
		xDouble[found] = 'e';

		//convert it to a double using string streams
		std::istringstream os(xDouble);
		double d;
		os >> d;
		return d;
	}

	//responsible for parsing the position string for the y position
	double getStartingYPos(string vehiclePosition, int endOfXString) {
		//find the whitespace after the beginning of the x position
		endOfXString++;
		int i = endOfXString;
		int spacesTillEmpty = 0;
		while (vehiclePosition[i] != ' ') {
			i++;
			spacesTillEmpty++;
		}

		//compose the string to hold the scientific notation double
		string yDouble = vehiclePosition.substr(endOfXString, spacesTillEmpty);

		//convert it to a double using string streams
		std::istringstream os(yDouble);
		double d;
		os >> d;
		return d;
	}

	//interprets the vehicles heading by parsing the oreintation string
	void setHeading(string ownOrientation) {
		ownHeading = 'N';
		return;
	}

	void readRest(std::ifstream &txtFileStream) {
		string inputCase;
		getline(txtFileStream, inputCase);
		while (!txtFileStream.eof()) {
			if (inputCase == "HCSM Gateway") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM VehFail") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM TrafficManager") {
				getline(txtFileStream, inputCase);
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM EnvironmentController") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM TrafficLightManager") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM StaticObjManager") {
				for (unsigned int i = 0; i < 12; i++) {
					getline(txtFileStream, inputCase);
				}
			}
			else if (inputCase == "HCSM DriverMirror") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM IntersectionManager") {
				getline(txtFileStream, inputCase);
			}
			else if (inputCase == "HCSM ExpressionTrigger") {
				trigger* newTrigger = new expressionTrigger;
				newTrigger->fileRead(txtFileStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM RoadPadTrigger") {
				trigger* newTrigger = new roadPadTrigger;
				newTrigger->fileRead(txtFileStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM TimeTrigger") {
				trigger* newTrigger = new timeTrigger;
				newTrigger->fileRead(txtFileStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM Ddo") {
				vehicle* newVehicle = new DDO;
				newVehicle->readFromFile(txtFileStream);
				vehicles.push_back(newVehicle);
			}
			else if (inputCase == "HCSM Ado") {
				vehicle* newVehicle = new ADO;
				newVehicle->readFromFile(txtFileStream);
				vehicles.push_back(newVehicle);
			}
			getline(txtFileStream, inputCase);
		}
		return;
	}

	~ExpresswayScenario() {
		for (unsigned int i = 0; i < vehicles.size(); i++) {
			delete vehicles[i]; vehicles[i] = 0;
		}
		for (unsigned int i = 0; i < triggers.size(); i++) {
			delete triggers[i]; triggers[i] = 0;
		}
	}
};
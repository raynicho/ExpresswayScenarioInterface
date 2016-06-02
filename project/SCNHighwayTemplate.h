#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <exception>
#include "Trigger.h"
#include "main.h"
#include "staticObject.h"
#include "VirtualObject.h"
#include "Vehicle.h"
#include "SCNHeader.h"

using std::string;
using std::vector;
using std::cout;
using std::ifstream;
using std::ostream;
using std::ofstream;

class SCNHighwayTemplate {
private:
	const int trialLength = 4000;
	double endOfRoad;
	double roadwayStartX = 0;
	double roadwayStartY = 0;
	char ownHeading;
	SCNHeader header;
	vector <Trigger*> triggers;
	vector <Vehicle*> vehicles;
	vector <StaticObject> staticObjects;
	vector <VirtualObject> virtualObjects;

public:
	
	void printUnusedSCNObjects(ostream &outStream) {
		outStream << "HCSM DriverMirror\n&&&&End&&&&\n";
		outStream << "HCSM IntersectionManager\n&&&&End&&&&\n";
		return;
	}

	void writeFile(string outputFilePath) {
		//open the file
		ofstream outStream;
		outStream.open(outputFilePath);

		//print the header
		header.print(outStream);

		//gateway and vehicle fail
		outStream << "HCSM Gateway\n&&&&End&&&&\n";
		outStream << "HCSM VehFail\n&&&&End&&&&\n";

		//print the static objects
		outStream << "HCSM StaticObjManager\n";
		for (auto stat : staticObjects) {
			stat.print(outStream);
		}
		outStream << "&&&&End&&&&\n";

		//print the traffic manager
		outStream << "HCSM TrafficLightManager\n  GroupName \"Traffic Manager\"\n&&&&End&&&&\n";

		//print the environment controller
		outStream << "HCSM EnvironmentController\n&&&&End&&&&\n";

		//print the traffic light manager
		outStream << "HCSM TrafficLightManager\n&&&&End&&&&\n";

		//print the triggers
		for (auto trigger : triggers) {
			trigger->filePrint(outStream);
		}

		//print the vehicles, only the non created ones
		for (auto vehicle : vehicles) {
			if (!vehicle->getCreation()) {
				vehicle->print(outStream);
			}
		}

		//print the virtual objects
		for (auto virt : virtualObjects) {
			virt.print(outStream);
		}

		printUnusedSCNObjects(outStream);
		
		outStream.close();
		return;
	}

	//reads in the file: header, triggers, vehicles, etc.
	void readFile(string SCNFilePath) {
		//open the filestream
		ifstream inputStream;
		inputStream.open(SCNFilePath);

		//if its not open
		if (!inputStream.is_open()) {
			//throw an error to be caught in main
			std::exception e("Filename not entered correctly. Exiting program.");
			inputStream.close();
			throw e;
		}

		//begin reading the file by reading the header
		this->readHeader(inputStream);

		//begin reading everything else
		this->readRest(inputStream);

		//close the file when done
		inputStream.close();

		//write the header and see what happens
		//ofstream out;
		//out.open("C:\\Users\\raynicho\\Desktop\\SCNHighwayTemplate\\SCNExampleFiles\\test.txt");
		//header.print(out);
		//out.close();
		return;
	}

	//responsible for reading in information from the header
	void readHeader(ifstream &inputStream) {
		if (!header.readFromFile(inputStream)) {
			std::exception e("The scn file entered does not have a vehicle position entered.");
		}
		return;
	}

	void readInStaticObjManager(ifstream &inputStream) {
		string currentLine;
		inputStream >> currentLine;
		while (currentLine != "&&&&End&&&&") {
			inputStream >> currentLine;
			StaticObject s;
			s.readFromFile(inputStream);
			staticObjects.push_back(s);
			inputStream >> currentLine;
		}
		return;
	}

	void readRest(ifstream &inputStream) {
		string inputCase;
		getline(inputStream, inputCase);
		while (!inputStream.eof()) {
			if (inputCase == "HCSM Gateway") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM VehFail") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM TrafficManager") {
				getline(inputStream, inputCase);
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM EnvironmentController") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM TrafficLightManager") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM StaticObjManager") {
				readInStaticObjManager(inputStream);
			}
			else if (inputCase == "HCSM DriverMirror") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM IntersectionManager") {
				getline(inputStream, inputCase);
			}
			else if (inputCase == "HCSM ExpressionTrigger") {
				Trigger* newTrigger = new expressionTrigger;
				newTrigger->fileRead(inputStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM RoadPadTrigger") {
				Trigger* newTrigger = new roadPadTrigger;
				newTrigger->fileRead(inputStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM TimeTrigger") {
				Trigger* newTrigger = new timeTrigger;
				newTrigger->fileRead(inputStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM Ddo") {
				Vehicle* newVehicle = new DDO;
				newVehicle->readFromFile(inputStream);
				vehicles.push_back(newVehicle);
			}
			else if (inputCase == "HCSM Ado") {
				Vehicle* newVehicle = new ADO;
				newVehicle->readFromFile(inputStream);
				vehicles.push_back(newVehicle);
			}
			else if (inputCase == "HCSM StaticObject") {
				StaticObject s;
				s.readFromFile(inputStream);
				staticObjects.push_back(s);
			}
			else if (inputCase == "HCSM VirtualObject") {
				VirtualObject v;
				v.readFromFile(inputStream);
				virtualObjects.push_back(v);
			}
			else {
				//string Error = "Unexpected object encountered: ";
				if (!inputCase.empty()) {
					cout << inputCase << '\n';
				}
			}
			getline(inputStream, inputCase);
		}
		//cout << "Completed reading the file.\n";
		return;
	}

	~SCNHighwayTemplate() {
		//delete the vehicles
		for (unsigned int i = 0; i < vehicles.size(); i++) {
			delete vehicles[i]; vehicles[i] = 0;
		}

		//delete the triggers
		for (unsigned int i = 0; i < triggers.size(); i++) {
			delete triggers[i]; triggers[i] = 0;
		}
	}
};
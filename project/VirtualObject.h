#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "main.h"

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
	int stateOne;
	int stateTwo;
	int option;
	double orientation;
	string stateString;
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
	vector <double> states;

public:
	VirtualObject() : groupName("-1"), stateString("") {}

	VirtualObject(string GroupName, int StateOne, int StateTwo, int Option, double Orientation, string StateString, string Sol,
		string Name, string IconName, string LongComment, string ShortComment, position Pos, position DrawPos, color fill, color boarder,
		drawSize Draw, vector<double> &States) : groupName(GroupName), stateOne(StateOne), stateTwo(StateTwo), option(Option), orientation(Orientation),
		stateString(StateString), solName(Sol), name(Name), iconName(IconName), longComment(LongComment), shortComment(ShortComment),
		pos(Pos), drawPosition(DrawPos), fillColor(fill), boarderColor(boarder), draw(Draw), states(States) {}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "GroupName") {
				getline(inputStream, groupName);
			}
			else if (current == "States") {
				//fill the vector
				for (int i = 0; i < 12; i++) {
					double state;
					inputStream >> state;
					states.push_back(state);
					inputStream >> current;
				}

				//get state 1 and state 2
				inputStream >> stateOne;
				inputStream >> current;
				inputStream >> stateTwo;

				//get the state string
				inputStream >> current;
				getline(inputStream, stateString);
			}
			else if (current == "Option") {
				inputStream >> option;
			}
			else if (current == "Orientation") {
				inputStream >> orientation;
			}
			else if (current == "SolName") {
				inputStream >> solName;
			}
			else if (current == "Name") {
				getline(inputStream, name);
			}
			else if (current == "IconName") {
				getline(inputStream, iconName);
			}
			else if (current == "LongComment") {
				getline(inputStream, longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, shortComment);
			}
			else if (current == "Position") {
				inputStream >> pos.x >> pos.y >> pos.z;
			}
			else if (current == "DrawPosition") {
				inputStream >> drawPosition.x >> drawPosition.y >> drawPosition.z;
			}
			else if (current == "FillColor") {
				inputStream >> fillColor.a >> fillColor.b >> fillColor.c >> fillColor.d;
			}
			else if (current == "BoarderColor") {
				inputStream >> boarderColor.a >> boarderColor.b >> boarderColor.c >> boarderColor.d;
			}
			else if (current == "DrawSize") {
				inputStream >> draw.width >> draw.heighth;
			}
			inputStream >> current;
		}
		return;
	}

	void print(ostream &outStream) {
		outStream << "HCSM VirtualObject\n";
		if (groupName != "-1") {
			outStream << "GroupName " << groupName << '\n';
		}
		outStream << "TargetName \"\"\n";
		outStream << "DrawPosition " << std::setprecision(7) << std::scientific << drawPosition.x << " " << drawPosition.y
			<< " " << drawPosition.z << '\n';
		outStream << "BlinkOff 1.0000000E+000\n";
		outStream << "BlinkOn 1.0000000E+000\n";
		outStream << "IsBlinking 0\n";
		outStream << "FillColor " << fillColor.a << " " << fillColor.b << " " << fillColor.c << " " << fillColor.d << '\n';
		outStream << "DrawSize " << draw.width << " " << draw.heighth << '\n';
		outStream << "IconName " << iconName << '\n';
		for (int i = 0; i < (int)states.size(); i++) {
			outStream << "States " << states[i] << '\n';
		}
		outStream << "States " << stateOne << '\n';
		outStream << "States " << stateTwo << '\n';
		outStream << "States " << stateString << '\n';
		outStream << "Option " << option << '\n';
		outStream << "DrawType 0\n";
		outStream << "LongComment " << longComment << '\n';
		outStream << "ShortComment " << shortComment << '\n';
		outStream << "Position " << pos.x << " " << pos.y << " " << pos.z << '\n';
 		return;
	}
};
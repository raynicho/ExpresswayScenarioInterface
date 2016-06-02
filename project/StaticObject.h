#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ostream;
using std::ifstream;

class StaticObject {
private:
	bool isNewObject;
	int colorIndex;
	int audioState;
	int option;
	int visualState;
	double orientation;
	string solName;
	string name;
	string longComment;
	string shortComment;
	position pos;

public:
	StaticObject() : isNewObject(false), audioState(0), option(0), visualState(0), orientation(0), longComment(" "),
		shortComment(" "), colorIndex(-1) {}

	StaticObject(bool isNew, int color, int audio, int Option, int visual, double Orientation, string sol, string Name, string Long,
		string Short, position Pos) : isNewObject(isNew), colorIndex(color), audioState(audio), option(Option), visualState(visual), orientation(Orientation),
		solName(sol), name(Name), longComment(Long), shortComment(Short), pos(Pos) {}

	void print(ostream &outStream) {
		string spaces = "      ";
		string spacesTillTitle = "    ";
		outStream << spacesTillTitle << "HCSM StaticObject\n";
		outStream << spaces << "IsNewObj " << isNewObject << '\n';
		outStream << spaces << "AudioState " << audioState << '\n';
		outStream << spaces << "VisualState " << visualState << '\n';
		outStream << spaces << "LongComment " << longComment << '\n';
		outStream << spaces << "ShortComment " << shortComment << '\n';
		outStream << spaces << "Orientation " << std::setprecision(7) << std::scientific << orientation << '\n';
		outStream << spaces << "SolName " << solName << '\n';
		outStream << spaces << "Name " << name << '\n';
		outStream << spaces << "Option " << option << '\n';
		if (colorIndex != -1) {
			outStream << spaces << "ColorIndex " << colorIndex << '\n';
		}
		outStream << spaces << "Position " << pos.x << " " << pos.y << " " << pos.z << '\n';
		outStream << spacesTillTitle << "&&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "IsNewObj") {
				inputStream >> isNewObject;
			}
			else if (current == "AudioState") {
				inputStream >> audioState;
			}
			else if (current == "VisualState") {
				inputStream >> visualState;
			}
			else if (current == "LongComment") {
				getline(inputStream, longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, shortComment);
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
			else if (current == "Option") {
				inputStream >> option;
			}
			else if (current == "Position") {
				inputStream >> pos.x >> pos.y >> pos.z;
			}
			else if (current == "ColorIndex"){
				inputStream >> colorIndex;
			}
			inputStream >> current;
		}
		return;
	}
};
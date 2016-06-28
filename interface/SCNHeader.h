#ifndef SCNHEADER_H
#define SCNHEADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Helpers.h"

using std::ostream;
using std::ifstream;
using std::string;

class SCNHeader {
private:
	string LRIFile;						position ownVehiclePosition;
	position ownVehicleOrientation;		string motionDrive;
	string motionSettings;				bool headLightsOn;
	int envMinute;						int envDay;
	int envHour;						int envYear;
	int envMonth;						double envLat;
	double envLong;						double envAlt;
	double headlightCutOffDist;			string trailerType;
	string visualSettings;				int sirensOverSpeed;
	int collisionEffectMask;			bool showCab;
	string cabType;						double scenePosX;
	double scenePosY;					double sceneZoom;
	string cellName;					string writeCellName;

	/*
	unused
	InitialTireConditions 1 1 1 1 1 1 1 1 1 1
	InitialBrakeConditions 0 1 1 1 1 1 1 1 1 1 1
	SirenSpeed 6.2000000E+001
	BlankRed 0.0000000E+000
	BlankGreen 0.0000000E+000
	BlankBlue 0.0000000E+000
	*/

public:
	SCNHeader();

	void print(ostream &);

	bool readFromFile(ifstream &);
};

#endif

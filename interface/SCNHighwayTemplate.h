#ifndef SCNHIGHWAYTEMPLATE_H
#define SCNHIGHWAYTEMPLATE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <exception>
#include <random>
#include <stdlib.h>
#include "Trigger.h"
#include "staticObject.h"
#include "VirtualObject.h"
#include "Vehicle.h"
#include "SCNHeader.h"
#include "Helpers.h"
#include "MajorSettings.h"
#include "Trial.h"

using std::string;
using std::vector;
using std::cout;
using std::ifstream;
using std::ostream;
using std::ofstream;

class SCNHighwayTemplate {
private:
	const double trialLengthFt = 3750;
    const double trialSetupLengthFt = 1250;
	double roadwayStartX = 0;
	double roadwayStartY = 0;
	SCNHeader header;
    std::default_random_engine re;
    vector <string> carSolModels;
    vector <string> truckSolModels;
	vector <Trigger*> triggers;
	vector <Vehicle*> vehicles;
	vector <StaticObject> staticObjects;
	vector <VirtualObject> virtualObjects;

public:
	//destructor
	~SCNHighwayTemplate();
    
    //constructor
    SCNHighwayTemplate ();
    
    void processLeadVehicle (FVLVInstructions &, ostream &);
    
    void processFollowVehicle (FVLVInstructions &, ostream &);
    
    void processRoadSide(roadSideControl &, ostream &, int);
    
    void generateFollowVehicle (FVLVSettings &, ostream &);
    
    void generateLeadVehicle (FVLVSettings &, ostream &);
    
    double randDouble (double, double);
    
    string getRandSol (bool);
    
    //returns true if it is truck or false if it is to be a car
    bool truckOrCar (int, int);
    
    int getRandSolColor (string);
    
    void generateTraffic (int, int, int, int, ostream &);
    
    void processLeftLane (leftLaneControl &, ostream &, int);
    
    void generateBlindSpot (vector<Trial> &, ostream &);
    
    void generateFCW (FCW &, vector<Trial> &, ostream &);
    
    void processAll (vector<Trial> &, MajorSettings &, ostream &);

	void printUnusedSCNObjects(ostream &);

    void clearTillEnd (ifstream &);

	void writeFile(string, vector<Trial> &, MajorSettings &);

	//reads in the file: header, triggers, vehicles, etc.
	void readFile(string);

	//responsible for reading in information from the header
	void readHeader(ifstream &);

	void readInStaticObjManager(ifstream &);

	void readRest(ifstream &);
    
    void speedLeadVehicle (int, ostream &, int);
    
    void slowFollowVehicle (int, ostream &, int);
    
    void roadSidePullFront (int, roadSideControl &, ostream &);
    
    void roadSideStationary (int, roadSideControl &, ostream &);
    
    void roadSidePullFrontStop (int, roadSideControl &, ostream &);
    
    void roadSideDriveShoulder (int, roadSideControl &, ostream &);
    
    void leftLaneBlindSpot (int, leftLaneControl &leftLane, ostream &outStream);
    
    void leftLaneCutBehind (int, leftLaneControl &, ostream &);
    
    void leftLaneCutFront (int, leftLaneControl &, ostream &);
    
    void leftLaneRemainLane (int, leftLaneControl &, ostream &);
    
    void leftLaneSlowDown (int, string, ostream &, vector<Action*> &);
};

#endif

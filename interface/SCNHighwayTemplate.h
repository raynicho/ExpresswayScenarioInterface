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
    
    
    /*
    Requires:   ostream is a valid output stream. 
    Modifies:   ostream.
    Effects:    If the lead vehicle option is selected, either the FVLVMatchET function is called if it
                is match the external driver or speedLeadVehicle is called with the specific speed. If 
                the lane change option is checked, then the laneChange function is called.
    */
    void processLeadVehicle (FVLVInstructions &, ostream &, int);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    If the follow vehicle option is selected, either the FVLVMatchET function is called if it
                is match the external driver or slowFollowVehicle is called with the specific speed. If 
                the lane change option is checked, then the laneChange function is called.
    */
    void processFollowVehicle (FVLVInstructions &, ostream &, int);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Calls the appropriate roadside vehicle function based on the movement option of the 
                roadSideControl input.
    */
    void processRoadSide(roadSideControl &, ostream &, int);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Creates and prints the follow vehicle to the ostream.
    */
    void generateFollowVehicle (FVLVSettings &, ostream &);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Creates and prints the lead vehicle to the ostream.
    */
    void generateLeadVehicle (FVLVSettings &, ostream &);
    
    /*
    Requires:   The first double is greater than the second.
    Modifies:   N/A
    Effects:    Generates a random double using a uniform distribution and returns that double.
    */
    double randDouble (double, double);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    If the bool is true, returns a random truck sol model as a string. If false, returns a
                random car sol model as a string.
    */
    string getRandSol (bool);
    
    //returns true if it is truck or false if it is to be a car
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns true if the next sol model in opposing truck generation is to be a truck or false
                if it is to be a car. If the first int is 0, return true. If the second int is 0, return
                false. Otherwise generate a random interger and if it is even, return true. Else return
                false.
    */
    bool truckOrCar (int, int);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns a valid color integer based on the sol model given.
    */
    int getRandSolColor (string);
    
    /*
    Requires:   ostream is a valid output stream. 
    Modifies:   ostream.
    Effects:    Creates numberCarsPerTrial every trial with numberOfCars as the amount of cars in a trial
                and numberOfTrucks as the number of trucks per trial. Prints the vehicles to the ostream.
    */
    void generateTraffic (int numberTrials, int numberCarsPerTrial, int numberOfCars, int numberOfTrucks, ostream &);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Calls the appropriate left lane function based on the leftLaneControl movement option.
    */
    void processLeftLane (leftLaneControl &, ostream &, int);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Calls functions to generate left and right blind spot warnings.
    */
    void generateBlindSpot (vector<Trial> &, ostream &);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Generates the FCW based on the user input.
    */
    void generateFCW (FCW &, vector<Trial> &, ostream &);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Process all trials and major file settings.
    */
    void processAll (vector<Trial> &, MajorSettings &, ostream &);

    /*
    Requires:   ostream is a valid ostream.
    Modifies:   ostream.
    Effects:    Prints unused SCN objects to the ostream.
    */
	void printUnusedSCNObjects(ostream &);

    /*
    Requires:   ifstream is a valid input file stream.
    Modifies:   ifstream.
    Effects:    Continues to read ifstream until it encounters a string "&&&&End&&&&".
    */
    void clearTillEnd (ifstream &);

    /*
    Requires:   string is a valid file path.
    Modifies:   N/A
    Effects:    Writes the header, all static objects, triggersm vehicles, and virtual objects to the
                first string (a file path).
    */
	void writeFile(string, vector<Trial> &, MajorSettings &);

    /*
    Requires:   string is a valid file path.
    Modifies:   N/A
    Effects:    Reads in a file: header, triggers, etc.
    */
	void readFile(string);

    /*
    Requires:   ifstream is a valid input stream.
    Modifies:   ifstream.
    Effects:    Reads in the header information.
    */
	void readHeader(ifstream &);

    /*
    Requires:   ifstream is a valid input stream.
    Modifies:   ifstream.
    Effects:    Reads in the static object manager.
    */
	void readInStaticObjManager(ifstream &);

    /*
    Requires:   ifstream is a valid input stream.
    Modifies:   ifstream.
    Effects:    Reads in the rest of the SCN file after the header has been read in.
    */
	void readRest(ifstream &);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Speeds the lead vehicle across 50% of the given trial at the given speed.
    */
    void speedLeadVehicle (int trialNum, ostream &, int speed);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Forces the vehicle given by the vehName to match the external driver's speed across the
                given trial number for the given trialPercentage. Prints all objects to the ostream.
    */
    void FVLVMatchET(int trialNum, ostream &, int trialPercentage, string vehName);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Speeds the lead vehicle over the given trial, at the given speed, for the given 
                percentage of the trial. Prints all objects to the ostream.
    */
    void speedLeadVehicle (int trialNum, ostream &, int speed, int trialPercentage);
    
    /*
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Slows the follow vehicle over the given trial to the given speed. Prints all SCN objects
                to the ostream.
    */
    void slowFollowVehicle (int trialNum, ostream &, int speed);
    
    /*
    Requires:   ostream us a valid output stream.
    Modifies:   ostream.
    Effects:    Slows the follow vehicle over the given trial to the given speed for the given percentage
                of the trial. Prints all SCN objects to the ostream.
    */
    void slowFollowVehicle (int trialNum, ostream &, int speed, int trialPercentage);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void roadSidePullFront (int, roadSideControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void roadSideStationary (int, roadSideControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void roadSidePullFrontStop (int, roadSideControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void roadSideDriveShoulder (int, roadSideControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void leftLaneBlindSpot (int, leftLaneControl &leftLane, ostream &outStream);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void leftLaneCutBehind (int, leftLaneControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void leftLaneCutFront (int, leftLaneControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void leftLaneRemainLane (int, leftLaneControl &, ostream &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void leftLaneSlowDown (int, string, ostream &, vector<Action*> &);
    
    /*
    Requires:   
    Modifies:   
    Effects:    
    */
    void laneChange (int, ostream &, string, int);
};

#endif

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;

enum blinkerControl {Hazards, Right, Left, None};

struct roadSideControl {
	bool addToList;
	bool checked;
	//0 = remain stationary
	//1 = pull out in front
	//2 = drive on shoulder
	//3 = pull out in front and stop
	int movementOption;
	double speed;
	double distance;
	//0 = pull to side
	//1 = slow down
    int deletionOption;
	blinkerControl blinker;
    roadSideControl () : addToList(false), checked(false), movementOption(-1), speed(0), distance(0), deletionOption(-1), blinker(None) {}
};

struct leftLaneControl {
	bool addToList;
	bool checked;
	//0 = blind spot
	//1 = cut behind driver
	//2 = cut in front of driver
	//3 = remain in lane
	int movementOption;
	//0 = absolute
	//1 = match driver
	int laneOption;
	//0 = behind
	//1 = front
    int creationOption;
	double distance;
    double speed;
    double creationDistance;
	blinkerControl blinker;
    leftLaneControl () : addToList(false), checked(false), movementOption(-1), laneOption(-1), creationOption(-1), distance(0), speed(0), blinker(None){}
};

struct FVLVInstructions {
	bool checked;
	double maxFollow;
	//true when a velocity change is present
	bool velocityChange;
	//0 = match the external driver
	//1 = absolute speed
	int velocityChangeOption;
	double absoluteSpeed;
	//true when forcing a lane change
	bool forceLaneChange;
	double forceLaneSpeed;
    double forceLaneAcceleration;
    FVLVInstructions () : checked(false), maxFollow(0), velocityChange(0), velocityChangeOption(-1), absoluteSpeed(0), forceLaneChange(false), forceLaneSpeed(0), forceLaneAcceleration(0) {}
};

struct Trial {
    int trialNumber;
	roadSideControl roadSide;
	leftLaneControl leftLane;
	FVLVInstructions followVehicle;
	FVLVInstructions leadVehicle;
    Trial () : trialNumber(-1), roadSide(), leftLane(), followVehicle(), leadVehicle(){}
};

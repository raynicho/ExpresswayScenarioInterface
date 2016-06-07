#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::vector;

enum blinkerControl {Hazards, Right, Left, None};

enum lifeTime {Experiment, TrialOnly};

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
	lifeTime life;
	blinkerControl blinker;
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
	double absoluteSpeed;
	double distance;
	double speed;
	lifeTime life;
	blinkerControl blinker;
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
};

struct Trial {
    int trialNumber;
	roadSideControl roadSide;
	leftLaneControl leftLane;
	FVLVInstructions followVehicle;
	FVLVInstructions leadVehicle;
};

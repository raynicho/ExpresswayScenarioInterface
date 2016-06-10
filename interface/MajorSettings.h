#pragma once
#include <string>
#include <vector>
#include "Helpers.h"

using std::string;

enum shape {Square, Triangle, Circle};

struct FVLVSettings {
	string SOLModel;
	double distance;
	double maxSpeed;
	double minSpeed;
	double maxAccel;
	double minAccel;
};

struct FCW {
    bool checked;
	position pos;
	double frequency;
	shape imageShape;
	string color;
	position start;
	position end;
};

struct animation {
    bool checked;
    position start;
    position end;
};

struct MajorSettings {
	bool generateTraffic;
	double lengthOfRoad;
	bool showBlindSpot;
    FVLVSettings followVehicle;
    FVLVSettings leadVehicle;
};
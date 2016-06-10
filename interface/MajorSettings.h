#pragma once
#include <string>
#include <vector>
#include "Helpers.h"
#include <QColor>

using std::string;

enum shape {Triangle, Circle, Octagon, Star, Diamond, Icon, Rectangle, Hexagon};

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
    bool animationOn;
    double frequency;
    string iconName;
    QColor FCWColor;
	position pos;
	shape imageShape;
};

struct animation {
    bool checked;
    position start;
    position end;
};

struct MajorSettings {
	bool generateTraffic;
	double numberTrials;
	bool showBlindSpot;
    FVLVSettings followVehicle;
    FVLVSettings leadVehicle;
    FCW warningSettings;
};

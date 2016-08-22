#ifndef MAJORSETTINGS_H
#define MAJORSETTINGS_H

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
	double maxDeccel;
};

struct FCW {
    bool checked;
    double frequency;
    double distance;
    double periodOn;
    string iconName;
    QColor FCWColor;
	position pos;
	shape imageShape;
    FCW () : checked(false){}
};

struct animation {
    bool checked;
    position start;
    position end;
    animation () : checked(false) {}
};

struct MajorSettings {
	bool generateTraffic;
    int numberCarsPerTrial;
	double numberTrials;
    int numberCars;
    int numberTrucks;
	bool showBlindSpot;
    FVLVSettings followVehicle;
    FVLVSettings leadVehicle;
    FCW warningSettings;
    animation FCWanimation;
    MajorSettings () : generateTraffic(false), showBlindSpot(false) {}
};

#endif

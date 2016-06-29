#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

struct position {
    double x;
    double y;
    double z = 0;
    position(double X, double Y) : x(X), y(Y) {}
    position() : x(0), y(0) {}
    position(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
};

struct trajectory {
    double x;
    double y;
    double speed;
    double xDir;
    double yDir;
    trajectory (double X, double Y, double Speed, double XDir, double YDir) : x(X), y(Y), speed(Speed), xDir(XDir), yDir(YDir) {}
    trajectory () : x(0), y(0), speed(0), xDir(0), yDir(0) {}
};

struct color {
    double a;
    double b;
    double c;
    double d;
};

struct drawSize {
    double width;
    double heighth;
};

struct state {
    vector<double> stateVector;
    int stateOne;
    int stateTwo;
    string stateString;
};

#endif

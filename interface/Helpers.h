#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

/*(X, Y, Z) STYLED POSITION STRUCT*/
struct position {
    double x;
    double y;
    double z = 0;
    position(double X, double Y) : x(X), y(Y) {}
    position() : x(0), y(0) {}
    position(double X, double Y, double Z) : x(X), y(Y), z(Z) {}
};

/*MINISIM SPECIFIC TRAJECTORY STRUCT FOR DDO's/DDDO's*/
struct trajectory {
    double x;
    double y;
    double speed;
    double xDir;
    double yDir;
    trajectory (double X, double Y, double Speed, double XDir, double YDir) : x(X), y(Y), speed(Speed), xDir(XDir), yDir(YDir) {}
    trajectory () : x(0), y(0), speed(0), xDir(0), yDir(0) {}
};

/*MINISIM SPECIFIC COLOR SCHEME. RGB STYLE WITH INTENSITY INCLUDED.*/
struct color {
    double red;         //RED
    double green;       //GREEN
    double blue;        //BLUE
    double intensity;   //INTENSITY
    color () : red (0), green (0), blue (0), intensity (0) {}
    color (double r, double g, double b, double intens) : red(r), green(g), blue(b), intensity(intens) {}
};

/*MINISIM SPECIFIC DRAW SIZE STRUCT FOR SIZE OF VIRTUAL/STATIC OBJECTS.*/
struct drawSize {
    double width;
    double heighth;
    drawSize () : width (0), heighth (0) {}
    drawSize (double Width, double Height) : width (Width), heighth (Height) {}
};

/*MINISIM SPECIFIC DRAW STATE STRUCT FOR VIRTUAL/STATIC OBJECTS.*/
struct state {
    vector<double> stateVector;
    int stateOne;
    int stateTwo;
    string stateString;
    state () : stateOne (1), stateTwo (1), stateString ("\"\"") {}
    state (int one, int two, string StateString, vector<double> StateVec) : stateOne(one), stateTwo(two),
                stateString(StateString), stateVector(StateVec){}
};

#endif

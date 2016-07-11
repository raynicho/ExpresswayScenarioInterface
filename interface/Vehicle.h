#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Helpers.h"

using std::string;
using std::vector;
using std::ifstream;
using std::ostream;

class Vehicle {
protected:
	bool createdByTrigger;
	int colorIndex;
	double lifetime;
	double actvDel;
	double crRad;
	string name;
	string longComment;
	string shortComment;
	string solName;

public:
	Vehicle();

	Vehicle(int, double, double, double, string, string, string, string);

    virtual void print(ostream &);
    
    virtual void readFromFile(ifstream &);
    
    virtual void setInitialVel (double &);
    
    virtual void setVelocitySettings (double, double, double);
    
	void setCreation(bool);

	bool getCreation();

	void printBasics(ostream &, string);
};

class ADO : public Vehicle {
private:
	bool autoControlBreakLights;
	bool velCtrlInitMatchOvVel;
	int velCtrlDistType;
    int visualState;
    double velCtrlDistVal2;
	double laneOffset;
	double maxLatOffset;
	double velCtrlDistVal1;
	double velCtrlInitVel;
	string roadPos;
	string path;

public:
	ADO();

	ADO(int, double, double, double, string, string, string, string, bool,
		bool, int, double, double, double, double, string, string);

    ADO (int, int, int, int, double, double, double, string, string, string, string, bool,
        bool, int, double, double, double, string, string);
    
    void setInitialVel(double);
    
    void setVelocitySettings (double, double , double);
    
    void setVisualState (int);
    
	void printUnused(ostream &, string);

	void print(ostream &);

	void readFromFile(ifstream &);
	/*unused variables
	bool randomSol = 0;						bool createRel = 0;
	bool autoControlHeadLights = 0;			bool useReaDel = 1;
	int latsOffType = 0;					int createRelLatInFeet = 0;
	int pathSearchDepth = 2;				int stdToAccType = 0;
	int stdToDecType = 0;					int stpToAccType = 0;
	int decToType = 0;						int accel2Catch = 0;
	int velCtrlFollowSpeedLimit = 0;		double normVel2Kp = 0.7;
	double lcvFall1 = 1.5;					double lcvFall2 = 2.0;
	double lcvFreq1 = 0.03;					double lcvFreq2 = 0.05;
	double lcvRAmpl1 = 0.1;					double lcvRAmpl2 = 0.5;
	double emergeDecClip = -11;				double followTimeMax = 2;
	double followTimeMin = 1;				double stdToDecVal1 = 0.9;
	string createRelExp = "";				string logfile = "";
	string dynModel = "\"Non Linear\"";		string runMode = "\"eRemote_Control\"";
	*/
};

class DDO : public Vehicle {
private:
	/*unused
	string MaxDecel 0.0000000E+000			bool QuitAtEnd 0
	bool UseInitVelocity 0					double MaxAccel 0.0000000E+000
	double MaxDecel 0.0000000E+000			string Coupled ""
	bool EnableAnimation 0					bool AccountAccel 0
	bool GlobTraj 1							bool InitState 0
	int Option 0							int AudioState 0
	string RelLoc 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string RelRot 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string InitVelXYZ 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string InitVelRPY 0.0000000E+000 0.0000000E+000 0.0000000E+000
	vector<double> Delays 0 (size of dirs or dirsdef)
	*/

	//consistent variables
	bool dependent;
	bool dependentOwnVeh;
	int visualState; //0, 1, or 2
    int refPoint;
    position dependentRefPoint;
	vector <double> dirs;
	vector <bool> dirsDef;
	vector <trajectory> trajs;

public:
	DDO ();

	DDO(int, double, double, double, string, string, string, string,
		bool, bool, int, position, vector<double>, vector<bool>,
		vector <trajectory>);
    
    DDO::DDO(int, int, double, double, double, string, string, string, string, bool, bool, int, position, vector<double>, vector<bool>, vector <trajectory>);

	void readFromFile(ifstream &);

	void printUnused(ostream &, string);

	void print(ostream &);
};

#endif

#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Vehicle.h"
#include <vector>
#include "Helpers.h"
#include "Trigger.h"

using std::vector;
using std::ostream;
using std::ifstream;
using std::string;

class Trigger;

class Action {
protected:
	int instigatorSet;
	double delay;
	string comment;

public:
    Action();

    Action(int, double, string);

    void printBasics(ostream &, bool);

    virtual void print(ostream &, bool);

    virtual void readFromFile(ifstream &);
    
    virtual void addVehicle (Vehicle*);
    
    virtual void addTrigger (Trigger*);
};

class LogData : public Action {
private:
	int stream;
	double streamVal;

public:
	LogData();

    LogData(int, double, string, int, double);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class SetDial : public Action {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	SetDial();

    SetDial(int, double, string, string, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class ResetDial : public Action {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	ResetDial();

    ResetDial(int, double, string, string, string, string);

    ResetDial(int, double, string, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class DeleteHCSM : public Action {
private:
	string byNameSet;

public:
	DeleteHCSM();

	DeleteHCSM(int, double, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class SetVar : public Action {
private:
	bool varValIsExpression;
	string varName;
	string varValue;

public:
	SetVar();

	SetVar(int, double, string, bool, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class SetButton : public Action {
private:
	string button;
	string buttonPath;

public:
	SetButton();

	SetButton(int, double, string, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class WriteCell : public Action {
private:
	bool isVariable;
	int cellType;
	string cellName;
	string cellData;

public:
	WriteCell();

	WriteCell(int, double, string, bool, int, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};

class CreateHCSM : public Action {
protected:
	vector<Vehicle*> createdVehicles;
    vector<Trigger*> createdTriggers;

public:
	CreateHCSM();

	CreateHCSM(int, double, string);

    ~CreateHCSM ();
    
    void addVehicle(Vehicle*);
    
	void print(ostream &, bool);

	void readFromFile(ifstream &);
    
    void addTrigger (Trigger*);
};

Action* readInAction(ifstream &);

#endif

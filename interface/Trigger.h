#ifndef TRIGGER_H
#define TRIGGER_H

#include <string>
#include <vector>
#include "Helpers.h"
#include "Actions.h"
#include "Vehicle.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;
using std::ostream;
using std::ifstream;

class Action;

class Trigger {
protected:
    int setOption;
    bool created;
	bool oneShot;
	bool sequentialActions;
	int priority = 0;
	int fireDelFrames;
	double debounce;
	double activationDelay;
	double creationRadius;
	double lifetime;
	string name;
	string longComment;
	string shortComment;
	position drawPosition;
	position pos;
	vector <Action*> Actions;

public:
	//default constructor for a Trigger
	Trigger();
	//constructor that takes in various parameters
    Trigger(bool, bool, int, double, double, double, double, string, string,
        string, position, position, vector <Action*> &);

    void setCreation (bool);
    
	string getShortComment();

	string getLongComment();

	string getName();

	position getPosition();

	//responsible for adding in an action to the vector of actions
	void addAction(Action *);

	void writeBasics(ostream &);

	//virtual function for printing the Trigger tp an output stream; different for each type of Trigger
    virtual void filePrint(ostream &);

	//virtual funciton for reading the Trigger; different for each type of Trigger
    virtual void fileRead(ifstream &);

	void printActions(ostream &);

    ~Trigger();
};

class ExpressionTrigger : public Trigger {
private:
	string expression;

public:
	ExpressionTrigger();

	ExpressionTrigger(bool, bool, double, double, double, double, double, string, string,
		string, position, position, vector <Action*> &, string);
    
	void filePrint(ostream &);

	void fileRead(ifstream &);
};

class RoadPadTrigger : public Trigger {
private:
    //true if by typeset
    bool byTypeSet;
	string typeSet;
	string path;

public:
	RoadPadTrigger();

	RoadPadTrigger(bool, bool, double, double, double, double, double, string, string,
		string, position, position, vector <Action*> &, string, string);
    
    void setTypeSet (bool);

	void filePrint(ostream &);

	void fileRead(ifstream &);
};

class TimeTrigger : public Trigger {
private:
	double time;

public:
	TimeTrigger();

	TimeTrigger(bool, bool, double, double, double, double, double, string, string,
		string, position, position, vector <Action*> &, double);

	void filePrint(ostream &);

	void fileRead(ifstream &);
};

#endif

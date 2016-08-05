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
	//Default constructor for a Trigger.
	Trigger();
    
	//Overridden constructor for a Trigger.
    Trigger(bool, bool, int, double, double, double, double, string, string,
        string, position, position, vector <Action*> &);

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   created member variable.
    Effects:    Sets the created bool variable.
    */
    void setCreation (bool);
    
    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns the short comment of the Trigger.
    */
	string getShortComment();

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns the short comment of the Trigger.
    */
	string getLongComment();

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns the name of the Trigger.
    */
	string getName();

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns the position of the Trigger.
    */
	position getPosition();
    
    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   N/A
    Modifies:   Actions vector.
    Effects:    Adds the Action * to the Actions vector.
    */
	void addAction(Action *);

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.  
    Effects:    Writes the parent Action variables to ostream.
    */
	void writeBasics(ostream &);

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Prints the child Action member variables to ostream.
    */
    virtual void filePrint(ostream &);

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   ifstream is a valid input file stream.
    Modifies:   ifstream.
    Effects:    Reads the Trigger from the ifstream.
    */
    virtual void fileRead(ifstream &);

    /*APPLICABLE TO ALL INHERITED TRIGGERS
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Prints all actions to the ostream.
    */
	void printActions(ostream &);

    //Deconstructor. Deletes all actions.
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
    bool byTypeSet; //True if by typeset, false if by nameset.
	string typeSet;
	string path;

public:
	RoadPadTrigger();

	RoadPadTrigger(bool, bool, double, double, double, double, double, string, string,
		string, position, position, vector <Action*> &, string, string);
    
    /*
    Requires:   N/A
    Modifies:   byTypeSet.
    Effects:    Sets the typset to either be by name or by type.
    */
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

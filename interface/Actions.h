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
    
    /*APPLICABLE TO ALL INHERITED ACTIONS
    Requires:   ostream is a valid output stream.
    Modifies:   ostream.
    Effects:    Prints instigatorSet, delay, and comment in the correct format. If the boolean 
                value is true then the information is printed with created tabbing.
    */
    void printBasics(ostream &, bool);
    
    /*APPLICABLE TO ALL INHERITED ACTIONS
    Requires:   ostream us a valid outout stream.
    Modifies:   ostream.
    Effects:    Prints the child's data in the correct format to the ostream.  
    */
    virtual void print(ostream &, bool) =  0;
    
    /*APPLICABLE TO ALL INHERITED ACTIONS
    Requires:   the ifstream is a valid input filestream.
    Modifies:   ifstream.
    Effects:    Reads the action in from the ifstream and sets member variables appropriately.
    */
    virtual void readFromFile(ifstream &) = 0;
    
    /*APPLICABLE TO THE CreateHCSM ACTION
    Requires:   Vehicle* is a valid, non-null pointer to a Vehicle object, on the heap.
    Modifies:   N/A
    Effects:    Adds the Vehicle pointer to the createdVehicles vector. 
    */
    virtual void addVehicle (Vehicle*);
    
    /*APPLICABLE TO THE CreateHCSM ACTION
    Requires:   Trigger* is a valid, non-null pointer to a Trigger object, on the heap.
    Modifies:   N/A
    Effects:    Adds the Trigger pointer to the createdTriggers vector. 
    */
    virtual void addTrigger (Trigger*);
};

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
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

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
class DeleteHCSM : public Action {
private:
	string byNameSet;

public:
	DeleteHCSM();

	DeleteHCSM(int, double, string, string);

	void print(ostream &, bool);

	void readFromFile(ifstream &);
};
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*SEE Action CLASS FOR RME COMMENTS*/
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
/*SEE Action CLASS FOR RME COMMENTS*/

/*
Requires:   ifstream is a valid input file stream.
Modifies:   ifstream.
Effects:    Reads in an Action from the input in its entirety. Returns a point that points
            to a specific Action (LogData, SetDial, etc.) located on the heap.
*/
Action* readInAction(ifstream &);

#endif

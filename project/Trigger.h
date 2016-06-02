#pragma once
#include <string>
#include <vector>
#include "main.h"
#include "actions.h"
#include "Vehicle.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;
using std::ostream;
using std::ifstream;

position readPositionFromFile(ifstream &inputStream) {
	position test;
	inputStream >> test.x >> test.y >> test.z;
	return test;
}

class Trigger {
protected:
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
	Trigger() : sequentialActions(false), oneShot(false), debounce(0), activationDelay(0), creationRadius(0), lifetime(0) {
	}

	//constructor that takes in various parameters
	Trigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <Action*> Act) : sequentialActions(seq), oneShot(shot), debounce(Debounce),
		activationDelay(actDelay), creationRadius(creRad), lifetime(LifeTime), name(Name), longComment(Long),
		shortComment(Short), drawPosition(Draw), pos(Pos), Actions(Act) {

	}

	string getShortComment() {
		return this->shortComment;
	}

	string getLongComment() {
		return this->longComment;
	}

	string getName() {
		return this->name;
	}

	position getPosition() {
		return this->pos;
	}

	//responsible for adding in an action to the vector of actions
	void addAction(Action *newAction) {
		Actions.push_back(newAction);
		return;
	}

	void writeBasics(ostream &outStream) {
		outStream << "  Position " << std::scientific << std::setprecision(7);
		outStream << this->pos.x << " " << this->pos.y << " " << this->pos.z << " " << '\n';
		outStream << "  LongComment" << this->longComment << " " << '\n';
		outStream << "  ShortComment" << this->shortComment << " " << '\n';
		outStream << "  ActvDel " << this->activationDelay << " " << '\n';
		outStream << "  CrRad " << this->creationRadius << " " << '\n';
		outStream << "  Debounce " << this->debounce << " " << '\n';
		outStream << "  FireDelFrames " << this->fireDelFrames << " " << '\n';
		outStream << "  Lifetime " << this->lifetime << " " << '\n';
		outStream << "  Name " << this->name << " " << '\n';
		outStream << "  OneShot " << this->oneShot << " " << '\n';
		outStream << "  Priority " << this->priority << " " << '\n';
		outStream << "  SeqAct " << this->sequentialActions << " " << '\n';
		outStream << "  DrawPosition ";
		outStream << this->drawPosition.x << " " << this->drawPosition.y << " " << this->drawPosition.z << " " << '\n';
		return;
	}

	//virtual function for printing the Trigger tp an output stream; different for each type of Trigger
	virtual void filePrint(ostream &outputStream) {}

	//virtual funciton for reading the Trigger; different for each type of Trigger
	virtual void fileRead(ifstream &inputStream) {}

	void printActions(ostream &outStream) {
		for (unsigned int i = 0; i < Actions.size(); i++) {
			Actions[i]->print(outStream);
		}
		return;
	}

	~Trigger() {
		//delete the actions
		for (unsigned int i = 0; i < Actions.size(); i++) {
			delete Actions[i];
			Actions[i] = 0;
		}
	}
};

class expressionTrigger : public Trigger {
private:
	string expression;

public:
	expressionTrigger() : Trigger() {
	}

	expressionTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <Action*> Act, string Expression) : Trigger(seq, shot, delay, Debounce, actDelay, creRad,
			LifeTime, Name, Long, Short, Draw, Pos, Act) {
		expression = Expression;
	}

	void filePrint(ostream &outStream) {
		outStream << "HCSM ExpressionTrigger" << '\n';
		outStream << "  Expression " << this->expression << " " << '\n';
		this->writeBasics(outStream);
		this->printActions(outStream);
		outStream << "&&&&End&&&&" << '\n';
		return;
	}

	void fileRead(ifstream &inputStream) {
		string current;
		inputStream >> current;
		//while not at the end, continue reading in
		while (current != "&&&&End&&&&") {
			//if if is the position
			if (current == "Position") {
				this->pos = readPositionFromFile(inputStream);
			}
			else if (current == "Expression") {
				getline(inputStream, expression);
			}
			else if (current == "LongComment") {
				getline(inputStream, this->longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, this->shortComment);
			}
			else if (current == "ActvDel") {
				inputStream >> this->activationDelay;
			}
			else if (current == "CrRad") {
				inputStream >> this->creationRadius;
			}
			else if (current == "Debounce") {
				inputStream >> this->debounce;
			}
			else if (current == "FireDelFrames") {
				inputStream >> this->fireDelFrames;
			}
			else if (current == "Lifetime") {
				inputStream >> this->lifetime;
			}
			else if (current == "Name") {
				getline(inputStream, name);
			}
			else if (current == "OneShot") {
				inputStream >> this->oneShot;
			}
			else if (current == "Priority") {
				inputStream >> this->priority;
			}
			else if (current == "SeqAct") {
				inputStream >> this->sequentialActions;
			}
			else if (current == "DrawPosition") {
				this->drawPosition = readPositionFromFile(inputStream);
			}
			else if (current == "HCSM") {
				Actions.push_back(readInAction(inputStream));
			}
			inputStream >> current;
		}
		return;
	}
};

class roadPadTrigger : public Trigger {
private:
	string typeSet;
	string path;

public:

	roadPadTrigger() : Trigger() {}

	roadPadTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <Action*> Act, string type, string Path) : Trigger(seq, shot, delay, Debounce, actDelay,
			creRad, LifeTime, Name, Long, Short, Draw, Pos, Act) {
		typeSet = type;
		path = Path;
	}

	void filePrint(ostream &outStream) {
		outStream << "HCSM RoadPadTrigger\n";
		this->writeBasics(outStream);
		outStream << "  ByTypeSet " << this->typeSet << " \n";
		outStream << "  Path " << path << " \n";
		outStream << "  NthFromStart 0 \n  NthFromEnd 0 \n  VehicleAhead 0 \n  VehicleBehind 0 \n";
		this->printActions(outStream);
		outStream << "&&&&End&&&&\n";
		return;
	}

	void fileRead(ifstream &inputStream) {
		string current;
		inputStream >> current;

		//while not at the end, continue reading in
		while (current != "&&&&End&&&&") {
			//if if is the position
			if (current == "Position") {
				this->pos = readPositionFromFile(inputStream);
			}
			else if (current == "LongComment") {
				getline(inputStream, this->longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, this->shortComment);
			}
			else if (current == "ActvDel") {
				inputStream >> this->activationDelay;
			}
			else if (current == "CrRad") {
				inputStream >> this->creationRadius;
			}
			else if (current == "Debounce") {
				inputStream >> this->debounce;
			}
			else if (current == "FireDelFrames") {
				inputStream >> this->fireDelFrames;
			}
			else if (current == "Lifetime") {
				inputStream >> this->lifetime;
			}
			else if (current == "Name") {
				getline(inputStream, name);
			}
			else if (current == "OneShot") {
				inputStream >> this->oneShot;
			}
			else if (current == "Priority") {
				inputStream >> this->priority;
			}
			else if (current == "SeqAct") {
				inputStream >> this->sequentialActions;
			}
			else if (current == "DrawPosition") {
				this->drawPosition = readPositionFromFile(inputStream);
			}
			else if (current == "HCSM") {
				Actions.push_back(readInAction(inputStream));
			}
			else if (current == "Path") {
				inputStream >> this->path;
			}
			else if (current == "ByTypeSet") {
				inputStream >> this->typeSet;
			}
			else if (current == "NthFromStart" || current == "NthFromEnd" || current == "VehicleAhead" || current == "VehicleBehind") {
				inputStream >> current;
			}
			inputStream >> current;
		}
		return;
	}
};

class timeTrigger : public Trigger {
private:
	double time;

public:
	timeTrigger() : Trigger() {}

	timeTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <Action*> Act, double Time) : Trigger(seq, shot, delay, Debounce, actDelay, creRad,
			LifeTime, Name, Long, Short, Draw, Pos, Act) {
		time = Time;
	}

	void filePrint(ostream &outStream) {
		outStream << "HCSM TimeTrigger" << '\n';
		outStream << "  Time " << std::setprecision(7) << std::scientific << this->time << " " << '\n';
		this->writeBasics(outStream);
		this->printActions(outStream);
		outStream << "&&&&End&&&&" << '\n';
		return;
	}

	void fileRead(ifstream &inputStream) {
		string current;
		inputStream >> current;

		//while not at the end, continue reading in
		while (current != "&&&&End&&&&") {
			//if if is the position
			if (current == "Position") {
				this->pos = readPositionFromFile(inputStream);
			}
			else if (current == "Time") {
				inputStream >> this->time;
			}
			else if (current == "LongComment") {
				getline(inputStream, this->longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, this->shortComment);
			}
			else if (current == "ActvDel") {
				inputStream >> this->activationDelay;
			}
			else if (current == "CrRad") {
				inputStream >> this->creationRadius;
			}
			else if (current == "Debounce") {
				inputStream >> this->debounce;
			}
			else if (current == "FireDelFrames") {
				inputStream >> this->fireDelFrames;
			}
			else if (current == "Lifetime") {
				inputStream >> this->lifetime;
			}
			else if (current == "Name") {
				getline(inputStream, name);
			}
			else if (current == "OneShot") {
				inputStream >> this->oneShot;
			}
			else if (current == "Priority") {
				inputStream >> this->priority;
			}
			else if (current == "SeqAct") {
				inputStream >> this->sequentialActions;
			}
			else if (current == "DrawPosition") {
				this->drawPosition = readPositionFromFile(inputStream);
			}
			else if (current == "HCSM") {
				Actions.push_back(readInAction(inputStream));
			}
			inputStream >> current;
		}
		return;
	}
};
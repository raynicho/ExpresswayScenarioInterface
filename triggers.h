#pragma once
#include <string>
#include <vector>
#include "main.h"
#include "actions.h"
#include "vehicles.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;

position readPositionFromFile(std::ifstream &inputStream) {
	position test;
	inputStream >> test.x >> test.y >> test.z;
	return test;
}

class trigger {
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
	vector <actions*> Actions;

public:
	//default constructor for a trigger
	trigger() : sequentialActions(false), oneShot(false), debounce(0), activationDelay(0), creationRadius(0), lifetime(0) {
	}

	//constructor that takes in various parameters
	trigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <actions*> Act) : sequentialActions(seq), oneShot(shot), debounce(Debounce),
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
	void addAction(actions *newAction) {
		Actions.push_back(newAction);
		return;
	}

	void writeBasics(std::ostream &outStream) {
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
		this->printActions(outStream);
		return;
	}

	//virtual function for printing the trigger tp an output stream; different for each type of trigger
	virtual void filePrint(std::ostream &outputStream) {}

	//virtual funciton for reading the trigger; different for each type of trigger
	virtual void fileRead(std::ifstream &inputStream) {}

	void printActions(std::ostream &outStream) {
		for (unsigned int i = 0; i < Actions.size(); i++) {
			Actions[i]->print(outStream);
		}
		return;
	}

	~trigger() {
		for (unsigned int i = 0; i < Actions.size(); i++) {
			delete Actions[i];
			Actions[i] = 0;
		}
	}
};

class expressionTrigger : public trigger {
private:
	string expression;

public:
	expressionTrigger() : trigger() {
	}

	expressionTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <actions*> Act, string Expression) : trigger(seq, shot, delay, Debounce, actDelay, creRad,
			LifeTime, Name, Long, Short, Draw, Pos, Act) {
		expression = Expression;
	}

	void filePrint(std::ostream &outStream) {
		outStream << "HCSM ExpressionTrigger" << '\n';
		outStream << "  Expression " << this->expression << " " << '\n';
		this->writeBasics(outStream);
		outStream << "&&&&End&&&&" << '\n';
		return;
	}

	void fileRead(std::ifstream &inputStream) {
		string current;
		inputStream >> current;

		//while not at the end, continue reading in
		while (current != "&&&&End&&&&") {
			//if if is the position
			if (current == "Position") {
				this->pos = readPositionFromFile(inputStream);
			}
			else if (current == "Expression") {
				inputStream >> this->expression;
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
				inputStream >> this->name;
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

class roadPadTrigger : public trigger {
private:
	string typeSet;
	string path;

public:

	roadPadTrigger() : trigger() {}

	roadPadTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <actions*> Act, string type, string Path) : trigger(seq, shot, delay, Debounce, actDelay,
			creRad, LifeTime, Name, Long, Short, Draw, Pos, Act) {
		typeSet = type;
		path = Path;
	}

	void filePrint(std::ostream &outStream) {
		outStream << "HCSM RoadPadTrigger\n";
		this->writeBasics(outStream);
		outStream << "  ByTypeSet " << this->typeSet << " \n";
		outStream << "  Path " << path << " \n";
		outStream << "  NthFromStart 0 \n  NthFromEnd 0 \n  VehicleAhead 0 \n  VehicleBehind 0 \n";
		outStream << "&&&&End&&&&\n";
		return;
	}

	void fileRead(std::ifstream &inputStream) {
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
				inputStream >> this->name;
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

class timeTrigger : public trigger {
private:
	double time;

public:
	timeTrigger() : trigger() {}

	timeTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <actions*> Act, double Time) : trigger(seq, shot, delay, Debounce, actDelay, creRad,
			LifeTime, Name, Long, Short, Draw, Pos, Act) {
		time = Time;
	}

	void filePrint(std::ostream &outStream) {
		outStream << "HCSM TimeTrigger" << '\n';
		outStream << "  Time " << std::setprecision(7) << std::scientific << this->time << " " << '\n';
		this->writeBasics(outStream);
		outStream << "&&&&End&&&&" << '\n';
		return;
	}

	void fileRead(std::ifstream &inputStream) {
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
				inputStream >> this->name;
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
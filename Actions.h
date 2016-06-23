#ifndef ACTIONS_H
#define ACTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include "Vehicle.h"
#include <vector>
#include "Helpers.h"

using std::vector;
using std::ostream;
using std::ifstream;
using std::string;


class Action {
protected:
	int instigatorSet;
	double delay;
	string comment;

public:
    Action(): delay(0), instigatorSet(0) {}

    Action(int set, double Delay, string Comment) : instigatorSet(set), delay(Delay), comment(Comment) {}

    void printBasics(ostream &outStream) {
        outStream << "      Comment " << this->comment << '\n';
        outStream << "      Delay " << this->delay << '\n';
        outStream << "      InstigatorSet " << this->instigatorSet << '\n';
        return;
    }

    virtual void print(ostream &) {}

    virtual void readFromFile(ifstream &) {}
    
    virtual void addVehicle (Vehicle*) {} 
};

class LogData : public Action {
private:
	int stream;
	double streamVal;

public:
	LogData() : Action() {}

    LogData(int set, double Delay, string Comment, int Stream, double val) : Action(set, Delay, Comment) {
		stream = Stream;
		streamVal = val;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM LogData\n";
		this->printBasics(outStream);
		outStream << "      Stream " << this->stream << '\n';
		outStream << "      StreamVal " << this->streamVal << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "Stream") {
				inputStream >> this->stream;
			}
			else if (current == "StreamVal") {
				inputStream >> this->streamVal;
			}
			inputStream >> current;
		}
		return;
	}
};

class SetDial : public Action {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	SetDial() : Action() {}

    SetDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : Action(set, Delay, Comment) {
		byNameSet = nameSet;
		dial = Dial;
		buttonDialPath = dialPath;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM SetDial\n";
		this->printBasics(outStream);
		outStream << "      ByNameSet " << this->byNameSet << '\n';
		outStream << "      Dial " << this->dial << '\n';
		outStream << "      ButtonDialPath " << this->buttonDialPath << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				getline(inputStream, byNameSet);
			}
			else if (current == "Dial") {
				getline(inputStream, dial);
			}
			else if (current == "ButtonDialPath") {
				getline(inputStream, buttonDialPath);
			}
			inputStream >> current;
		}
		return;
	}
};

class ResetDial : public Action {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	ResetDial() : Action() {}

    ResetDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : Action(set, Delay, Comment) {
		byNameSet = nameSet;
		dial = Dial;
		buttonDialPath = dialPath;
	}

    ResetDial(int set, double Delay, string Comment, string Dial, string dialPath) : Action(set, Delay, Comment) {
		byNameSet = "null";
		dial = Dial;
		buttonDialPath = dialPath;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM ResetDial\n";
		this->printBasics(outStream);
		if (byNameSet != "null") {
			outStream << "      ByNameSet " << this->byNameSet << '\n';
		}
		outStream << "      Dial " << this->dial << '\n';
		outStream << "      ButtonDialPath " << this->buttonDialPath << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				getline(inputStream, byNameSet);
			}
			else if (current == "Dial") {
				getline(inputStream, dial);
			}
			else if (current == "ButtonDialPath") {
				getline(inputStream, buttonDialPath);
			}
			inputStream >> current;
		}
		return;
	}
};

class DeleteHCSM : public Action {
private:
	string byNameSet;

public:
	DeleteHCSM() : Action() {}

	DeleteHCSM(int set, double Delay, string Comment, string ByNameSet) : Action(set, Delay, Comment) {
		byNameSet = ByNameSet;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM DeleteHcsm\n";
		this->printBasics(outStream);
		outStream << "      ByNameSet " << this->byNameSet << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				getline(inputStream, byNameSet);
			}
			inputStream >> current;
		}
		return;
	}
};

class SetVar : public Action {
private:
	bool varValIsExpression;
	string varName;
	string varValue;

public:
	SetVar() : Action() {}

	SetVar(int set, double Delay, string Comment, bool isExpression, string VarName, string VarValue) : Action(set, Delay, Comment) {
		varValIsExpression = isExpression;
		varName = VarName;
		varValue = VarValue;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM SetVar\n";
		this->printBasics(outStream);
		outStream << "      VarName " << this->varName << '\n';
		outStream << "      VarValue " << this->varValue << '\n';
		outStream << "      IsVarValExpression " << this->varValIsExpression << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "VarName") {
				getline(inputStream, varName);
			}
			else if (current == "VarValue") {
				getline(inputStream, varValue);
			}
			else if (current == "IsVarValExpression") {
				inputStream >> this->varValIsExpression;
			}
			inputStream >> current;
		}
		return;
	}
};

class SetButton : public Action {
private:
	string button;
	string buttonPath;

public:
	SetButton() : Action() {}

	SetButton(int set, double Delay, string Comment, string Button, string ButtonPath) : Action(set, Delay, Comment) {
		button = Button;
		buttonPath = ButtonPath;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM SetButton\n";
		this->printBasics(outStream);
		outStream << "      Button " << this->button << '\n';
		outStream << "      ButtonDialPath " << this->buttonPath << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "Button") {
				getline(inputStream, button);
			}
			else if (current == "ButtonDialPath") {
				getline(inputStream, buttonPath);
			}
			inputStream >> current;
		}
		return;
	}
};

class WriteCell : public Action {
private:
	bool isVariable;
	int cellType;
	string cellName;
	string cellData;

public:
	WriteCell() : Action() {}

	WriteCell(int set, double Delay, string Comment, bool isVar, int type, string CellName, string data) : Action(set, Delay, Comment) {
		isVariable = isVar;
		cellType = type;
		cellName = CellName;
		cellData = data;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM WriteCell\n";
		this->printBasics(outStream);
		outStream << "      CellName " << this->cellName << '\n';
		outStream << "      CellData " << this->cellData << '\n';
		outStream << "      CellType " << this->cellType << '\n';
		outStream << "      CellVar " << this->isVariable << '\n';
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "CellName") {
				getline(inputStream, cellName);
			}
			else if (current == "CellData") {
				getline(inputStream, cellData);
			}
			else if (current == "CellType") {
				inputStream >> this->cellType;
			}
			else if (current == "CellVar") {
				inputStream >> this->isVariable;
			}
			inputStream >> current;
		}
		return;
	}
};

class CreateHCSM : public Action {
private:
	vector<Vehicle*> createdVehicles;

public:
	CreateHCSM() : Action() {}

	CreateHCSM(int set, double Delay, string Comment) : Action(set, Delay, Comment) {}

    ~CreateHCSM () {
        for (auto veh : createdVehicles){
            delete veh; veh = 0;
        }
    }
    
    void addVehicle(Vehicle* veh){
        createdVehicles.push_back(veh);
        return;
    }
    
	void print(ostream &outStream) {
		string spaces = "      ";
		string spacesTillTitle = "    ";
		outStream << spacesTillTitle << "HCSM CreateHcsm\n";
		this->printBasics(outStream);
		
		for (unsigned int i = 0; i < createdVehicles.size(); i++) {
			createdVehicles[i]->print(outStream);
		}
		outStream << "    &&&&End&&&&\n";
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "HCSM") {
				inputStream >> current;
				if (current == "Ddo") {
					Vehicle* newVehicle = new DDO;
					newVehicle->readFromFile(inputStream);
					newVehicle->setCreation(true);
					createdVehicles.push_back(newVehicle);
				}
				else if (current == "Ado") {
					Vehicle* newVehicle = new ADO;
					newVehicle->readFromFile(inputStream);
					newVehicle->setCreation(true);
					createdVehicles.push_back(newVehicle);
				}
				else {
					while (current != "&&&&End&&&&") {
						inputStream >> current;
					}
				}
			}
			inputStream >> current;
		}
		return;
	}
};

Action* readInAction(ifstream &);

#endif

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "vehicles.h"
#include <vector>

using std::vector;
using std::ostream;
using std::ifstream;
using std::string;


class actions {
protected:
	int instigatorSet;
	double delay;
	string comment;

public:
	actions() : delay(0), instigatorSet(0) {}

	actions(int set, double Delay, string Comment) : instigatorSet(set), delay(Delay), comment(Comment) {}

	void printBasics(ostream &outStream) {
		outStream << "      Comment " << this->comment << '\n';
		outStream << "      Delay " << this->delay << '\n';
		outStream << "      InstigatorSet " << this->instigatorSet << '\n';
	}

	virtual void print(ostream &outStream) {}

	virtual void readFromFile(ifstream &inputStream) {}

	virtual void readFromFile(ifstream &inputStream, vector <vehicle*> *vehicles) {}
};

class logData : public actions {
private:
	int stream;
	double streamVal;

public:
	logData() : actions() {}

	logData(int set, double Delay, string Comment, int Stream, double val) : actions() {
		stream = Stream;
		streamVal = val;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM LogData\n";
		this->printBasics(outStream);
		outStream << "      Stream " << this->stream << '\n';
		outStream << "      StreamVal " << this->streamVal << '\n';
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

class setDial : public actions {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	setDial() : actions() {}

	setDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : actions() {
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
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		//std::cout << "Read from file function reached.";
		inputStream >> current;
		
		//std::cout << current << '\n';
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				getline(inputStream, comment);
				//std::cout << comment << '\n';
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
			//std::cout << current << '\n';
		}
		return;
	}
};

class resetDial : public actions {
private:
	string byNameSet;
	string dial;
	string buttonDialPath;

public:
	resetDial() : actions() {}

	resetDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : actions() {
		byNameSet = nameSet;
		dial = Dial;
		buttonDialPath = dialPath;
	}

	resetDial(int set, double Delay, string Comment, string Dial, string dialPath) : actions() {
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

class deleteHCSM : public actions {
private:
	string byNameSet;

public:
	deleteHCSM() : actions() {}

	deleteHCSM(int set, double Delay, string Comment, string ByNameSet) : actions(set, Delay, Comment) {
		byNameSet = ByNameSet;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM DeleteHCSM\n";
		this->printBasics(outStream);
		outStream << "      ByNameSet " << this->byNameSet << '\n';
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

class setVar : public actions {
private:
	bool varValIsExpression;
	string varName;
	string varValue;

public:
	setVar() : actions() {}

	setVar(int set, double Delay, string Comment, bool isExpression, string VarName, string VarValue) : actions(set, Delay, Comment) {
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

class setButton : public actions {
private:
	string button;
	string buttonPath;

public:
	setButton() : actions() {}

	setButton(int set, double Delay, string Comment, string Button, string ButtonPath) : actions(set, Delay, Comment) {
		button = Button;
		buttonPath = ButtonPath;
	}

	void print(ostream &outStream) {
		outStream << "    HCSM SetButton\n";
		this->printBasics(outStream);
		outStream << "      Button " << this->button << '\n';
		outStream << "      ButtonDialPath " << this->buttonPath << '\n';
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

class writeCell : public actions {
private:
	bool isVariable;
	int cellType;
	string cellName;
	string cellData;

public:
	writeCell() : actions() {}

	writeCell(int set, double Delay, string Comment, bool isVar, int type, string CellName, string data) : actions(set, Delay, Comment) {
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

class createHCSM : public actions {
private:
	vector<vehicle*> createdVehicles;

public:
	createHCSM() : actions() {}

	createHCSM(int set, double Delay, string Comment) : actions(set, Delay, Comment) {}

	void print(ostream &outStream) {
		string spaces = "      ";
		string spacesTillTitle = "    ";
		outStream << spacesTillTitle << "HCSM CreateHcsm\n";
		this->printBasics(outStream);
		
		for (unsigned int i = 0; i < createdVehicles.size(); i++) {
			createdVehicles[i]->print(outStream);
		}
		return;
	}

	void readFromFile(ifstream &inputStream) {
		return;
	}

	void readFromFile(ifstream &inputStream, vector <vehicle*> *vehicles) {
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
					vehicle* newVehicle = new DDO;
					newVehicle->readFromFile(inputStream);
					newVehicle->setCreation(true);
					vehicles->push_back(newVehicle);
					createdVehicles.push_back(newVehicle);
				}
				else if (current == "Ado") {
					vehicle* newVehicle = new ADO;
					newVehicle->readFromFile(inputStream);
					newVehicle->setCreation(true);
					vehicles->push_back(newVehicle);
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

actions* readInAction(ifstream &inputStream, vector <vehicle*> *vehicles) {
	string actionType;
	actions* act = 0;
	inputStream >> actionType;
	if (actionType == "WriteCell") {
		act = new writeCell();
		act->readFromFile(inputStream);
	}
	else if (actionType == "SetButton") {
		act = new setButton();
		act->readFromFile(inputStream);
	}
	else if (actionType == "DeleteHCSM") {
		act = new deleteHCSM();
		act->readFromFile(inputStream);
	}
	else if (actionType == "ResetDial") {
		act = new resetDial();
		act->readFromFile(inputStream);
	}
	else if (actionType == "CreatHCSM") {
		act = new createHCSM ();
		act->readFromFile(inputStream, vehicles);
	}
	else if (actionType == "SetVar") {
		act = new setVar();
		act->readFromFile(inputStream);
	}
	else if (actionType == "LogData") {
		act = new logData();
		act->readFromFile(inputStream);
	}
	else if (actionType == "SetDial") {
		//std::cout << "Reading SetDial action..." << '\n';
		setDial x;
		x.readFromFile(inputStream);
		act = new setDial(x);
		//act->print(std::cout);
	}
	//std::cout << "Done reading action.\n";
	return act;
}
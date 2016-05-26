#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;


class actions {
protected:
	int instigatorSet;
	double delay;
	string comment;

public:
	actions() : delay(0), instigatorSet(0) {}

	actions(int set, double Delay, string Comment) : instigatorSet(set), delay(Delay), comment(Comment) {}

	void printBasics(std::ostream &outStream) {
		outStream << "      Comment " << this->comment << '\n';
		outStream << "      Delay " << this->delay << '\n';
		outStream << "      InstigatorSet " << this->instigatorSet << '\n';
	}

	virtual void print(std::ostream &outStream) {}

	virtual void readFromFile(std::ifstream &inputStream) {}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM LogData\n";
		this->printBasics(outStream);
		outStream << "      Stream " << this->stream << '\n';
		outStream << "      StreamVal " << this->streamVal << '\n';
		return;
	}

	void readFromFIle(std::ifstream inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM SetDial\n";
		this->printBasics(outStream);
		outStream << "      ByNameSet " << this->byNameSet << '\n';
		outStream << "      Dial " << this->dial << '\n';
		outStream << "      ButtonDialPath " << this->buttonDialPath << '\n';
		return;
	}

	void readFromFIle(std::ifstream inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				inputStream >> this->byNameSet;
			}
			else if (current == "Dial") {
				inputStream >> this->dial;
			}
			else if (current == "ButtonDialPath") {
				inputStream >> this->buttonDialPath;
			}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM ResetDial\n";
		this->printBasics(outStream);
		if (byNameSet != "null") {
			outStream << "      ByNameSet " << this->byNameSet << '\n';
		}
		outStream << "      Dial " << this->dial << '\n';
		outStream << "      ButtonDialPath " << this->buttonDialPath << '\n';
		return;
	}

	void readFromFIle(std::ifstream inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				inputStream >> this->byNameSet;
			}
			else if (current == "Dial") {
				inputStream >> this->dial;
			}
			else if (current == "ButtonDialPath") {
				inputStream >> this->buttonDialPath;
			}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM DeleteHCSM\n";
		this->printBasics(outStream);
		outStream << "      ByNameSet " << this->byNameSet << '\n';
	}

	void readFromFile(std::ifstream &inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "ByNameSet") {
				inputStream >> this->byNameSet;
			}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM SetVar\n";
		this->printBasics(outStream);
		outStream << "      VarName " << this->varName << '\n';
		outStream << "      VarValue " << this->varValue << '\n';
		outStream << "      IsVarValExpression " << this->varValIsExpression << '\n';
		return;
	}

	void readFromFile(std::ifstream &inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "VarName") {
				inputStream >> this->varName;
			}
			else if (current == "VarValue") {
				inputStream >> this->varValue;
			}
			else if (current == "IsVarValExpression") {
				inputStream >> this->varValIsExpression;
			}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM SetButton\n";
		this->printBasics(outStream);
		outStream << "      Button " << this->button << '\n';
		outStream << "      ButtonDialPath " << this->buttonPath << '\n';
		return;
	}

	void readFromFile(std::ifstream &inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "Button") {
				inputStream >> this->button;
			}
			else if (current == "ButtonDialPath") {
				inputStream >> this->buttonPath;
			}
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

	void print(std::ostream &outStream) {
		outStream << "    HCSM WriteCell\n";
		this->printBasics(outStream);
		outStream << "      CellName " << this->cellName << '\n';
		outStream << "      CellData " << this->cellData << '\n';
		outStream << "      CellType " << this->cellType << '\n';
		outStream << "      CellVar " << this->isVariable << '\n';
		return;
	}

	void readFromFile(std::ifstream &inputStream) {
		string current;
		while (current != "&&&&End&&&&") {
			if (current == "Comment") {
				inputStream >> this->comment;
			}
			else if (current == "Delay") {
				inputStream >> this->delay;
			}
			else if (current == "InstigatorSet") {
				inputStream >> this->instigatorSet;
			}
			else if (current == "CellName") {
				inputStream >> this->cellName;
			}
			else if (current == "CellData") {
				inputStream >> this->cellData;
			}
			else if (current == "CellType") {
				inputStream >> this->cellType;
			}
			else if (current == "CellVar") {
				inputStream >> this->isVariable;
			}
		}
		return;
	}
};

class createHCSM : public actions {
private:

public:
	createHCSM() : actions() {}

	void print(std::ostream &outStream) {
		return;
	}

	void readFromFile(std::ifstream &inputStream) {
		return;
	}
};

actions* readInAction(std::ifstream &inputStream) {
	string actionType;
	actions* act = 0;
	inputStream >> actionType;
	if (actionType == "WriteCell") {
		act = new writeCell();
	}
	else if (actionType == "SetButton") {
		act = new setButton();
	}
	else if (actionType == "DeleteHCSM") {
		act = new deleteHCSM();
	}
	else if (actionType == "ResetDial") {
		act = new resetDial();
	}
	else if (actionType == "CreatHCSM") {
		return act;
	}
	else if (actionType == "SetVar") {
		act = new setVar();
	}
	else if (actionType == "LogData") {
		act = new logData();
	}
	else if (actionType == "SetDial") {
		act = new setDial();
	}
	act->readFromFile(inputStream);
	return act;
}
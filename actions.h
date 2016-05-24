#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::string;

actions* readInAction(std::ifstream &inputStream) {

}

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

	virtual void print (std::ostream &outStream) {}

	virtual void readFromFile (std::ifstream inputStream) {}
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

	void readFromFIle  (std::ifstream inputStream) {
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

	setDial (int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : actions() {
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
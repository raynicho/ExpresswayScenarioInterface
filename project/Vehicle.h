#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using std::string;
using std::vector;
using std::ifstream;
using std::ostream;

class Vehicle {
protected:
	bool createdByTrigger;
	int colorIndex;
	double lifetime;
	double actvDel;
	double crRad;
	string name;
	string longComment;
	string shortComment;
	string solName;

public:
	Vehicle() : createdByTrigger(false), colorIndex(1), lifetime(0), actvDel(0), crRad(0), solName("\"Audi\"") {

	}

	Vehicle(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName) :
		colorIndex(color), lifetime(LifeTime), actvDel(delay), crRad(CrRad), name(Name), longComment(Long), shortComment(Short),
		solName(SolName) {}

	virtual void print(ostream &outStream) {}

	virtual void readFromFile(ifstream &inputStream) {}

	void setCreation(bool wasICreated) {
		createdByTrigger = wasICreated;
		return;
	}

	bool getCreation() {
		return createdByTrigger;
	}

	void printBasics(ostream &outStream, string spaces) {
		outStream << spaces << "ColorIndex " << colorIndex << "\n";
		outStream << spaces << "Lifetime " << lifetime << "\n";
		outStream << spaces << "ActvDel " << actvDel <<"\n";
		outStream << spaces << "CrRad " << crRad << "\n";
		outStream << spaces << "Name " << name << "\n";
		outStream << spaces << "LongComment " << longComment << "\n";
		outStream << spaces << "ShortComment " << shortComment << "\n";
		outStream << spaces << "SolName " << solName << "\n";
		return;
	}
};

class ADO : public Vehicle {
private:
	bool autoControlBreakLights;
	bool velCtrlInitMatchOvVel;
	int velCtrlDistType;
	double laneOffset;
	double maxLatOffset;
	double velCtrlDistVal1;
	double velCtrlInitVel;
	string roadPos;
	string path;

public:
	ADO() : Vehicle(), autoControlBreakLights(false), velCtrlInitMatchOvVel(false), velCtrlDistType(2), laneOffset(-0.49), maxLatOffset(9),
		velCtrlDistVal1(62) {}

	ADO(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName, bool autoBreak,
		bool velInitMatch, int distType, double laneOff, double maxLatOff, double distVal1, double initVel, string RoadPos, string Path) : Vehicle(color,
			LifeTime, delay, CrRad, Name, Long, Short, SolName), autoControlBreakLights(autoBreak), velCtrlInitMatchOvVel(velInitMatch),
		velCtrlDistType(distType), laneOffset(laneOff), maxLatOffset(maxLatOff), velCtrlDistVal1(distVal1), velCtrlInitVel(initVel), roadPos(RoadPos), path(Path) {}

	void printUnused(ostream &outStream, string spaces) {
		outStream << spaces << "RunMode \"eRemote_Control\"\n";				outStream << spaces << "CreateRelOffsLonUsingExpr 0 \n";
		outStream << spaces << "AutoControlHeadLights 0\n";					outStream << spaces << "UseReaDel 1\n";
		outStream << spaces << "LatOffsType 0\n";							outStream << spaces << "CreateRelLatInFeet 0\n";
		outStream << spaces << "PathSearchDepth 2\n";						outStream << spaces << "StdToAccType 0\n";
		outStream << spaces << "StdToDecType 0\n";							outStream << spaces << "StdToAccType 0\n";
		outStream << spaces << "DecToAccType 0\n";							outStream << spaces << "Accel2Catch 0\n";
		outStream << spaces << "VelCtrlFollowSpeedLimit 0\n";				outStream << spaces << "NormVel2Kp 7.0000000E-001\n";
		outStream << spaces << "LcvFall 1.5000000E+000 2.0000000E+000\n";	outStream << spaces << "LcvFreq 3.0000000E-002 5.0000000E-002\n";
		outStream << spaces << "EmergDecClip -1.1000000E+001\n";			outStream << spaces << "FollowTimeMax 2.0000000E+000\n";
		outStream << spaces << "FollowTimeMin 1.0000000E+000\n";			outStream << spaces << "LcvRAmpl 1.0000000E-001 5.0000000E-001\n";
		outStream << spaces << "StdToDecVal1 9.0000000E-001\n";				outStream << spaces << "CreateRelOffsLonExprStr \"\"\n";
		outStream << spaces << "\n";										outStream << spaces << "DynModel \"Non Linear\"\n";
		outStream << spaces << "LogFile \"\"\n";
		return;
	}

	void print(ostream &outStream) {
		string spaces = "  ";
		string spacesTillTitle = "";
		if (createdByTrigger) {
			spaces = "          ";
			spacesTillTitle = "        ";
		}
		outStream << spacesTillTitle << "HCSM Ado\n";
		this->printUnused(outStream, spaces);
		
		outStream << std::setprecision(7) << std::scientific;
		outStream << spaces << "AutoControlBreakLights " << autoControlBreakLights << "\n";
		outStream << spaces << "VelCtrlInitMatchOvVel " << velCtrlInitMatchOvVel << "\n";
		outStream << spaces << "VelCtrlDistType " << velCtrlDistType << "\n";
		outStream << spaces << "LaneOffs " << laneOffset << "\n";
		outStream << spaces << "MaxLatOffset " << maxLatOffset << "\n";
		outStream << spaces << "VelCtrlDistVal1 " << velCtrlDistVal1 << "\n";
		outStream << spaces << "RoadPos " << roadPos << "\n";
		
		if (path != "-1") {
			outStream << spaces << "Path " << path << "\n";
		}
		
		if (velCtrlInitVel != -1) {
			outStream << spaces << "VelCtrlInitVel " << velCtrlInitVel << "\n";
		}

		this->printBasics(outStream, spaces);
		return;
	}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "AutoControlBreakLights") {
				inputStream >> this->autoControlBreakLights;
			}
			else if (current == "VelCtrlInitMatchOvVel") {
				inputStream >> this->velCtrlInitMatchOvVel;
			}
			else if (current == "VelCtrlDistType") {
				inputStream >> this->velCtrlDistType;
			}
			else if (current == "LaneOffs") {
				inputStream >> laneOffset;
			}
			else if (current == "MaxLatOffset") {
				inputStream >> this->maxLatOffset;
			}
			else if (current == "VelCtrlDistVal1") {
				inputStream >> this->velCtrlDistVal1;
			}
			else if (current == "VelCtrlInitVel") {
				inputStream >> this->velCtrlInitVel;
			}
			else if (current == "RoadPos") {
				inputStream >> this->roadPos;
			}
			else if (current == "Path") {
				inputStream >> this->path;
			}
			else if (current == "ColorIndex") {
				inputStream >> this->colorIndex;
			}
			else if (current == "LifeTime") {
				inputStream >> this->lifetime;
			}
			else if (current == "ActvDel") {
				inputStream >> this->actvDel;
			}
			else if (current == "CrRad") {
				inputStream >> this->crRad;
			}
			else if (current == "Name") {
				getline(inputStream, name);
			}
			else if (current == "LongComment") {
				getline(inputStream, longComment);
			}
			else if (current == "ShortComment") {
				getline(inputStream, shortComment);
			}
			else if (current == "SolName") {
				inputStream >> solName;
			}
			inputStream >> current;
		}
		return;
	}

	/*unused variables
	bool randomSol = 0;						bool createRel = 0;
	bool autoControlHeadLights = 0;			bool useReaDel = 1;
	int latsOffType = 0;					int createRelLatInFeet = 0;
	int pathSearchDepth = 2;				int stdToAccType = 0;
	int stdToDecType = 0;					int stpToAccType = 0;
	int decToType = 0;						int accel2Catch = 0;
	int velCtrlFollowSpeedLimit = 0;		double normVel2Kp = 0.7;
	double lcvFall1 = 1.5;					double lcvFall2 = 2.0;
	double lcvFreq1 = 0.03;					double lcvFreq2 = 0.05;
	double lcvRAmpl1 = 0.1;					double lcvRAmpl2 = 0.5;
	double emergeDecClip = -11;				double followTimeMax = 2;
	double followTimeMin = 1;				double stdToDecVal1 = 0.9;
	string createRelExp = "";				string logfile = "";
	string dynModel = "\"Non Linear\"";		string runMode = "\"eRemote_Control\"";
	*/
};

class DDO : public Vehicle {
private:
	/*unused
	string MaxDecel 0.0000000E+000			bool QuitAtEnd 0
	bool UseInitVelocity 0					double MaxAccel 0.0000000E+000
	double MaxDecel 0.0000000E+000			string Coupled ""
	bool EnableAnimation 0					bool AccountAccel 0
	bool GlobTraj 1							bool InitState 0
	int Option 0							int AudioState 0
	string RelLoc 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string RelRot 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string InitVelXYZ 0.0000000E+000 0.0000000E+000 0.0000000E+000
	string InitVelRPY 0.0000000E+000 0.0000000E+000 0.0000000E+000
	vector<double> Delays 0 (size of dirs or dirsdef)
	*/

	//consistent variables
	bool dependent;
	bool dependentOwnVeh;
	int visualState; //0, 1, or 2
	position dependentRefPoint;
	vector <double> dirs;
	vector <bool> dirsDef;
	vector <trajectory> trajs;

public:
	DDO () : Vehicle () {}

	DDO(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName,
		bool Dependent, bool DependentOwn, int visState, position refPoint, vector<double> Dirs, vector<bool> DirsDef,
		vector <trajectory> Trajs) : Vehicle(color, LifeTime, delay, CrRad, Name, Long, Short, SolName), dependent(Dependent),
		dependentOwnVeh(DependentOwn), visualState(visState), dependentRefPoint(refPoint), dirs(Dirs), dirsDef(DirsDef),
		trajs(Trajs) {}

	void readFromFile(ifstream &inputStream) {
		string current;
		inputStream >> current;
		while (current != "&&&&End&&&&") {
			if (current == "Dependent") {
				inputStream >> this->dependent;
			}
			else if (current == "DependentOwnVeh") {
				inputStream >> this->dependentOwnVeh;
			}
			else if (current == "VisualState") {
				inputStream >> this->visualState;
			}
			else if (current == "DependDentRefPoint") {
				inputStream >> this->dependentRefPoint.x >> this->dependentRefPoint.y >> this->dependentRefPoint.z;
			}
			else if (current == "Dirs") {
				//read input until the dirsdef is encountered
				inputStream >> current;
				while (current != "DirsDef") {
					dirs.push_back(stod(current));
					inputStream >> current;
				}

				//read in the dirsdef
				bool DirsDef;
				for (unsigned int i = 0; i < dirs.size(); i++) {
					inputStream >> DirsDef;
					dirsDef.push_back(DirsDef);
				}
			}
			else if (current == "Traj") {
				trajectory in;
				inputStream >> in.x >> in.y >> in.speed >> in.xDir >> in.yDir;
				trajs.push_back(in);
			}
			else if (current == "ColorIndex") {
				inputStream >> this->colorIndex;
			}
			else if (current == "LifeTime") {
				inputStream >> this->lifetime;
			}
			else if (current == "ActvDel") {
				inputStream >> this->actvDel;
			}
			else if (current == "CrRad") {
				inputStream >> this->crRad;
			}
			else if (current == "Name") {
				inputStream >> this->name;
			}
			else if (current == "LongComment") {
				inputStream >> this->longComment;
			}
			else if (current == "ShortComment") {
				inputStream >> this->shortComment;
			}
			else if (current == "SolName") {
				inputStream >> this->solName;
			}
			inputStream >> current;
		}
		return;
	}

	void printUnused(ostream &outStream, string spaces) {
		outStream << spaces << "MaxDecel 0.0000000E+000\n";	outStream << spaces << "QuitAtEnd 0\n";
		outStream << spaces << "UseInitVelocity 0\n";	outStream << spaces << "MaxAccel 0.0000000E+000\n";
		outStream << spaces << "Coupled \"\"\n";	outStream << spaces << "EnableAnimation 0\n";
		outStream << spaces << "AccountAccel 0\n";	outStream << spaces << "GlobTraj 1\n";
		outStream << spaces << "InitState 0\n";	outStream << spaces << "Option 0\n";
		outStream << spaces << "Option 0\n";	outStream << spaces << "AudioState 0\n";
		outStream << spaces << "string RelLoc 0.0000000E+000 0.0000000E+000 0.0000000E+000\n";	
		outStream << spaces << "string RelRot 0.0000000E+000 0.0000000E+000 0.0000000E+000\n";
		outStream << spaces << "InitVelXYZ 0.0000000E+000 0.0000000E+000 0.0000000E+000\n";
		outStream << spaces << "InitVelRPY 0.0000000E+000 0.0000000E+000 0.0000000E+000\n";
		outStream << spaces << "Delays ";

		for (unsigned int i = 0; i < dirs.size(); i++) {
			outStream << "0.0000000E+000 ";
		}
		outStream << '\n';

		return;
	}

	void print(ostream &outStream) {
		string spaces = "  ";
		string spacesTillTitle = "";
		if (createdByTrigger) {
			spaces = "          ";
			spacesTillTitle = "        ";
		}
		outStream << spacesTillTitle << "HCSM Ddo\n";
		this->printBasics(outStream, spaces);
		this->printUnused(outStream, spaces);

		outStream << spaces << "Dependent " << dependent << '\n';
		outStream << spaces << "DependentOwnVeh " << dependentOwnVeh << '\n';
		outStream << spaces << "VisualState " << visualState << '\n';
		outStream << spaces << "DependentRefPosition " << dependentRefPoint.x << dependentRefPoint.y 
			<< dependentRefPoint.z << '\n';

		outStream << spaces << "Dirs " << std::setprecision(7) << std::scientific;
		for (unsigned int i = 0; i < dirs.size(); i++) {
			outStream << dirs[i] << " ";
		}
		outStream << '\n';

		outStream << spaces << "DirsDef ";
		for (unsigned int i = 0; i < dirsDef.size(); i++) {
			outStream << dirsDef[i] << " ";
		}
		outStream << '\n';

		for (unsigned int i = 0; i < trajs.size(); i++) {
			outStream << "Traj " << trajs[i].x << " " << trajs[i].y << trajs[i].speed << " " << trajs[i].xDir << trajs[i].yDir;
			outStream << '\n';
		}
		return;
	}
};
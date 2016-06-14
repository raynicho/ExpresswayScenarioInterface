#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <exception>
#include "Trigger.h"
#include "staticObject.h"
#include "VirtualObject.h"
#include "Vehicle.h"
#include "SCNHeader.h"
#include "Helpers.h"
#include "MajorSettings.h"
#include "Trial.h"

using std::string;
using std::vector;
using std::cout;
using std::ifstream;
using std::ostream;
using std::ofstream;

class SCNHighwayTemplate {
private:
	const int trialLength = 4000;
	double roadwayStartX = 0;
	double roadwayStartY = 0;
	SCNHeader header;
	vector <Trigger*> triggers;
	vector <Vehicle*> vehicles;
	vector <StaticObject> staticObjects;
	vector <VirtualObject> virtualObjects;

public:
	//destructor
	~SCNHighwayTemplate() {
		//delete the vehicles
		for (unsigned int i = 0; i < vehicles.size(); i++) {
			delete vehicles[i]; vehicles[i] = 0;
		}

		//delete the triggers
		for (unsigned int i = 0; i < triggers.size(); i++) {
			delete triggers[i]; triggers[i] = 0;
		}
	}
    
    void processLeadVehicle (FVLVInstructions &leadVehicle) {
        
        return;
    }
    
    void processFollowVehicle (FVLVInstructions &followVehicle) {
        
        return;
    }
    
    void processLeftLane (leftLaneControl &leftLane) {
        
        return;
    }
    
    void processRoadSide(roadSideControl &roadSide) {
        
        return;
    }
    
    void generateFollowVehicle (FVLVSettings &followVehicle) {
        //create the vehicle
        int color = 0;
        double LifeTime = 0;
        double delay = 0;
        double CrRad = 0;
        string Name = "\"FV\"";
        string Long = "\"\"";
        string Short = "\"\"";
        string SolName = "\"" + followVehicle.SOLModel + "\"";
        bool autoBreak = false;
        bool velInitMatch = false;
        int distType = 1;
        double laneOff = 0.78;
        double maxLatOff = 9;
        double distVal1 = 54.6;
        double initVel = 65;
        string RoadPos = "\"r1_0_113520:0:30.99:0.80\""; 
        string Path  = "-1";        
        
        Vehicle* follow = new ADO (color, LifeTime, delay, CrRad, Name, Long, Short, SolName, autoBreak, velInitMatch, distType, laneOff, maxLatOff, distVal1, initVel, RoadPos, Path);
        follow->setCreation(false);
        
        followVehicle.maxDeccel = followVehicle.maxDeccel * -1;
        
        //create the set dial action for the maintain gap       
        int set = 0;
        double Delay = 0;
        string Comment = "\"FV_Keep_Distance\"";
        string nameSet = "\"FV\"";
        string Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(followVehicle.distance) + ";" + std::to_string(followVehicle.maxSpeed) + ";" + std::to_string(followVehicle.minSpeed) + ";4;4;" + std::to_string(followVehicle.maxAccel) + ";" + std::to_string(followVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
        string dialPath = "\"Ado/MaintainGap\"";
        Action* keep = new SetDial (set, Delay, Comment, nameSet, Dial, dialPath);
        
        //create the gap maintain trigger
        bool seq = false;
        bool shot = false;
        double timeDelay = 0;
        double Debounce = 0;
        double actDelay = 0;
        double creRad = 0;
        double Life = 0;
        string name = "\"FV_Keep_Distance\"";
        string LongComment = "\"\"";
        string ShortComment = "\"\"";
        position Draw;
        position Pos;
        Draw.x = 52; Draw.y = -1480; Draw.z = 0;
        Pos.x = 52; Pos.y = -1480; Pos.z = 0;
        vector <Action*> Act;
        Act.push_back(keep);
        string Expression = "\"1=1\"";        
        
        Trigger* maintain = new expressionTrigger(seq, shot, timeDelay, Debounce, actDelay, creRad, Life, name, LongComment, ShortComment, Draw, Pos, Act, Expression);
        
        //add the vehicle and the trigger
        vehicles.push_back(follow);
        triggers.push_back(maintain);
        
        return;
    }
    
    void generateLeadVehicle (FVLVSettings &leadVehicle) {
        //create the vehicle
        
        
        //create the gap maintain trigger
        
        return;
    }
    
    void generateTraffic (int numberTrials, int numberCars) {
        return;
    }
    
    void generateBlindSpot () {
        return;
    }
    
    void generateFCW (FCW &fcwSettings, vector<Trial> &trials) {
        return;
    }
    
    void processAll (vector<Trial> &trials, MajorSettings &settings) {
        //process the settings
        generateFollowVehicle(settings.followVehicle);
        
        generateLeadVehicle(settings.leadVehicle);
        
        if (settings.generateTraffic){
            generateTraffic(settings.numberTrials, settings.numberOfVehicles);
        }
        
        if (settings.showBlindSpot) {
            generateBlindSpot();
        }
        
        if (settings.warningSettings.checked) {
            generateFCW(settings.warningSettings, trials);
        }
        
        //process the trials
        for (auto trial : trials) {
            if (trial.roadSide.checked) {
                processRoadSide(trial.roadSide);
            }
            if (trial.leftLane.checked) {
                processLeftLane(trial.leftLane);
            }
            if (trial.followVehicle.checked){
                processFollowVehicle(trial.followVehicle);
            }
            if (trial.leadVehicle.checked) {
                processLeadVehicle(trial.leadVehicle);
            }
        }
        
        return;
    }

	void printUnusedSCNObjects(ostream &outStream) {
		outStream << "HCSM DriverMirror\n&&&&End&&&&\n";
		outStream << "HCSM IntersectionManager\n&&&&End&&&&\n";
		return;
	}

    void clearTillEnd (ifstream &inputStream) {
        string current;
        inputStream >> current;
        while (current != "&&&&End&&&&") {
            inputStream >> current;
        }
        return;
    }

	void writeFile(string outputFilePath) {
		//open the file
		ofstream outStream;
		outStream.open(outputFilePath);

		//print the header
		header.print(outStream);

		//gateway and vehicle fail
		outStream << "HCSM Gateway\n&&&&End&&&&\n";
		outStream << "HCSM VehFail\n&&&&End&&&&\n";

		//print the static objects
		outStream << "HCSM StaticObjManager\n";
		for (auto stat : staticObjects) {
			stat.print(outStream);
		}
		outStream << "&&&&End&&&&\n";

		//print the traffic manager
		outStream << "HCSM TrafficLightManager\n  GroupName \"Traffic Manager\"\n&&&&End&&&&\n";

		//print the environment controller
		outStream << "HCSM EnvironmentController\n&&&&End&&&&\n";

		//print the traffic light manager
		outStream << "HCSM TrafficLightManager\n&&&&End&&&&\n";

		//print the triggers
		for (auto trigger : triggers) {
			trigger->filePrint(outStream);
		}

		//print the vehicles, only the non created ones
		for (auto vehicle : vehicles) {
			if (!vehicle->getCreation()) {
				vehicle->print(outStream);
			}
		}

		//print the virtual objects
		for (auto virt : virtualObjects) {
			virt.print(outStream);
		}

		printUnusedSCNObjects(outStream);
		
		outStream.close();
		return;
	}

	//reads in the file: header, triggers, vehicles, etc.
	void readFile(string SCNFilePath) {
        if (SCNFilePath.empty()) {
            return;
        }
        
		//open the filestream
		ifstream inputStream;
		inputStream.open(SCNFilePath);

        /*
        //if its not open
		if (!inputStream.is_open()) {
			//throw an error to be caught in main
			std::exception e("Filename not entered correctly. Exiting program.");
			inputStream.close();
			throw e;
		}
        */
        

		//begin reading the file by reading the header
		this->readHeader(inputStream);

		//begin reading everything else
		this->readRest(inputStream);

		//close the file when done
		inputStream.close();

		//write the header and see what happens
		//ofstream out;
		//out.open("C:\\Users\\raynicho\\Desktop\\SCNHighwayTemplate\\SCNExampleFiles\\test.txt");
		//header.print(out);
		//out.close();
		return;
	}

	//responsible for reading in information from the header
	void readHeader(ifstream &inputStream) {
		if (!header.readFromFile(inputStream)) {
			std::exception e("The scn file entered does not have a vehicle position entered.");
		}
		return;
	}

	void readInStaticObjManager(ifstream &inputStream) {
		string currentLine;
		inputStream >> currentLine;
		while (currentLine != "&&&&End&&&&") {
			inputStream >> currentLine;
			StaticObject s;
			s.readFromFile(inputStream);
			staticObjects.push_back(s);
			inputStream >> currentLine;
		}
		return;
	}

	void readRest(ifstream &inputStream) {
        vector<Vehicle*>* vehPtr = &vehicles;
		string inputCase;
		getline(inputStream, inputCase);
		while (!inputStream.eof()) {
			if (inputCase == "HCSM Gateway") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM VehFail") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM TrafficManager") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM EnvironmentController") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM TrafficLightManager") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM StaticObjManager") {
				readInStaticObjManager(inputStream);
			}
			else if (inputCase == "HCSM DriverMirror") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM IntersectionManager") {
                clearTillEnd(inputStream);
			}
			else if (inputCase == "HCSM ExpressionTrigger") {
				Trigger* newTrigger = new expressionTrigger;
                newTrigger->fileRead(inputStream, vehPtr);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM RoadPadTrigger") {
				Trigger* newTrigger = new roadPadTrigger;
                newTrigger->fileRead(inputStream, vehPtr);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM TimeTrigger") {
				Trigger* newTrigger = new timeTrigger;
                newTrigger->fileRead(inputStream, vehPtr);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM Ddo") {
				Vehicle* newVehicle = new DDO;
				newVehicle->readFromFile(inputStream);
				vehicles.push_back(newVehicle);
			}
			else if (inputCase == "HCSM Ado") {
				Vehicle* newVehicle = new ADO;
				newVehicle->readFromFile(inputStream);
				vehicles.push_back(newVehicle);
			}
			else if (inputCase == "HCSM StaticObject") {
				StaticObject s;
				s.readFromFile(inputStream);
				staticObjects.push_back(s);
			}
			else if (inputCase == "HCSM VirtualObject") {
				VirtualObject v;
				v.readFromFile(inputStream);
				virtualObjects.push_back(v);
			}
			else {
				//string Error = "Unexpected object encountered: ";
				if (!inputCase.empty()) {
                    cout << inputCase << '\n';
				}
			}
			getline(inputStream, inputCase);
		}
		//cout << "Completed reading the file.\n";
		return;
	}
};

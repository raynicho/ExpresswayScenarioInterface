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
#include <random>
#include <stdlib.h>
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
	const double trialLengthFt = 3937;
    const double trialSetupLengthFt = 656;
	double roadwayStartX = 0;
	double roadwayStartY = 0;
	SCNHeader header;
    std::default_random_engine re;
    vector <string> carSolModels;
    vector <string> truckSolModels;
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
    
    //constructor
    SCNHighwayTemplate () {
        const int seed = 10;
        srand(10);
        
        carSolModels.push_back("\"Audi\"");
        carSolModels.push_back("\"ChevyBlazer\"");
        carSolModels.push_back("\"Deville\"");
        carSolModels.push_back("\"DodgeNeon\"");
        carSolModels.push_back("\"LandRover\"");
        carSolModels.push_back("\"PEUGEOT_306\"");        
        carSolModels.push_back("\"Windstar\"");
        carSolModels.push_back("\"Towncar\"");
        carSolModels.push_back("\"FordTaurus\"");
        carSolModels.push_back("\"BMW_StationWagon\"");
        
        truckSolModels.push_back("\"Ford_F150Xcab\"");
        truckSolModels.push_back("\"Freightliner_Semi\"");
        truckSolModels.push_back("\"DumpTruck\"");
        truckSolModels.push_back("\"CokeTruck\"");
        truckSolModels.push_back("\"cargill_semi_freightliner_red\"");
        truckSolModels.push_back("\"semi_peterbilt_yel_Walmart\"");
        truckSolModels.push_back("\"schoolbus\"");
        truckSolModels.push_back("\"CementTruck\"");
        truckSolModels.push_back("\"GarbageTruck\"");
        truckSolModels.push_back("\"semi_peterbilt_white_FordRacing\"");
    }
    
    void processLeadVehicle (FVLVInstructions &leadVehicle, ostream &outStream) {
        
        return;
    }
    
    void processFollowVehicle (FVLVInstructions &followVehicle, ostream &outStream) {
        
        return;
    }
    
    void processRoadSide(roadSideControl &roadSide, ostream &outStream) {
        
        return;
    }
    
    void generateFollowVehicle (FVLVSettings &followVehicle, ostream &outStream) {
        //create the vehicle
        int color = getRandSolColor(followVehicle.SOLModel);
        double LifeTime = 0;
        double delay = 0;
        double CrRad = 0;
        string Name = "\"FV\"";
        string Long = "\"\"";
        string Short = "\"\"";
        string SolName = followVehicle.SOLModel;
        bool autoBreak = false;
        bool velInitMatch = false;
        int distType = 1;
        double laneOff = 0.78;
        double maxLatOff = 9;
        double distVal1 = 54.6;
        double initVel = 0;
        string RoadPos = "\"r1_0_113520:0:30.99:0.80\""; 
        string Path  = "-1";        
        
        ADO follow(color, LifeTime, delay, CrRad, Name, Long, Short, SolName, autoBreak, velInitMatch, distType, laneOff, maxLatOff, distVal1, initVel, RoadPos, Path);
        follow.setCreation(false);
        
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
        
        expressionTrigger maintain(seq, shot, timeDelay, Debounce, actDelay, creRad, Life, name, LongComment, ShortComment, Draw, Pos, Act, Expression);
        
        //print the vehicle and the trigger
        follow.print(outStream);
        maintain.filePrint(outStream);
        
        return;
    }
    
    void generateLeadVehicle (FVLVSettings &leadVehicle, ostream &outStream) {
        //create the vehicle
        int color = getRandSolColor(leadVehicle.SOLModel);
        double LifeTime = 0;
        double delay = 0;
        double CrRad = 0;
        string Name = "\"LV\"";
        string Long = "\"\"";
        string Short = "\"\"";
        string SolName = leadVehicle.SOLModel;
        bool autoBreak = false;
        bool velInitMatch = false;
        int distType = 1;
        double laneOff = 0.78;
        double maxLatOff = 9;
        double distVal1 = 54.6;
        double initVel = 0;
        string RoadPos = "\"r1_0_113520:0:266.44:0.78\""; 
        string Path  = "-1";        
        
        ADO lead(color, LifeTime, delay, CrRad, Name, Long, Short, SolName, autoBreak, velInitMatch, distType, laneOff, maxLatOff, distVal1, initVel, RoadPos, Path);
        lead.setCreation(false);
        
        //create the maintain gap action
        int set = 0;
        double Delay = 0;
        string Comment = "\"LV_Keep_Distance\"";
        string nameSet = "\"LV\"";
        string Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(leadVehicle.distance) + ";" + std::to_string(leadVehicle.maxSpeed) + ";" + std::to_string(leadVehicle.minSpeed) + ";4;4;" + std::to_string(leadVehicle.maxAccel) + ";" + std::to_string(leadVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
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
        string name = "\"LV_Keep_Distance\"";
        string LongComment = "\"\"";
        string ShortComment = "\"\"";
        position Draw;
        position Pos;
        Draw.x = 62; Draw.y = -1480; Draw.z = 0;
        Pos.x = 62; Pos.y = -1480; Pos.z = 0;
        vector <Action*> Act;
        Act.push_back(keep);
        string Expression = "\"1=1\"";        
        
        expressionTrigger maintain (seq, shot, timeDelay, Debounce, actDelay, creRad, Life, name, LongComment, ShortComment, Draw, Pos, Act, Expression);
        
        
        //print the vehicle and the trigger
        lead.print(outStream);
        maintain.filePrint(outStream);
        
        return;
    }
    
    double randDouble (double min, double max) {
        std::uniform_real_distribution<double> unif(min, max);
        double rand = unif(re);
        return rand;
    }
    
    string getRandSol (bool isTruck) {
        if (isTruck) {
            return truckSolModels[rand() % truckSolModels.size()];
        }
        return carSolModels[rand() % carSolModels.size()];
    }
    
    //returns true if it is truck or false if it is to be a car
    bool truckOrCar (int carsLeft, int trucksLeft) {
        if (carsLeft == 0) {
            return true;
        }
        if (trucksLeft == 0) {
            return false;
        }
        int r = rand () % 2;
        
        //if even return true
        if (r == 0) {
            return true;
        }
        return false;
    }
    
    int getRandSolColor (string sol) {
        if (sol == "\"Audi\"") {
            return rand() % 5;
        }
        else if (sol == "\"ChevyBlazer\"") {
            return rand() % 4;
        }
        else if (sol == "\"Deville\"") {
            return rand() % 5;
        }
        else if (sol == "\"DodgeNeon\"") {
            return rand() % 5;
        }
        else if (sol == "\"Ford_F150Xcab\"") {
            return rand() % 5;
        }
        else if (sol == "\"LandRover\"") {
            return rand() % 5;
        }
        else if (sol == "\"PEUGEOT_306\"") {
            return rand() % 5;
        }
        else if (sol == "\"Windstar\"") {
            return rand() % 5;
        }
        else if (sol == "\"Towncar\"") {
            return rand() % 5;
        }
        else if (sol == "\"Freightliner_Semi\"") {
            return rand() % 2;
        }
        else if (sol == "\"FordTaurus\"") {
            return rand() % 5;
        }
        else if (sol == "\"BMW_StationWagon\"") {
            return rand() % 5;
        }
        else if (sol == "\"DumpTruck\"" || sol == "\"CokeTruck\"" || sol == "\"cargill_semi_freightliner_red\"" || sol == "\"semi_peterbilt_yel_Walmart\"" || sol == "\"schoolbus\"" || sol == "\"CementTruck\"" || sol == "\"GarbageTruck\"" || sol == "\"semi_peterbilt_white_FordRacing\"") {
            return 0;
        }
        return 0;
    }
    
    void generateTraffic (int numberTrials, int numberCarsPerTrial, int numberOfCars, int numberOfTrucks, ostream &outStream) {
        //define parameters for road pos left, right, start of trial 1, trial length, in between length of trials
        double currentY = numberTrials*trialLengthFt + numberTrials*trialSetupLengthFt;
        double increationLength = (trialLengthFt + trialSetupLengthFt)/numberCarsPerTrial;
        double lowerRange = currentY - increationLength;
        double yPos;
        int lanePos;
        string SolName;
        string name;
        int color;
        string RoadPos;
        int laneOffset = 1;
        int carsLeft = numberOfCars;
        int trucksLeft = numberOfTrucks;
        
        //constants for the vehicle
        double LifeTime = 0;
        double delay = 0;
        double CrRad = 2000;
        string Long = "\"\"";
        string Short = "\"\"";
        bool autoBreak = false;
        bool velInitMatch = false;
        int distType = 1;
        double laneOff = 0.78;
        double maxLatOff = 9;
        double distVal1 = 54.6;
        double initVel = 65;
        string Path  = "-1";
        
        //iterate from 1 to the max number of trials
        for (int i = numberTrials; i >= 2; i--) {
            //divide the trial into numberCars sections
            for (int k = 0; k < numberCarsPerTrial; k++) {              
                //get a random y coordinate in the range
                yPos = randDouble(lowerRange, currentY);
                
                //get a random lane and set the lane position accordingly
                lanePos = rand () % 2;
                
                //get the random sol and random color
                if (truckOrCar(carsLeft, trucksLeft)) {
                    trucksLeft--;
                    SolName = getRandSol(true);
                }
                else {
                    carsLeft--;
                    SolName = getRandSol(false);
                }
                color = getRandSolColor(SolName);
                
                //set the road pos
                RoadPos = "\"r2_0_113520:" + std::to_string(lanePos) + ":" + std::to_string(yPos) + ":" + std::to_string(laneOffset) + "\"";
                
                //name the vehicle properly
                name = "\"Opposite" + std::to_string(i) + "_" + std::to_string(k) + "\"";
                
                //create the vehicle
                ADO opposite (color, LifeTime, delay, CrRad, name, Long, Short, SolName, autoBreak, velInitMatch, distType, laneOff, maxLatOff, distVal1, initVel, RoadPos, Path);
                opposite.setCreation(false);
                
                //write the vehicle to the filestream
                opposite.print(outStream);
                
                //decrease the lower range and the current y by the increation length
                lowerRange = lowerRange - increationLength;
                currentY = currentY - increationLength;
                
                if (carsLeft == 0 && trucksLeft == 0) {
                    carsLeft = numberOfCars;
                    trucksLeft = numberOfTrucks;
                }
            }
        }
        return;
    }
    
    void processLeftLane (leftLaneControl &leftLane, ostream &outStream) {
        //create the vehicle
        string SolName = getRandSol(false);
        int color = getRandSolColor(SolName);
        double LifeTime = 0;
        double delay = 0;
        double CrRad = 0;
        string Name = "\"LV\"";
        string Long = "\"\"";
        string Short = "\"\"";
        bool autoBreak = false;
        bool velInitMatch = false;
        int distType = 1;
        double laneOff = 0.78;
        double maxLatOff = 9;
        double distVal1 = 54.6;
        double initVel = 0;
        string RoadPos = "\"r1_0_113520:0:266.44:0.78\""; 
        string Path  = "-1";        
        
        ADO lead(color, LifeTime, delay, CrRad, Name, Long, Short, SolName, autoBreak, velInitMatch, distType, laneOff, maxLatOff, distVal1, initVel, RoadPos, Path);
        lead.setCreation(false);
            //alter the position accordingly
        
        //generate the creation action
        Action* act = new CreateHCSM(0, 0, "");
                
            //alter the position accordingly
        
        //generate the roadpad trigger
        
            //alter the position accordingly
            
        
        
        //movement option 0
        
        //movement option 1
        
        //movement option 2
        
        //movement option 3
        
        //blinker control
        
        return;
    }
    
    void generateBlindSpot (vector<Trial> &trials, ostream &outStream) {
        return;
    }
    
    void generateFCW (FCW &fcwSettings, vector<Trial> &trials, ostream &outStream) {
        return;
    }
    
    void processAll (vector<Trial> &trials, MajorSettings &settings, ostream &outStream) {
        //process the settings
        generateFollowVehicle(settings.followVehicle, outStream);
        
        generateLeadVehicle(settings.leadVehicle, outStream);
        
        if (settings.generateTraffic){
            generateTraffic(settings.numberTrials, settings.numberCarsPerTrial, settings.numberCars, settings.numberTrucks, outStream);
        }
        
        if (settings.showBlindSpot) {
            generateBlindSpot(trials, outStream);
        }
        
        if (settings.warningSettings.checked) {
            generateFCW(settings.warningSettings, trials, outStream);
        }
        
        int trialNum = 0;
        
        //process the trials
        for (auto trial : trials) {
            trial.trialNumber = trialNum;
            if (trialNum > 0) {
                if (trial.roadSide.checked) {
                    processRoadSide(trial.roadSide, outStream);
                }
                if (trial.leftLane.checked) {
                    processLeftLane(trial.leftLane, outStream);
                }
                if (trial.followVehicle.checked){
                    processFollowVehicle(trial.followVehicle, outStream);
                }
                if (trial.leadVehicle.checked) {
                    processLeadVehicle(trial.leadVehicle, outStream);
                }
            }
            trialNum++;
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

	void writeFile(string outputFilePath, vector<Trial> &trials, MajorSettings &settings) {
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
        
        processAll (trials, settings, outStream);

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

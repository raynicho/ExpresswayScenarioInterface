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
	const double trialLengthFt = 3750;
    const double trialSetupLengthFt = 1250;
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
        string SolName = followVehicle.SOLModel; 
        
        ADO follow(color, 0, 0, 0, "\"FV\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 0, "\"r1_0_113520:0:30.99:0.80\"", "-1");
        follow.setCreation(false);
        
        //create the set dial action for the maintain gap
        string Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(followVehicle.distance) + ";" + std::to_string(followVehicle.maxSpeed) + ";" + std::to_string(followVehicle.minSpeed) + ";4;4;" + std::to_string(followVehicle.maxAccel) + ";" + std::to_string(followVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
        Action* keep = new SetDial (0, 0, "\"FV_Keep_Distance\"", "\"FV\"", Dial, "\"Ado/MaintainGap\"");
        
        //create the gap maintain trigger
        position Draw;
        position Pos;
        Draw.x = 52; Draw.y = -1480; Draw.z = 0;
        Pos.x = 52; Pos.y = -1480; Pos.z = 0;
        vector <Action*> Act;
        Act.push_back(keep);      
        
        expressionTrigger maintain(false, false, 0, 0, 0, 0, 0, "\"FV_Keep_Distance\"", "\"\"", "\"\"", Draw, Pos, Act, "\"1=1\"");
        
        //print the vehicle and the trigger
        follow.print(outStream);
        maintain.filePrint(outStream);
        return;
    }
    
    void generateLeadVehicle (FVLVSettings &leadVehicle, ostream &outStream) {
        //create the vehicle
        int color = getRandSolColor(leadVehicle.SOLModel);
        string SolName = leadVehicle.SOLModel;
        
        ADO lead(color, 0, 0, 0, "\"LV\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 0, "\"r1_0_113520:0:266.44:0.78\"", "-1");
        lead.setCreation(false);
        
        //create the maintain gap action
        string Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(leadVehicle.distance) + ";" + std::to_string(leadVehicle.maxSpeed) + ";" + std::to_string(leadVehicle.minSpeed) + ";4;4;" + std::to_string(leadVehicle.maxAccel) + ";" + std::to_string(leadVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
        Action* keep = new SetDial (0, 0, "\"LV_Keep_Distance\"", "\"LV\"", Dial, "\"Ado/MaintainGap\"");
        
        //create the gap maintain trigger
        position Draw;
        Draw.x = 62; Draw.y = -1480; Draw.z = 0;
        vector <Action*> Act;
        Act.push_back(keep);        
        expressionTrigger maintain (false, false, 0, 0, 0, 0, 0, "\"LV_Keep_Distance\"", "\"\"", "\"\"", Draw, Draw, Act, "\"1=1\"");
                
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
        //else if (sol == "\"DumpTruck\"" || sol == "\"CokeTruck\"" || sol == "\"cargill_semi_freightliner_red\"" || sol == "\"semi_peterbilt_yel_Walmart\"" || sol == "\"schoolbus\"" || sol == "\"CementTruck\"" || sol == "\"GarbageTruck\"" || sol == "\"semi_peterbilt_white_FordRacing\"") {
            //return 0;
        //}
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
                ADO opposite (color, 0, 0, 2000, name, "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 65, RoadPos, "-1");
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
    
    void processLeftLane (leftLaneControl &leftLane, ostream &outStream, int trialNum) {
        //create the vehicle
        string SolName = getRandSol(false);
        int color = getRandSolColor(SolName);
        string RoadPos;
        string leftVehName = "\"Left_" + std::to_string(trialNum) + "\"";

        //if the creation position in front
        if (leftLane.creationOption == 1) {
            //A is 1 (Northern Roadway), B is 1 (inside lane
            RoadPos = "\"r1_0_113520:1:";
                    
            //C is based on the trial number ((trial number * trial length + trial number * trialsetup) + creationDistance), D is 0 
            RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) + leftLane.creationDistance) + ":0\"";
            
        }
        //if the creation position is behind
        else {
            //A is 1 (Northern Roadway), B is 1 (inside lane)
            RoadPos = "\"r1_0_113520:1:";
                    
            //C is based on the trial number ((trial number * trial length + trial number * trialsetup) - creationDistance), D is 0 
            RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) - leftLane.creationDistance) + ":0\"";           
        }
        
        ADO left(color, 0, 0, 0, "\"Left_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 65, RoadPos, "-1");
        left.setCreation(true);
        
        //generate the creation action, add the vehicle, blinker dials
        //Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
        //Vehicle* leftPtr = new ADO (left);
        //leftPtr->setInitialVel();
        //act->addVehicle(leftPtr);
        Action* reset = 0;
        Action* blinker = 0;
        //Act.push_back(act);
        //Act.push_back(reset);
        //Act.push_back(blinker);
        
        //blinker control
        string dial = "\"VisualState\" ";
        switch (leftLane.blinker) {
            case (Left) : {
                dial = dial + "\"1;20000\"";
                break;
            }
            case (Hazards) : {
                dial = dial + "\"4;20000\"";
                break;
            }
            case (Right) : {
                dial = dial + "\"2;20000\"";
                break;
            }
        }
        
        if (leftLane.blinker != None) {
            reset = new ResetDial (0, 0, "\"LeftResetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, "\"VisualState\" \"16;2\"", "\"Ado/VisualState\"");
            blinker = new SetDial(0, 0, "\"LeftSetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, dial, "\"Ado/VisualState\"");
        }
        
        //generate the roadpad trigger
        position Draw;
        Draw.x = 450;
        Draw.y = (trialNum * (trialLengthFt + trialSetupLengthFt)) - 1320;
        vector <Action*> Act;
        double beginYPos = (trialNum * (trialLengthFt + trialSetupLengthFt));
        double endYpos = beginYPos + 20;
        double initVeloc = 0;
        
        //movement option 0
        //set the initial speed according to the creation position
        if (leftLane.movementOption == 0) {
            //if its created in front
            if (leftLane.creationOption == 1) {
                initVeloc = 30;
                //reset the speed and then force the velocity to be 90 miles an hour
                //Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
                //Action* setSpeed = new SetDial (0, 0, "\"LeftSetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"30\"", "\"Ado/ForcedVelocity\"");
                
                //add both actions to the roadpad trigger
                //Act.push_back(resetSpeed);
                //Act.push_back(setSpeed);
            }
            //otherwise it is created behind
            else {
                initVeloc = 90;
                //reset the speed and then force the velocity to be 30 miles an hours
                //Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
                //Action* setSpeed = new SetDial (0, 0, "\"LeftSetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"90\"", "\"Ado/ForcedVelocity\"");
                
                //add both actions to the roadpad trigger
                //Act.push_back(resetSpeed);
                //Act.push_back(setSpeed);
            }
            
            //generate the creation action, add the vehicle, blinker dials
            Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
            Vehicle* leftPtr = new ADO (left);
            leftPtr->setInitialVel(initVeloc);
            act->addVehicle(leftPtr);
            Act.push_back(act);
            Act.push_back(reset);
            Act.push_back(blinker);
            roadPadTrigger roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, Act, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
            roadTrigger.filePrint(outStream);
            
            //generate the action to reset the velocity and then match the Et velocity
            //Action* resetBeforeMatching = new ResetDial (0, 0, "\"LeftResetSpeedBeforeMatch_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
            Action* setToMatch = new SetDial (0, 0, "\"LeftMatchSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
            
            //generate the expression trigger to match velocity
            position pos = Draw;
            pos.x = pos.x + 70;
            vector <Action*> blindActions;
            //blindActions.push_back(resetBeforeMatching);
            blindActions.push_back(setToMatch);
            expressionTrigger blindSpot (true, false, 0, 0, 0, trialLengthFt, 0, "\"LeftBlindSpot_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", pos, pos, blindActions, "\" GetObjDistPow2('Left_" + std::to_string(trialNum) + "') < 10 * 10\"");
            blindSpot.filePrint(outStream);
        }
        
        //movement option 1
        else if (leftLane.movementOption == 1){
            //if the creation is in front
            if (leftLane.creationOption == 1) {
                initVeloc = 30;
                //set speed to 30 mph
                //Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
                //Action* setSpeed = new SetDial (0, 0, "\"LeftSetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"30\"", "\"Ado/ForcedVelocity\"");
                
                //add both actions to the roadpad trigger
                //Act.push_back(resetSpeed);
                //Act.push_back(setSpeed);
            }
            //if the creation is behind
            else {
                initVeloc = 90;
                //set speed to 90 mph
                //Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
                //Action* setSpeed = new SetDial (0, 0, "\"LeftSetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"90\"", "\"Ado/ForcedVelocity\"");
                
                //add both actions to the roadpad trigger
                //Act.push_back(resetSpeed);
                //Act.push_back(setSpeed);
            }
            
            //generate the creation action, add the vehicle, blinker dials
            Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
            Vehicle* leftPtr = new ADO (left);
            leftPtr->setInitialVel(initVeloc);
            act->addVehicle(leftPtr);
            Act.push_back(act);
            Act.push_back(reset);
            Act.push_back(blinker);
            roadPadTrigger roadTrigger (true, true, 0, 0, 0, 2000, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, Act, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
            roadTrigger.filePrint(outStream);
            
            //create expression trigger once within distance (40 ft) (one shot), actions include: reseting speed dial, setting speed dial to match et, lane change, then resetting speed dial again
            Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
            Action* matchSpeed = new SetDial (0, 0, "\"LeftMatchSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
            Action* resetLaneChange = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"LaneChange\" \"right;1;2\"", "\"Ado/LaneChange\"");
            Action* laneChange = new SetDial (0, 0, "\"LeftChangeRight_" + std::to_string(trialNum) + "\"", leftVehName, "\"LaneChange\" \"right;1;2\"", "\"Ado/LaneChange\"");
            
            vector<Action*> changeRightActions;
            changeRightActions.push_back(resetSpeed);
            changeRightActions.push_back(matchSpeed);
            changeRightActions.push_back(resetLaneChange);
            changeRightActions.push_back(laneChange);
            changeRightActions.push_back(resetSpeed);
            
            position pos = Draw;
            pos.x = pos.x + 70;
            expressionTrigger leftChangeRight (true, true, 0, 0, 0, trialLengthFt, 0, "\"LeftChangeRight_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", pos, pos, changeRightActions, "\"GetObjDistPow2('Left_" + std::to_string(trialNum) + "') < 40 * 40\"");
            leftChangeRight.filePrint(outStream);
            
            //create another expression trigger to match the external driver once within that 40 ft range
            //Action* resetSpeedAfterChange = new ResetDial (0, 0, "\"LeftResetSpeedAfterChange_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
            Action* matchSpeedAfterChange = new SetDial (0, 0, "\"LeftMatchSpeedAfterChange_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
            vector <Action*> afterChangeActions;
            //afterChangeActions.push_back(resetSpeedAfterChange);
            afterChangeActions.push_back(matchSpeedAfterChange);
            position afterChange = pos;
            afterChange.x = afterChange.x + 70;
            expressionTrigger matchSpeedAfterChangeTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"LeftMatchAfterChange_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", afterChange, afterChange, afterChangeActions, "\"GetObjDistPow2('Left_" + std::to_string(trialNum) + "') < 40 * 40\"");
            matchSpeedAfterChangeTrigger.filePrint(outStream);
            
            //create roadpad trigger towards end of trial
            //need to add position
            position changeLanePos = Draw;
            changeLanePos.y = changeLanePos.y + trialLengthFt - 100;
            double pathBegin = trialNum*(trialSetupLengthFt + trialLengthFt) + trialLengthFt - 100;
            double pathEnd = pathBegin + 20;
            string changeAtEndPath = "\"R:r1_0_113520:0[" + std::to_string(pathBegin) + ":" + std::to_string(pathEnd) + "]:1[" + std::to_string(pathBegin) + ":" + std::to_string(pathEnd) + "]\"";
            
            Action* deleteMatchEt = new DeleteHCSM (0, 0, "\"\"", "\"LeftMatchAfterChange_" + std::to_string(trialNum) + "\"");
            Action* resetChangeAtEnd = new ResetDial (0, 0, "LeftResetLaneChangeAtEnd_" + std::to_string(trialNum) + "\"", leftVehName, "\"LaneChange\" \"right;1;2\"", "\"Ado/LaneChange\"");
            Action* changeAtEndAct = new SetDial (0, 0, "\"LeftChangeLeft_" + std::to_string(trialNum) + "\"", leftVehName, "\"LaneChange\" \"left;1;2\"", "\"Ado/LaneChange\"");
            vector<Action*> changeLaneAtEndActions;
            changeLaneAtEndActions.push_back(deleteMatchEt);
            changeLaneAtEndActions.push_back(resetChangeAtEnd);
            changeLaneAtEndActions.push_back(changeAtEndAct);
            
            roadPadTrigger changeLaneAtEnd (true, true, 0, 0, 0, trialLengthFt, 0, "\"LeftChangeAtEnd_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", changeLanePos, changeLanePos, changeLaneAtEndActions, leftVehName, changeAtEndPath);
            changeLaneAtEnd.setTypeSet(false);
            changeLaneAtEnd.filePrint(outStream);
        }
        
        //movement option 2
        else if (leftLane.movementOption == 2) {
            
        }
        
        //movement option 3
        else {
            
        }
        
        //create action to make it slow down
        Action* resetSlowDown = new ResetDial (0, 0, "\" \"", leftVehName, "\"ForcedVelocity\" \" \"", "\"Ado/ForcedVelocity\"");
        Action* slowDown = new SetDial(0, 0, "\" \"", leftVehName, "\"ForcedVelocity\" \"25\"", "\"Ado/ForcedVelocity\"");
        
        //create roadpad trigger to hold slow down action
        vector<Action*> Act2;
        Act2.push_back(resetSlowDown);
        Act2.push_back(slowDown);
        position slowDraw = Draw;
        slowDraw.y = slowDraw.y + trialLengthFt;
        string slowPath = "\"R:r1_0_113520:0[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]:1[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]\"";
        roadPadTrigger slowDownTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"SlowLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", slowDraw, slowDraw, Act2, leftVehName, slowPath);
        slowDownTrigger.setTypeSet(false);
        slowDownTrigger.filePrint(outStream);
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
                    processLeftLane(trial.leftLane, outStream, trial.trialNumber);
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
                newTrigger->fileRead(inputStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM RoadPadTrigger") {
				Trigger* newTrigger = new roadPadTrigger;
                newTrigger->fileRead(inputStream);
				triggers.push_back(newTrigger);
			}
			else if (inputCase == "HCSM TimeTrigger") {
				Trigger* newTrigger = new timeTrigger;
                newTrigger->fileRead(inputStream);
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
		return;
	}
};

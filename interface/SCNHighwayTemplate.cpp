#include "SCNHighwayTemplate.h"

#define _USE_MATH_DEFINES

#include <math.h>

SCNHighwayTemplate::~SCNHighwayTemplate() {
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
SCNHighwayTemplate::SCNHighwayTemplate () {
    const int seed = 13;
    srand(seed);
    
    carSolModels.push_back("\"Audi\"");                 carSolModels.push_back("\"ChevyBlazer\"");
    carSolModels.push_back("\"Deville\"");              carSolModels.push_back("\"DodgeNeon\"");
    carSolModels.push_back("\"LandRover\"");            carSolModels.push_back("\"PEUGEOT_306\"");        
    carSolModels.push_back("\"Windstar\"");             carSolModels.push_back("\"Towncar\"");
    carSolModels.push_back("\"FordTaurus\"");           carSolModels.push_back("\"BMW_StationWagon\"");
    
    truckSolModels.push_back("\"Ford_F150Xcab\"");      truckSolModels.push_back("\"Freightliner_Semi\"");
    truckSolModels.push_back("\"DumpTruck\"");          truckSolModels.push_back("\"CokeTruck\"");
    truckSolModels.push_back("\"schoolbus\"");          truckSolModels.push_back("\"cargill_semi_freightliner_red\"");
    truckSolModels.push_back("\"CementTruck\"");        truckSolModels.push_back("\"semi_peterbilt_yel_Walmart\"");
    truckSolModels.push_back("\"GarbageTruck\"");       truckSolModels.push_back("\"semi_peterbilt_white_FordRacing\"");
}

void SCNHighwayTemplate::slowFollowVehicle (int trialNum, ostream &outStream, int speed, int trialPercentage) {
    //road pad trigger to reset follow vehicle speed
    double              resetFVPathStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetFVSpeedDraw (450, -1320 + resetFVPathStart, 0);
    vector <Action*>    resetFVSpeedActions;
    string              resetFVSpeedHelperPath = std::to_string(resetFVPathStart) + ":" + std::to_string(resetFVPathStart + 10);
    string              resetFVSpeedPath = "\"R:r1_0_113520:0[" + resetFVSpeedHelperPath + "]:1[" + resetFVSpeedHelperPath + "]\"";
    Action*             resetFVSpeed = new ResetDial (0, 0, "\"ResetFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetFVSpeedActions.push_back(resetFVSpeed);
    
    RoadPadTrigger      resetFVSpeedTrigger (false, true, 0, 0, 0, trialLengthFt, 0, "\"ResetFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetFVSpeedDraw, resetFVSpeedDraw, resetFVSpeedActions, "\"FV\"", resetFVSpeedPath);
    resetFVSpeedTrigger.setTypeSet(false);
    resetFVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to set the follow vehicle speed
    double              lengthRatio = trialPercentage/100;
    double              setFVPathStart = resetFVPathStart + 80;
    double              setFVPathEnd = setFVPathStart + (trialLengthFt + trialSetupLengthFt)*lengthRatio;
    position            setFVSpeedDraw (450, -1320 + setFVPathStart, 0);
    vector <Action*>    setFVSpeedActions;
    string              setFVSpeedHelperPath = std::to_string(setFVPathStart) + ":" + std::to_string(setFVPathEnd);
    string              setFVSpeedPath = "\"R:r1_0_113520:0[" + setFVSpeedHelperPath + "]:1[" + setFVSpeedHelperPath + "]\"";
    Action*             setFVSpeed = new SetDial (0, 0, "\"SetFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"" + std::to_string(speed) + "\"", "\"Ado/ForcedVelocity\"");
    
    setFVSpeedActions.push_back(setFVSpeed);
    
    RoadPadTrigger      setFVSpeedTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"SetFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", setFVSpeedDraw, setFVSpeedDraw, setFVSpeedActions, "\"FV\"", setFVSpeedPath);
    setFVSpeedTrigger.setTypeSet(false);
    setFVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the follow vehicle speed
    double              resetEndFVPathStart = setFVPathEnd + 40;
    double              resetEndFVPathEnd = resetEndFVPathStart + 40;
    position            resetEndFVDraw (450, -1320 + resetEndFVPathStart, 0);
    vector <Action*>    resetEndFVActions;
    string              resetEndFVHelperPath = std::to_string(resetEndFVPathStart) + ":" + std::to_string(resetEndFVPathEnd);
    string              resetEndFVPath = "\"R:r1_0_113520:0[" + resetEndFVHelperPath + "]:1[" + resetEndFVHelperPath + "]\"";
    Action*             resetEndFV = new ResetDial (0, 0, "\"ResetEndFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetEndFVActions.push_back(resetEndFV);
    
    RoadPadTrigger resetEndFVTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"ResetEndFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndFVDraw, resetEndFVDraw, resetEndFVActions, "\"FV\"", resetEndFVPath);
    resetEndFVTrigger.setTypeSet(false);
    resetEndFVTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::FVLVMatchET(int trialNum, ostream &outStream, int trialPercentage, string vehName) {
    //road pad trigger to reset follow/lead vehicle speed
    double              resetFVLVPathStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetFVLVSpeedDraw (450, -1320 + resetFVLVPathStart, 0);
    vector <Action*>    resetFVLVSpeedActions;
    string              resetFVLVSpeedHelperPath = std::to_string(resetFVLVPathStart) + ":" + std::to_string(resetFVLVPathStart + 10);
    string              resetFVLVSpeedPath = "\"R:r1_0_113520:0[" + resetFVLVSpeedHelperPath + "]:1[" + resetFVLVSpeedHelperPath + "]\"";
    Action*             resetFVLVSpeed = new ResetDial (0, 0, "\"ResetFVLVSpeed_" + std::to_string(trialNum) + "\"", vehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetFVLVSpeedActions.push_back(resetFVLVSpeed);
    
    RoadPadTrigger      resetFVLVSpeedTrigger (false, true, 0, 0, 0, trialLengthFt, 0, "\"ResetFVLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetFVLVSpeedDraw, resetFVLVSpeedDraw, resetFVLVSpeedActions, vehName, resetFVLVSpeedPath);
    resetFVLVSpeedTrigger.setTypeSet(false);
    resetFVLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to set the follow/lead vehicle speed
    double              lengthRatio = trialPercentage/100;
    double              setFVLVPathStart = resetFVLVPathStart + 80;
    double              setFVLVPathEnd = setFVLVPathStart + (trialLengthFt + trialSetupLengthFt)*lengthRatio;
    position            setFVLVSpeedDraw (450, -1320 + setFVLVPathStart, 0);
    vector <Action*>    setFVLVSpeedActions;
    string              setFVLVSpeedHelperPath = std::to_string(setFVLVPathStart) + ":" + std::to_string(setFVLVPathEnd);
    string              setFVLVSpeedPath = "\"R:r1_0_113520:0[" + setFVLVSpeedHelperPath + "]:1[" + setFVLVSpeedHelperPath + "]\"";
    Action*             setFVLVSpeed = new SetDial (0, 0, "\"SetFVLVSpeed_" + std::to_string(trialNum) + "\"", vehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
    
    setFVLVSpeedActions.push_back(setFVLVSpeed);
    
    RoadPadTrigger      setFVLVSpeedTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"SetFVLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", setFVLVSpeedDraw, setFVLVSpeedDraw, setFVLVSpeedActions, vehName, setFVLVSpeedPath);
    setFVLVSpeedTrigger.setTypeSet(false);
    setFVLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the follow/lead vehicle speed
    double              resetEndFVLVPathStart = setFVLVPathEnd + 40;
    double              resetEndFVLVPathEnd = resetEndFVLVPathStart + 40;
    position            resetEndFVLVDraw (450, -1320 + resetEndFVLVPathStart, 0);
    vector <Action*>    resetEndFVLVActions;
    string              resetEndFVLVHelperPath = std::to_string(resetEndFVLVPathStart) + ":" + std::to_string(resetEndFVLVPathEnd);
    string              resetEndFVLVPath = "\"R:r1_0_113520:0[" + resetEndFVLVHelperPath + "]:1[" + resetEndFVLVHelperPath + "]\"";
    Action*             resetEndFVLV = new ResetDial (0, 0, "\"ResetEndFVLVSpeed_" + std::to_string(trialNum) + "\"", vehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetEndFVLVActions.push_back(resetEndFVLV);
    
    RoadPadTrigger resetEndFVLVTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"ResetEndFVLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndFVLVDraw, resetEndFVLVDraw, resetEndFVLVActions, vehName, resetEndFVLVPath);
    resetEndFVLVTrigger.setTypeSet(false);
    resetEndFVLVTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::speedLeadVehicle (int trialNum, ostream &outStream, int speed, int trialPercentage) {
    //road pad trigger to reset lead vehicle speed
    double              resetLVPathStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetLVSpeedDraw (450, -1320 + resetLVPathStart, 0);
    vector <Action*>    resetLVSpeedActions;
    string              resetLVSpeedHelperPath = std::to_string(resetLVPathStart) + ":" + std::to_string(resetLVPathStart + 10);
    string              resetLVSpeedPath = "\"R:r1_0_113520:0[" + resetLVSpeedHelperPath + "]:1[" + resetLVSpeedHelperPath + "]\"";
    Action*             resetLVSpeed = new ResetDial (0, 0, "\"ResetLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetLVSpeedActions.push_back(resetLVSpeed);
    
    RoadPadTrigger      resetLVSpeedTrigger (false, true, 0, 0, 0, trialLengthFt, 0, "\"ResetLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetLVSpeedDraw, resetLVSpeedDraw, resetLVSpeedActions, "\"LV\"", resetLVSpeedPath);
    resetLVSpeedTrigger.setTypeSet(false);
    resetLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to set the lead vehicle speed
    double              lengthRatio = trialPercentage/100;
    double              setLVPathStart = resetLVPathStart + 80;
    double              setLVPathEnd = setLVPathStart + (trialLengthFt + trialSetupLengthFt)*lengthRatio;
    position            setLVSpeedDraw (450, -1320 + setLVPathStart, 0);
    vector <Action*>    setLVSpeedActions;
    string              setLVSpeedHelperPath = std::to_string(setLVPathStart) + ":" + std::to_string(setLVPathEnd);
    string              setLVSpeedPath = "\"R:r1_0_113520:0[" + setLVSpeedHelperPath + "]:1[" + setLVSpeedHelperPath + "]\"";
    Action*             setLVSpeed = new SetDial (0, 0, "\"SetLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"" + std::to_string(speed) + "\"", "\"Ado/ForcedVelocity\"");
    
    setLVSpeedActions.push_back(setLVSpeed);
    
    RoadPadTrigger      setLVSpeedTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"SetLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", setLVSpeedDraw, setLVSpeedDraw, setLVSpeedActions, "\"LV\"", setLVSpeedPath);
    setLVSpeedTrigger.setTypeSet(false);
    setLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the lead vehicle speed
    double              resetEndLVPathStart = setLVPathEnd + 40;
    double              resetEndLVPathEnd = resetEndLVPathStart + 40;
    position            resetEndLVDraw (450, -1320 + resetEndLVPathStart, 0);
    vector <Action*>    resetEndLVActions;
    string              resetEndLVHelperPath = std::to_string(resetEndLVPathStart) + ":" + std::to_string(resetEndLVPathEnd);
    string              resetEndLVPath = "\"R:r1_0_113520:0[" + resetEndLVHelperPath + "]:1[" + resetEndLVHelperPath + "]\"";
    Action*             resetEndLV = new ResetDial (0, 0, "\"ResetEndLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetEndLVActions.push_back(resetEndLV);
    
    RoadPadTrigger resetEndLVTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"ResetEndLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndLVDraw, resetEndLVDraw, resetEndLVActions, "\"LV\"", resetEndLVPath);
    resetEndLVTrigger.setTypeSet(false);
    resetEndLVTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::laneChange (int trialNum, ostream &outStream, string vehName, int direction) {
    //set the dial and path
    string              dial;
    string              endDial;
    string              buttonDialPath = "\"Ado/LaneChange\"";
    
    if (direction == 0) {
        dial = "\"LaneChange\" \"left;1;2\"";
        endDial = "\"LaneChange\" \"right;1;2\"";
    }
    else {
        dial = "\"LaneChange\" \"right;1;2\"";
        endDial = "\"LaneChange\" \"left;1;2\"";
    }
    
    //road pad trigger to reset follow/lead vehicle lane change dial
    double              resetLaneStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetLaneDraw (450, -1320 + resetLaneStart, 0);
    vector <Action*>    resetLaneActions;
    string              resetLaneHelperPath = std::to_string(resetLaneStart) + ":" + std::to_string(resetLaneStart + 10);
    string              resetLanePath = "\"R:r1_0_113520:0[" + resetLaneHelperPath + "]:1[" + resetLaneHelperPath + "]\"";
    Action*             resetLane = new ResetDial (0, 0, "\"ResetLaneChange_" + std::to_string(trialNum) + "\"", vehName, dial, buttonDialPath);
    Action*             setLane = new SetDial (0, 0, "\"SetLaneChange_" + std::to_string(trialNum) + "\"", vehName, dial, buttonDialPath);
    
    resetLaneActions.push_back(resetLane);
    resetLaneActions.push_back(setLane);
    
    RoadPadTrigger      resetLaneTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"LaneChange_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetLaneDraw, resetLaneDraw, resetLaneActions, vehName, resetLanePath);
    resetLaneTrigger.setTypeSet(false);
    resetLaneTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the lane change
    double              remainingTrialLength = trialLengthFt - 10;
    double              resetEndLanePathStart = resetLaneStart + remainingTrialLength;
    double              resetEndLanePathEnd = resetEndLanePathStart + 40;
    position            resetEndLaneDraw (450, -1320 + resetEndLanePathStart, 0);
    vector <Action*>    resetEndLaneActions;
    string              resetEndLaneHelperPath = std::to_string(resetEndLanePathStart) + ":" + std::to_string(resetEndLanePathEnd);
    string              resetEndLanePath = "\"R:r1_0_113520:0[" + resetEndLaneHelperPath + "]:1[" + resetEndLaneHelperPath + "]\"";
    Action*             resetEndLane = new ResetDial (0, 0, "\"EndLaneChange_" + std::to_string(trialNum) + "\"", vehName, endDial, buttonDialPath);
    
    resetEndLaneActions.push_back(resetEndLane);
    
    RoadPadTrigger resetEndLaneTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"EndLaneChange_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndLaneDraw, resetEndLaneDraw, resetEndLaneActions, vehName, resetEndLanePath);
    resetEndLaneTrigger.setTypeSet(false);
    resetEndLaneTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::leftLaneSlowDown (int trialNum, string leftVehName, ostream &outStream, vector<Action*> &slowDownActions) {
    //create action to make it slow down
    Action*     resetSlowDown = new ResetDial (0, 0, "\"LeftResetBeforeSlowDown_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \" \"", "\"Ado/ForcedVelocity\"");
    Action*     slowDown = new SetDial(0, 0, "\"LeftSlowDown_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"20\"", "\"Ado/ForcedVelocity\"");
    
    //create roadpad trigger to hold slow down action
    slowDownActions.push_back(resetSlowDown);
    slowDownActions.push_back(slowDown);
    
    position    slowDraw (450, (trialNum * (trialLengthFt + trialSetupLengthFt)) - 1320 + trialLengthFt, 0);
    string      slowPath = "\"R:r1_0_113520:0[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]:1[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]\"";
    
    RoadPadTrigger slowDownTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"SlowLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", slowDraw, slowDraw, slowDownActions, leftVehName, slowPath);
    slowDownTrigger.setTypeSet(false);
    slowDownTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::leftLaneBlindSpot (int trialNum, leftLaneControl &leftLane, ostream &outStream) {
    //create the vehicle
    string  RoadPos = "\"r1_0_113520:1:";    
    string  SolName = leftLane.solModel;
    string  leftVehName = "\"Left_" + std::to_string(trialNum) + "\"";
    int     matchETDistance = 60;               
    int     color = getRandSolColor(SolName);   
    double  initVeloc = 0;
    
    //if the creation position in front
    if (leftLane.creationOption == 1) {                
        //C is based on the trial number ((trial number * trial length + trial number * trialsetup) + creationDistance), D is 0 
        RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) + leftLane.creationDistance) + ":0\"";
        
        //velocity options
        initVeloc = 35;
        matchETDistance = 20;
    }
    //if the creation position is behind
    else {                
        //C is based on the trial number ((trial number * trial length + trial number * trialsetup) - creationDistance), D is 0 
        RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) - leftLane.creationDistance) + ":0\"";
        
        //velocity options
        initVeloc = 90;
    }
    
    ADO     left(color, 0, 0, 0, "\"Left_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 65, RoadPos, "-1");
    left.setCreation(true);
    
    //blinker control
    switch (leftLane.blinker) {
        case (Left) : {
            left.setVisualState(1);
            break;
        }
        case (Hazards) : {
            left.setVisualState(4);
            break;
        }
        case (Right) : {
            left.setVisualState(2);
            break;
        }
    }
    
    //generate the roadpad trigger that creates the ADO
    position Draw (450, (trialNum * (trialLengthFt + trialSetupLengthFt)) - 1320, 0);
    
    vector <Action*> creationActions;
    double beginYPos = (trialNum * (trialLengthFt + trialSetupLengthFt));
    
    //generate the creation action, add the vehicle
    Action* createADO = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
    
    Vehicle* leftPtr = new ADO (left);
    leftPtr->setInitialVel(initVeloc);  leftPtr->setVelocitySettings(0, initVeloc, 1.0051923E-240);
    createADO->addVehicle(leftPtr);
    
    creationActions.push_back(createADO);
    
    RoadPadTrigger roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, creationActions, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(beginYPos + 20) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(beginYPos + 20) + "]\"");
    roadTrigger.filePrint(outStream);
    
    //generate the action to reset the velocity and then match the Et velocity
    Action* setToMatch = new SetDial (0, 0, "\"LeftMatchSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
    
    //generate the expression trigger to match velocity
    Draw.x = Draw.x + 70;
    vector <Action*> blindActions;
    blindActions.push_back(setToMatch);
    ExpressionTrigger blindSpot (true, false, 0, 0, 0, trialLengthFt, 0, "\"LeftBlindSpot_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", Draw, Draw, blindActions, "\" GetObjDistPow2('Left_" + std::to_string(trialNum) + "') < " + std::to_string(matchETDistance) + " * " + std::to_string(matchETDistance) + "\"");
    blindSpot.filePrint(outStream);
    
    vector<Action*> slowDownActions;
    Action* deleteMatchET = new DeleteHCSM (0, 0, "\"LeftDeleteBlindTrigger_" + std::to_string(trialNum) + "\"", "\"LeftBlindSpot_" + std::to_string(trialNum) + "\"");
    slowDownActions.push_back(deleteMatchET);
    
    leftLaneSlowDown(trialNum, leftVehName, outStream, slowDownActions);
    
    return;
}

void SCNHighwayTemplate::leftLaneCutBehind (int trialNum, leftLaneControl &leftLane, ostream &outStream) {    
    string              SOLModel = leftLane.solModel;
    int                 ddoReferenceIndex = 4;
    int                 color = getRandSolColor(SOLModel);
    int                 visState = 0;
    double              trialBeginning = -1320 +  trialNum * (trialLengthFt + trialSetupLengthFt);
    double              laneChangeAngle = M_PI_2 - atan (12/250);
    double              laneChangeHypotenuse = sqrt(250 * 250 + 144);
    string              leftVehName = "\"Left_" + std::to_string(trialNum) + "\"";
    position            ddoReferencePosition (388, 0, 0);
    vector<double>      Dirs;
    vector<bool>        DirsDef;
    vector <trajectory> Trajs;
    trajectory          creationPoint (376, 0, 55, 0, 1);
    
    //slow down follow vehicle
    slowFollowVehicle(trialNum, outStream, 40);
    
    //ddo creation point and one traffic point
    if (leftLane.creationOption == 1) { //front        
        //set the creation trajectory
        creationPoint.y = trialBeginning + leftLane.creationDistance;
        Trajs.push_back(creationPoint);
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
    }
    else {
        //set the creation trajectory
        creationPoint.y = trialBeginning - leftLane.creationDistance;
        Trajs.push_back(creationPoint);
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
    }
    
    //generate only one straight line point
    trajectory trafficPoint1 (376, creationPoint.y + trialLengthFt/12, 55, 0, 1);
    Trajs.push_back(trafficPoint1);
    Dirs.push_back(M_PI_2);
    DirsDef.push_back(1);
    
    //ddo begin lane change points
    trajectory beginLaneChange (376, (Trajs.back()).y + 100, 55, cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(beginLaneChange);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    //ddo lane change right
    trajectory lanePoint1 (382, beginLaneChange.y + laneChangeHypotenuse/2, 55, cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint1);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    trajectory lanePoint2 (388, lanePoint1.y + laneChangeHypotenuse/2, 55, cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint2);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    //set the reference point
    ddoReferencePosition.y = lanePoint2.y + 35;
    
    //ddo rest of path
    double      remainingRoadway = trialBeginning + trialLengthFt - lanePoint2.y;
    double      remainingPathIncrementLength = remainingRoadway / 10;
    trajectory  remainingTraj (388, lanePoint2.y, 55, 0, 1);
    for (unsigned int i = 0; i < 10; ++i) {
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
        
        remainingTraj.y += remainingPathIncrementLength;
        Trajs.push_back(remainingTraj);
    }
    
    //ddo lane change left
    double      deletionLaneChangeAngle = atan(12/250) + M_PI_2;
    double      deletionLaneChangeHypotenuse = sqrt(144 + 62500);
    
    trajectory pullLeft1 (388, trialBeginning + trialLengthFt + 40, 55, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
    Trajs.push_back(pullLeft1);
    Dirs.push_back(deletionLaneChangeAngle);
    DirsDef.push_back(1);    
    
    trajectory pullLeft2 (382, pullLeft1.y + deletionLaneChangeHypotenuse * .5, 25, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
    Trajs.push_back(pullLeft2);
    Dirs.push_back(deletionLaneChangeAngle);
    DirsDef.push_back(1);
    
    trajectory pullLeft3 (376, pullLeft2.y + deletionLaneChangeHypotenuse * .5, 25, 0, 1);
    Trajs.push_back(pullLeft3);
    Dirs.push_back(M_PI_2);
    DirsDef.push_back(1);
    
    //set the visual state
    switch (leftLane.blinker) {
    case (Right) : { 
        visState = 2;
        break;
    }
    case (Left) : {
        visState = 1;
        break;   
    }
    case (Hazards) : {
        visState = 4;
        break;
    }
    }
    
    //create the ddo
    Vehicle* leftLaneVeh = new DDO (ddoReferenceIndex, color, 0, 0, leftLane.creationDistance, leftVehName, "\"\"", "\"\"", SOLModel, true, false, visState, ddoReferencePosition, Dirs, DirsDef, Trajs);
    
    //if creation point is behind the et
    if (leftLane.creationOption == 0) {        
        //use a trigger to create the ddo
        string              createLeftLanePath = "\"R:r1_0_113520:0[" + std::to_string(trialBeginning) + ":" + std::to_string(trialBeginning + 20) + "]:1[" + std::to_string(trialBeginning) + ":" + std::to_string(trialBeginning + 20) + "]\"";;
        position            createLeftLaneDraw (450, trialBeginning, 0);
        Action*             createLeftLaneAction = new CreateHCSM (0, 0, "\"LeftCreateVeh_" + std::to_string(trialNum) + "\"");
        vector <Action*>    createLeftLaneActions;
        
        leftLaneVeh->setCreation(true);
        createLeftLaneAction->addVehicle(leftLaneVeh);
        createLeftLaneActions.push_back(createLeftLaneAction);
        
        RoadPadTrigger  createLeftLane (true, true, 0, 0, 0, trialLengthFt, 0, "\"LeftCreateVehicle_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", createLeftLaneDraw, createLeftLaneDraw, createLeftLaneActions, "\"ExternalDriver\"", createLeftLanePath);
        createLeftLane.filePrint(outStream);
    }
    //else if the creation is behind
    else {
        //just have the creation radius be the creation distance
        leftLaneVeh->print(outStream);
        
        delete leftLaneVeh; leftLaneVeh = 0;
    }
    return;
}

void SCNHighwayTemplate::leftLaneCutFront (int trialNum, leftLaneControl &leftLane, ostream &outStream) {
    double                  trialBeginning = -1320 +  trialNum * (trialLengthFt + trialSetupLengthFt);
    double                  laneChangeAngle = M_PI_2 - atan (12/leftLane.distance);
    double                  laneChangeHypotenuse = sqrt(leftLane.distance * leftLane.distance + 144);
    position                ddoReferencePoint (388, 0,  0);
    string                  SOLModel = leftLane.solModel;
    string                  leftVehName = "\"Left_" + std::to_string(trialNum) + "\"";
    int                     color = getRandSolColor(SOLModel);
    int                     visState = 0;
    int                     referencePointID = 3;
    vector <bool>           DirsDef;
    vector <double>         Dirs;
    vector <trajectory>     Trajs;
    
    //speed up the lead vehicle
    speedLeadVehicle(trialNum, outStream, 85);    
    
    //ddo creation point and a traffic point
    trajectory creationPoint (376, 0, leftLane.speed * .5, 0, 1);
    
    if (leftLane.creationOption == 1) { //front
        //generate the creation point
        creationPoint.y = trialBeginning + leftLane.creationDistance;
        Trajs.push_back(creationPoint);
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);      
        
        //set the reference point
        ddoReferencePoint.y = trialBeginning + leftLane.creationDistance + trialLengthFt/12 + 100;
    }
    else {
        //generate the creation point
        creationPoint.y = trialBeginning - leftLane.creationDistance;
        Trajs.push_back(creationPoint);
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
        
        //set the reference point
        ddoReferencePoint.y = trialBeginning + trialLengthFt/12 - leftLane.creationDistance + 100;   
    }
    
    //generate only one straight line point
    trajectory trafficPoint1 (376, creationPoint.y + trialLengthFt/12, leftLane.speed * .5, 0, 1);
    Trajs.push_back(trafficPoint1);
    Dirs.push_back(M_PI_2);
    DirsDef.push_back(1);
    
    //ddo begin lane change points
    trajectory beginLaneChange (376, (Trajs.back()).y + 100, leftLane.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(beginLaneChange);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    //ddo lane change right
    trajectory lanePoint1 (382, beginLaneChange.y + laneChangeHypotenuse/2, leftLane.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint1);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    trajectory lanePoint2 (388, lanePoint1.y + laneChangeHypotenuse/2, leftLane.speed * (.75), cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint2);
    Dirs.push_back(laneChangeAngle);
    DirsDef.push_back(1);
    
    //ddo rest of path
    double      remainingRoadway = trialBeginning + trialLengthFt - lanePoint2.y;
    double      remainingPathIncrementLength = remainingRoadway / 10;
    trajectory  remainingTraj (388, lanePoint2.y, leftLane.speed * (.85), 0, 1);
    for (unsigned int i = 0; i < 10; ++i) {
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
        
        remainingTraj.y += remainingPathIncrementLength;
        Trajs.push_back(remainingTraj);
        
        remainingTraj.speed = leftLane.speed;
    }
    
    //ddo lane change left
    double      deletionLaneChangeAngle = atan(12/250) + M_PI_2;
    double      deletionLaneChangeHypotenuse = sqrt(144 + 62500);
    
    trajectory pullLeft1 (388, trialBeginning + trialLengthFt + 40, leftLane.speed, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
    Trajs.push_back(pullLeft1);
    Dirs.push_back(deletionLaneChangeAngle);
    DirsDef.push_back(1);    
    
    trajectory pullLeft2 (382, pullLeft1.y + deletionLaneChangeHypotenuse * .5, 25, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
    Trajs.push_back(pullLeft2);
    Dirs.push_back(deletionLaneChangeAngle);
    DirsDef.push_back(1);
    
    trajectory pullLeft3 (376, pullLeft2.y + deletionLaneChangeHypotenuse * .5, 25, 0, 1);
    Trajs.push_back(pullLeft3);
    Dirs.push_back(M_PI_2);
    DirsDef.push_back(1);
    
    //set the visual state
    switch (leftLane.blinker) {
    case (Right) : { 
        visState = 2;
        break;
    }
    case (Left) : {
        visState = 1;
        break;   
    }
    case (Hazards) : {
        visState = 4;
        break;
    }
    }
    
    //create the ddo
    Vehicle* leftLaneVeh = new DDO (referencePointID, color, 0, 0, leftLane.creationDistance, leftVehName, "\"\"", "\"\"", SOLModel, true, false, visState, ddoReferencePoint, Dirs, DirsDef, Trajs);
    
    //if creation point is behind the et
    if (leftLane.creationOption == 0) {        
        //use a trigger to create the ddo
        string              createLeftLanePath = "\"R:r1_0_113520:0[" + std::to_string(trialBeginning) + ":" + std::to_string(trialBeginning + 20) + "]:1[" + std::to_string(trialBeginning) + ":" + std::to_string(trialBeginning + 20) + "]\"";;
        position            createLeftLaneDraw (450, trialBeginning, 0);
        Action*             createLeftLaneAction = new CreateHCSM (0, 0, "\"LeftCreateVeh_" + std::to_string(trialNum) + "\"");
        vector <Action*>    createLeftLaneActions;
        
        leftLaneVeh->setCreation(true);
        createLeftLaneAction->addVehicle(leftLaneVeh);
        createLeftLaneActions.push_back(createLeftLaneAction);
        
        RoadPadTrigger  createLeftLane (true, true, 0, 0, 0, trialLengthFt, 0, "\"LeftCreateVehicle_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", createLeftLaneDraw, createLeftLaneDraw, createLeftLaneActions, "\"ExternalDriver\"", createLeftLanePath);
        createLeftLane.filePrint(outStream);
    }
    //else if the creation is behind
    else {
        //just have the creation radius be the creation distance
        leftLaneVeh->print(outStream);
        
        delete leftLaneVeh; leftLaneVeh = 0;
    }
    return;
}

void SCNHighwayTemplate::leftLaneRemainLane (int trialNum, leftLaneControl &leftLane, ostream &outStream) {
    //create the vehicle
    string                  RoadPos = "\"r1_0_113520:1:";    
    string                  leftVehName = "\"Left_" + std::to_string(trialNum) + "\"";
    string                  SolName = leftLane.solModel;     
    position                Draw (450, (trialNum * (trialLengthFt + trialSetupLengthFt)) - 1320, 0);
    double                  initVeloc = 0;                   
    double                  beginYPos = (trialNum * (trialLengthFt + trialSetupLengthFt));
    double                  endYpos = beginYPos + 20;        
    int                     color = getRandSolColor(SolName);
    vector <Action*>        creationActions;       
    vector<Action*>         endTrialActions;
    
    //if the creation position in front
    if (leftLane.creationOption == 1) {
        //C is based on the trial number ((trial number * trial length + trial number * trialsetup) + creationDistance), D is 0 
        RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) + leftLane.creationDistance) + ":0\"";
    }
    //if the creation position is behind
    else {        
        //C is based on the trial number ((trial number * trial length + trial number * trialsetup) - creationDistance), D is 0 
        RoadPos = RoadPos + std::to_string(((trialLengthFt + trialSetupLengthFt)*trialNum) - leftLane.creationDistance) + ":0\"";           
    }
    
    ADO left(color, 0, 0, 0, "\"Left_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 65, RoadPos, "-1");
    left.setCreation(true);
    
    //blinker control
    switch (leftLane.blinker) {
        case (Left) : {
            left.setVisualState(1);
            break;
        }
        case (Hazards) : {
            left.setVisualState(4);
            break;
        }
        case (Right) : {
            left.setVisualState(2);
            break;
        }
    }
    
    //if it is match the et
    if (leftLane.laneOption == 1) {
        //intial velocity is 60 and fixed
        Action*             act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
        Vehicle*            leftPtr = new ADO (left);
        initVeloc = 60;
        leftPtr->setInitialVel(initVeloc);
        leftPtr->setVelocitySettings(0, 60, 1.0051923E-240);
        act->addVehicle(leftPtr);
        creationActions.push_back(act);
        
        //create the expression trigger to match the et
        vector <Action*>    matchETActions;
        Action*             setLeftVelocity = new SetDial (0, 0, "\"LeftMatchET_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
        position            matchETPosition = Draw;
        matchETActions.push_back(setLeftVelocity);
        
        matchETPosition.x += 140;
        
        ExpressionTrigger   matchETTrigger (true, false, 0, 0, 0, trialLengthFt, 0, "\"LeftMatchET_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", matchETPosition, matchETPosition, matchETActions, "\"1=1\"");  
        Trigger*            matchETTriggerPtr = new ExpressionTrigger(matchETTrigger);
        
        //create the action to create the expression trigger match et and also one to reset the velocity of the left vehicle
        Action*             resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
        creationActions.push_back (resetSpeed);
        Action*             createMatchEt = new CreateHCSM (0, 0, "\"LeftCreateMatchETTrigger_" + std::to_string(trialNum) + "\"");
        createMatchEt->addTrigger(matchETTriggerPtr);
        
        //write the create vehicle trigger
        position            createMatchETPos = Draw;
        createMatchETPos.x += 70;
        vector<Action*>     createMatchActions;
        createMatchActions.push_back(createMatchEt);
        RoadPadTrigger      createMatchRoadTrigger (true, true, 5, 0, 0, trialLengthFt, 0, "\"LeftCreateMatchET_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", createMatchETPos, createMatchETPos, createMatchActions,"\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
        createMatchRoadTrigger.filePrint(outStream);
        
        RoadPadTrigger      roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, creationActions, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
        roadTrigger.filePrint(outStream);           
        
        //create action to delete match et trigger
        Action*             deleteMatchEt = new DeleteHCSM (0, 0, "\"LeftDeleteMatchET_" + std::to_string(trialNum) + "\"", "\"LeftMatchET_" + std::to_string(trialNum) + "\"");
        endTrialActions.push_back(deleteMatchEt);
    }
    //else it is an absolute value
    else {
        //initial velocity is the absolute value and fixed
        initVeloc = leftLane.speed;
        Action*             act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
        Vehicle*            leftPtr = new ADO (left);
        initVeloc = leftLane.speed;
        leftPtr->setInitialVel(initVeloc);
        leftPtr->setVelocitySettings(0, leftLane.speed, 1.0051923E-240);
        act->addVehicle(leftPtr);
        creationActions.push_back(act);
        
        //write the create vehicle trigger
        RoadPadTrigger      roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, creationActions, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
        roadTrigger.filePrint(outStream);  
    }
    
    leftLaneSlowDown(trialNum, leftVehName, outStream, endTrialActions);
    return;
}

void SCNHighwayTemplate::slowFollowVehicle(int trialNum, ostream &outStream, int speed) {
    //road pad trigger to reset follow vehicle speed
    double              resetFVPathStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetFVSpeedDraw (450, -1320 + resetFVPathStart, 0);
    vector <Action*>    resetFVSpeedActions;
    string              resetFVSpeedHelperPath = std::to_string(resetFVPathStart) + ":" + std::to_string(resetFVPathStart + 10);
    string              resetFVSpeedPath = "\"R:r1_0_113520:0[" + resetFVSpeedHelperPath + "]:1[" + resetFVSpeedHelperPath + "]\"";
    Action              *resetFVSpeed = new ResetDial (0, 0, "\"ResetFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetFVSpeedActions.push_back(resetFVSpeed);
    
    RoadPadTrigger      resetFVSpeedTrigger (false, true, 0, 0, 0, trialLengthFt, 0, "\"ResetFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetFVSpeedDraw, resetFVSpeedDraw, resetFVSpeedActions, "\"FV\"", resetFVSpeedPath);
    resetFVSpeedTrigger.setTypeSet(false);
    resetFVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to set the lead vehicle speed
    double              setFVPathStart = resetFVPathStart + 80;
    double              setFVPathEnd = setFVPathStart + (trialLengthFt + trialSetupLengthFt)/2;
    position            setFVSpeedDraw (450, -1320 + setFVPathStart, 0);
    vector <Action*>    setFVSpeedActions;
    string              setFVSpeedHelperPath = std::to_string(setFVPathStart) + ":" + std::to_string(setFVPathEnd);
    string              setFVSpeedPath = "\"R:r1_0_113520:0[" + setFVSpeedHelperPath + "]:1[" + setFVSpeedHelperPath + "]\"";
    Action*             setFVSpeed = new SetDial (0, 0, "\"SetFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"" + std::to_string(speed) + "\"", "\"Ado/ForcedVelocity\"");
    
    setFVSpeedActions.push_back(setFVSpeed);
    
    RoadPadTrigger      setFVSpeedTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"SetFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", setFVSpeedDraw, setFVSpeedDraw, setFVSpeedActions, "\"FV\"", setFVSpeedPath);
    setFVSpeedTrigger.setTypeSet(false);
    setFVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the lead vehicle speed
    double              resetEndFVPathStart = setFVPathEnd + 40;
    double              resetEndFVPathEnd = resetEndFVPathStart + 40;
    position            resetEndFVDraw (450, -1320 + resetEndFVPathStart, 0);
    vector <Action*>    resetEndFVActions;
    string              resetEndFVHelperPath = std::to_string(resetEndFVPathStart) + ":" + std::to_string(resetEndFVPathEnd);
    string              resetEndFVPath = "\"R:r1_0_113520:0[" + resetEndFVHelperPath + "]:1[" + resetEndFVHelperPath + "]\"";
    Action*             resetEndFV = new ResetDial (0, 0, "\"ResetEndFVSpeed_" + std::to_string(trialNum) + "\"", "\"FV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetEndFVActions.push_back(resetEndFV);
    
    RoadPadTrigger resetEndFVTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"ResetEndFVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndFVDraw, resetEndFVDraw, resetEndFVActions, "\"FV\"", resetEndFVPath);
    resetEndFVTrigger.setTypeSet(false);
    resetEndFVTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::speedLeadVehicle (int trialNum, ostream &outStream, int speed){
    //road pad trigger to reset lead vehicle speed
    double              resetLVPathStart = (trialNum * (trialLengthFt + trialSetupLengthFt)) - trialSetupLengthFt;
    position            resetLVSpeedDraw (450, -1320 + resetLVPathStart, 0);
    vector <Action*>    resetLVSpeedActions;
    string              resetLVSpeedHelperPath = std::to_string(resetLVPathStart) + ":" + std::to_string(resetLVPathStart + 10);
    string              resetLVSpeedPath = "\"R:r1_0_113520:0[" + resetLVSpeedHelperPath + "]:1[" + resetLVSpeedHelperPath + "]\"";
    Action              *resetLVSpeed = new ResetDial (0, 0, "\"ResetLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetLVSpeedActions.push_back(resetLVSpeed);
    
    RoadPadTrigger      resetLVSpeedTrigger (false, true, 0, 0, 0, trialLengthFt, 0, "\"ResetLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetLVSpeedDraw, resetLVSpeedDraw, resetLVSpeedActions, "\"LV\"", resetLVSpeedPath);
    resetLVSpeedTrigger.setTypeSet(false);
    resetLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to set the lead vehicle speed
    double              setLVPathStart = resetLVPathStart + 80;
    double              setLVPathEnd = setLVPathStart + (trialLengthFt + trialSetupLengthFt)/2;
    position            setLVSpeedDraw (450, -1320 + setLVPathStart, 0);
    vector <Action*>    setLVSpeedActions;
    string              setLVSpeedHelperPath = std::to_string(setLVPathStart) + ":" + std::to_string(setLVPathEnd);
    string              setLVSpeedPath = "\"R:r1_0_113520:0[" + setLVSpeedHelperPath + "]:1[" + setLVSpeedHelperPath + "]\"";
    Action*             setLVSpeed = new SetDial (0, 0, "\"SetLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"" + std::to_string(speed) + "\"", "\"Ado/ForcedVelocity\"");
    
    setLVSpeedActions.push_back(setLVSpeed);
    
    RoadPadTrigger      setLVSpeedTrigger (false, false, 0, 0, 0, trialLengthFt, 0, "\"SetLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", setLVSpeedDraw, setLVSpeedDraw, setLVSpeedActions, "\"LV\"", setLVSpeedPath);
    setLVSpeedTrigger.setTypeSet(false);
    setLVSpeedTrigger.filePrint(outStream);
    
    //roadpad trigger to reset the lead vehicle speed
    double              resetEndLVPathStart = setLVPathEnd + 40;
    double              resetEndLVPathEnd = resetEndLVPathStart + 40;
    position            resetEndLVDraw (450, -1320 + resetEndLVPathStart, 0);
    vector <Action*>    resetEndLVActions;
    string              resetEndLVHelperPath = std::to_string(resetEndLVPathStart) + ":" + std::to_string(resetEndLVPathEnd);
    string              resetEndLVPath = "\"R:r1_0_113520:0[" + resetEndLVHelperPath + "]:1[" + resetEndLVHelperPath + "]\"";
    Action*             resetEndLV = new ResetDial (0, 0, "\"ResetEndLVSpeed_" + std::to_string(trialNum) + "\"", "\"LV\"", "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
    
    resetEndLVActions.push_back(resetEndLV);
    
    RoadPadTrigger resetEndLVTrigger (false,  true, 0, 0, 0, trialLengthFt, 0, "\"ResetEndLVSpeed_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", resetEndLVDraw, resetEndLVDraw, resetEndLVActions, "\"LV\"", resetEndLVPath);
    resetEndLVTrigger.setTypeSet(false);
    resetEndLVTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::processLeadVehicle (FVLVInstructions &leadVehicle, ostream &outStream, int trialNum) {
    //if the velocity change is checked
    if (leadVehicle.velocityChange) {
        //if it is match the et
        if (leadVehicle.velocityChangeOption == 0) {
            //call the correct function
            FVLVMatchET(trialNum, outStream, 100, "\"LV\"");
        }
        //otherwise
        else { 
            //call the correct function with the absolute speed
            speedLeadVehicle (trialNum, outStream, leadVehicle.absoluteSpeed, 100);
        }
    }
    //if the force lane change option is checked
    if (leadVehicle.forceLaneChange) {
        laneChange (trialNum, outStream, "\"LV\"", leadVehicle.laneChangeOption);
    }
    return;
}

void SCNHighwayTemplate::processFollowVehicle (FVLVInstructions &followVehicle, ostream &outStream, int trialNum) {
    //if the velocity change is checked
    if (followVehicle.velocityChange) {
        //if it is match the et
        if (followVehicle.velocityChangeOption == 0) {
            //call the correct function
            FVLVMatchET(trialNum, outStream, 100, "\"FV\"");
        }
        //otherwise
        else {
            //call the correct function with the absolute speed
            slowFollowVehicle(trialNum, outStream, followVehicle.absoluteSpeed, 100);
        }
    }
    //if the force lane change option is checked
    if (followVehicle.forceLaneChange) {
        laneChange (trialNum, outStream, "\"FV\"", followVehicle.laneChangeOption);
    }
    return;
}

void SCNHighwayTemplate::roadSidePullFrontStop (int trialNum, roadSideControl &roadSide, ostream &outStream) {
    speedLeadVehicle(trialNum, outStream, 90);
    
    string                  SOLModel = getRandSol(false);
    int                     color = getRandSolColor(SOLModel);
    string                  rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
    position                fake;
    int                     visState = 0; //visual state
    double                  laneChangeAngle = atan(12/roadSide.distance) + M_PI_2;
    double                  laneChangeHypotenuse = sqrt(roadSide.distance * roadSide.distance + 144);
    vector<double>          Dirs;       Dirs.push_back(laneChangeAngle);   //dirs
    vector<bool>            DirsDef;    DirsDef.push_back(1); //dirsdef
    vector <trajectory>     Trajs;  //trajectories
    trajectory              creationTrajectory(400, (-1320) + trialNum * (trialLengthFt + trialSetupLengthFt), roadSide.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle)); //creation point
    Trajs.push_back(creationTrajectory);
    
    //lane change points
    Dirs.push_back(laneChangeAngle);//point 1
    DirsDef.push_back(1);
    trajectory              lanePoint1 (394, creationTrajectory.y + laneChangeHypotenuse/2, roadSide.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint1);
            
    Dirs.push_back(laneChangeAngle);//point 2
    DirsDef.push_back(1);
    trajectory              lanePoint2 (388, lanePoint1.y + laneChangeHypotenuse/2, 0, cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint2);
    
    //reference point
    fake.x = 388;
    fake.y = -1320 + trialNum * (trialLengthFt + trialSetupLengthFt);
    
    switch (roadSide.blinker) {
        case (Left) : {
            visState = 1;
            break;
        }
        case (Right) : {
            visState = 2;
            break;
        }
        case (Hazards) : {
            visState = 4;
        break;
        }
    }
    
    //write the vehicle
    DDO pullFront (1, color, 0, 0, trialLengthFt, rightVehName, "\"\"", "\"\"", SOLModel, true, false, visState, fake, Dirs, DirsDef, Trajs);
    pullFront.print(outStream);
}

void SCNHighwayTemplate::roadSideDriveShoulder (int trialNum, roadSideControl &roadSide, ostream &outStream) {
    string              SOLModel = getRandSol(false);
    int                 color = getRandSolColor(SOLModel);
    string              rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
    position            fake;
    
    //create the ddo
    vector <double>     Dirs;
    Dirs.push_back(1.57);

    vector <bool>       DirsDef;
    DirsDef.push_back(false);
    
    vector <trajectory> Trajs;
    trajectory          tempTraj (400, -1320 + trialNum * (trialLengthFt + trialSetupLengthFt), roadSide.speed, 0, 1);
    Trajs.push_back(tempTraj);
    for (int i = 1; i < 10; ++i) {
        DirsDef.push_back(true);
        Dirs.push_back(1.57);
        tempTraj.y = tempTraj.y + trialLengthFt/10;
        Trajs.push_back(tempTraj);
    }

    tempTraj.y = tempTraj.y + trialLengthFt/10;
    tempTraj.speed = 25;
    Trajs.push_back(tempTraj);
    DirsDef.push_back(true);
    Dirs.push_back(1.57);

    int visState = 0;
    switch (roadSide.blinker) {
        case (Right) : {
            visState = 2;
            break;
        }
        case (Left) : {
            visState = 1;
            break;
        }
        case (Hazards) : {
            visState = 4;
            break;
        }
    }

    DDO driveShoulderDDO (color, 0, 5, trialLengthFt, rightVehName, "\"\"", "\"\"", SOLModel, false, true, visState, fake, Dirs, DirsDef, Trajs);
    driveShoulderDDO.print(outStream);
}

void SCNHighwayTemplate::roadSideStationary (int trialNum, roadSideControl &roadSide, ostream &outStream) {
    //create the ddo
    string              SOLModel = getRandSol(false);
    int                 color = getRandSolColor(SOLModel);
    int                 visState = 0;
    string              rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
    position            fake;
    
    vector<double>      Dirs;       Dirs.push_back(1.5707963);
    

    vector<bool>        DirsDef;    DirsDef.push_back(0);
    

    vector <trajectory> Trajs;
    trajectory          stationaryTrajectory (400, (-1320) + trialNum * (trialLengthFt + trialSetupLengthFt), 1, 0, 0);
    Trajs.push_back(stationaryTrajectory);

    switch (roadSide.blinker) {
        case (Left) : {
            visState = 1;
            break;
        }
        case (Right) : {
            visState = 2;
            break;
        }
        case (Hazards) : {
            visState = 4;
        break;
        }
    }

    DDO stationaryDDO (color, 0, 0, trialLengthFt, rightVehName, "\" \"", "\" \"", SOLModel, false, true, visState, fake, Dirs, DirsDef, Trajs);
    stationaryDDO.print(outStream);
}

void SCNHighwayTemplate::roadSidePullFront (int trialNum, roadSideControl &roadSide, ostream &outStream){
    speedLeadVehicle(trialNum, outStream, 90);
    
    string              SOLModel = getRandSol(false);
    int                 color = getRandSolColor(SOLModel);
    int                 visState = 0; //visual state
    string              rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
    position            fake;
    double              laneChangeAngle = atan(12/roadSide.distance) + M_PI_2;
    double              laneChangeHypotenuse = sqrt(roadSide.distance * roadSide.distance + 144);
    vector<double>      Dirs;       Dirs.push_back(laneChangeAngle); //dirs
    vector<bool>        DirsDef;    DirsDef.push_back(1); //dirsdef
    vector <trajectory> Trajs; //trajectories
    trajectory          creationTrajectory(400, (-1320) + trialNum * (trialLengthFt + trialSetupLengthFt), roadSide.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle)); //creation point
    Trajs.push_back(creationTrajectory);
    
    //lane change points
    Dirs.push_back(laneChangeAngle);//point 1
    DirsDef.push_back(1);
    trajectory          lanePoint1 (394, creationTrajectory.y + laneChangeHypotenuse/2, roadSide.speed * (.5), cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint1);
            
    Dirs.push_back(laneChangeAngle);//point 2
    DirsDef.push_back(1);
    trajectory          lanePoint2 (388, lanePoint1.y + laneChangeHypotenuse/2, roadSide.speed * 0.75, cos(laneChangeAngle), sin(laneChangeAngle));
    Trajs.push_back(lanePoint2);
    
    //rest of the path
    double              remainingPath =  (-1320 + trialNum * (trialLengthFt + trialSetupLengthFt) + trialLengthFt) - lanePoint2.y;
    double              remainingPathIncrementLength = remainingPath / 10;
    trajectory          remain (388, lanePoint2.y, roadSide.speed * 0.85, 0, 1);
    for (int i = 0; i < 10; i++) {
        Dirs.push_back(M_PI_2);
        DirsDef.push_back(1);
        
        remain.y += remainingPathIncrementLength;
        Trajs.push_back(remain);
        
        remain.speed = roadSide.speed;
    }
    
    //deletion option: pull to the right
    double              deletionLaneChangeAngle = atan(12/250);
    double              deletionLaneChangeHypotenuse = sqrt(144 + 62500);
    if (roadSide.deletionOption == 0) {
        deletionLaneChangeAngle = M_PI_2 - deletionLaneChangeAngle;
        Dirs.push_back(deletionLaneChangeAngle);
        DirsDef.push_back(1);
        trajectory      pullRight1 (388, (-1320 + trialNum * (trialLengthFt + trialSetupLengthFt) + trialLengthFt) + 40, roadSide.speed, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
        Trajs.push_back(pullRight1);
        
        Dirs.push_back(deletionLaneChangeAngle);
        DirsDef.push_back(1);
        trajectory      pullRight2 (394, pullRight1.y + deletionLaneChangeHypotenuse/2, roadSide.speed, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
        Trajs.push_back(pullRight2);
        
        Dirs.push_back(1.57);
        DirsDef.push_back(1);
        trajectory      pullRight3 (400, pullRight2.y + deletionLaneChangeHypotenuse/2, 25, 0, 1);
        Trajs.push_back(pullRight3);
    }
    
    //deletion option: pull to the left
    else {
        deletionLaneChangeAngle += M_PI_2;
        Dirs.push_back(deletionLaneChangeAngle);
        DirsDef.push_back(1);
        trajectory      pullLeft1 (388, (-1320 + trialNum * (trialLengthFt + trialSetupLengthFt) + trialLengthFt) + 40, roadSide.speed, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
        Trajs.push_back(pullLeft1);
        
        Dirs.push_back(deletionLaneChangeAngle);
        DirsDef.push_back(1);
        trajectory      pullLeft2 (382, pullLeft1.y + deletionLaneChangeHypotenuse/2, 25, cos(deletionLaneChangeAngle), sin(deletionLaneChangeAngle));
        Trajs.push_back(pullLeft2);
        
        Dirs.push_back(1.57);
        DirsDef.push_back(1);
        trajectory      pullLeft3 (376, pullLeft2.y + deletionLaneChangeHypotenuse/2, 25, 0, 1);
        Trajs.push_back(pullLeft3);
    }
    
    //reference point
    fake.x = 388;
    fake.y = -1320 + trialNum * (trialLengthFt + trialSetupLengthFt);
    
    switch (roadSide.blinker) {
        case (Left) : {
            visState = 1;
            break;
        }
        case (Right) : {
            visState = 2;
            break;
        }
        case (Hazards) : {
            visState = 4;
        break;
        }
    }
    
    //write the vehicle
    DDO pullFront (1, color, 0, 0, trialLengthFt, rightVehName, "\"\"", "\"\"", SOLModel, true, false, visState, fake, Dirs, DirsDef, Trajs);
    pullFront.print(outStream);
    return;
}

void SCNHighwayTemplate::processRoadSide(roadSideControl &roadSide, ostream &outStream, int trialNum) {
    if (roadSide.movementOption == 0) {
        roadSideStationary(trialNum, roadSide, outStream);
    }
    else if (roadSide.movementOption == 1) {
        roadSidePullFront(trialNum, roadSide, outStream);
    }
    else if (roadSide.movementOption == 2) {
        roadSideDriveShoulder(trialNum, roadSide, outStream);
    }
    else {
        roadSidePullFrontStop(trialNum, roadSide, outStream);
    }
    return;
}

void SCNHighwayTemplate::generateFollowVehicle (FVLVSettings &followVehicle, ostream &outStream) {
    //create the vehicle
    int                 color = getRandSolColor(followVehicle.SOLModel);
    string              SolName = followVehicle.SOLModel; 
    
    ADO                 follow(color, 0, 0, 0, "\"FV\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 0, "\"r1_0_113520:0:30.99:0.80\"", "-1");
    follow.setCreation(false);
    
    //create the set dial action for the maintain gap
    string              Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(followVehicle.distance) + ";" + std::to_string(followVehicle.maxSpeed) + ";" + std::to_string(followVehicle.minSpeed) + ";4;4;" + std::to_string(followVehicle.maxAccel) + ";" + std::to_string(followVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
    Action*             keep = new SetDial (0, 0, "\"FV_Keep_Distance\"", "\"FV\"", Dial, "\"Ado/MaintainGap\"");
    
    //create the gap maintain trigger
    position            Draw;
    position            Pos;
    Draw.x = 52; Draw.y = -1480; Draw.z = 0;
    Pos.x = 52; Pos.y = -1480; Pos.z = 0;
    vector <Action*>    Act;
    Act.push_back(keep);      
    
    ExpressionTrigger   maintain(false, false, 0, 0, 0, 0, 0, "\"FV_Keep_Distance\"", "\"\"", "\"\"", Draw, Pos, Act, "\"1=1\"");
    
    //print the vehicle and the trigger
    follow.print(outStream);
    maintain.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateLeadVehicle (FVLVSettings &leadVehicle, ostream &outStream) {
    //create the vehicle
    int                 color = getRandSolColor(leadVehicle.SOLModel);
    string              SolName = leadVehicle.SOLModel;
    
    ADO                 lead(color, 0, 0, 0, "\"LV\"", "\"\"", "\"\"", SolName, false, false, 1, 0.78, 9, 54.6, 0, "\"r1_0_113520:0:266.44:0.78\"", "-1");
    lead.setCreation(false);
    
    //create the maintain gap action
    string              Dial = "\"MaintainGap\" \"ExternalDriver;d " + std::to_string(leadVehicle.distance) + ";" + std::to_string(leadVehicle.maxSpeed) + ";" + std::to_string(leadVehicle.minSpeed) + ";4;4;" + std::to_string(leadVehicle.maxAccel) + ";" + std::to_string(leadVehicle.maxDeccel) + ";-1;-1;-1;-1\"";
    Action*             keep = new SetDial (0, 0, "\"LV_Keep_Distance\"", "\"LV\"", Dial, "\"Ado/MaintainGap\"");
    
    //create the gap maintain trigger
    position            Draw;
    Draw.x = 62; Draw.y = -1480; Draw.z = 0;
    vector <Action*>    Act;
    Act.push_back(keep);        
    ExpressionTrigger   maintain (false, false, 0, 0, 0, 0, 0, "\"LV_Keep_Distance\"", "\"\"", "\"\"", Draw, Draw, Act, "\"1=1\"");
            
    //print the vehicle and the trigger
    lead.print(outStream);
    maintain.filePrint(outStream);
    return;
}

double SCNHighwayTemplate::randDouble (double min, double max) {
    std::uniform_real_distribution<double> unif(min, max);
    double  rand = unif(re);
    return  rand;
}

string SCNHighwayTemplate::getRandSol (bool isTruck) {
    if (isTruck) {
        return truckSolModels[rand() % truckSolModels.size()];
    }
    return carSolModels[rand() % carSolModels.size()];
}

//returns true if it is truck or false if it is to be a car
bool SCNHighwayTemplate::truckOrCar (int carsLeft, int trucksLeft) {
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

int SCNHighwayTemplate::getRandSolColor (string sol) {
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

void SCNHighwayTemplate::generateTraffic (int numberTrials, int numberCarsPerTrial, int numberOfCars, int numberOfTrucks, ostream &outStream) {
    //define parameters for road pos left, right, start of trial 1, trial length, in between length of trials
    double  currentY = numberTrials*trialLengthFt + numberTrials*trialSetupLengthFt;
    double  increationLength = (trialLengthFt + trialSetupLengthFt)/numberCarsPerTrial;
    double  lowerRange = currentY - increationLength;
    double  yPos;
    
    string  SolName;     
    string  name;
    string  RoadPos;
    
    int     color;                      
    int     laneOffset = 1;
    int     carsLeft = numberOfCars;    int trucksLeft = numberOfTrucks;
    int     lanePos;
    
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

void SCNHighwayTemplate::processLeftLane (leftLaneControl &leftLane, ostream &outStream, int trialNum) {
    //movement option 0
    //set the initial speed according to the creation position
    if (leftLane.movementOption == 0) {
        leftLaneBlindSpot(trialNum, leftLane, outStream);
    }
    
    //movement option 1
    else if (leftLane.movementOption == 1){
        leftLaneCutBehind(trialNum, leftLane, outStream);
    }
    
    //movement option 2
    else if (leftLane.movementOption == 2) {
        leftLaneCutFront(trialNum, leftLane, outStream);
    }
    
    //movement option 3
    else {
        leftLaneRemainLane(trialNum, leftLane, outStream);
    }
    return;
}

void SCNHighwayTemplate::generateBSWVirtualObjects (ostream &outStream) {
    string          groupName ("\"LeftArrow\"");
    string          solName ("\"RouteNumber\"");
    position        rightPosition (207.9, -1494.2763, 0);
    position        leftPosition (223.2, -1494.6, 0);
    position        drawPosition (0, 0, 0);
    color           graphicColor (0.992, 0.754, 0.051, 1);
    drawSize        sizeOne (60, 60);
    drawSize        sizeTwo (50, 50);
    vector <state>  graphicStates;
    
    //state one
    vector <double> stateVectorOne;
    stateVectorOne.push_back(9.9218750E-001);   stateVectorOne.push_back(7.5390625E-001);
    stateVectorOne.push_back(5.0781250E-002);   stateVectorOne.push_back(0);
    stateVectorOne.push_back(9.9218750E-001);   stateVectorOne.push_back(7.5390625E-001);
    stateVectorOne.push_back(5.0781250E-002);   stateVectorOne.push_back(1);
    stateVectorOne.push_back(600);              stateVectorOne.push_back(1);
    stateVectorOne.push_back(1);                stateVectorOne.push_back(0);
    state           stateOne (1, 1, "\"\"", stateVectorOne);
    graphicStates.push_back(stateOne);
    
    //state two
    vector <double> stateVectorTwo;
    stateVectorOne.push_back(0);                stateVectorOne.push_back(0);
    stateVectorOne.push_back(9.4531250E-001);   stateVectorOne.push_back(0);
    stateVectorOne.push_back(0);                stateVectorOne.push_back(0);
    stateVectorOne.push_back(0);                stateVectorOne.push_back(0);
    stateVectorOne.push_back(9.9999998E-003);   stateVectorOne.push_back(0);
    stateVectorOne.push_back(0);                stateVectorOne.push_back(0);
    state stateTwo (1, 1, "\"\"", stateVectorTwo);
    graphicStates.push_back(stateTwo);
    
    VirtualObject   BSW_Right (groupName, 0, 0, solName, "\"BSW_Right_Graphic\"", "", "\" \"", "\" \"", 
                                rightPosition, drawPosition, graphicColor, graphicColor, sizeOne, graphicStates);
    BSW_Right.print(outStream);
            
    VirtualObject   BSW_Left (groupName, 0, 0, solName, "\"BSW_Left_Graphic\"", "", "\" \"", "\" \"", 
                              leftPosition, drawPosition, graphicColor, graphicColor, sizeTwo, graphicStates);
    BSW_Left.print(outStream);
    return;
}

void SCNHighwayTemplate::generateBSWActivationTriggers(ostream &outStream) {
    //turn on right blind spot
    string              rightPositionDialOn ("\"SetPoisition\" \"2230 150 0\"");
    string              rightPositionButtonPathOn ("\"VirtualObject/SetPosition\"");
    string              rightPositionNameSetOn ("\"BSW_Right_Graphic\"");
    Action*             setRightGraphicPosition = new SetDial (0, 0, "\"SetRightGraphicPosition\"", rightPositionNameSetOn, rightPositionDialOn, rightPositionButtonPathOn);
    
    string              rightSetStateDialOn ("\"SetStateIndex\" \"1\"");
    string              rightSetStateButtonPathOn ("\"VirtualObject/SetStateIndex\"");
    string              rightSetNameSetOn ("\"BSW_Right_Graphic\"");
    Action*             setRightVisualStateOn = new SetDial (0, 10, "\"SetRightGraphicState\"", rightSetNameSetOn, rightSetStateDialOn, rightSetStateButtonPathOn);
    
    position            rightOnPosition (1.6020619E+002, -1.5544549E+003, 0);
    vector <Action*>    rightGraphicOnActions;
    rightGraphicOnActions.push_back(setRightGraphicPosition);
    rightGraphicOnActions.push_back(setRightVisualStateOn);
    string              rightGraphicOnExpression ("\"ReadVar('Right_Blind')>0\"");
    ExpressionTrigger   turnOnRightGraphic (true, false, 0, 0, 0, 0, 0, "\"BSWRightOn\"", "\"\"",
                                          "\"\"", rightOnPosition, rightOnPosition, rightGraphicOnActions, rightGraphicOnExpression);
    turnOnRightGraphic.filePrint(outStream);
    
    //turn off right blind spot
    Action*             setRightVisualStateOff = new SetDial (0, 10, "\"SetRightGraphicState\"", "\"BSW_Right_Graphic\"", "\"SetStateIndex\" \"0\"", "\"VirtualObject/SetStateIndex\"");
    position            rightOffPostion (1.9644389E+002, -1.5557413E+003, 0);
    vector <Action*>    rightGraphicOffActions;
    rightGraphicOffActions.push_back(setRightVisualStateOff);
    string              rightGraphicOffExpression ("\"ReadVar('Right_Blind')<1\"");
    ExpressionTrigger   turnOffRightGraphic (true, false, 0, 0, 0, 0, 0, "\"BSWRightOff\"", "\"\"", "\"\"", rightOffPostion, rightOffPostion, rightGraphicOffActions, rightGraphicOffExpression);
    turnOffRightGraphic.filePrint(outStream);
    
    //turn on left blind spot
    string              leftPositionDialOn ("\"SetPoisition\" \"-1000 150 0\"");
    string              leftPositionButtonPathOn ("\"VirtualObject/SetPosition\"");
    string              leftPositionNameSetOn ("\"BSW_Left_Graphic\"");
    Action*             setLeftGraphicPosition = new SetDial (0, 0, "\"SetLeftGraphicPosition\"", leftPositionNameSetOn, leftPositionDialOn, leftPositionButtonPathOn);
    
    string              leftSetStateDialOn ("\"SetStateIndex\" \"1\"");
    string              leftSetStateButtonPathOn ("\"VirtualObject/SetStateIndex\"");
    string              leftSetNameSetOn ("\"BSW_Left_Graphic\"");
    Action*             setLeftVisualStateOn = new SetDial (0, 10, "\"SetLeftGraphicState\"", leftSetNameSetOn, leftSetStateDialOn, leftSetStateButtonPathOn);
    
    position            leftOnPosition (1.6270157E+002, -1.5859587E+003, 0);
    vector <Action*>    leftGraphicOnActions;
    leftGraphicOnActions.push_back(setLeftGraphicPosition);
    leftGraphicOnActions.push_back(setLeftVisualStateOn);
    string              leftGraphicOnExpression ("\"ReadVar('Left_Blind')>0\"");
    ExpressionTrigger   turnOnLeftGraphic (true, false, 0, 0, 0, 0, 0, "\"BSWLeftOn\"", "\"\"", "\"\"", leftOnPosition, leftOnPosition, leftGraphicOnActions, leftGraphicOnExpression);
    turnOnLeftGraphic.filePrint(outStream);
    
    //turn off left blind spot
    Action*             setLeftVisualStateOff = new SetDial (0, 10, "\"SetLeftGraphicState\"", "\"BSW_Left_Graphic\"", "\"SetStateIndex\" \"0\"", "\"VirtualObject/SetStateIndex\"");
    position            leftOffPostion (2.0810244E+002, -1.5883068E+003, 0);
    vector <Action*>    leftGraphicOffActions;
    leftGraphicOffActions.push_back(setLeftVisualStateOff);
    string              leftGraphicOffExpression ("\"ReadVar('Left_Blind')<1\"");
    ExpressionTrigger   turnOffLeftGraphic (true, false, 0, 0, 0, 0, 0, "\"BSWLeftOff\"", "\"\"", "\"\"", leftOffPostion, leftOffPostion, leftGraphicOffActions, leftGraphicOffExpression);
    turnOffLeftGraphic.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateBSWInitializeTrigger (ostream &outStream) {
    Action*             setRightBlind = new SetVar (0, 0, "\"RightBlind=0\"", true, "\"Right_Blind\"", "\"0\"");
    Action*             setLeftBlind = new SetVar (0, 0, "\"LeftBlind=0\"", true, "\"Left_Blind\"", "\"0\"");
    
    position            blindInitPosition (1.2117200E+002, -1.4808678E+003, 0);
    vector <Action*>    blindInitActions;
    blindInitActions.push_back(setRightBlind);
    blindInitActions.push_back(setLeftBlind);
    TimeTrigger         setBlindInit (true, true, 0, 0, 0, 0, 0, "\"BSWInit\"", "\"\"",
                              "\"\"", blindInitPosition, blindInitPosition, blindInitActions, 0);
    setBlindInit.filePrint(outStream);
    return;
}

string SCNHighwayTemplate::getLeftVehNameNoQuotations (int trialNum) {
    return "Left_" + std::to_string(trialNum);
}

string SCNHighwayTemplate::getRightVehNameNoQuotations (int trialNum) {
    return "Right_" + std::to_string(trialNum);
}

void SCNHighwayTemplate::generateBSWLeftOn (vector<Trial> &trials, ostream &outStream) {
    //default expression string
    string              leftOnExpression;
    bool                firstLeftVehicleFound (false);
    Trial               trialIt;
    
    //iterate across the trials
    for (int i = 0; i < trials.size (); i++) {
        //set the trialIt
        trialIt = trials[i];
        
        //if the left vehicle is checked
        if (trialIt.leftLane.checked) {
            //if the first vehicle hasn't been found
            if (!firstLeftVehicleFound) {
                firstLeftVehicleFound = true;
                leftOnExpression = "\"GetObjDistPow2('" + getLeftVehNameNoQuotations (trialIt.trialNumber) + "')< 36*36 "; 
            }            
            //otherwise
            else {
                leftOnExpression = leftOnExpression + "| GetObjDistPow2('" + getLeftVehNameNoQuotations (trialIt.trialNumber) + "')< 36*36";
            }
        }
    }
    
    //add in last quotation
    leftOnExpression = leftOnExpression + "\"";
    
    //write the trigger
    Action*             setLeftBlind = new SetVar (0, 0, "\"Left_Blind=1\"", true, "\"Left_Blind\"", "\"1\"");
    position            leftAllOnPos (5.7774066E+001, -1.7308735E+003, 0);
    vector <Action*>    leftAllOnActions;       
    leftAllOnActions.push_back(setLeftBlind);
    ExpressionTrigger   leftAllOn (true, true, 0, 0, 0, 0, 0, "\"BSWLeftAllExpressionsOn\"", "\"\"", "\"\"", leftAllOnPos, leftAllOnPos, leftAllOnActions, leftOnExpression);
    
    leftAllOn.filePrint(outStream);
    return;        
}

void SCNHighwayTemplate::generateBSWLeftOff (vector <Trial> &trials, ostream &outStream) {
    //default expression string
    string              leftOffExpression;
    bool                firstLeftVehicleFound (false);
    Trial               trialIt;
    
    //iterate across the trials
    for (int i = 0; i < trials.size (); i++) {
        //set the trialIt
        trialIt = trials[i];
        
        //if the left vehicle is checked
        if (trialIt.leftLane.checked) {
            //if the first vehicle hasn't been found
            if (!firstLeftVehicleFound) {
                firstLeftVehicleFound = true;
                leftOffExpression = "\"GetObjDistPow2('" + getLeftVehNameNoQuotations (trialIt.trialNumber) + "')> 36*36 "; 
            }            
            //otherwise
            else {
                leftOffExpression = leftOffExpression + "| GetObjDistPow2('" + getLeftVehNameNoQuotations (trialIt.trialNumber) + "')> 36*36";
            }
        }
    }
    
    //add in last quotation
    leftOffExpression = leftOffExpression + "\"";
    
    //write the trigger
    Action*             setLeftBlind = new SetVar (0, 0, "\"Left_Blind=0\"", true, "\"Left_Blind\"", "\"0\"");
    position            leftAllOffPos (1.1937059E+002, -1.7279644E+003, 0);
    vector <Action*>    leftAllOffActions;       
    leftAllOffActions.push_back(setLeftBlind);
    ExpressionTrigger   leftAllOff (true, true, 0, 0, 0, 0, 0, "\"BSWLeftAllExpressionsOff\"", "\"\"", "\"\"", leftAllOffPos, leftAllOffPos, leftAllOffActions, leftOffExpression);
    
    leftAllOff.filePrint(outStream);
    return;   
}

void SCNHighwayTemplate::generateBSWRightStationary (Trial &currTrial, ostream &outStream) {
    //get the position of the stationary vehicle
    double              vehYPosition = currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt);    
    double              rightOnStart = vehYPosition - 24;
    double              rightOnEnd = vehYPosition + 9;
    string              rightOnMidString (std::to_string(rightOnStart) + ":" + std::to_string(rightOnEnd));
    double              rightOffStart = vehYPosition + 47;
    double              rightOffEnd = vehYPosition + 69;
    string              rightOffMidString (std::to_string(rightOffStart) + ":" + std::to_string(rightOffEnd));    
    
    //on roadpad trigger
    position            rightBlindOnPosition (450, -1320 + vehYPosition, 0);
    Action*             rightBlindOnSetVar = new SetVar (0, 0, "\"Right_Blind=1\"", true, "\"Right_Blind\"", "\"1\"");
    vector <Action*>    rightBlindOnActions;
    rightBlindOnActions.push_back(rightBlindOnSetVar);
    string              rightBlindOnPath ("\"R:r1_0_113520:0[" + rightOnMidString + "]:1[" + rightOnMidString + "]\"");
    RoadPadTrigger      rightBlindOn (false, true, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOn" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                 "\"\"", rightBlindOnPosition, rightBlindOnPosition, rightBlindOnActions, "\"ExternalDriver\"", rightBlindOnPath);
    rightBlindOn.filePrint(outStream);
    
    //off roadpad trigger
    position            rightBlindOffPosition (520, -1320 + vehYPosition, 0);
    Action*             rightBlindOffSetVar = new SetVar (0, 0, "\"Right_Blind=0\"", true, "\"Right_Blind\"", "\"0\"");
    vector <Action*>    rightBlindOffActions;
    rightBlindOffActions.push_back(rightBlindOffSetVar);
    string              rightBlindOffPath ("\"R:r1_0_113520:0[" + rightOffMidString + "]:1[" + rightOffMidString + "]\"");
    RoadPadTrigger      rightBlindOff (false, true, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOff" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                 "\"\"", rightBlindOffPosition, rightBlindOffPosition, rightBlindOffActions, "\"ExternalDriver\"", rightBlindOffPath);
    rightBlindOff.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateBSWRightPullFront (Trial &currTrial, ostream &outStream) {
    //expression trigger to turn on blind spot
    double              trialBeginPos = -1320 + currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt);
    position            rightBlindOnPosition (450, trialBeginPos + trialLengthFt, 0);
    Action*             rightBlindOnSetVar = new SetVar (0, 0, "\"Right_Blind=1\"", true, "\"Right_Blind\"", "\"1\"");
    vector <Action*>    rightBlindOnActions;
    rightBlindOnActions.push_back(rightBlindOnSetVar);
    string              rightBlindOnExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')<36*36\"");
    Trigger*            rightBlindOn = new ExpressionTrigger (false, false, 0, 0, 0, 0, 0, "\"RightBlindOn" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOnPosition, rightBlindOnPosition, rightBlindOnActions, rightBlindOnExpression);
    
    //roadpad trigger to create the blind spot on expression trigger
    position            createRightBlindOnPos (520, trialBeginPos + trialLengthFt, 0);
    Action*             createAction = new CreateHCSM (0, 0, "\"CreateRightBlindOn" + std::to_string(currTrial.trialNumber) + "\"");
    createAction->addTrigger(rightBlindOn);
    vector <Action*>    createRightBlindOnActions;
    createRightBlindOnActions.push_back(createAction);
    double              pathBeginning = (currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt) + trialLengthFt) + 40;
    string              createRightBlindOnPathMid (std::to_string(pathBeginning) + ":" + std::to_string(pathBeginning + 10));
    string              createRightBlindOnPath ("\"R:r1_0_113520:0[" + createRightBlindOnPathMid + "]:1[" + createRightBlindOnPathMid + "]\"");
    RoadPadTrigger      createRightBlindOn (false, false, 0, 0, 0, trialLengthFt, 0, "\"CreateRightBlind" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                       "\"\"", createRightBlindOnPos, createRightBlindOnPos, createRightBlindOnActions, "\"ExternalDriver\"", createRightBlindOnPath);
    createRightBlindOn.filePrint(outStream);
    
    //expression trigger to turn off blind spot
    position            rightBlindOffPosition (450, trialBeginPos, 0);
    Action*             rightBlindOffSetVar = new SetVar (0, 0, "\"Right_Blind=0\"", true, "\"Right_Blind\"", "\"0\"");
    vector <Action*>    rightBlindOffActions;
    rightBlindOffActions.push_back(rightBlindOffSetVar);
    string              rightBlindOffExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')>36*36\"");
    ExpressionTrigger   rightBlindOff (false, false, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOff" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOffPosition, rightBlindOffPosition, rightBlindOffActions, rightBlindOffExpression);
    rightBlindOff.filePrint(outStream);
}

void SCNHighwayTemplate::generateBSWRightShoulder (Trial &currTrial, ostream &outStream) {
    //expression trigger on
    double              trialBeginPos = -1320 + currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt);;
    position            rightBlindOnPosition (450, trialBeginPos, 0);
    Action*             rightBlindOnSetVar = new SetVar (0, 0, "\"Right_Blind=1\"", true, "\"Right_Blind\"", "\"1\"");
    vector <Action*>    rightBlindOnActions;
    rightBlindOnActions.push_back(rightBlindOnSetVar);
    string              rightBlindOnExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')<36*36\"");
    ExpressionTrigger   rightBlindOn (false, false, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOn" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOnPosition, rightBlindOnPosition, rightBlindOnActions, rightBlindOnExpression);
    rightBlindOn.filePrint(outStream);
    
    //expression trigger off
    position            rightBlindOffPosition (520, trialBeginPos, 0);
    Action*             rightBlindOffSetVar = new SetVar (0, 0, "\"Right_Blind=0\"", true, "\"Right_Blind\"", "\"0\"");
    vector <Action*>    rightBlindOffActions;
    rightBlindOffActions.push_back(rightBlindOffSetVar);
    string              rightBlindOffExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')>36*36\"");
    ExpressionTrigger   rightBlindOff (false, false, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOff" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOffPosition, rightBlindOffPosition, rightBlindOffActions, rightBlindOffExpression);
    rightBlindOff.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateBSWRightPullFrontStop (Trial &currTrial, ostream &outStream) {
    //expression trigger to turn on blind spot
    double              trialBeginPos = -1320 + currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt);
    position            rightBlindOnPosition (450, trialBeginPos + currTrial.roadSide.distance, 0);
    Action*             rightBlindOnSetVar = new SetVar (0, 0, "\"Right_Blind=1\"", true, "\"Right_Blind\"", "\"1\"");
    vector <Action*>    rightBlindOnActions;
    rightBlindOnActions.push_back(rightBlindOnSetVar);
    string              rightBlindOnExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')<36*36\"");
    Trigger*            rightBlindOn = new ExpressionTrigger (false, false, 0, 0, 0, 0, 0, "\"RightBlindOn" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOnPosition, rightBlindOnPosition, rightBlindOnActions, rightBlindOnExpression);
    
    //roadpad trigger to create the blind spot on expression trigger
    position            createRightBlindOnPos (520, trialBeginPos + currTrial.roadSide.distance, 0);
    Action*             createAction = new CreateHCSM (0, 0, "\"CreateRightBlindOn" + std::to_string(currTrial.trialNumber) + "\"");
    createAction->addTrigger(rightBlindOn);
    vector <Action*>    createRightBlindOnActions;
    createRightBlindOnActions.push_back(createAction);
    double              pathBeginning = (currTrial.trialNumber * (trialLengthFt + trialSetupLengthFt) + currTrial.roadSide.distance);
    string              createRightBlindOnPathMid (std::to_string(pathBeginning) + ":" + std::to_string(pathBeginning + 10));
    string              createRightBlindOnPath ("\"R:r1_0_113520:0[" + createRightBlindOnPathMid + "]:1[" + createRightBlindOnPathMid + "]\"");
    RoadPadTrigger      createRightBlindOn (false, false, 0, 0, 0, trialLengthFt, 0, "\"CreateRightBlind" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                       "\"\"", createRightBlindOnPos, createRightBlindOnPos, createRightBlindOnActions, "\"ExternalDriver\"", createRightBlindOnPath);
    createRightBlindOn.filePrint(outStream);
    
    //expression trigger to turn off blind spot
    position            rightBlindOffPosition (520, trialBeginPos, 0);
    Action*             rightBlindOffSetVar = new SetVar (0, 0, "\"Right_Blind=0\"", true, "\"Right_Blind\"", "\"0\"");
    vector <Action*>    rightBlindOffActions;
    rightBlindOffActions.push_back(rightBlindOffSetVar);
    string              rightBlindOffExpression ("\"GetObjDistPow2('" + getRightVehNameNoQuotations(currTrial.trialNumber)  + "')>36*36\"");
    ExpressionTrigger   rightBlindOff (false, false, 0, 0, 0, trialLengthFt, 0, "\"RightBlindOff" + std::to_string(currTrial.trialNumber) + "\"", "\"\"",
                                    "\"\"", rightBlindOffPosition, rightBlindOffPosition, rightBlindOffActions, rightBlindOffExpression);
    rightBlindOff.filePrint(outStream);
}

void SCNHighwayTemplate::generateBlindSpot (vector<Trial> &trials, ostream &outStream) {
    //generate virtual objects
    generateBSWVirtualObjects(outStream);
    
    //triggers to activate and deactivate the left/right bsw
    generateBSWActivationTriggers (outStream);
    
    //trigger to initialize state variables
    generateBSWInitializeTrigger (outStream);
    
    //left set variable trigger
    generateBSWLeftOn(trials, outStream);
    
    //left unset variable after trial for each left trial
    generateBSWLeftOff (trials, outStream);
    
    //iterate across the trials
    roadSideControl   rightControl;
    for (int i = 0; i < trials.size (); i++) {
        if (trials[i].roadSide.checked) {
            //remain stationary
            if (trials[i].roadSide.movementOption == 0) {
                generateBSWRightStationary (trials[i], outStream);
            }
            //pull out in front
            else if (trials[i].roadSide.movementOption == 1) {
                generateBSWRightPullFront (trials[i], outStream);
            }
            //drive on shoulder
            else if (trials[i].roadSide.movementOption == 2) {
                generateBSWRightShoulder (trials[i], outStream);
            }
            //pull out in front and stop
            else {
                generateBSWRightPullFrontStop (trials[i], outStream);
            }
        }
    }     
    return;
}

void SCNHighwayTemplate::generateFCWGraphics (FCW &fcwSettings, ostream &outStream) {
    string          iconName ("\"\"");
    position        FCWDrawPosition (fcwSettings.pos);
    position        FCWPosition (2.3905214E+002, -1.4957105E+003, 0.0000000E+000);
    color           FCWColor (0, 0, 0, 0);
    drawSize        FCWSize (200, 45);
    double          periodOff = (1 - (fcwSettings.frequency * fcwSettings.periodOn))/fcwSettings.frequency;
    
    //get the colors
    double          percentRed ((double)fcwSettings.FCWColor.red()/255);
    double          percentGreen ((double)fcwSettings.FCWColor.green()/255);
    double          percentBlue ((double)fcwSettings.FCWColor.blue()/255);

    //create the states
    vector <double> stateVecOne;
    stateVecOne.push_back(percentRed);              stateVecOne.push_back(percentGreen);
    stateVecOne.push_back(percentBlue);             stateVecOne.push_back(0);
    stateVecOne.push_back(percentRed);              stateVecOne.push_back(percentGreen);
    stateVecOne.push_back(percentBlue);             stateVecOne.push_back(0);
    stateVecOne.push_back(fcwSettings.periodOn);    stateVecOne.push_back(1);
    stateVecOne.push_back(1);                       stateVecOne.push_back(0);
    state           stateOne (8, 1, "\"\"", stateVecOne);
    
    vector <double> stateVecTwo;
    stateVecTwo.push_back(0);                       stateVecTwo.push_back(0);
    stateVecTwo.push_back(0);                       stateVecTwo.push_back(0);
    stateVecTwo.push_back(0);                       stateVecTwo.push_back(0);
    stateVecTwo.push_back(0);                       stateVecTwo.push_back(0);
    stateVecTwo.push_back(periodOff);               stateVecTwo.push_back(0);
    stateVecTwo.push_back(0);                       stateVecTwo.push_back(0);
    state           stateTwo (8, 1, "\"\"", stateVecTwo);
    
    vector<state>   FCWStates;
    FCWStates.push_back(stateOne);
    FCWStates.push_back(stateTwo);
            
    if (fcwSettings.imageShape == Icon) {
        iconName = (std::string)"\"" + fcwSettings.iconName + (std::string)"\"";
    }
    
    VirtualObject   FCWGraph ("-1", 6, 0, "\"RouteNumber\"", "\"FCWGraph\"", iconName, "\"\"", 
                            "\"\"", FCWPosition, FCWDrawPosition, FCWColor, FCWColor, FCWSize, FCWStates);
    FCWGraph.print(outStream);
    return;
}

void SCNHighwayTemplate::generateFCWInitializeTriggers (ostream &outStream) {
    //time trigger to set the variables
    position            FCWInitPos (1.2026720E+002, -1.4808678E+003, 0.0000000E+000);
    vector <Action*>    FCWInitActions;
    Action*             FCWInRangeInit = new SetVar (0, 0, "\"\"", true, "\"FCWInRange\"", "\"0\"");
    Action*             FCWCenterInit = new SetVar (0, 0, "\"\"", true, "\"FCWCenter\"", "\"0\"");
    FCWInitActions.push_back(FCWInRangeInit);
    FCWInitActions.push_back(FCWCenterInit);
    TimeTrigger         FCWSetup (true, true, 0, 0, 0, 0, 0, "\"FCWInitializer\"", "\"\"",
                          "\"\"", FCWInitPos, FCWInitPos, FCWInitActions, 0);
    FCWSetup.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateFCWActivationTriggers (ostream &outStream) {
    //on
    position            FCWOnPos (3.1276509E+002, -1.6780857E+003, 0.0000000E+000);
    vector <Action*>    FCWOnActions;
    Action*             SetStateOn = new SetDial (0, 10, "SetStateIndex=1", "\"FCWGraph\"", "\"SetStateIndex\" \"1\"", "\"VirtualObject/SetStateIndex\"");
    FCWOnActions.push_back(SetStateOn);
    string              FCWOnExpression ("\"ReadVar('FCWCenter')>0\"");
    ExpressionTrigger   FCWOn (true, false, 0, 0, 0, 0, 0, "\"FCWOn\"", "\"\"",
                             "\"\"", FCWOnPos, FCWOnPos, FCWOnActions, FCWOnExpression);
    FCWOn.filePrint(outStream);
    
    //off
    position            FCWOffPos (3.8188715E+002, -1.6796473E+003, 0.0000000E+000);
    vector <Action*>    FCWOffActions;
    Action*             SetStateOff = new SetDial (0, 10, "SetStateIndex=0", "\"FCWGraph\"", "\"SetStateIndex\" \"0\"", "\"VirtualObject/SetStateIndex\"");
    FCWOffActions.push_back(SetStateOff);
    string              FCWOffExpression ("\"ReadVar('FCWCenter')<0\"");
    ExpressionTrigger   FCWOff (true, false, 0, 0, 0, 0, 0, "\"FCWOn\"", "\"\"",
                             "\"\"", FCWOffPos, FCWOffPos, FCWOffActions, FCWOffExpression);
    FCWOff.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateFCWLeftCutFront (leftLaneControl &leftLane, ostream &outStream, int trialNum) {
    double trialBegin (trialInt * (trialLengthFt + trialSetupLengthFt));
    
    //expression trigger on
    position            leftOnPos (450, trialBegin + 100, 0);
    vector <Action*>    leftOnActions;
    Action*             leftOnSetVarOn = new SetVar (0, 0, "FCWOn", true, "\"FCWCenter\"", "\"1\""); //setvar
    Action*             leftOnAudioOn = new WriteCell (0, 0, "\"FCWAudioOn\"", true, 2, "\"SCC_Audio_Trigger\"", "\"1002\""); //writecell
    string              leftOnExpression ("\"\"");
    leftOnActions.push_back(leftOnSetVarOn);
    leftOnActions.push_back(leftOnAudioOn);
    ExpressionTrigger   leftOn (true, true, 0, 0, 0, 0, 0, "\"FCWLeft_" + trialNum + "\"", "\"\"",
                              "\"\"", leftOnPos, leftOnPos, leftOnActions, leftOnExpression);
    leftOn.filePrint(outStream);
    
    //expression trigger off
    
    
    //roadpad trigger for in range on
    
    
    //roadpad trigger fo in range off
    
}

void SCNHighwayTemplate::generateFCWRightCutFront (roadSideControl &roadSide, ostream &outStream, int trialNum) {
    //expression trigger on
    
    
    //expression trigger off
    
    
    //roadpad trigger for in range on
    
    
    //roadpad trigger fo in range off
    
}

void SCNHighwayTemplate::generateFCWRightCutFrontStop (roadSideControl &roadSide, ostream &outStream, int trialNum) {
    //expression trigger on
    
    
    //expression trigger off
    
    
    //roadpad trigger for in range on
    
    
    //roadpad trigger fo in range off
    
    
}

void SCNHighwayTemplate::generateFCW (FCW &fcwSettings, vector<Trial> &trials, ostream &outStream) {
    //generate the graphics
    generateFCWGraphics (fcwSettings, outStream);
    
    //generate the triggers to initialize the fcw variables
    generateFCWInitializeTriggers (outStream);
    
    //generate triggers to set the fcw on, off, and reset the one time variable
    for (auto trial:trials) {
        if (trial.leftLane.checked) {
            //cut in front of driver
            if (trial.leftLane.movementOption == 2) {
                generateFCWLeftCutFront (trial.leftLane, outStream, trial.trialNumber);
            }
        }
        if (trial.roadSide.checked) {
            //pull out in front
            if (trial.roadSide.movementOption == 1) {
                generateFCWRightCutFront (trial.roadSide, outStream, trial.trialNumber);
            }
            //pull out in front and stop
            else if (trial.roadSide.movementOption == 3) {
                generateFCWRightCutFrontStop(trial.roadSide, outStream, trial.trialNumber);
            }
        }
    }
    
    //generate triggers to activate the graphic
    generateFCWActivationTriggers (outStream);
    
    //animation?        
    
            
    return;
}

void SCNHighwayTemplate::processAll (vector<Trial> &trials, MajorSettings &settings, ostream &outStream) {
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
                processRoadSide(trial.roadSide, outStream, trial.trialNumber);
            }
            if (trial.leftLane.checked) {
                processLeftLane(trial.leftLane, outStream, trial.trialNumber);
            }
            if (trial.followVehicle.checked){
                processFollowVehicle(trial.followVehicle, outStream, trial.trialNumber);
            }
            if (trial.leadVehicle.checked) {
                processLeadVehicle(trial.leadVehicle, outStream, trial.trialNumber);
            }
        }
        trialNum++;
    }
    
    return;
}

void SCNHighwayTemplate::printUnusedSCNObjects(ostream &outStream) {
    outStream << "HCSM DriverMirror\n&&&&End&&&&\n";
    outStream << "HCSM IntersectionManager\n&&&&End&&&&\n";
    return;
}

void SCNHighwayTemplate::clearTillEnd (ifstream &inputStream) {
    string  current;
    inputStream >> current;
    while (current != "&&&&End&&&&") {
        inputStream >> current;
    }
    return;
}

void SCNHighwayTemplate::writeFile(string outputFilePath, vector<Trial> &trials, MajorSettings &settings) {
    //open the file
    ofstream    outStream;
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

void SCNHighwayTemplate::readFile(string SCNFilePath) {
    if (SCNFilePath.empty()) {
        return;
    }
    
    //open the filestream
    ifstream    inputStream;
    inputStream.open(SCNFilePath);

    //begin reading the file by reading the header
    this->readHeader(inputStream);

    //begin reading everything else
    this->readRest(inputStream);

    //close the file when done
    inputStream.close();

    return;
}

void SCNHighwayTemplate::readHeader(ifstream &inputStream) {
    if (!header.readFromFile(inputStream)) {}
    return;
}

void SCNHighwayTemplate::readInStaticObjManager(ifstream &inputStream) {
    string  currentLine;
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

void SCNHighwayTemplate::readRest(ifstream &inputStream) {
    string  inputCase;
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
            Trigger* newTrigger = new ExpressionTrigger;
            newTrigger->fileRead(inputStream);
            triggers.push_back(newTrigger);
        }
        else if (inputCase == "HCSM RoadPadTrigger") {
            Trigger* newTrigger = new RoadPadTrigger;
            newTrigger->fileRead(inputStream);
            triggers.push_back(newTrigger);
        }
        else if (inputCase == "HCSM TimeTrigger") {
            Trigger* newTrigger = new TimeTrigger;
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

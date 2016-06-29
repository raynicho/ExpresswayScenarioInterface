#include "SCNHighwayTemplate.h"

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

void SCNHighwayTemplate::processLeadVehicle (FVLVInstructions &leadVehicle, ostream &outStream) {
    
    return;
}

void SCNHighwayTemplate::processFollowVehicle (FVLVInstructions &followVehicle, ostream &outStream) {
    
    return;
}

void SCNHighwayTemplate::processRoadSide(roadSideControl &roadSide, ostream &outStream, int trialNum) {
    if (roadSide.movementOption == 0) {
	//create the ddo
	string SOLModel = getRandSol(false);
	int color = getRandSolColor(SOLModel);
	string rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
	position fake;
	
	vector<double> Dirs; 
	Dirs.push_back(1.5707963);
	
	vector<bool> DirsDef;
	DirsDef.push_back(0);
	
	vector <trajectory> Trajs;
	trajectory stationaryTrajectory (400, (-1320) + trialNum * (trialLengthFt + trialSetupLengthFt), 1, 0, 0);
	Trajs.push_back(stationaryTrajectory);
	
	int visState = 0;
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
	Vehicle* stationaryDDO = new DDO (color, 0, 0, trialLengthFt, rightVehName, "\" \"", "\" \"", SOLModel, false, true, visState, fake, Dirs, DirsDef, Trajs);
	stationaryDDO->print(outStream);
    }
    else if (roadSide.movementOption == 1) {
	string SOLModel = getRandSol(false);
	int color = getRandColor(SOLModel);
	
	
	//create the ddo
	
	    //set the visual state
	
	    //created at what disctance?
	
	    //whats the path?
	
	    //cut in at certain distance at certain speed	
	
	//roadpad trigger after the ddo pull out path
	    
	    //create the ado
	
		//set the visual state
	    
	    //reset ado inhibit lane change
	
	    //set the ado inhibit lane change
	
	//roadpad trigger after the ddo pull out path to have the ado match the external driver
	
	//roadpad trigger at end of trial
	
	    //delete the ado
	
	    //create the ddo
	
		//if deletion option is left
		
		//if deletion option is right
		
    }
    else if (roadSide.movementOption == 2) {
	//create the ddo
	string SOLModel = getRandSol(false);
	int color = getRandSolColor(SOLModel);
	string rightVehName = "\"Right_" + std::to_string(trialNum) + "\"";
	position fake;
	
	vector <double> Dirs;
	Dirs.push_back(1.57);
	
	vector <bool> DirsDef;
	DirsDef.push_back(false);
	
	vector <trajectory> Trajs;
	trajectory tempTraj (400, -1320 + trialNum * (trialLengthFt + trialSetupLengthFt), roadSide.speed, 0, 1);
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
	    }
	    case (Left) : {
		visState = 1;
	    }
	    case (Hazards) : {
		visState = 4;
	    }
	}
	
	Vehicle* driveShoulderDDO = new DDO (color, 0, 5, 500, rightVehName, "\"\"", "\"\"", SOLModel, false, true, visState, fake, Dirs, DirsDef, Trajs);
	driveShoulderDDO->print(outStream);
    }
    else {
	
    }
    return;
}

void SCNHighwayTemplate::generateFollowVehicle (FVLVSettings &followVehicle, ostream &outStream) {
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
    
    ExpressionTrigger maintain(false, false, 0, 0, 0, 0, 0, "\"FV_Keep_Distance\"", "\"\"", "\"\"", Draw, Pos, Act, "\"1=1\"");
    
    //print the vehicle and the trigger
    follow.print(outStream);
    maintain.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateLeadVehicle (FVLVSettings &leadVehicle, ostream &outStream) {
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
    ExpressionTrigger maintain (false, false, 0, 0, 0, 0, 0, "\"LV_Keep_Distance\"", "\"\"", "\"\"", Draw, Draw, Act, "\"1=1\"");
            
    //print the vehicle and the trigger
    lead.print(outStream);
    maintain.filePrint(outStream);
    return;
}

double SCNHighwayTemplate::randDouble (double min, double max) {
    std::uniform_real_distribution<double> unif(min, max);
    double rand = unif(re);
    return rand;
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

void SCNHighwayTemplate::processLeftLane (leftLaneControl &leftLane, ostream &outStream, int trialNum) {
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
    
    //generate the roadpad trigger
    position Draw;
    Draw.x = 450;
    Draw.y = (trialNum * (trialLengthFt + trialSetupLengthFt)) - 1320;
    vector <Action*> Act;
    double beginYPos = (trialNum * (trialLengthFt + trialSetupLengthFt));
    double endYpos = beginYPos + 20;
    double initVeloc = 0;
    
    vector<Action*> Act2;
    
    //movement option 0
    //set the initial speed according to the creation position
    if (leftLane.movementOption == 0) {
        int matchETDistance = 60;
        
        //if its created in front
        if (leftLane.creationOption == 1) {
            initVeloc = 35;
            matchETDistance = 20;
        }
        //otherwise it is created behind
        else {
            initVeloc = 90;
        }
        
        //generate the creation action, add the vehicle, blinker dials
        Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
        Vehicle* leftPtr = new ADO (left);
        leftPtr->setInitialVel(initVeloc);
        leftPtr->setVelocitySettings(0, initVeloc, 1.0051923E-240);
        act->addVehicle(leftPtr);
        Act.push_back(act);
        
        if (leftLane.blinker != None) {
            Action* reset = new ResetDial (0, 0, "\"LeftResetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, "\"VisualState\" \"16;2\"", "\"Ado/VisualState\"");
            Action* blinker = new SetDial(0, 0, "\"LeftSetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, dial, "\"Ado/VisualState\"");
            Act.push_back(reset);
            Act.push_back(blinker);
        }
        
        RoadPadTrigger roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, Act, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
        roadTrigger.filePrint(outStream);
        
        //generate the action to reset the velocity and then match the Et velocity
        Action* setToMatch = new SetDial (0, 0, "\"LeftMatchSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
        
        //generate the expression trigger to match velocity
        position pos = Draw;
        pos.x = pos.x + 70;
        vector <Action*> blindActions;
        blindActions.push_back(setToMatch);
        ExpressionTrigger blindSpot (true, false, 0, 0, 0, trialLengthFt, 0, "\"LeftBlindSpot_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", pos, pos, blindActions, "\" GetObjDistPow2('Left_" + std::to_string(trialNum) + "') < " + std::to_string(matchETDistance) + " * " + std::to_string(matchETDistance) + "\"");
        blindSpot.filePrint(outStream);
        
        Action* deleteMatchET = new DeleteHCSM (0, 0, "\"LeftDeleteBlindTrigger_" + std::to_string(trialNum) + "\"", "\"LeftBlindSpot_" + std::to_string(trialNum) + "\"");
        Act2.push_back(deleteMatchET);
    }
    
    //movement option 1
    else if (leftLane.movementOption == 1){
        
    }
    
    //movement option 2
    else if (leftLane.movementOption == 2) {
        
    }
    
    //movement option 3
    else {
        //if it is match the et
        if (leftLane.laneOption == 1) {
            //intial velocity is 60 and fixed
            Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
            Vehicle* leftPtr = new ADO (left);
            initVeloc = 60;
            leftPtr->setInitialVel(initVeloc);
            leftPtr->setVelocitySettings(0, 60, 1.0051923E-240);
            act->addVehicle(leftPtr);
            Act.push_back(act);
            
            //set the blinker
            if (leftLane.blinker != None) {
                Action* reset = new ResetDial (0, 0, "\"LeftResetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, "\"VisualState\" \"16;2\"", "\"Ado/VisualState\"");
                Action* blinker = new SetDial(0, 0, "\"LeftSetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, dial, "\"Ado/VisualState\"");
                Act.push_back(reset);
                Act.push_back(blinker);
            }
            
            //create the expression trigger to match the et
            vector <Action*> matchETActions;
            Action* setLeftVelocity = new SetDial (0, 0, "\"LeftMatchET_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"ovvel\"", "\"Ado/ForcedVelocity\"");
            matchETActions.push_back(setLeftVelocity);
	    position matchETPosition = Draw;
	    matchETPosition.x += 140;
            
            ExpressionTrigger matchETTrigger (true, false, 0, 0, 0, trialLengthFt, 0, "\"LeftMatchET_" + std::to_string(trialNum) + "\"", "\"\"", "\"\"", matchETPosition, matchETPosition, matchETActions, "\"1=1\"");  
	    Trigger* matchETTriggerPtr = new ExpressionTrigger(matchETTrigger);
            
            //create the action to create the expression trigger match et and also one to reset the velocity of the left vehicle
            Action* resetSpeed = new ResetDial (0, 0, "\"LeftResetSpeed_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"\"", "\"Ado/ForcedVelocity\"");
            Act.push_back (resetSpeed);
            Action* createMatchEt = new CreateHCSM (0, 0, "\"LeftCreateMatchETTrigger_" + std::to_string(trialNum) + "\"");
	    createMatchEt->addTrigger(matchETTriggerPtr);
            
            //write the create vehicle trigger
	    position createMatchETPos = Draw;
	    createMatchETPos.x += 70;
	    vector<Action*> createMatchActions;
	    createMatchActions.push_back(createMatchEt);
	    RoadPadTrigger createMatchRoadTrigger (true, true, 5, 0, 0, trialLengthFt, 0, "\"LeftCreateMatchET_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", createMatchETPos, createMatchETPos, createMatchActions,"\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
	    createMatchRoadTrigger.filePrint(outStream);
	    
            RoadPadTrigger roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, Act, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
            roadTrigger.filePrint(outStream);           
            
            //create action to delete match et trigger
            Action* deleteMatchEt = new DeleteHCSM (0, 0, "\"LeftDeleteMatchET_" + std::to_string(trialNum) + "\"", "\"LeftMatchET_" + std::to_string(trialNum) + "\"");
	    Act2.push_back(deleteMatchEt);
        }
        //else it is an absolute value
        else {
            //initial velocity is the absolute value and fixed
            Action* act = new CreateHCSM(0, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"");
            Vehicle* leftPtr = new ADO (left);
            initVeloc = leftLane.speed;
            leftPtr->setInitialVel(initVeloc);
            leftPtr->setVelocitySettings(0, leftLane.speed, 1.0051923E-240);
            act->addVehicle(leftPtr);
            Act.push_back(act);
	    
	    //set the blinker
	    if (leftLane.blinker != None) {
                Action* reset = new ResetDial (0, 0, "\"LeftResetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, "\"VisualState\" \"16;2\"", "\"Ado/VisualState\"");
                Action* blinker = new SetDial(0, 0, "\"LeftSetBlinker_" + std::to_string(trialNum) + "\"", leftVehName, dial, "\"Ado/VisualState\"");
                Act.push_back(reset);
                Act.push_back(blinker);
            }
	    
            //write the create vehicle trigger
	    RoadPadTrigger roadTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"CreateLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", Draw, Draw, Act, "\"ExternalDriver\"", "\"R:r1_0_113520:0[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]:1[" + std::to_string(beginYPos) + ":" + std::to_string(endYpos) + "]\"");
            roadTrigger.filePrint(outStream);  
        }
    }
    
    //create action to make it slow down
    Action* resetSlowDown = new ResetDial (0, 0, "\"LeftResetBeforeSlowDown_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \" \"", "\"Ado/ForcedVelocity\"");
    Action* slowDown = new SetDial(0, 0, "\"LeftSlowDown_" + std::to_string(trialNum) + "\"", leftVehName, "\"ForcedVelocity\" \"25\"", "\"Ado/ForcedVelocity\"");
    
    //create roadpad trigger to hold slow down action
    Act2.push_back(resetSlowDown);
    Act2.push_back(slowDown);
    position slowDraw = Draw;
    slowDraw.y = slowDraw.y + trialLengthFt;
    string slowPath = "\"R:r1_0_113520:0[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]:1[" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt) + ":" + std::to_string(trialNum*(trialLengthFt + trialSetupLengthFt) + trialLengthFt + 20) + "]\"";
    RoadPadTrigger slowDownTrigger (true, true, 0, 0, 0, trialLengthFt, 0, "\"SlowLeft_" + std::to_string(trialNum) + "\"", "\" \"", "\" \"", slowDraw, slowDraw, Act2, leftVehName, slowPath);
    slowDownTrigger.setTypeSet(false);
    slowDownTrigger.filePrint(outStream);
    return;
}

void SCNHighwayTemplate::generateBlindSpot (vector<Trial> &trials, ostream &outStream) {
    return;
}

void SCNHighwayTemplate::generateFCW (FCW &fcwSettings, vector<Trial> &trials, ostream &outStream) {
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

void SCNHighwayTemplate::printUnusedSCNObjects(ostream &outStream) {
    outStream << "HCSM DriverMirror\n&&&&End&&&&\n";
    outStream << "HCSM IntersectionManager\n&&&&End&&&&\n";
    return;
}

void SCNHighwayTemplate::clearTillEnd (ifstream &inputStream) {
    string current;
    inputStream >> current;
    while (current != "&&&&End&&&&") {
        inputStream >> current;
    }
    return;
}

void SCNHighwayTemplate::writeFile(string outputFilePath, vector<Trial> &trials, MajorSettings &settings) {
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
void SCNHighwayTemplate::readFile(string SCNFilePath) {
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
void SCNHighwayTemplate::readHeader(ifstream &inputStream) {
    if (!header.readFromFile(inputStream)) {
        std::exception e("The scn file entered does not have a vehicle position entered.");
    }
    return;
}

void SCNHighwayTemplate::readInStaticObjManager(ifstream &inputStream) {
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

void SCNHighwayTemplate::readRest(ifstream &inputStream) {
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

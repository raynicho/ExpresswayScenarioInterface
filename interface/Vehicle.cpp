#include "Vehicle.h"

/*********************************************************************************************************/
                                            /*Vehicle Class*/
Vehicle::Vehicle() : createdByTrigger(false), colorIndex(1), lifetime(0), actvDel(0), crRad(0), solName("\"Audi\"") {

}

Vehicle::Vehicle(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName) :
    colorIndex(color), lifetime(LifeTime), actvDel(delay), crRad(CrRad), name(Name), longComment(Long), shortComment(Short),
    solName(SolName), createdByTrigger(false) {}

void Vehicle::print(ostream &) {}

void Vehicle::readFromFile(ifstream &) {}

void Vehicle::setInitialVel (double &) {}

void Vehicle::setVelocitySettings (double, double, double) {
    
}

void Vehicle::setCreation(bool wasICreated) {
    createdByTrigger = wasICreated;
    return;
}

bool Vehicle::getCreation() {
    return createdByTrigger;
}

void Vehicle::printBasics(ostream &outStream, string spaces) {
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
                                            /*Vehicle Class*/
/*********************************************************************************************************/
                                             
/*********************************************************************************************************/
                                            /*ADO*/
ADO::ADO() : Vehicle(), autoControlBreakLights(false), velCtrlInitMatchOvVel(false), velCtrlDistType(2), laneOffset(-0.49), maxLatOffset(9),
    velCtrlDistVal1(62), path ("-1"), velCtrlDistVal2(-1), visualState(0) {
}

ADO::ADO(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName, bool autoBreak,
    bool velInitMatch, int distType, double laneOff, double maxLatOff, double distVal1, double initVel, string RoadPos, string Path) : Vehicle(color,
        LifeTime, delay, CrRad, Name, Long, Short, SolName), autoControlBreakLights(autoBreak), velCtrlInitMatchOvVel(velInitMatch),
        velCtrlDistType(distType), laneOffset(laneOff), maxLatOffset(maxLatOff), velCtrlDistVal1(distVal1), velCtrlInitVel(initVel), roadPos(RoadPos), path(Path), velCtrlDistVal2(-1),
        visualState(0){}

ADO::ADO (int color, int visState, int velCtrlVal1, int velCtrlVal2, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName, bool autoBreak,
    bool velInitMatch, int distType, double laneOff, double maxLatOff, double initVel, string RoadPos, string Path) : Vehicle(color, LifeTime, delay, CrRad, Name, Long, Short, SolName),
        visualState (visState), velCtrlDistVal1 (velCtrlVal1), velCtrlDistVal2 (velCtrlVal2), autoControlBreakLights(autoBreak), velCtrlInitMatchOvVel(velInitMatch), 
        velCtrlDistType(distType), laneOffset(laneOff), maxLatOffset(maxLatOff), velCtrlInitVel(initVel), 
        roadPos(RoadPos), path(Path) {}

void ADO::setInitialVel(double velocity) {
    velCtrlInitVel = velocity;
    return;
}

void ADO::setVelocitySettings (double velCtrlType, double velCtrlVal1, double velCtrlVal2){
    velCtrlDistType = (int) velCtrlType;
    velCtrlDistVal1 = (int) velCtrlVal1;
    velCtrlDistVal2 = (int) velCtrlVal2;
    return;
}

void ADO::setVisualState (int state) {
    visualState = state;
    return;
}

void ADO::printUnused(ostream &outStream, string spaces) {
    outStream << spaces << "RunMode \"eRemote_Control\"\n";			outStream << spaces << "RandomSol 0\n";
    outStream << spaces << "CreateRelOffsLonUsingExpr 0 \n";			outStream << spaces << "AutoControlHeadLights 0\n";					outStream << spaces << "UseReaDel 1\n";
    outStream << spaces << "LatOffsType 0\n";					outStream << spaces << "CreateRelLatInFeet 0\n";
    outStream << spaces << "PathSearchDepth 2\n";				outStream << spaces << "StdToAccType 0\n";
    outStream << spaces << "StdToDecType 0\n";					outStream << spaces << "StdToAccType 0\n";
    outStream << spaces << "DecToAccType 0\n";					outStream << spaces << "Accel2Catch 0\n";
    outStream << spaces << "VelCtrlFollowSpeedLimit 0\n";			outStream << spaces << "NormVel2Kp 7.0000000E-001\n";
    outStream << spaces << "LcvFall 1.5000000E+000 2.0000000E+000\n";		outStream << spaces << "LcvFreq 3.0000000E-002 5.0000000E-002\n";
    outStream << spaces << "EmergDecClip -1.1000000E+001\n";			outStream << spaces << "FollowTimeMax 2.0000000E+000\n";
    outStream << spaces << "FollowTimeMin 1.0000000E+000\n";			outStream << spaces << "LcvRAmpl 1.0000000E-001 5.0000000E-001\n";
    outStream << spaces << "StdToDecVal1 9.0000000E-001\n";			outStream << spaces << "DynModel \"Non Linear\"\n";
    outStream << spaces << "LogFile \"\"\n";
    return;
}

void ADO::print(ostream &outStream) {
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
    if (velCtrlDistVal2 != -1) {
        outStream << spaces << "VelCtrlDistVal2 " << velCtrlDistVal2 << "\n";
    }
    outStream << spaces << "RoadPos " << roadPos << "\n";
    
    if (path != "-1") {
        outStream << spaces << "Path " << path << "\n";
    }
    
    if (velCtrlInitVel != -1) {
        outStream << spaces << "VelCtrlInitVel " << velCtrlInitVel << "\n";
    }
    
    if (visualState != 0) {
	outStream << spaces << "VisualState " << visualState << "\n";
    }

    this->printBasics(outStream, spaces);
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void ADO::readFromFile(ifstream &inputStream) {
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
        else if (current == "VelCtrlDistVal2") {
            inputStream >> velCtrlDistVal2;
        }
	else if (current == "VisualState") {
	    inputStream >> visualState;
	}
        inputStream >> current;
    }
    return;
}
                                            /*ADO*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                            /*DDO*/
DDO::DDO () : Vehicle () {}

DDO::DDO(int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName,
    bool Dependent, bool DependentOwn, int visState, position refPoint, vector<double> Dirs, vector<bool> DirsDef,
    vector <trajectory> Trajs) : Vehicle(color, LifeTime, delay, CrRad, Name, Long, Short, SolName), dependent(Dependent),
    dependentOwnVeh(DependentOwn), visualState(visState), dependentRefPoint(refPoint), dirs(Dirs), dirsDef(DirsDef),
    trajs(Trajs) {}

DDO::DDO(int ref, int color, double LifeTime, double delay, double CrRad, string Name, string Long, string Short, string SolName,
    bool Dependent, bool DependentOwn, int visState, position targetPoint, vector<double> Dirs, vector<bool> DirsDef,
    vector <trajectory> Trajs) : Vehicle(color, LifeTime, delay, CrRad, Name, Long, Short, SolName), refPoint(ref), dependent(Dependent),
    dependentOwnVeh(DependentOwn), visualState(visState), dependentRefPoint(targetPoint), dirs(Dirs), dirsDef(DirsDef),
    trajs(Trajs) {}

void DDO::readFromFile(ifstream &inputStream) {
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
	else if (current == "RefPoint") {
	    inputStream >> this->refPoint;
	}
        inputStream >> current;
    }
    return;
}

void DDO::printUnused(ostream &outStream, string spaces) {
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

void DDO::print(ostream &outStream) {
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
    if (dependent) {
        outStream << spaces << "RefPoint " << this->refPoint << "\n";
        outStream << spaces << "DependentRefPoint " << dependentRefPoint.x << " " << dependentRefPoint.y 
	    << " " << dependentRefPoint.z << '\n';
    }
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
        outStream << spaces << "Traj " << trajs[i].x << " " << trajs[i].y << " " << trajs[i].speed << " " << trajs[i].xDir << " " << trajs[i].yDir;
        outStream << '\n';
    }
    
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}
                                            /*DDO*/
/*********************************************************************************************************/

#include "Actions.h"

/*********************************************************************************************************/
                                                /*Action Class*/
Action::Action(): delay(0), instigatorSet(0) {}

Action::Action(int set, double Delay, string Comment) : instigatorSet(set), delay(Delay), comment(Comment) {}

void Action::printBasics(std::ostream &outStream, bool created) {
    string spaces = "      ";
    if (created) {
        spaces = "              ";
    }
    outStream << spaces << "Comment " << this->comment << '\n';
    outStream << spaces << "Delay " << this->delay << '\n';
    outStream << spaces << "InstigatorSet " << this->instigatorSet << '\n';
    return;
}

void Action::print(ostream &, bool) {}

void Action::readFromFile(ifstream &) {}

void Action::addVehicle (Vehicle*) {}
                                                /*Action Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*LogData Class*/
LogData::LogData() : Action() {}

LogData::LogData(int set, double Delay, string Comment, int Stream, double val) : Action(set, Delay, Comment) {
    stream = Stream;
    streamVal = val;
}

void LogData::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "    HCSM LogData\n";
    this->printBasics(outStream, created);
    outStream << spaces << "Stream " << this->stream << '\n';
    outStream << spaces << "StreamVal " << this->streamVal << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void LogData::readFromFile(ifstream &inputStream) {
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
                                                /*LogData Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*SetDial Class*/
SetDial::SetDial() : Action() {}

SetDial::SetDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : Action(set, Delay, Comment) {
    byNameSet = nameSet;
    dial = Dial;
    buttonDialPath = dialPath;
}

void SetDial::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "HCSM SetDial\n";
    this->printBasics(outStream, created);
    outStream << spacesTillTitle << "ByNameSet " << this->byNameSet << '\n';
    outStream << spaces << "Dial " << this->dial << '\n';
    outStream << spaces << "ButtonDialPath " << this->buttonDialPath << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void SetDial::readFromFile(ifstream &inputStream) {
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
                                                /*SetDial Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*ResetDial Class*/
ResetDial::ResetDial() : Action() {}

ResetDial::ResetDial(int set, double Delay, string Comment, string nameSet, string Dial, string dialPath) : Action(set, Delay, Comment) {
    byNameSet = nameSet;
    dial = Dial;
    buttonDialPath = dialPath;
}

ResetDial::ResetDial(int set, double Delay, string Comment, string Dial, string dialPath) : Action(set, Delay, Comment) {
    byNameSet = "null";
    dial = Dial;
    buttonDialPath = dialPath;
}

void ResetDial::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }        
    outStream << spacesTillTitle << "HCSM ResetDial\n";
    this->printBasics(outStream, created);
    if (byNameSet != "null") {
        outStream << spaces << "ByNameSet " << this->byNameSet << '\n';
    }
    outStream << spaces << "Dial " << this->dial << '\n';
    outStream << spaces << "ButtonDialPath " << this->buttonDialPath << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void ResetDial::readFromFile(ifstream &inputStream) {
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
                                                /*ResetDial Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*DeleteHCSM Class*/
DeleteHCSM::DeleteHCSM() : Action() {}

DeleteHCSM::DeleteHCSM(int set, double Delay, string Comment, string ByNameSet) : Action(set, Delay, Comment) {
    byNameSet = ByNameSet;
}

void DeleteHCSM::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }                
    outStream << spacesTillTitle << "HCSM DeleteHcsm\n";
    this->printBasics(outStream, created);
    outStream << spaces << "ByNameSet " << this->byNameSet << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void DeleteHCSM::readFromFile(ifstream &inputStream) {
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
                                                /*DeleteHCSM Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*SetVar Class*/

SetVar::SetVar() : Action() {}

SetVar::SetVar(int set, double Delay, string Comment, bool isExpression, string VarName, string VarValue) : Action(set, Delay, Comment) {
    varValIsExpression = isExpression;
    varName = VarName;
    varValue = VarValue;
}

void SetVar::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "HCSM SetVar\n";
    this->printBasics(outStream, created);
    outStream << spaces << "VarName " << this->varName << '\n';
    outStream << spaces << "VarValue " << this->varValue << '\n';
    outStream << spaces << "IsVarValExpression " << this->varValIsExpression << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void SetVar::readFromFile(ifstream &inputStream) {
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

                                                /*SetVar Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*SetButton Class*/
SetButton::SetButton() : Action() {}

SetButton::SetButton(int set, double Delay, string Comment, string Button, string ButtonPath) : Action(set, Delay, Comment) {
    button = Button;
    buttonPath = ButtonPath;
}

void SetButton::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "HCSM SetButton\n";
    this->printBasics(outStream, created);
    outStream << spaces << "Button " << this->button << '\n';
    outStream << spaces << "ButtonDialPath " << this->buttonPath << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void SetButton::readFromFile(ifstream &inputStream) {
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
                                                /*SetButton Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*WriteCell Class*/
WriteCell::WriteCell() : Action() {}

WriteCell::WriteCell(int set, double Delay, string Comment, bool isVar, int type, string CellName, string data) : Action(set, Delay, Comment) {
    isVariable = isVar;
    cellType = type;
    cellName = CellName;
    cellData = data;
}

void WriteCell::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "HCSM WriteCell\n";
    this->printBasics(outStream, created);
    outStream << spaces << "CellName " << this->cellName << '\n';
    outStream << spaces << "CellData " << this->cellData << '\n';
    outStream << spaces << "CellType " << this->cellType << '\n';
    outStream << spaces << "CellVar " << this->isVariable << '\n';
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void WriteCell::readFromFile(ifstream &inputStream) {
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
                                                /*WriteCell Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                                /*CreateHCSM Class*/
CreateHCSM::CreateHCSM() : Action() {}

CreateHCSM::CreateHCSM(int set, double Delay, string Comment) : Action(set, Delay, Comment) {}

CreateHCSM::~CreateHCSM () {
    for (auto veh : createdVehicles){
        delete veh; veh = 0;
    }
    for (auto trig : createdTriggers) {
        delete trig; trig = 0;
    }
}

void CreateHCSM::addVehicle(Vehicle* veh){
    createdVehicles.push_back(veh);
    return;
}

void CreateHCSM::print(ostream &outStream, bool created) {
    string spaces = "      ";
    string spacesTillTitle = "    ";
    if (created) {
        spaces = "              ";
        spacesTillTitle = "            ";
    }
    outStream << spacesTillTitle << "HCSM CreateHcsm\n";
    this->printBasics(outStream, created);
    
    for (unsigned int i = 0; i < createdVehicles.size(); i++) {
        createdVehicles[i]->print(outStream);
    }
    for (auto trig: createdTriggers) {
        trig->filePrint (outStream);
    }        
    outStream << spacesTillTitle << "&&&&End&&&&\n";
    return;
}

void CreateHCSM::readFromFile(ifstream &inputStream) {
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
                Vehicle* newVehicle = new DDO;
                newVehicle->readFromFile(inputStream);
                newVehicle->setCreation(true);
                createdVehicles.push_back(newVehicle);
            }
            else if (current == "Ado") {
                Vehicle* newVehicle = new ADO;
                newVehicle->readFromFile(inputStream);
                newVehicle->setCreation(true);
                createdVehicles.push_back(newVehicle);
            }
            else if (current == "RoadPadTrigger") {
                Trigger* newTrigger = new RoadPadTrigger;
                newTrigger->fileRead(inputStream);
                newTrigger->setCreation(true);
                createdTriggers.push_back(newTrigger);
            }
            else if (current == "ExpressionTrigger") {
                Trigger* newTrigger = new ExpressionTrigger;
                newTrigger->fileRead(inputStream);
                newTrigger->setCreation(true);
                createdTriggers.push_back(newTrigger);
            }
            else if (current == "TimeTrigger") {
                Trigger* newTrigger = new TimeTrigger;
                newTrigger->fileRead(inputStream);
                newTrigger->setCreation(true);
                createdTriggers.push_back(newTrigger);
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
                                                /*CreateHCSM Class*/
/*********************************************************************************************************/

Action* readInAction(ifstream &inputStream) {
    string actionType;
    Action* act = 0;
    inputStream >> actionType;
    if (actionType == "WriteCell") {
        act = new WriteCell();
        act->readFromFile(inputStream);
    }
    else if (actionType == "SetButton") {
        act = new SetButton();
        act->readFromFile(inputStream);
    }
    else if (actionType == "DeleteHcsm") {
        act = new DeleteHCSM();
        act->readFromFile(inputStream);
    }
    else if (actionType == "ResetDial") {
        act = new ResetDial();
        act->readFromFile(inputStream);
    }
    else if (actionType == "CreateHcsm") {
        act = new CreateHCSM ();
        act->readFromFile(inputStream);
    }
    else if (actionType == "SetVar") {
        act = new SetVar();
        act->readFromFile(inputStream);
    }
    else if (actionType == "LogData") {
        act = new LogData();
        act->readFromFile(inputStream);
    }
    else if (actionType == "SetDial") {
        act = new SetDial();
        act->readFromFile(inputStream);
    }
    return act;
}

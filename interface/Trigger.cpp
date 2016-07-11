#include "Trigger.h"

/*********************************************************************************************************/
                                            /*Trigger Class*/                                        
Trigger::Trigger() : sequentialActions(false), oneShot(false), debounce(0), activationDelay(0), creationRadius(0), lifetime(0) {
    created = false;
}

Trigger::Trigger(bool seq, bool shot, int fireDel, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
    string Short, position Draw, position Pos, vector <Action*> &Act) : sequentialActions(seq), oneShot(shot), fireDelFrames(fireDel),debounce(Debounce),
    activationDelay(actDelay), creationRadius(creRad), lifetime(LifeTime), name(Name), longComment(Long),
    shortComment(Short), drawPosition(Draw), pos(Pos), Actions(Act) {
        created = false;
}

void Trigger::setCreation (bool createdByAction) {
    created = createdByAction;
    return;
}

string Trigger::getShortComment() {
    return this->shortComment;
}

string Trigger::getLongComment() {
    return this->longComment;
}

string Trigger::getName() {
    return this->name;
}

position Trigger::getPosition() {
    return this->pos;
}

void Trigger::addAction(Action *newAction) {
    Actions.push_back(newAction);
    return;
}

void Trigger::writeBasics(ostream &outStream) {
    string spaces = "  ";
    if (created) {
        spaces = "          ";
    }
    outStream << spaces << "Position " << std::scientific << std::setprecision(7);
    outStream << spaces << this->pos.x << " " << this->pos.y << " " << this->pos.z << " " << '\n';
    outStream << spaces << "LongComment " << this->longComment << " " << '\n';
    outStream << spaces << "ShortComment " << this->shortComment << " " << '\n';
    outStream << spaces << "ActvDel " << this->activationDelay << " " << '\n';
    outStream << spaces << "CrRad " << this->creationRadius << " " << '\n';
    outStream << spaces << "Debounce " << this->debounce << " " << '\n';
    outStream << spaces << "FireDelFrames " << this->fireDelFrames << " " << '\n';
    outStream << spaces << "Lifetime " << this->lifetime << " " << '\n';
    outStream << spaces << "Name " << this->name << " " << '\n';
    outStream << spaces << "OneShot " << this->oneShot << " " << '\n';
    outStream << spaces << "Priority " << this->priority << " " << '\n';
    outStream << spaces << "SeqAct " << this->sequentialActions << " " << '\n';
    outStream << spaces << "DrawPosition ";
    outStream << spaces << this->drawPosition.x << " " << this->drawPosition.y << " " << this->drawPosition.z << " " << '\n';
    return;
}

void Trigger::filePrint(ostream &) {}

void Trigger::fileRead(ifstream &) {}

void Trigger::printActions(ostream &outStream) {
    for (unsigned int i = 0; i < Actions.size(); i++) {
        Actions[i]->print(outStream, created);
    }
    return;
}

Trigger::~Trigger(){
    for (auto action : Actions) {
        delete action;
    }
}
                                            /*Trigger Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                            /*ExpressionTrigger Class*/
ExpressionTrigger::ExpressionTrigger() : Trigger() {}

ExpressionTrigger::ExpressionTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
    string Short, position Draw, position Pos, vector <Action*> &Act, string Expression) : Trigger(seq, shot, delay, Debounce, actDelay, creRad,
        LifeTime, Name, Long, Short, Draw, Pos, Act) {
    expression = Expression;
}

void ExpressionTrigger::filePrint(ostream &outStream) {
    string spaces = "  ";
    string spacesTillTitle = "";
    if (created) {
        
    }
    outStream << spacesTillTitle <<"HCSM ExpressionTrigger" << '\n';
    outStream << spaces << "Expression " << this->expression << " " << '\n';
    this->writeBasics(outStream);
    this->printActions(outStream);
    outStream << "&&&&End&&&&" << '\n';
    return;
}

void ExpressionTrigger::fileRead(ifstream &inputStream) {
    string current;
    inputStream >> current;
    //while not at the end, continue reading in
    while (current != "&&&&End&&&&") {
        //if if is the position
        if (current == "Position") {
            inputStream >> pos.x >> pos.y >> pos.z;
        }
        else if (current == "Expression") {
            getline(inputStream, expression);
        }
        else if (current == "LongComment") {
            getline(inputStream, this->longComment);
        }
        else if (current == "ShortComment") {
            getline(inputStream, this->shortComment);
        }
        else if (current == "ActvDel") {
            inputStream >> this->activationDelay;
        }
        else if (current == "CrRad") {
            inputStream >> this->creationRadius;
        }
        else if (current == "Debounce") {
            inputStream >> this->debounce;
        }
        else if (current == "FireDelFrames") {
            inputStream >> this->fireDelFrames;
        }
        else if (current == "Lifetime") {
            inputStream >> this->lifetime;
        }
        else if (current == "Name") {
            getline(inputStream, name);
        }
        else if (current == "OneShot") {
            inputStream >> this->oneShot;
        }
        else if (current == "Priority") {
            inputStream >> this->priority;
        }
        else if (current == "SeqAct") {
            inputStream >> this->sequentialActions;
        }
        else if (current == "DrawPosition") {
            inputStream >> drawPosition.x >> drawPosition.y >> drawPosition.z;
        }
        else if (current == "HCSM") {
            Actions.push_back(readInAction(inputStream));
        }
        inputStream >> current;
    }
    return;
}
                                            /*ExpressionTrigger Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                            /*RoadPadTrigger Class*/

RoadPadTrigger::RoadPadTrigger() : Trigger() {
    byTypeSet = true;
}

RoadPadTrigger::RoadPadTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
    string Short, position Draw, position Pos, vector <Action*> &Act, string TypeSet, string Path) : Trigger(seq, shot, delay, Debounce, actDelay,
        creRad, LifeTime, Name, Long, Short, Draw, Pos, Act), typeSet (TypeSet), path(Path), byTypeSet (true) {}

void RoadPadTrigger::setTypeSet (bool isTypeSet) {
    byTypeSet = isTypeSet;
    return;
}

void RoadPadTrigger::filePrint(ostream &outStream) {
    outStream << "HCSM RoadPadTrigger\n";
    this->writeBasics(outStream);
    if (byTypeSet) {
        outStream << "  ByTypeSet " << this->typeSet << "\n";
    }
    else {
        outStream << "  ByNameSet " << this->typeSet << "\n";
    }
    outStream << "  Path " << std::setprecision(7) << std::scientific << path << " \n";
    outStream << "  NthFromStart 0 \n  NthFromEnd 0 \n  VehicleAhead 0 \n  VehicleBehind 0 \n";
    this->printActions(outStream);
    outStream << "&&&&End&&&&\n";
    return;
}

void RoadPadTrigger::fileRead(ifstream &inputStream) {
    string current;
    inputStream >> current;

    //while not at the end, continue reading in
    while (current != "&&&&End&&&&") {
        //if if is the position
        if (current == "Position") {
            inputStream >> pos.x >> pos.y >> pos.z;
        }
        else if (current == "LongComment") {
            getline(inputStream, this->longComment);
        }
        else if (current == "ShortComment") {
            getline(inputStream, this->shortComment);
        }
        else if (current == "ActvDel") {
            inputStream >> this->activationDelay;
        }
        else if (current == "CrRad") {
            inputStream >> this->creationRadius;
        }
        else if (current == "Debounce") {
            inputStream >> this->debounce;
        }
        else if (current == "FireDelFrames") {
            inputStream >> this->fireDelFrames;
        }
        else if (current == "Lifetime") {
            inputStream >> this->lifetime;
        }
        else if (current == "Name") {
            getline(inputStream, name);
        }
        else if (current == "OneShot") {
            inputStream >> this->oneShot;
        }
        else if (current == "Priority") {
            inputStream >> this->priority;
        }
        else if (current == "SeqAct") {
            inputStream >> this->sequentialActions;
        }
        else if (current == "DrawPosition") {
            inputStream >> drawPosition.x >> drawPosition.y >> drawPosition.z;
        }
        else if (current == "HCSM") {
            Actions.push_back(readInAction(inputStream));
        }
        else if (current == "Path") {
            inputStream >> this->path;
        }
        else if (current == "ByTypeSet") {
            byTypeSet = true;
            inputStream >> this->typeSet;
        }
        else if (current == "ByNameSet") {
            byTypeSet = false;
            inputStream >> this->typeSet;
        }
        else if (current == "NthFromStart" || current == "NthFromEnd" || current == "VehicleAhead" || current == "VehicleBehind") {
            inputStream >> current;
        }
        inputStream >> current;
    }
    return;
}
                                            /*RoadPadTrigger Class*/
/*********************************************************************************************************/

/*********************************************************************************************************/
                                            /*TimeTrigger Class*/

TimeTrigger::TimeTrigger() : Trigger() {}

TimeTrigger::TimeTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
    string Short, position Draw, position Pos, vector <Action*> &Act, double Time) : Trigger(seq, shot, delay, Debounce, actDelay, creRad,
        LifeTime, Name, Long, Short, Draw, Pos, Act) {
    time = Time;
}

void TimeTrigger::filePrint(ostream &outStream) {
    outStream << "HCSM TimeTrigger" << '\n';
    outStream << "  Time " << std::setprecision(7) << std::scientific << this->time << " " << '\n';
    this->writeBasics(outStream);
    this->printActions(outStream);
    outStream << "&&&&End&&&&" << '\n';
    return;
}

void TimeTrigger::fileRead(ifstream &inputStream) {
    string current;
    inputStream >> current;

    //while not at the end, continue reading in
    while (current != "&&&&End&&&&") {
        //if if is the position
        if (current == "Position") {
            inputStream >> pos.x >> pos.y >> pos.z;
        }
        else if (current == "Time") {
            inputStream >> this->time;
        }
        else if (current == "LongComment") {
            getline(inputStream, this->longComment);
        }
        else if (current == "ShortComment") {
            getline(inputStream, this->shortComment);
        }
        else if (current == "ActvDel") {
            inputStream >> this->activationDelay;
        }
        else if (current == "CrRad") {
            inputStream >> this->creationRadius;
        }
        else if (current == "Debounce") {
            inputStream >> this->debounce;
        }
        else if (current == "FireDelFrames") {
            inputStream >> this->fireDelFrames;
        }
        else if (current == "Lifetime") {
            inputStream >> this->lifetime;
        }
        else if (current == "Name") {
            getline(inputStream, name);
        }
        else if (current == "OneShot") {
            inputStream >> this->oneShot;
        }
        else if (current == "Priority") {
            inputStream >> this->priority;
        }
        else if (current == "SeqAct") {
            inputStream >> this->sequentialActions;
        }
        else if (current == "DrawPosition") {
            inputStream >> pos.x >> pos.y >> pos.z;
        }
        else if (current == "HCSM") {
            Actions.push_back(readInAction(inputStream));
        }
        inputStream >> current;
    }
    return;
}
                                            /*TimeTrigger Class*/
/*********************************************************************************************************/

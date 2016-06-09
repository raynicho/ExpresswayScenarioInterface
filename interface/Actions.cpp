#include "Actions.h"

Action* readInAction(ifstream &inputStream, vector<Vehicle*>* vehiclesPtr) {
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
        act->readFromFile(inputStream, vehiclesPtr);
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

#include "VirtualObject.h"

VirtualObject::VirtualObject() : groupName("-1") {}

VirtualObject::VirtualObject(string GroupName, int Option, double Orientation, string Sol, string Name, string IconName, string LongComment, 
    string ShortComment, position Pos, position DrawPos, color fill, color boarder, drawSize Draw, vector<state> &States) : 
    groupName(GroupName), option(Option), orientation(Orientation), solName(Sol), name(Name), iconName(IconName), longComment(LongComment), 
    shortComment(ShortComment), pos(Pos), drawPosition(DrawPos), fillColor(fill), boarderColor(boarder), draw(Draw), states(States) {}

void VirtualObject::readFromFile(ifstream &inputStream) {
    string current;
    inputStream >> current;
    while (current != "&&&&End&&&&") {
        if (current == "GroupName") {
            getline(inputStream, groupName);
        }
        else if (current == "States") {
            state temp;
            //fill the vector
            for (int i = 0; i < 12; i++) {
                double state;
                inputStream >> state;
                temp.stateVector.push_back(state);
                inputStream >> current;
            }

            //get state 1 and state 2
            inputStream >> temp.stateOne;
            inputStream >> current;
            inputStream >> temp.stateTwo;

            //get the state string
            inputStream >> current;
            getline(inputStream, temp.stateString);

            //push back the state to the virtual object
            states.push_back(temp);
        }
        else if (current == "Option") {
            inputStream >> option;
        }
        else if (current == "Orientation") {
            inputStream >> orientation;
        }
        else if (current == "SolName") {
            inputStream >> solName;
        }
        else if (current == "Name") {
            getline(inputStream, name);
        }
        else if (current == "IconName") {
            getline(inputStream, iconName);
        }
        else if (current == "LongComment") {
            getline(inputStream, longComment);
        }
        else if (current == "ShortComment") {
            getline(inputStream, shortComment);
        }
        else if (current == "Position") {
            inputStream >> pos.x >> pos.y >> pos.z;
        }
        else if (current == "DrawPosition") {
            inputStream >> drawPosition.x >> drawPosition.y >> drawPosition.z;
        }
        else if (current == "FillColor") {
            inputStream >> fillColor.a >> fillColor.b >> fillColor.c >> fillColor.d;
        }
        else if (current == "BoarderColor") {
            inputStream >> boarderColor.a >> boarderColor.b >> boarderColor.c >> boarderColor.d;
        }
        else if (current == "DrawSize") {
            inputStream >> draw.width >> draw.heighth;
        }
        inputStream >> current;
    }
    return;
}

void VirtualObject::printStates(ostream &outStream) {
    outStream << std::setprecision(7) << std::scientific;
    for (auto s : states) {
        for (auto d : s.stateVector) {
            outStream << "  States " << d << '\n';
        }
        outStream << "  States " << s.stateOne << '\n';
        outStream << "  States " << s.stateTwo << '\n';
        outStream << "  States " << s.stateString << '\n';
    }
    return;
}

void VirtualObject::print(ostream &outStream) {
    outStream << "HCSM VirtualObject\n";
    if (groupName != "-1") {
        outStream << "  " << "GroupName " << groupName << '\n';
    }
    outStream << "  " << "TargetName \"\"\n";
    outStream << "  " << "DrawPosition " << std::setprecision(7) << std::scientific << drawPosition.x << " " << drawPosition.y
        << " " << drawPosition.z << '\n';
    outStream << "  " << "BlinkOff 1.0000000E+000\n";
    outStream << "  " << "BlinkOn 1.0000000E+000\n";
    outStream << "  " << "IsBlinking 0\n";
    outStream << "  " << "FillColor " << fillColor.a << " " << fillColor.b << " " << fillColor.c << " " << fillColor.d << '\n';
    outStream << "  " << "BoarderColor " << boarderColor.a << " " << boarderColor.b << " " << boarderColor.c << " " << boarderColor.d << '\n';
    outStream << "  " << "DrawSize " << draw.width << " " << draw.heighth << '\n';
    outStream << "  " << "IconName " << iconName << '\n';
    printStates(outStream);
    
    outStream << "  " << "DrawType 0\n";
    outStream << "  " << "LongComment " << longComment << '\n';
    outStream << "  " << "ShortComment " << shortComment << '\n';
    outStream << "  Orientation " << orientation << '\n';
    outStream << "  SolName " << solName << '\n';
    outStream << "  Name " << name << '\n';
    outStream << "  " << "Option " << option << '\n';
    outStream << "  Position " << pos.x << " " << pos.y << " " << pos.z << '\n';
    outStream << "&&&&End&&&&\n";
    return;
}

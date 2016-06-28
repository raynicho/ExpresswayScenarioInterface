#include "SCNHeader.h"

SCNHeader::SCNHeader() : LRIFile ("\"ES175.bli\""), ownVehiclePosition(0,0,0), ownVehicleOrientation(0, 0, 0), motionDrive("\"NadsCabMalibu\""),
    motionSettings("\"\""), headLightsOn(false), envMinute(0), envDay(1), envHour(12), envYear(2006), envMonth(6), envLat(35),
    envLong(122), envAlt(0), headlightCutOffDist(400), trailerType("\"\""), visualSettings("\"\""), sirensOverSpeed(0), collisionEffectMask(3),
    showCab(true), cabType("\"NadsCabTaurus\""), scenePosX(0), scenePosY(0), sceneZoom(0), cellName("\"OvVelLocal\""), writeCellName("\"SCC_Audio_Trigger\""){}

void SCNHeader::print(ostream &outStream) {
    outStream << "Header\n";
    outStream << "  LriFile " << LRIFile << '\n';
    outStream << "  InitialTireConditions 1 1 1 1 1 1 1 1 1 1\n";
    outStream << "  InitialBrakeConditions 0 1 1 1 1 1 1 1 1 1 1\n";
    outStream << "  SirenSpeed 6.2000000E+001\n";
    outStream << "  MotionDrive " << motionDrive << '\n';
    outStream << "  MotionSettings " << motionSettings << '\n';
    outStream << "  HeadlightsOn " << headLightsOn << '\n';
    outStream << "  EnvMinute " << envMinute << '\n';
    outStream << "  EnvDay " << envDay << '\n';
    outStream << "  EnvHour " << envHour << '\n';
    outStream << "  EnvYear " << envYear << '\n';
    outStream << "  EnvMonth " << envMonth << '\n';
    outStream << "  EnvLat " << std::setprecision(7) << std::scientific << envLat << '\n';
    outStream << "  EnvLong " << envLong << '\n';
    outStream << "  EnvAlt " << envAlt << '\n';
    outStream << "  BlankRed 0.0000000E+000\n";
    outStream << "  BlankGreen 0.0000000E+000\n";
    outStream << "  BlankBlue 0.0000000E+000\n";
    outStream << "  HeadlightsCutOffDist " << headlightCutOffDist << '\n';
    outStream << "  TrailerType " << trailerType << '\n';
    outStream << "  VisualSettings " << visualSettings << '\n';
    outStream << "  SirenOverSpeed " << sirensOverSpeed << '\n';
    outStream << "  CollisionEffectMask " << collisionEffectMask << '\n';
    outStream << "  ShowCab " << showCab << '\n';
    outStream << "  CabType " << cabType << '\n';
    outStream << "  OwnVehiclePosition " << ownVehiclePosition.x << " " << ownVehiclePosition.y << " " << ownVehiclePosition.z <<'\n';
    outStream << "  OwnVehicleOrientation " << ownVehicleOrientation.x << " " << ownVehicleOrientation.y << " " << ownVehicleOrientation.z << '\n';
    outStream << "  ScenPosX " << scenePosX << '\n';
    outStream << "  ScenPosY " << scenePosY << '\n';
    outStream << "  ScenZoom " << sceneZoom << '\n';
    outStream << "  CellName " << cellName << '\n';
    outStream << "  WriteCellName " << writeCellName << '\n';
    outStream << "&&&&End&&&&\n";
    return;
}

bool SCNHeader::readFromFile(ifstream &inputStream) {
    bool vehiclePositionFound = false;
    string current;
    inputStream >> current;
    while (current != "&&&&End&&&&") {
        if (current == "LriFile") {
            inputStream >> LRIFile;
        }
        else if (current == "OwnVehiclePosition") {
            vehiclePositionFound = true;
            inputStream >> ownVehiclePosition.x >> ownVehiclePosition.y >> ownVehiclePosition.z;
        }
        else if (current == "OwnVehicleOrientation") {
            inputStream >> ownVehicleOrientation.x >> ownVehicleOrientation.y >> ownVehicleOrientation.z;
        }
        else if (current == "MotionDrive") {
            inputStream >> motionDrive;
        }
        else if (current == "HeadlightsOn") {
            inputStream >> headLightsOn;
        }
        else if (current == "EnvMinute") {
            inputStream >> envMinute;
        }
        else if (current == "EnvDay") {
            inputStream >> envDay;
        }
        else if (current == "EnvHour") {
            inputStream >> envHour;
        }
        else if (current == "EnvYear") {
            inputStream >> envYear;
        }
        else if (current == "EnvMonth") {
            inputStream >> envMonth;
        }
        else if (current == "EnvLat") {
            inputStream >> envLat;
        }
        else if (current == "EnvLong") {
            inputStream >> envLong;
        }
        else if (current == "EnvAlt") {
            inputStream >> envAlt;
        }
        else if (current == "HeadlightsCutOffDist") {
            inputStream >> headlightCutOffDist;
        }
        else if (current == "TrailerType") {
            inputStream >> trailerType;
        }
        else if (current == "VisualSettings") {
            inputStream >> visualSettings;
        }
        else if (current == "SirenOverSpeed") {
            inputStream >> sirensOverSpeed;
        }
        else if (current == "CollisionEffectMask") {
            inputStream >> collisionEffectMask;
        }
        else if (current == "ShowCab") {
            inputStream >> showCab;
        }
        else if (current == "CabType") {
            inputStream >> cabType;
        }
        else if (current == "ScenPosX") {
            inputStream >> scenePosX;
        }
        else if (current == "ScenPosY") {
            inputStream >> scenePosY;
        }
        else if (current == "ScenZoom") {
            inputStream >> sceneZoom;
        }
        else if (current == "CellName") {
            inputStream >> cellName;
        }
        else if (current == "WriteCellName") {
            inputStream >> writeCellName;
        }
        inputStream >> current;
    }
    return vehiclePositionFound;
}

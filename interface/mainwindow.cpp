#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <QColorDialog>
#include <QColor>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList solModelChoices;
    solModelChoices << "DodgeNeon" << "Audi" << "Windstar" << "FordTaurus" << "LandRover" << "Ford_F150Xcab"
                    << "Deville" << "Towncar" << "BMW_StationWagon" << "PEUGEOT_306";
    ui->followSolModel->addItems(solModelChoices);
    ui->leadSolModel->addItems(solModelChoices);
    
    QStringList shapeOptions;
    shapeOptions << "Circle" << "Triangle" << "Octagon" << "Star" << "Diamond" << "Icon" << "Rectangle"
                 << "Hexagon";
    ui->shapeOption->addItems(shapeOptions);
                    
    QPixmap pix("C:/Users/raynicho/Desktop/SCNHighwayTemplate/Docs/UMTRI-logo.png");
    ui->umtriLogo->setPixmap(pix);
    
    //fill the base settings for testing purposes
    ui->leadSolModel->setCurrentIndex(4);
    ui->leadDistanceLineEdit->setText("-400");
    ui->leadMaxSpeedLineEdit->setText("100");
    ui->leadMinSpeedLineEdit->setText("50");
    ui->leadMaxAccelLineEdit->setText("4");
    ui->leadMaxDecel->setText("-4");
    
    ui->followSolModel->setCurrentIndex(6);
    ui->followDistanceLineEdit->setText("150");
    ui->followMaxSpeedLineEdit->setText("100");
    ui->followMinSpeedLineEdit->setText("0");
    ui->followMaxAccelLineEdit->setText("4");
    ui->followMaxDecel->setText("-4");
}

//requires:
//modifies:
//effects:
void MainWindow::getSettings() {
    //load the lead vehicle settings
    FVLVSettings tmpFVLV;
    tmpFVLV.SOLModel = ui->followSolModel->currentText().toStdString();
    tmpFVLV.SOLModel = (std::string)"\"" + tmpFVLV.SOLModel + (std::string)"\"";
    tmpFVLV.distance = ui->followDistanceLineEdit->text().toDouble(false);
    tmpFVLV.maxSpeed = ui->followMaxSpeedLineEdit->text().toDouble(false);
    tmpFVLV.minSpeed = ui->followMinSpeedLineEdit->text().toDouble(false);
    tmpFVLV.maxAccel = ui->followMaxAccelLineEdit->text().toDouble(false);
    tmpFVLV.maxDeccel = ui->followMaxDecel->text().toDouble(false);
    settings.followVehicle = tmpFVLV;
    
    //load the follow vehicle settings
    tmpFVLV.SOLModel = ui->leadSolModel->currentText().toStdString();
    tmpFVLV.SOLModel = (std::string)"\"" + tmpFVLV.SOLModel + (std::string)"\"";
    tmpFVLV.distance = ui->leadDistanceLineEdit->text().toDouble(false);
    tmpFVLV.maxSpeed = ui->leadMaxSpeedLineEdit->text().toDouble(false);
    tmpFVLV.minSpeed = ui->leadMinSpeedLineEdit->text().toDouble(false);
    tmpFVLV.maxAccel = ui->leadMaxAccelLineEdit->text().toDouble(false);
    tmpFVLV.maxDeccel = ui->leadMaxDecel->text().toDouble(false);
    settings.leadVehicle = tmpFVLV;
    
    //load the fcw
    FCW warnings;
    if (ui->fcwOn->isChecked()) {
        //frequency, position, shape, icon name, color, is checked,
        warnings.checked = true;
        warnings.frequency = ui->frequency->text().toDouble(false);
        warnings.pos.x = ui->fcwPositionX->text().toDouble(false);
        warnings.pos.y = ui->fcwPositionY->text().toDouble(false);
        warnings.pos.z = ui->fcwPositionZ->text().toDouble(false);
        switch (ui->shapeOption->currentIndex()) {
            case (1) : {
                warnings.imageShape = Circle;
            }
            case (2) : {
                warnings.imageShape = Triangle;
            }
            case (3) : {
                warnings.imageShape = Octagon;
            }
            case (4) : {
                warnings.imageShape = Star;
            }
            case (5) : {
                warnings.imageShape = Diamond;
            }
            case (6) : {
                warnings.imageShape = Icon;
                warnings.iconName = ui->fcwIconName->text().toStdString();
            }
            case (7) : {
        
            }
            default : {
            
            }
        }
        
        //if animation is checked, load animation, set animation on
        if (ui->animationOn->isChecked()) {
            animation tmpAnimation;
            tmpAnimation.checked = true;
            tmpAnimation.start.x = ui->animationStartX->text().toDouble(false);
            tmpAnimation.start.y = ui->animationStartY->text().toDouble(false);
            tmpAnimation.start.z = ui->animationStartZ->text().toDouble(false);
            tmpAnimation.end.x = ui->animationEndX->text().toDouble(false);
            tmpAnimation.end.y = ui->animationEndY->text().toDouble(false);
            tmpAnimation.end.z = ui->animationEndZ->text().toDouble(false);
            settings.FCWanimation = tmpAnimation;
        }
    }
        
    //load number of trials
    settings.numberTrials = ui->lengthOfRoadLineEdit->text().toDouble(false);
    
    //load boolean values
    settings.showBlindSpot = ui->showBlindSpotWarning->isChecked();
    settings.generateTraffic = ui->generateOpposingTraffic->isChecked();
    if (settings.generateTraffic) {
        settings.numberCarsPerTrial = ui->numberOpposingVehicles->text().toInt(false);
        settings.numberCars = ui->numberCars->text().toInt(false);
        settings.numberTrucks = ui->numberTrucks->text().toInt(false);
    }
    return;
}

//requires:
//modifies:
//effects:
roadSideControl MainWindow::getRoadSideTrial() {
    roadSideControl roadSide;
    //if roadside is checked
    if (ui->roadSideTrialOn->isChecked()) {
        //set the bool to checked
        roadSide.checked = true;
        
        //if remain station stationary is checked
        if (ui->roadSideTrialRemainStationary->isChecked()) {
            //set the option
            roadSide.movementOption = 0;
        }   
        //else if the pull out in front is checked
        else if (ui->roadSideTrialPullFront->isChecked()) {
            //set the option
            roadSide.movementOption = 1;
            
            //get and set the speed
            roadSide.speed = ui->roadSideTrialPullFrontSpeed->text().toDouble(false);
            roadSide.distance = ui->roadSideTrialPullFrontDistance->text().toDouble(false);
        }
        //else if the drive on shoulder was checked
        else if (ui->roadSideTrialDriveOnShoulder->isChecked()) {
            //set the option
            roadSide.movementOption = 2;
            
            //get the speed
            roadSide.speed = ui->roadSideTrialDriveOnShoulderSpeed->text().toDouble(false);
        }
        //else if the pull out in front and stop is selected
        else {
            //set the option        
            roadSide.movementOption = 3;
                    
            //get the speed
            roadSide.speed = ui->roadSideTrialPullFrontStopSpeed->text().toDouble(false);
            
            //get the distance
            roadSide.distance = ui->roadSideTrialPullFrontStopDistance->text().toDouble(false);
        }
        
        //blinker control none
        if (ui->roadSideTrialBlinkerNone->isChecked()) {
            roadSide.blinker = None;
        }
        
        //blinker control right
        else if (ui->roadSideTrialBlinkerRight->isChecked()) {
            roadSide.blinker = Right;
        }
        
        //blinker control left
        else if (ui->roadSideTrialBlinkerLeft->isChecked()) {
            roadSide.blinker = Left;
        }
        
        //blinker control hazards
        else {
            roadSide.blinker = Hazards;
        }
        
        //get the FCW
        if (ui->roadSideTrialAddToList->isChecked()){
            roadSide.addToList = true;
        }
        
        //get the deletion
        if (ui->roadSideTrialDeletionPullToSide) {
            roadSide.deletionOption = 0;
        }
        else { 
            roadSide.deletionOption = 1;   
        }
    }
    return roadSide;
}

//requires:
//modifies:
//effects:
void MainWindow::loadRoadSideTrial(roadSideControl &roadSide){
    //if road side is selected
    if (roadSide.checked) {
        //set the checked box
        ui->roadSideTrialOn->setChecked(true);
        
        switch (roadSide.movementOption) {
            //if movement option is 0
            case(0): {
                //set remain stationary on
                ui->roadSideTrialRemainStationary->setChecked(true);
            
                //set pull out in front off and speed empty
                ui->roadSideTrialPullFront->setChecked(false);
                ui->roadSideTrialPullFrontSpeed->setText("");
                ui->roadSideTrialPullFrontDistance->setText("");
                
                //set drive on shoulder off and speed empty
                ui->roadSideTrialDriveOnShoulder->setChecked(false);
                ui->roadSideTrialDriveOnShoulderSpeed->setText("");
                
                //set pull out in front and stop off, clear speed and distance
                ui->roadSideTrialPullFrontStop->setChecked(false);
                ui->roadSideTrialPullFrontStopSpeed->setText("");
                ui->roadSideTrialPullFrontStopDistance->setText("");
                break;
            }
            
            //else if movement option is 1
            case (1): {
            //set pull out in front on and speed
                ui->roadSideTrialPullFront->setChecked(true);
                ui->roadSideTrialPullFrontSpeed->setText(QString::number(roadSide.speed));
                ui->roadSideTrialPullFrontDistance->setText(QString::number(roadSide.distance));
        
                //set remain stationary off
                ui->roadSideTrialRemainStationary->setChecked(false);
            
                //set drive on shoulder off and clear speed
                ui->roadSideTrialDriveOnShoulder->setChecked(false);
                ui->roadSideTrialDriveOnShoulderSpeed->setText("");
            
                //set pull out in front and stop off, clear speed and distance
                ui->roadSideTrialPullFrontStop->setChecked(false);
                ui->roadSideTrialPullFrontStopSpeed->setText("");
                ui->roadSideTrialPullFrontStopDistance->setText("");
                break;
            }
        
            //else if movement option is 2
            case (2) : {
                //set drive on shoulder on and set speed
                ui->roadSideTrialDriveOnShoulder->setChecked(true);
                ui->roadSideTrialDriveOnShoulderSpeed->setText(QString::number(roadSide.speed));
            
                //set remain stationary off
                ui->roadSideTrialRemainStationary->setChecked(false);
            
                //set pull out in front off and clear speed
                ui->roadSideTrialPullFront->setChecked(false);
                ui->roadSideTrialPullFrontSpeed->setText("");
                ui->roadSideTrialPullFrontDistance->setText("");
    
                //set pull out in front and stop off, clear distance and speed
                ui->roadSideTrialPullFrontStop->setChecked(false);
                ui->roadSideTrialPullFrontStopSpeed->setText("");
                ui->roadSideTrialPullFrontStopDistance->setText("");
                break;
            }
            
            //else
            default: {
                //set pull out in front and stop on, set distance and speed
                ui->roadSideTrialPullFrontStop->setChecked(true);
                ui->roadSideTrialPullFrontStopSpeed->setText(QString::number(roadSide.speed));
                ui->roadSideTrialPullFrontStopDistance->setText(QString::number(roadSide.distance));
            
                //set remain stationary off
                ui->roadSideTrialRemainStationary->setChecked(false);
    
                //set pull out in front off and clear speed
                ui->roadSideTrialPullFront->setChecked(false);
                ui->roadSideTrialPullFrontSpeed->setText("");
                ui->roadSideTrialPullFrontDistance->setText("");
    
                //set drive on shoulder off and clear speed
                ui->roadSideTrialDriveOnShoulder->setChecked(false);
                ui->roadSideTrialDriveOnShoulderSpeed->setText("");
                break;
            }
        }
        
        switch (roadSide.blinker) {
            //if the blinker option is none
            case (None): {
                //set none on
                ui->roadSideTrialBlinkerNone->setChecked(true);
                
                //set hazards off
                ui->roadSideTrialBlinkerHazards->setChecked(false);
                
                //set right off
                ui->roadSideTrialBlinkerRight->setChecked(false);
                
                //set left off
                ui->roadSideTrialBlinkerLeft->setChecked(false);
                break;
            }
            //else if the blinker option is right
            case (Right) : {
                //set right on
                ui->roadSideTrialBlinkerRight->setChecked(true);
                
                //set hazards off
                ui->roadSideTrialBlinkerHazards->setChecked(false);
                
                //set none off
                ui->roadSideTrialBlinkerNone->setChecked(false);
                
                //set left off
                ui->roadSideTrialBlinkerLeft->setChecked(false);
                break;
            }
            //else if the blinker option is left
            case (Left) : { 
                //set left on
                ui->roadSideTrialBlinkerLeft->setChecked(true);
                
                //set right off
                ui->roadSideTrialBlinkerRight->setChecked(false);
                
                //set hazards off
                ui->roadSideTrialBlinkerHazards->setChecked(false);
                
                //set none off
                ui->roadSideTrialBlinkerNone->setChecked(false);
                break;
            }
            //else
            default : {
                //hazards on
                ui->roadSideTrialBlinkerHazards->setChecked(true);
            
                //right off
                ui->roadSideTrialBlinkerRight->setChecked(false);
            
                //left off
                ui->roadSideTrialBlinkerLeft->setChecked(false);
            
                //none off
                ui->roadSideTrialBlinkerNone->setChecked(false);
                break;
            }
        }
        
        switch (roadSide.deletionOption) {
            //if deletion option is 0    
            case (0) : {
                //set pull to side on
                ui->roadSideTrialDeletionPullToSide->setChecked(true);
            
                //set slow down to off
                ui->roadSideTrialDeletionSlowDown->setChecked(false);
                break;
            }
            //else
            default: {
                //slow down to on
                ui->roadSideTrialDeletionSlowDown->setChecked(true);
            
                //pull to side off
                ui->roadSideTrialDeletionPullToSide->setChecked(false);
                break;
            }
        }
        //if addtolist
        if (roadSide.addToList) {
            //set add to list on
            ui->roadSideTrialAddToList->setChecked(true);
        }
        
        else {
            ui->roadSideTrialAddToList->setChecked(false);
        }
    }
    
    //else road side is not selected
    else {
        //uncheck the box
        ui->roadSideTrialOn->setChecked(false);
        
        //check remain stationary
        ui->roadSideTrialRemainStationary->setChecked(true);
        
        //uncheck pull out in front and clear text
        ui->roadSideTrialPullFront->setChecked(false);
        ui->roadSideTrialPullFrontSpeed->setText("");
        
        //uncheck drive on shoulder and clear text
        ui->roadSideTrialDriveOnShoulder->setChecked(false);
        ui->roadSideTrialDriveOnShoulderSpeed->setText("");
        
        //uncheck pull out in front and stop, clear distance and speed
        ui->roadSideTrialPullFrontStop->setChecked(false);
        ui->roadSideTrialPullFrontStopSpeed->setText("");
        ui->roadSideTrialPullFrontStopDistance->setText("");
        
        //set none on
        ui->roadSideTrialBlinkerNone->setChecked(true);
        
        //set hazards off
        ui->roadSideTrialBlinkerHazards->setChecked(false);
        
        //set right off
        ui->roadSideTrialBlinkerRight->setChecked(false);
        
        //set left off
        ui->roadSideTrialBlinkerLeft->setChecked(false);
             
        //set pull to side on
        ui->roadSideTrialDeletionPullToSide->setChecked(true);
    
        //set slow down to off
        ui->roadSideTrialDeletionSlowDown->setChecked(false);
        
        //uncheck fcw add to list
        ui->roadSideTrialAddToList->setChecked(false);
    }
    return;
}

//requires:
//modifies:
//effects:
leftLaneControl MainWindow::getLeftLaneTrial(){
    leftLaneControl leftLane;
    //if left lane is checked
    if (ui->leftLaneTrialOn->isChecked()) {
        //set the checked bool
        leftLane.checked = true;
        
        //if blind spot is selected
        if (ui->leftLaneTrialBlindSpot->isChecked()) {
            //set the movement option
            leftLane.movementOption = 0;
        }
        //else if cut behind is selected
        else if (ui->leftLaneTrialCutBehind->isChecked()) {
            //set the movement option
            leftLane.movementOption = 1;
        }
        //else if cut in front is selected
        else if (ui->leftLaneTrialCutFront->isChecked()) {
            //set the movement option
            leftLane.movementOption = 2;
            
            //get distance and speed
            leftLane.distance = ui->leftLaneTrialCutFrontDistance->text().toDouble(false);
            leftLane.speed = ui->leftLaneTrialCutFrontSpeed->text().toDouble(false);
        }
        //else it is remain in lane
        else {
            //set the movement option
            leftLane.movementOption = 3;
            
            //if the absolute is checked
            if (ui->leftLaneTrialRemainLaneAbsolute->isChecked()) {
                //set the lane option
                leftLane.laneOption = 0;
                
                //get the absolute speed
                leftLane.speed = ui->leftLaneTrialRemainLaneAbsoluteSpeed->text().toDouble(false);
            }
            //else it is the match driver
            else {
                //set the lane option
                leftLane.laneOption = 1;
            }
        }
        
        //blinker control none
        if (ui->leftLaneTrialBlinkerNone->isChecked()) {
            leftLane.blinker = None;
        }
        
        //blinker option right
        else if (ui->leftLaneTrialBlinkerRight->isChecked()) {
            leftLane.blinker = Right;
        }
        
        //blinker option left
        else if (ui->leftLaneTrialBlinkerLeft->isChecked()) {
            leftLane.blinker = Left;
        }
    
        //blinker option hazards
        else {
            leftLane.blinker = Hazards;
        }
        
        //creation option behind
        if (ui->leftLaneTrialCreationBehind->isChecked()) {
            leftLane.creationOption = 0;
        }
        
        //cration option front
        else {
            leftLane.creationOption = 1;
        }
        
        //get the creation distance
        leftLane.creationDistance = ui->leftLaneTrialDistanceFromET->text().toDouble(false);
        
        //if the fcw is selected
        if (ui->leftLaneTrialAddToFCW->isChecked()){
            leftLane.addToList = true;
        }
        else {
            leftLane.addToList = false;
        }
    }
    return leftLane;
}

//requires:
//modifies:
//effects:
void MainWindow::loadLeftLaneTrial(leftLaneControl &leftLane) {
    //if the left lane is checked
    if (leftLane.checked) {
        //check the left lane check box
        ui->leftLaneTrialOn->setChecked(true);
        
        //switch over the movement option
        switch (leftLane.movementOption){
    
            //case 0
            case (0) : {
                //check blind spot
                ui->leftLaneTrialBlindSpot->setChecked(true);
    
                //uncheck cut behind driver
                ui->leftLaneTrialCutBehind->setChecked(false);
                
                //uncheck cut in front of driver, clear speed and distance
                ui->leftLaneTrialCutFront->setChecked(false);
                ui->leftLaneTrialCutFrontDistance->setText("");
                ui->leftLaneTrialCutFrontSpeed->setText("");
    
                //uncheck remain in lane, check match and uncheck absolute, clear absolute
                ui->leftLaneTRialRemainLane->setChecked(false);
                ui->leftLaneTrialRemainLaneMatchET->setChecked(true);
                ui->leftLaneTrialRemainLaneAbsolute->setChecked(false);
                ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText("");
                break;
            }   
            //case 1
            case (1) : {
                //uncheck blind spot
                ui->leftLaneTrialBlindSpot->setChecked(false);
                
                //check cut behind driver
                ui->leftLaneTrialCutBehind->setChecked(true);
    
                //uncheck cut in front of driver, clear speed and distance
                ui->leftLaneTrialCutFront->setChecked(false);
                ui->leftLaneTrialCutFrontDistance->setText("");
                ui->leftLaneTrialCutFrontSpeed->setText("");

                //uncheck remain in lane, check match and uncheck absolute, clear absolute
                ui->leftLaneTRialRemainLane->setChecked(false);
                ui->leftLaneTrialRemainLaneMatchET->setChecked(true);
                ui->leftLaneTrialRemainLaneAbsolute->setChecked(false);
                ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText("");
                break;
            }
            //case 2
            case (2) : {
                //uncheck blind spot
                ui->leftLaneTrialBlindSpot->setChecked(false);
    
                //uncheck cut behind driver
                ui->leftLaneTrialCutBehind->setChecked(false);
    
                //check cut in behind driver, set speed and distance
                ui->leftLaneTrialCutFront->setChecked(true);
                ui->leftLaneTrialCutFrontDistance->setText(QString::number(leftLane.distance));
                ui->leftLaneTrialCutFrontSpeed->setText(QString::number(leftLane.speed));
    
                //uncheck remain in lane, check match and uncheck absolute, clear absolute
                ui->leftLaneTRialRemainLane->setChecked(false);
                ui->leftLaneTrialRemainLaneMatchET->setChecked(true);
                ui->leftLaneTrialRemainLaneAbsolute->setChecked(false);
                ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText("");
                break;
            }
            //default
            default : {
                //uncheck blind spot
                ui->leftLaneTrialBlindSpot->setChecked(false);
            
                //uncheck cut behind driver
                ui->leftLaneTrialCutBehind->setChecked(false);
    
                //uncheck cut in front of driver, clear speed and distance
                ui->leftLaneTrialCutFront->setChecked(false);
                ui->leftLaneTrialCutFrontDistance->setText("");
                ui->leftLaneTrialCutFrontSpeed->setText("");
    
                //check remain in lane
                ui->leftLaneTRialRemainLane->setChecked(true);
                    //swtich lane option
                    switch (leftLane.laneOption) {
                        //case 0
                        case (0) : {
                            //check absolute and set speed
                            ui->leftLaneTrialRemainLaneAbsolute->setChecked(true);
                            ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText(QString::number(leftLane.speed));
                            
                            //uncheck match
                            ui->leftLaneTrialRemainLaneMatchET->setChecked(false);    
                            break;
                        }
                        //default
                        default : {
                            //uncheck absolute, clear speed
                            ui->leftLaneTrialRemainLaneAbsolute->setChecked(false);
                            ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText("");
    
                            //check match
                            ui->leftLaneTrialRemainLaneMatchET->setChecked(true);
                            break;
                        }
                    }
                break;
            }             
        }
        //switch blinker control
        switch (leftLane.blinker) { 
            //case hazards
            case (Hazards) : {
                ui->leftLaneTrialBlinkerHazards->setChecked(true);
                ui->leftLaneTrialBlinkerLeft->setChecked(false);
                ui->leftLaneTrialBlinkerRight->setChecked(false);
                ui->leftLaneTrialBlinkerNone->setChecked(false);
                break;
            }
            
            //case right
            case (Right) : {
                ui->leftLaneTrialBlinkerHazards->setChecked(false);
                ui->leftLaneTrialBlinkerLeft->setChecked(false);
                ui->leftLaneTrialBlinkerRight->setChecked(true);
                ui->leftLaneTrialBlinkerNone->setChecked(false);
                break;
            }
        
            //case left
            case (Left) : { 
                ui->leftLaneTrialBlinkerHazards->setChecked(false);
                ui->leftLaneTrialBlinkerLeft->setChecked(true);
                ui->leftLaneTrialBlinkerRight->setChecked(false);
                ui->leftLaneTrialBlinkerNone->setChecked(false);
                break;
            }
    
            //default
            default : {
                ui->leftLaneTrialBlinkerHazards->setChecked(false);
                ui->leftLaneTrialBlinkerLeft->setChecked(false);
                ui->leftLaneTrialBlinkerRight->setChecked(false);
                ui->leftLaneTrialBlinkerNone->setChecked(true);
                break;
            }
        }
        //switch creation option
        switch (leftLane.creationOption) { 
            //case 0
            case (0) : {
                ui->leftLaneTrialCreationBehind->setChecked(true);
                ui->leftLaneTrialCreationFront->setChecked(false);
                break;
            }
    
            //default
            default : { 
                ui->leftLaneTrialCreationBehind->setChecked(false);
                ui->leftLaneTrialCreationFront->setChecked(true);
                break;
            }
        }
        
        //load the creation distance
        ui->leftLaneTrialDistanceFromET->setText(QString::number(leftLane.creationDistance));
        
        //if addtolist
        if (leftLane.addToList) {
            //check add to list
            ui->leftLaneTrialAddToFCW->setChecked(true);
        }
        //else
        else {
            //uncheck add to list
            ui->leftLaneTrialAddToFCW->setChecked(false);
        }
    }
    //else if its not checked
    else {
        //uncheck the left lane check box
        ui->leftLaneTrialOn->setChecked(false);
        
        //set the movement option
        ui->leftLaneTrialBlindSpot->setChecked(true);
        ui->leftLaneTrialCutBehind->setChecked(false);
        ui->leftLaneTrialCutFront->setChecked(false);
        ui->leftLaneTrialCutFrontDistance->setText("");
        ui->leftLaneTrialCutFrontSpeed->setText("");
        ui->leftLaneTRialRemainLane->setChecked(false);
        ui->leftLaneTrialRemainLaneMatchET->setChecked(true);
        ui->leftLaneTrialRemainLaneAbsolute->setChecked(false);
        ui->leftLaneTrialRemainLaneAbsoluteSpeed->setText("");
        
        //set the blinker control
        ui->leftLaneTrialBlinkerHazards->setChecked(false);
        ui->leftLaneTrialBlinkerLeft->setChecked(false);
        ui->leftLaneTrialBlinkerRight->setChecked(false);
        ui->leftLaneTrialBlinkerNone->setChecked(true);
        
        //set the creation option
        ui->leftLaneTrialCreationBehind->setChecked(true);
        ui->leftLaneTrialCreationFront->setChecked(false);
        
        //reset the creation distance
        ui->leftLaneTrialDistanceFromET->setText("");
        
        //set the fcw add to list
        ui->leftLaneTrialAddToFCW->setChecked(false);
    }
    return;
}

//requires:
//modifies:
//effects:
FVLVInstructions MainWindow::getLeadTrial() {
    FVLVInstructions lead;
    //if the lead vehicle is checked
    if (ui->leadTrialOn->isChecked()) {
        //set the bool for the lead vehicle being checked
        lead.checked=true;
        
        //get the lead distance
        lead.maxFollow = (ui->leadTrialMaxLeadDistance->text()).toDouble(false);
        
        //if the velocity change is checked
        if (ui->leadTrialVelocityChange->isChecked()) {
            //set the bool
            lead.velocityChange = true;
            
            //if the match is checked
            if (ui->leadTrialMatchExternalDriver->isChecked()) {
                //set the option
                lead.velocityChangeOption = 0; 
            }
            
            //otherwise its absolute
            else {
                //set the option
                lead.velocityChangeOption = 1;
                
                //set the absolute speed
                lead.absoluteSpeed = (ui->leadTrialVelocityChangeAbsoluteSpeed->text()).toDouble(false);
            }
        }
        
        //otherwise set it too false
        else {
            lead.velocityChange = false;
        }
        
        //if the force lane change is selected
        if (ui->leadTrialForceLaneChange->isChecked()) {
            //set the bool
            lead.forceLaneChange = true;
            
            //get the acceleration and speed
            lead.forceLaneSpeed = ui->leadTrialForceLaneChangeSpeed->text().toDouble(false);
            lead.forceLaneAcceleration = ui->leadTrialForceLaneChangeAcceleration->text().toDouble(false);
        }
        //otherwise set it to false
        else {
            lead.forceLaneChange = false;
        }
    }
    return lead;
}

//requires:
//modifies:
//effects:
void MainWindow::loadLeadTrial(FVLVInstructions &tmp){
    //if its the lead vehicle is checked
    if (tmp.checked) {
        //check the box
        ui->leadTrialOn->setCheckState(Qt::Checked);

        //set the dsitance
        ui->leadTrialMaxLeadDistance->setText(QString::number(tmp.maxFollow));

        //if the velocity change is checked
        if (tmp.velocityChange) {
            //check the box
            ui->leadTrialVelocityChange->setCheckState(Qt::Checked);

            //set the speed option
            //match
            if (tmp.velocityChangeOption == 0) {
                //check the box
                ui->leadTrialMatchExternalDriver->setChecked(true);

                //uncheck the absolute box and clear the line edit
                ui->leadTrialVelocityChangeAbsolute->setChecked(false);
                ui->leadTrialVelocityChangeAbsoluteSpeed->setText("");
            }
            //absolute
            else {
                //check the box and fill the line edit
                ui->leadTrialVelocityChangeAbsolute->setChecked(true);
                ui->leadTrialVelocityChangeAbsoluteSpeed->setText(QString::number(tmp.absoluteSpeed));

                //uncheck the match box
                ui->leadTrialMatchExternalDriver->setChecked(false);
            }
        }

        //if the velocity change is not checked
        else {
            //uncheck the box
            ui->leadTrialVelocityChange->setCheckState(Qt::Unchecked);
            
            //check match and uncheck absolute
            ui->leadTrialMatchExternalDriver->setChecked(true);
            ui->leadTrialVelocityChangeAbsolute->setChecked(false);
            
            //reset absolute speed
            ui->leadTrialVelocityChangeAbsoluteSpeed->setText("");
        }
        
        //if the force lane change is checked
        if (tmp.forceLaneChange) {
            //check the box
            ui->leadTrialForceLaneChange->setCheckState(Qt::Checked);
            
            //set the speed
            ui->leadTrialForceLaneChangeSpeed->setText(QString::number(tmp.forceLaneSpeed));
            
            //set the acceleration
            ui->leadTrialForceLaneChangeAcceleration->setText(QString::number(tmp.forceLaneAcceleration));
        }
        //if the force lane change is not checked
        else {
            //uncheck the box
            ui->leadTrialForceLaneChange->setCheckState(Qt::Unchecked);
            
            //clear the speed and acceleration
            ui->leadTrialForceLaneChangeAcceleration->setText("");
            ui->leadTrialForceLaneChangeSpeed->setText("");
        }

    }
    //if the lead vehicle is not checked
    else {
        //uncheck the follow vehicle
        ui->leadTrialOn->setCheckState(Qt::Unchecked);
        
        //clear the max follow distance
        ui->leadTrialMaxLeadDistance->setText("");
        
        //set velocity change off
        ui->leadTrialVelocityChange->setCheckState(Qt::Unchecked);
        
        //uncheck absolute and check match
        ui->leadTrialVelocityChangeAbsolute->setChecked(false);
        ui->leadTrialMatchExternalDriver->setChecked(true);
        
        //clear absolute speed lin edit
        ui->leadTrialVelocityChangeAbsoluteSpeed->setText("");
        
        //uncheck force lane change
        ui->leadTrialForceLaneChange->setCheckState(Qt::Unchecked);
        
        //clear the speed
        ui->leadTrialForceLaneChangeSpeed->setText("");
        
        //clear the acceleration
        ui->leadTrialForceLaneChangeAcceleration->setText("");
    }
    return;
}

//requires:
//modifies:
//effects:
FVLVInstructions MainWindow::getFollowTrial() {
    FVLVInstructions follow;
    //if the follow vehicle is checked
    if (ui->followTrialOn->isChecked()) {
        //set the bool for the follow vehicle being checked
        follow.checked=true;
        
        //get the follow distance
        follow.maxFollow = (ui->followTrialDistance->text()).toDouble(false);
        
        //if the velocity change is checked
        if (ui->followTrialVelocityChange->isChecked()) {
            //set the bool
            follow.velocityChange = true;
            
            //if the match is checked
            if (ui->followTrialVelocityChangeMatchExternalDriver->isChecked()) {
                //set the option
                follow.velocityChangeOption = 0; 
            }
            
            //otherwise its absolute
            else {
                //set the option
                follow.velocityChangeOption = 1;
                
                //set the absolute speed
                follow.absoluteSpeed = (ui->followTrialVelocityChangeAbsoluteLineEdit->text()).toDouble(false);
            }
        }
        
        //otherwise set it too false
        else {
            follow.velocityChange = false;
        }
        
        //if the force lane change is selected
        if (ui->followTrialForceLaneChange->isChecked()) {
            //set the bool
            follow.forceLaneChange = true;
            
            //get the acceleration and speed
            follow.forceLaneSpeed = ui->followTrialForceLaneChangeSpeed->text().toDouble(false);
            follow.forceLaneAcceleration = ui->followTrialForceLaneChangeAcceleration->text().toDouble(false);
        }
        //otherwise set it to false
        else {
            follow.forceLaneChange = false;
        }
    }
    return follow;
}

//requires:
//modifies:
//effects:
void MainWindow::loadFollowTrial(FVLVInstructions &tmp){
    //if its the follow vehicle is checked
    if (tmp.checked) {
        //check the box
        ui->followTrialOn->setCheckState(Qt::Checked);

        //set the dsitance
        ui->followTrialDistance->setText(QString::number(tmp.maxFollow));

        //if the velocity change is checked
        if (tmp.velocityChange) {
            //check the box
            ui->followTrialVelocityChange->setCheckState(Qt::Checked);

            //set the speed option
            //match
            if (tmp.velocityChangeOption == 0) {
                //check the box
                ui->followTrialVelocityChangeMatchExternalDriver->setChecked(true);

                //uncheck the absolute box and clear the line edit
                ui->followTrialVelocityChangeAbsolute->setChecked(false);
                ui->followTrialVelocityChangeAbsoluteLineEdit->setText("");
            }
            //absolute
            else {
                //check the box and fill the line edit
                ui->followTrialVelocityChangeAbsolute->setChecked(true);
                ui->followTrialVelocityChangeAbsoluteLineEdit->setText(QString::number(tmp.absoluteSpeed));

                //uncheck the match box
                ui->followTrialVelocityChangeMatchExternalDriver->setChecked(false);
            }
        }

        //if the velocity change is not checked
        else {
            //uncheck the box
            ui->followTrialVelocityChange->setCheckState(Qt::Unchecked);
            
            //check match and uncheck absolute
            ui->followTrialVelocityChangeMatchExternalDriver->setChecked(true);
            ui->followTrialVelocityChangeAbsolute->setChecked(false);
            
            //reset absolute speed
            ui->followTrialVelocityChangeAbsoluteLineEdit->setText("");
        }
        
        //if the force lane change is checked
        if (tmp.forceLaneChange) {
            //check the box
            ui->followTrialForceLaneChange->setCheckState(Qt::Checked);
            
            //set the speed
            ui->followTrialForceLaneChangeSpeed->setText(QString::number(tmp.forceLaneSpeed));
            
            //set the acceleration
            ui->followTrialForceLaneChangeAcceleration->setText(QString::number(tmp.forceLaneAcceleration));
        }
        //if the force lane change is not checked
        else {
            //uncheck the box
            ui->followTrialForceLaneChange->setCheckState(Qt::Unchecked);
            
            //clear the speed and acceleration
            ui->followTrialForceLaneChangeAcceleration->setText("");
            ui->followTrialForceLaneChangeSpeed->setText("");
        }

    }
    //if the follow vehicle is not checked
    else {
        //uncheck the follow vehicle
        ui->followTrialOn->setCheckState(Qt::Unchecked);
        
        //clear the max follow distance
        ui->followTrialDistance->setText("");
        
        //set velocity change off
        ui->followTrialVelocityChange->setCheckState(Qt::Unchecked);
        
        //uncheck absolute and check match
        ui->followTrialVelocityChangeAbsolute->setChecked(false);
        ui->followTrialVelocityChangeMatchExternalDriver->setChecked(true);
        
        //clear absolute speed lin edit
        ui->followTrialVelocityChangeAbsoluteLineEdit->setText("");
        
        //uncheck force lane change
        ui->followTrialForceLaneChange->setCheckState(Qt::Unchecked);
        
        //clear the speed
        ui->followTrialForceLaneChangeSpeed->setText("");
        
        //clear the acceleration
        ui->followTrialForceLaneChangeAcceleration->setText("");
    }
    return;
}

//requires: trialNumber is between 0 and maxtrials (inclusive)
//modifies: all current trial settings other than the curren trial number
//effects: changes the current trial display to the trial number given
void MainWindow::loadTrial(int trialNumber) {
    //if the trial number is 1, set it
    Trial tmpTrial = trials[trialNumber];

    //follow instructions
    loadFollowTrial(tmpTrial.followVehicle);

    //lead instructions
    loadLeadTrial(tmpTrial.leadVehicle);
    
    //roadside control
    loadRoadSideTrial(tmpTrial.roadSide);

    //left lane
    loadLeftLaneTrial(tmpTrial.leftLane);
    
    return;
}

//requires: that all trial settings must be checked before getting them
//modifies:
//effects:
Trial MainWindow::getTrial(){
    Trial tmp;
    
    tmp.trialNumber = ui->currentTrial->text().toInt(false);
    
    //get follow vehicle
    tmp.followVehicle = getFollowTrial();
    
    //get the lead vehicle
    tmp.leadVehicle = getLeadTrial();
    
    //get the roadside vehicle
    tmp.roadSide = getRoadSideTrial();
    
    //get the left lane
    tmp.leftLane = getLeftLaneTrial();
    return tmp;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//requires:
//modifies: the number of max trials and the size of the vector of trials
//effects: checks that the number of trials matches the max trials and also that the vector of trials can hold the max amount of trials, returns true if there was an issue with the length of the road
bool MainWindow::checkLength(){
    //if max trial has not been set
    if (maxTrial == 0) {
        if (ui->lengthOfRoadLineEdit->text().isEmpty()) {
            QMessageBox::information(this, tr("Error Encountered"), tr("Please enter a number of trials before making changes to trials."));
            return true;
        }
        else if (ui->lengthOfRoadLineEdit->text().toDouble(false) < 0) {
            QMessageBox::information(this, tr("Error Encountered"), tr("Please enter a number of trials that is positive before making changes to trials."));
            return true;
        }
    }
    if (maxTrial != ui->lengthOfRoadLineEdit->text().toDouble(false)) {
        this->maxTrial = ui->lengthOfRoadLineEdit->text().toDouble(false);
        if (this->trials.size() < maxTrial) {
            trials.resize(maxTrial+1);
        }
    }
    return false;
}

//requires:
//modifies: changes the loadFilename for the main window
//effects: prompts the user for a file to load and then loads the file
void MainWindow::on_loadFile_clicked()
{
    //C:\Users\raynicho\Desktop\SCNHighwayTemplate\SCNExampleFiles
    QString filename = QFileDialog::getOpenFileName(this, tr("Load File"), "C://Users//raynicho//Desktop//SCNHighwayTemplate//SCNExampleFiles", "SCN File (*.scn)");
    this->loadFilename=filename;
    highway.readFile(loadFilename.toStdString());
}

//requires:
//modifies: changes the current trial number, all current trial display settings, the trial
//at the current trial of the trials vector
//effects: checks that the trial is valid and the length settings are valid, then gets and stores
//the current trial, then loads the next trial if in range
void MainWindow::on_nextTrial_clicked()
{
    if (!checkTrial ()){
        return;
    }
    if (checkLength()) {
        return;
    }
    QString current = ui->currentTrial->text();
    std::string trial = current.toStdString();
    int trialInt = std::stoi(trial);
    if (trialInt < maxTrial - 1){
        Trial tmp = getTrial ();
        if (trialInt >= trials.size()) {
            trials.resize(trialInt+1);
        }
        trials[trialInt] = tmp;
        trialInt++;
        loadTrial(trialInt);
        trial = std::to_string(trialInt);
        current = QString::fromStdString(trial);
        ui->currentTrial->setText(current);
    }
}

//requires:
//modifies:
//effects:
void MainWindow::on_prevTrial_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    if (checkLength()) {
        return;
    }
    QString current = ui->currentTrial->text();
    std::string trial = current.toStdString();
    int trialInt = std::stoi(trial);
    if (trialInt != 0){
        Trial tmp = getTrial ();
        if (trialInt >= trials.size()) {
            trials.resize(trialInt+1);
        }
        trials[trialInt] = tmp;
        trialInt--;
        loadTrial(trialInt);
        trial = std::to_string(trialInt);
        current = QString::fromStdString(trial);
        ui->currentTrial->setText(current);
    }
}

//requires:
//modifies:
//effects:
void MainWindow::on_saveFileButton_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    if (!checkSettings ()) {
        return;
    }
    //get the last trial and the file settings
    int current = ui->currentTrial->text().toInt(false);
    if (current >= trials.size()){
        trials.resize(current+1);
    }
    
    trials[current] = getTrial();
    getSettings();
    
    
    if (this->loadFilename.isEmpty()) {
        this->loadFilename = "C://";
    }
    
    
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), this->loadFilename, "SCN File (*.scn)");
    this->saveFilename = filename;
    
    highway.writeFile(filename.toStdString(), trials, settings);
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::on_goToButton_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    if (checkLength()) {
        return;
    }
    QString goToString = ui->goToLinEdit->text();
    std::string goTo = goToString.toStdString();
    int goToNumber = std::stoi(goTo);
    int current = ui->currentTrial->text().toDouble(false);
    if (goToNumber > -1 && goToNumber < maxTrial){
        Trial tmp = getTrial ();
        //save the tmp based on the current trial
        if (current > trials.size()) {
            //check to make sure the current trial is gonna fit
            trials.resize(current);
        }
        trials[current] = tmp;
        
        //change the current trial number to the goto number
        ui->currentTrial->setText(QString::number(goToNumber));
        
        //load the new trial
        loadTrial(goToNumber);
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkTrialFollowVehicle()
{
    QString current;
    bool* ok = 0;
    ok = false;
    if (ui->followTrialOn->checkState() == Qt::Checked) {

        //check follow distance
        current = ui->followTrialDistance->text();
        if (current.isEmpty()){
            throw ((std::string)"Please enter a follow distance for the follow vehcile instructions for the current trial.");
        }

        if (current.toDouble(ok) < 0) {
            throw ((std::string)"Please enter a max follow distance that is positive for the follow vehicle instructions for the current trial.");
        }

        //if velocity change is checked and absolute speed is checked
        if (ui->followTrialVelocityChange->checkState() == Qt::Checked && ui->followTrialVelocityChangeAbsolute->isChecked()){
            //check the absolute speed
            current = ui->followTrialVelocityChangeAbsoluteLineEdit->text();
            if (current.isEmpty()){
                throw ((std::string)"Please enter an absolute speed for the follow vehicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 0){
                throw((std::string)"Please enter an absolute speed that is positive for the follow vehicle instructions for the current trial.");
            }
        }

        //if force lane change is selected
        if (ui->followTrialForceLaneChange->checkState() == Qt::Checked) {
            //check the speed
            current = ui->followTrialForceLaneChangeSpeed->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter a speed for the force lane change in the follow vehicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 0){
                throw ((std::string)"Please enter a positive value for the force lane change speed parameter on the follow vehicle instructions for the current trial.");
            }

            //check the acceleration
            current = ui->followTrialForceLaneChangeAcceleration->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter an acceleration for the force lane change in the follow vehicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 10) {
                throw ((std::string)"Please enter a positive acceleraion for the force lane change in the follow vehicle instructions for the current trial.");
            }
        }
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkTrialLeadVehicle() {
    QString current;
    bool *ok = 0;
    ok = false;

    if (ui->leadTrialOn->checkState() == Qt::Checked) {
        //check follow distance
        current = ui->leadTrialMaxLeadDistance->text();
        if (current.isEmpty()){
            throw ((std::string)"Please enter a max distance for the lead vehicle instructions for the current trial.");
        }

        if (current.toDouble(ok) < 0){
            throw ((std::string)"Please enter a positive max distance for the lead vehicle instructions for the current trail.");
        }

        //if velocity change is checked and absolute speed is checked
        if (ui->leadTrialVelocityChange->checkState() == Qt::Checked && ui->leadTrialVelocityChangeAbsolute->isChecked()) {
            //check the absolute speed
            current = ui->leadTrialVelocityChangeAbsoluteSpeed->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter an absolute speed for the lead vehicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 0) {
                throw((std::string)"Please enter a positive absolute speed for the lead vehicle instructions for the current trial.");
            }
        }

        //if force lane change is selected
        if (ui->leadTrialForceLaneChange->checkState() == Qt::Checked) {
            //check the speed
            current = ui->leadTrialForceLaneChangeSpeed->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter a change lane speed for the lead vheicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 0){
                throw ((std::string)"Please enter a positive lane change speed for the lead vehicle instructions for the current trial.");
            }

            //check the acceleration
            current = ui->leadTrialForceLaneChangeAcceleration->text();
            if (current.isEmpty()){
                throw ((std::string)"Please enter a lane change acceleration for the lead vehicle instructions for the current trial.");
            }

            if (current.toDouble(ok) < 0) {
                throw ((std::string)"Please enter a positive value for the lane change acceleration fo the lead vehicle instructions for the current trial.");
            }
        }
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkTrialRoadSide(){
    QString current;
    bool* ok = 0;
    ok = false;

    if (ui->roadSideTrialOn->checkState() == Qt::Checked){
        //if pull out in front is selected
        if (ui->roadSideTrialPullFront->isChecked()){
            //check speed
            current = ui->roadSideTrialPullFrontSpeed->text();
            if (current.isEmpty()) {
                throw((std::string)"Please enter a pull out front speed for the roadside vehicle control.");
            }

            if (current.toDouble(ok) < 0) {
                throw((std::string)"Please enter a positive pull out front speed for the roadside vehicle control.");
            }
            
            //check distance
            if (ui->roadSideTrialPullFrontDistance->text().isEmpty()) {
                throw((std::string)"Please enter a pull out front distance for the roadside vehicle.");
            }
            
            if (ui->roadSideTrialPullFrontDistance->text().toDouble(false) < 0) {
                throw((std::string)"Please enter a positive pull out front distance for the roadside vehicle.");
            }
        }
        //if drive on shoulder is selected
        if (ui->roadSideTrialDriveOnShoulder->isChecked()) {
            //check speed
            current = ui->roadSideTrialDriveOnShoulderSpeed->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter a shoulder driving speed for the roadside vehicle control.");
            }

            if (current.toDouble(ok) < 0) {
                throw ((std::string)"Please enter a positive shoulder driving speed for the roadside vehicle control.");
            }
        }
        //if pull out in front and stop is checked
        if (ui->roadSideTrialPullFrontStop->isChecked()) {
            //check speed
            current = ui->roadSideTrialPullFrontStopSpeed->text();
            if (current.isEmpty()){
                throw ((std::string)"Please enter a pull out and stop speed for the road side vehicle control.");
            }

            if (current.toDouble(ok) < 0){
                throw ((std::string)"Please enter a positve pull out and stop speed for the road side vehicle control.");
            }

            //check distance
            current = ui->roadSideTrialPullFrontStopDistance->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter a pull in front and stop distance for the road side vehicle control.");
            }

            if (current.toDouble(ok) < 0){
                throw((std::string)"Please enter a positive pull in front and stop distance for the road side vehicle control.");
            }
        }
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkTrialLeftLane() {
    QString current;
    bool *ok = 0;
    ok = false;
    if (ui->leftLaneTrialOn->checkState() == Qt::Checked) {
        //check that the creation distance is positive and not empty
        if (ui->leftLaneTrialDistanceFromET->text().isEmpty() || ui->leftLaneTrialDistanceFromET->text().toDouble(false) < 0) {
            throw ((std::string)"Please make corrections to the left lane creation distance.");
        }
        
        //if cut in front of driver is selected
        if (ui->leftLaneTrialCutFront->isChecked()) {
            //check distance
            current = ui->leftLaneTrialCutFrontDistance->text();
            if (current.isEmpty()) {
                throw ((std::string)"Please enter a left lane cut in front distance.");
            }

            if (current.toDouble(ok) < 0) {
                throw((std::string)"Please enter a positive left lane cut in front distance.");
            }

            //check speed
            current = ui->leftLaneTrialCutFrontSpeed->text();
            if (current.isEmpty()) {
                throw((std::string)"Please enter a left lane cut in front speed.");
            }

            if (current.toDouble(ok) < 0){
                throw((std::string)"Please enter a positive left lane cut in front speed.");
            }
        }
        //if remain in lane and absolute is selected
        if (ui->leftLaneTRialRemainLane->isChecked() && ui->leftLaneTrialRemainLaneAbsolute->checkState() == Qt::Checked){
            //check absolute
            current = ui->leftLaneTrialRemainLaneAbsoluteSpeed->text();
            if (current.isEmpty()) {
                throw((std::string)"Please enter a left lane remain in lane absolute speed.");
            }

            if (current.toDouble(ok) < 0){
                throw((std::string)"Please enter a positive left lane remain in lane absolute speed.");
            }

            //if absolute and match are picked
            if (ui->leftLaneTrialRemainLaneAbsolute->checkState() == Qt::Checked && ui->leftLaneTrialRemainLaneMatchET->checkState() == Qt::Checked) {
                throw((std::string)"Please choose either absolute or match speed for left lane vehicle remain in lane.");
            }
        }



        //if remain in lane is chosen but nothing else is
        if (ui->leftLaneTRialRemainLane->isChecked() && ui->leftLaneTrialRemainLaneAbsolute->checkState() == Qt::Unchecked && ui->leftLaneTrialRemainLaneMatchET->checkState() == Qt::Unchecked) {

            throw ((std::string)"Please either choose absolute or match speed for the left lane vehicle lane speed.");
        }
    }
    return;
}

//requires:
//modifies:
//effects:
//returns false if there is an error with the trial readings
//also displays a message so that the user sees the error
bool MainWindow::checkTrial () {
    try {
        //follow vehicle
        checkTrialFollowVehicle ();

        //lead vehicle
        checkTrialLeadVehicle();

        //road side
        checkTrialRoadSide();

        //left lane
        checkTrialLeftLane();
    }
    catch (std::string &e) {
        QMessageBox::information(this, tr("Error Encountered"), tr(e.c_str()));
        return false;
    }
    return true;
}

//requires:
//modifies:
//effects:
//returns true if the QString is empty or is negative when read as a double
bool MainWindow::emptyOrNegative (QString &lineEdit) {
    bool* ok = 0;
    ok = false;
    if (lineEdit.isEmpty()) {
        return true;
    }
    if (lineEdit.toDouble(ok) < 0){
        return true;
    }
    return false;
}

bool MainWindow::emptyOrPositive (QString &lineEdit) {
    bool* ok = 0;
    ok = false;
    if (lineEdit.isEmpty()) {
        return true;
    }
    if (lineEdit.toDouble(ok) > 0){
        return true;
    }
    return false;
}

//requires:
//modifies:
//effects:
void MainWindow::checkFCWSettings(){
    //if fcw is checked
    if (ui->fcwOn->checkState() == Qt::Checked){
        //check the frequency
        if (emptyOrNegative(ui->frequencyLineEdit->text())) {
            throw((std::string)"Please make changes to the FCW frequency.");
        }

        //check the position
        if ((ui->fcwPositionX->text()).isEmpty() || (ui->fcwPositionY->text()).isEmpty() || (ui->fcwPositionZ->text()).isEmpty()) {
            throw((std::string)"Please make changes to the FCW position.");
        }

        //check the color
        if (!fcwColor.isValid()) {
            throw ((std::string)"Please choose a color.");
        }
        
        //check the shape and icon
        if (ui->shapeOption->currentText() == "Icon" && ui->fcwIconName->text().isEmpty()) {
            throw ((std::string)"Please enter an icon name for frontal crash warning.");
        }
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkAnimation() {
    //if animation is selected and the fcw is selected
    if (ui->fcwOn->checkState() == Qt::Checked && ui->animationOn->checkState() == Qt::Checked) {
        //check the start position
        if ((ui->animationStartX->text()).isEmpty() || (ui->animationStartY->text()).isEmpty() || (ui->animationEndZ->text()).isEmpty()) {
            throw((std::string)"Please make changes to the animation start position.");
        }

        //check the end position
        if ((ui->animationEndX->text()).isEmpty() || (ui->animationEndY->text()).isEmpty() || (ui->animationEndZ->text()).isEmpty()){
            throw((std::string)"Please make changes to the animation end position.");
        }
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkFollowVehicleSettings(){
    if (emptyOrNegative(ui->followDistanceLineEdit->text())){
        throw((std::string)"Please make changes to the follow vehicle distance.");
    }
    if (emptyOrNegative(ui->followMaxSpeedLineEdit->text())) {
        throw((std::string)"Please make changes to the follow vehicle max speed.");
    }
    if (emptyOrNegative(ui->followMinSpeedLineEdit->text())) {
        throw((std::string)"Please make changes to the follow vehicle min speed.");
    }
    if (emptyOrNegative(ui->followMaxAccelLineEdit->text())) {
        throw((std::string)"Please make changes to the follow vehicle max acceleration.");
    }
    if (emptyOrPositive(ui->followMaxDecel->text())) {
        throw((std::string)"Please make changes to the follow vehicle max deceleration.");
    }
    return;
}

//requires:
//modifies:
//effects:
void MainWindow::checkLeadVehicleSettings(){
    if (emptyOrPositive(ui->leadDistanceLineEdit->text())) {
        throw ((std::string)"Please make changes to the lead vehicle distance.");
    }
    if (emptyOrNegative(ui->leadMaxSpeedLineEdit->text())) {
        throw((std::string)"Please make changes to the lead vehicle max speed.");
    }
    if (emptyOrNegative(ui->leadMinSpeedLineEdit->text())) {
        throw((std::string)"Please make changes to the lead vehicle min speed.");
    }
    if (emptyOrNegative(ui->leadMaxAccelLineEdit->text())) {
        throw((std::string)"Please make changes to the lead vehicle max acceleration.");
    }
    if (emptyOrPositive(ui->leadMaxDecel->text())) {
        throw((std::string)"Please make changes to the lead vehicle max deceleraion.");
    }
    return;
}

void MainWindow::checkOpposingTraffic () {
    if (ui->generateOpposingTraffic->isChecked()){
        if (emptyOrNegative(ui->numberOpposingVehicles->text())) {
            throw((std::string)"Please make changes to the level of opposing traffic.");
        }
        if (emptyOrNegative(ui->numberCars->text())) {
            throw((std::string)"Please make changes to the number of cars in the opposing traffic ratio.");
        }
        if (emptyOrNegative(ui->numberTrucks->text())) {
            throw((std::string)"Please make changes to the number of trucks in the opposing traffic ratio.");
        }
        if (ui->numberCars->text().toInt(false) == 0 && ui->numberTrucks->text().toInt(false) == 0) {
            throw((std::string)"Either number of trucks or number of cars must be positive for opposing traffic generation.");
        }
    }
    return;
}

//requires:
//modifies:
//effects:
//returns false if there is an error with the settings readings
//also displays a message so that the user sees the error
bool MainWindow::checkSettings () {
    try {
        //lead vehicle
        checkLeadVehicleSettings();

        //follow vehicle
        checkFollowVehicleSettings();

        //fcw
        checkFCWSettings();

        //check animation
        checkAnimation();

        //length of road
        if (ui->lengthOfRoadLineEdit->text().isEmpty()) {
            throw ((std::string)"Please enter a number of trials.");
        }

        if ((ui->lengthOfRoadLineEdit->text()).toDouble(false) < 0){
            throw((std::string)"Please enter a number of trials.");
        }
        
        //opposing traffic
        checkOpposingTraffic();
    }
    catch (std::string &e) {
        //QMessageBox::information(this, "", "made it here");
        QMessageBox::information(this, tr("Error Encountered"), tr(e.c_str()));
        return false;
    }

    return true;
}

//requires:
//modifies:
//effects:
void MainWindow::on_colorButton_clicked()
{
    fcwColor = QColorDialog::getColor(Qt::white, this, "FCW Color");
    QPalette palette = ui->colorDisplay->palette();
    palette.setColor(ui->colorDisplay->backgroundRole(), fcwColor);
    ui->colorDisplay->setAutoFillBackground(true);
    ui->colorDisplay->setPalette(palette);
}

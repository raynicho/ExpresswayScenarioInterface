#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList solModelChoices;
    solModelChoices << "DodgeNeon" << "Audi" << "WindStar" << "FordTaurus" << "LandRover" << "Ford_F150Xcab"
                    << "Deville" << "Towncar" << "BMW_StationWagon" << "PEUGEOT_306";
    ui->followSolModel->addItems(solModelChoices);
    ui->leadSolModel->addItems(solModelChoices);

    QStringList shapeChoices;
    shapeChoices << "Triangle" << "Square" << "Circle";
    ui->fcwComboBox->addItems(shapeChoices);

    QPixmap pix("C:/Users/raynicho/Desktop/SCNHighwayTemplate/Docs/UMTRI-logo.png");
    ui->umtriLogo->setPixmap(pix);

    ui->statusBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Load File"), "C://", "SCN File (*.scn)");
    ui->fileStatus->setText("File Status: File Read Properly");
}

void MainWindow::on_nextTrial_clicked()
{
    if (!checkTrial ()){
        return;
    }
    QString current = ui->currentTrial->text();
    std::string trial = current.toStdString();
    int trialInt = std::stoi(trial);
    if (trialInt < maxTrial){
        trialInt++;
        trial = std::to_string(trialInt);
        current = QString::fromStdString(trial);
        ui->currentTrial->setText(current);
    }
}

void MainWindow::on_prevTrial_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    QString current = ui->currentTrial->text();
    std::string trial = current.toStdString();
    int trialInt = std::stoi(trial);
    if (trialInt != 0){
        trialInt--;
        trial = std::to_string(trialInt);
        current = QString::fromStdString(trial);
        ui->currentTrial->setText(current);
    }
}

void MainWindow::on_saveFileButton_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    if (!checkSettings ()) {
        return;
    }
    QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "C://", "SCN File (*.scn)");
}

void MainWindow::on_goToButton_clicked()
{
    if (!checkTrial ()) {
        return;
    }
    QString goToString = ui->goToLinEdit->text();
    std::string goTo = goToString.toStdString();
    int goToNumber = std::stoi(goTo);
    if (goToNumber > -1 && goToNumber <= maxTrial){
        //remember to save the trial and check the trial for errors
        goTo = std::to_string(goToNumber);
        goToString = QString::fromStdString(goTo);
        ui->currentTrial->setText(goToString);
        //load the new trial
    }
}

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

void MainWindow::checkTrialLeftLane() {
    QString current;
    bool *ok = 0;
    ok = false;
    if (ui->leftLaneTrialOn->checkState() == Qt::Checked) {
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

void MainWindow::checkFCWSettings(){

    return;
}

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
    if (emptyOrNegative(ui->followMinAccel->text())) {
        throw((std::string)"Please make changes to the follow vehicle min acceleration.");
    }
    return;
}

void MainWindow::checkLeadVehicleSettings(){
    if (emptyOrNegative(ui->leadDistanceLineEdit->text())) {
        throw ((std::string)"Please make cahnges to the lead vehicle distance.");
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
    if (emptyOrNegative(ui->leadMinAccelLineEdit->text())) {
        throw((std::string)"Please make changes to the lead vehicle min acceleration.");
    }
    return;
}

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

        //length of road
        if (ui->lengthOfRoadLineEdit->text().isEmpty()) {
            throw ((std::string)"Please enter the length of road.");
        }

        if ((ui->lengthOfRoadLineEdit->text()).toDouble(false) < 0){
            throw((std::string)"Please enter a positive length of road.");
        }
    }
    catch (std::string &e) {
        //QMessageBox::information(this, "", "made it here");
        QMessageBox::information(this, tr("Error Encountered"), tr(e.c_str()));
        return false;
    }

    return true;
}

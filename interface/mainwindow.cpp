#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <string>

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
    int maxTrial = 37;
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

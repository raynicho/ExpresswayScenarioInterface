#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QMainWindow>
#include <vector>
#include "Trial.h"
#include "MajorSettings.h"
#include "SCNHighwayTemplate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool checkTrial ();

    bool checkSettings ();

    void checkTrialFollowVehicle();

    void checkTrialLeadVehicle();

    void checkTrialRoadSide();

    void checkTrialLeftLane();

    void checkLeadVehicleSettings();

    void checkFollowVehicleSettings();

    void checkFCWSettings();

    bool emptyOrNegative (QString &lineEdit);

    void checkAnimation ();

    bool checkLength();

    Trial getTrial ();

    void loadTrial (int);

    void loadFollowTrial (FVLVInstructions &);
    
    FVLVInstructions getFollowTrial ();
    
    void loadLeadTrial (FVLVInstructions &);
    
    FVLVInstructions getLeadTrial ();
    
    void loadRoadSideTrial (roadSideControl &);
    
    roadSideControl getRoadSideTrial ();
    
    void loadLeftLaneTrial (leftLaneControl &);
    
    leftLaneControl getLeftLaneTrial ();

private slots:
    void on_loadFile_clicked();

    void on_nextTrial_clicked();

    void on_prevTrial_clicked();

    void on_saveFileButton_clicked();

    void on_goToButton_clicked();

    void on_colorButton_clicked();

private:
    QString loadFilename;
    QString saveFilename;
    SCNHighwayTemplate highway;
    QColor fcwColor;
    Ui::MainWindow *ui;
    int maxTrial = 0;
    MajorSettings settings;
    std::vector <Trial> trials;
};

#endif // MAINWINDOW_H

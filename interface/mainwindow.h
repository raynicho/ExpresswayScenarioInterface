#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "Trial.h"
#include "MajorSettings.h"

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

private slots:
    void on_loadFile_clicked();

    void on_nextTrial_clicked();

    void on_prevTrial_clicked();

    void on_saveFileButton_clicked();

    void on_goToButton_clicked();

private:
    Ui::MainWindow *ui;
    int maxTrial = 37;
    MajorSettings settings;
    std::vector <Trial> trials;
};

#endif // MAINWINDOW_H

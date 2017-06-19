#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QMainWindow>
#include <vector>
#include "Trial.h"
#include "MajorSettings.h"
#include "SCNHighwayTemplate.h"

/*
Requires:   
Modifies:   
Effects:    
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /*
    Requires:   N/A      
    Modifies:   N/A   
    Effects:    Tries checkTrialFollowVehicle (), checkTrialLeadVehicle(), checkTrialRoadSide(), and
                checkTrialLeftLane(). If a string is caught then a QMessageBox is displayed containing
                the error caught and the functiond returns false. Otherwise the function returns true. 
    */
    bool checkTrial ();

    /*
    Requires:   N/A      
    Modifies:   N/A
    Effects:    Tries checkLeadVehicleSettings(), checkFollowVehicleSettings(), checkFCWSettings(), and 
                checkAnimation(). If a string is caught then a QMessageBox is displayed containing
                the error caught and the functiond returns false. Otherwise the function returns true.
    */
    bool checkSettings ();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks that if trial follow vehicle instructions are present, the velocity change option 
                is selected, and that the absolute option is selected the absolute velosity is not 
                empty and is greater than 0 (when interpretted as a double).
    */
    void checkTrialFollowVehicle();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks that if trial lead vehicle instructions are present, the velocity change option 
                is selected, and that the absolute option is selected the absolute velocity is not 
                empty and is greater than 0 (when interpretted as a double).
    */
    void checkTrialLeadVehicle();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks the trial roadside settings when this option is selected. If the pull front
                option is checked, then the following are checked to be positive and non-empty: speed 
                and distance. If the drive on shoulder option is checked, then the following are 
                checked to be positive and non-empty: speed. If the pull front and stop option is 
                checked, then the following are checked to be positive and non-empty: speed and distance.
                If any inputs are invalid, the functions throws a string that contains information that
                will help the user identify an error.
    */
    void checkTrialRoadSide();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks the trial left lane settings when this option is selected. If the cut in front
                option is checked, then the following are checked to be positive and non-empty: speed 
                and distance. If the remain in lane with an absolute speed option is checked, then the 
                following are checked to be positive and non-empty: speed. If remain in lane option is
                selected, the function makes sure that either match et or absolute speed are selected
                and not both. The creation distance is also checked to be non-empty and positive.If any
                inputs are invalid, the functions throws a string that contains information that will 
                help the user identify an error.
    */
    void checkTrialLeftLane();

    /*
    Requires:   N/A
    Modifies:   N/A   
    Effects:    Checks that the  lead vehicle settings are non-empty and positive: lead distance, max 
                speed, min speed, max acceleration, and max deceleration. If any inputs are invalid 
                then function throws a string that contains information that will help the user 
                indentify an error.
    */
    void checkLeadVehicleSettings();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks that the follow vehicle settings are non-empty and positive: follow distance, max 
                speed, min speed, max acceleration, and max deceleration. If any inputs are invalid 
                then function throws a string that contains information that will help the user 
                indentify an error.
    */
    void checkFollowVehicleSettings();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks that the FCW settings are non-empty and positive: frequency, position (x, y, and
                z), and icon (if icon is selected as the shape). Also checks that the color input is 
                valid. If any inputs are invalid then function throws a string that contains 
                information that will help the user indentify an error.
    */
    void checkFCWSettings();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns true if the QString is empty or negative(when interpretted as a double).
    */
    bool emptyOrNegative (QString);

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks the start and end position of the FCW Animation if the FCW and Animation options
                are selected. If any inputs are invalid then function throws a string that contains 
                information that will help the user indentify an error.
    */
    void checkAnimation ();

    /*
    Requires:   N/A
    Modifies:   The number of max trials and the zise of the trials vector.
    Effects:    If the max number of trials is 0 or less than 0, the user is prompted to enter a new 
                number of trials and then returns true (indicating an error). Also if the max number of
                trials member variable does not match the user input then update the member variable and
                resize the trials vector as appropriate.
    */
    bool checkLength();

    /*
    Requires:   All trials have been checked.
    Modifies:   N/A
    Effects:    Returns a Trial object that has loaded all Trial member variables: followVehicle, 
                leadVehicle, roadSide, and leftLane.
    */
    Trial getTrial ();

    /*
    Requires:   int parameter is between 0 and the max number of trials (inclusive).
    Modifies:   N/A
    Effects:    Makes calls to: loadFollowTrial (FVLVInstructions), loadLeadTrial (FVLVInstructions), 
                loadRoadSideTrial (roadSideControl), loadLeftLaneTrial (leftLaneControl). The paremeters
                are loaded from the trials vector at the int location.
    */
    void loadTrial (int);

    /*
    Requires:   N/A
    Modifies:   All current follow trial settings of the interface.
    Effects:    Loads the follow vehicle trial settings to the interface display from the given 
                FVLVInstructions parameter.
    */
    void loadFollowTrial (FVLVInstructions &);
    
    /*
    Requires:   The follow trial vehicle settings have been checked.
    Modifies:   N/A
    Effects:    Gets all follow vehicle trial settings from the interface input and returns a 
                FVLVInstructions holding all those settings.
    */
    FVLVInstructions getFollowTrial ();
    
    /*
    Requires:   N/A
    Modifies:   All current trial settings of the interface.
    Effects:    Loads the lead vehicle trial settings to the interface display from the given 
                FVLVInstructions parameter.
    */
    void loadLeadTrial (FVLVInstructions &);
    
    /*
    Requires:   The lead trial vehicle settings have been checked.
    Modifies:   N/A
    Effects:    Gets all lead vehicle trial settings from the interface input and returns a 
                FVLVInstructions holding all those settings.
    */
    FVLVInstructions getLeadTrial ();
    
    /*
    Requires:   N/A
    Modifies:   All current roadside trial settings of the interface.
    Effects:    Loads all road side vehicle trial settings to the interface display from the given
                roadSideControl parameter.
    */
    void loadRoadSideTrial (roadSideControl &);
    
    /*
    Requires:   The road side trial vehicle settings have been checked.
    Modifies:   N/A
    Effects:    Gets all road side vehicle trial settings from the interface input and returns a 
                roadSideControl holding all those settings.
    */
    roadSideControl getRoadSideTrial ();
    
    /*
    Requires:   N/A
    Modifies:   All current left lane trial settings of the interface.
    Effects:    Loads all left lane vehicle trial settings to the interface display from the given
                leftLaneControl parameter.
    */
    void loadLeftLaneTrial (leftLaneControl &);
    
    /*
    Requires:   The left lane trial vehicle settings have been checked.
    Modifies:   N/A
    Effects:    Gets all left lane vehicle trial settings from the interface input and returns a 
                leftLaneControl holding all those settings.
    */
    leftLaneControl getLeftLaneTrial ();
    
    /*
    Requires:   The major vfile settings have been checked.
    Modifies:   settings member variable.
    Effects:    Gets all major file settings and stores them in the settings member variable.
    */
    void getSettings ();

    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Returns true if the QString parameter is empty or positive.
    */
    bool emptyOrPositive (QString);
    
    /*
    Requires:   N/A
    Modifies:   N/A
    Effects:    Checks that the opposing traffic generation settings are valid. If any inputs are 
                invalid then function throws a string that contains information that will help the 
                user indentify an error.
    */
    void checkOpposingTraffic ();
    
private slots:
    /*
    Requires:   N/A
    Modifies:   loadFileName member variable and highway member variable.
    Effects:    Gets the filename of the SCN file to load then loads it into the SCNHighwayTemplate
                member variable named highway.
    */
    void on_loadFile_clicked();

    /*
    Requires:   N/A
    Modifies:   All interface settings.
    Effects:    Checks the trial settings and the number of trials input. If it is not the last trial,
                then the current trial settings are saved and the next trial is loaded.
    */
    void on_nextTrial_clicked();

    /*
    Requires:   N/A
    Modifies:   All interface settings.
    Effects:    Checks the trial settings and the number of trials input. If it is not the first trial,
                then the current trial settings are saved and the previous trial is loaded.
    */
    void on_prevTrial_clicked();

    /*
    Requires:   N/A
    Modifies:   highway member variable.
    Effects:    Checks the trial and major file settings. Then gets the last trial and saves it to the 
                trials vector. Then gets the save filename and writes the highway member variable to that
                filename.
    */
    void on_saveFileButton_clicked();

    /*
    Requires:   N/A
    Modifies:   highway member variable.
    Effects:    Checks the trial settings and number of trials input. If the goToNumber is in range,
                then get and save the current trial. Then loads the trial at the goToNumber.                
    */
    void on_goToButton_clicked();

    /*
    Requires:   N/A
    Modifies:   fcwColor member variable.
    Effects:    Launhces window to get FCW color and assigns it to the fcwColor member variable. Then
                changes the colorDisplay label to the color chosen.
    */
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

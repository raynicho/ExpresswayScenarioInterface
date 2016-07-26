/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *umtriLogo;
    QGroupBox *majorFileSettings;
    QLabel *label_5;
    QLineEdit *animationStartZ;
    QLabel *label_6;
    QLineEdit *animationStartY;
    QLineEdit *animationEndZ;
    QLineEdit *animationStartX;
    QLineEdit *animationEndX;
    QLineEdit *animationEndY;
    QLabel *label_30;
    QCheckBox *animationOn;
    QComboBox *shapeOption;
    QLineEdit *fcwIconName;
    QGroupBox *groupBox;
    QCheckBox *fcwOn;
    QPushButton *colorButton;
    QLabel *colorDisplay;
    QLabel *label_7;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QCheckBox *showBlindSpotWarning;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QLabel *label_15;
    QLabel *label_32;
    QLabel *label_35;
    QLabel *label_37;
    QLabel *followMinAccelLabl;
    QLabel *followMaxAccelLabel;
    QLabel *solModelLabel;
    QLabel *minFollowSpeedLabel;
    QLabel *followVehicleDistanceLabel;
    QLabel *maxFollowSpeedLabel;
    QGroupBox *groupBox_4;
    QLabel *label_21;
    QLabel *label_28;
    QLabel *label_31;
    QLabel *label_38;
    QLabel *label_39;
    QComboBox *leadSolModel;
    QLabel *solModelLabel_2;
    QLineEdit *leadDistanceLineEdit;
    QLabel *maxFollowSpeedLabel_2;
    QLabel *leadVehicleDistanceLabel;
    QLineEdit *leadMaxAccelLineEdit;
    QLabel *followMaxAccelLabel_2;
    QLineEdit *leadMaxSpeedLineEdit;
    QLineEdit *leadMinSpeedLineEdit;
    QLabel *followMinAccelLabl_2;
    QLabel *minFollowSpeedLabel_2;
    QLineEdit *leadMaxDecel;
    QLineEdit *followMaxAccelLineEdit;
    QLineEdit *followMaxDecel;
    QLineEdit *followMinSpeedLineEdit;
    QLineEdit *followDistanceLineEdit;
    QLineEdit *followMaxSpeedLineEdit;
    QComboBox *followSolModel;
    QLabel *lengthOfRoadLabel;
    QGroupBox *fileManager;
    QPushButton *loadFile;
    QPushButton *saveFileButton;
    QLabel *label_4;
    QLineEdit *fcwPositionZ;
    QLineEdit *frequencyLineEdit;
    QLineEdit *fcwPositionY;
    QLineEdit *fcwPositionX;
    QLabel *frequency;
    QLineEdit *lengthOfRoadLineEdit;
    QLineEdit *numberOpposingVehicles;
    QLabel *label;
    QLineEdit *numberCars;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *numberTrucks;
    QGroupBox *groupBox_5;
    QCheckBox *generateOpposingTraffic;
    QGroupBox *trialManager;
    QGroupBox *leadVehicleInstructions;
    QCheckBox *leadTrialOn;
    QCheckBox *leadTrialVelocityChange;
    QCheckBox *leadTrialForceLaneChange;
    QLineEdit *leadTrialVelocityChangeAbsoluteSpeed;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *leadTrialMatchExternalDriver;
    QRadioButton *leadTrialVelocityChangeAbsolute;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_10;
    QRadioButton *leadTrialChangeLeft;
    QRadioButton *leadTrialChangeRight;
    QGroupBox *roadSideVehicleControl;
    QCheckBox *roadSideTrialOn;
    QRadioButton *roadSideTrialAddToList;
    QLabel *label_23;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *roadSideTrialBlinkerHazards;
    QRadioButton *roadSideTrialBlinkerRight;
    QRadioButton *roadSideTrialBlinkerLeft;
    QRadioButton *roadSideTrialBlinkerNone;
    QLabel *label_20;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_7;
    QLabel *label_16;
    QLabel *label_18;
    QLineEdit *roadSideTrialPullFrontStopSpeed;
    QLineEdit *roadSideTrialPullFrontStopDistance;
    QRadioButton *roadSideTrialRemainStationary;
    QRadioButton *roadSideTrialDriveOnShoulder;
    QRadioButton *roadSideTrialPullFront;
    QRadioButton *roadSideTrialPullFrontStop;
    QGridLayout *gridLayout_8;
    QLineEdit *roadSideTrialPullFrontSpeed;
    QLabel *label_17;
    QLineEdit *roadSideTrialPullFrontDistance;
    QLabel *label_2;
    QGridLayout *gridLayout_9;
    QLabel *label_19;
    QLineEdit *roadSideTrialDriveOnShoulderSpeed;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_13;
    QRadioButton *roadSideTrialDeletionSlowDown;
    QRadioButton *roadSideTrialDeletionPullToSide;
    QLabel *label_22;
    QGroupBox *leftLaneVehicleControl;
    QCheckBox *leftLaneTrialOn;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QRadioButton *leftLaneTrialBlinkerHazards;
    QRadioButton *leftLaneTrialBlinkerRight;
    QRadioButton *leftLaneTrialBlinkerLeft;
    QRadioButton *leftLaneTrialBlinkerNone;
    QLabel *label_26;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_6;
    QLineEdit *leftLaneTrialCutFrontDistance;
    QLineEdit *leftLaneTrialCutFrontSpeed;
    QLabel *label_25;
    QLabel *label_27;
    QRadioButton *leftLaneTrialCutBehind;
    QRadioButton *leftLaneTrialCutFront;
    QRadioButton *leftLaneTrialBlindSpot;
    QRadioButton *leftLaneTRialRemainLane;
    QGridLayout *gridLayout_4;
    QCheckBox *leftLaneTrialRemainLaneAbsolute;
    QLineEdit *leftLaneTrialRemainLaneAbsoluteSpeed;
    QCheckBox *leftLaneTrialRemainLaneMatchET;
    QLabel *label_24;
    QRadioButton *leftLaneTrialAddToFCW;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_12;
    QLabel *label_36;
    QLineEdit *leftLaneTrialDistanceFromET;
    QRadioButton *leftLaneTrialCreationFront;
    QRadioButton *leftLaneTrialCreationBehind;
    QLabel *label_29;
    QPushButton *prevTrial;
    QLineEdit *goToLinEdit;
    QPushButton *goToButton;
    QPushButton *nextTrial;
    QLabel *currentTrial;
    QGroupBox *followVehicleInstruction;
    QCheckBox *followTrialOn;
    QLineEdit *followTrialVelocityChangeAbsoluteLineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *followTrialVelocityChangeMatchExternalDriver;
    QRadioButton *followTrialVelocityChangeAbsolute;
    QCheckBox *followTrialVelocityChange;
    QCheckBox *followTrialForceLaneChange;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_11;
    QRadioButton *followTrialChangeLeft;
    QRadioButton *followTrialChangeRight;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1199, 584);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        umtriLogo = new QLabel(centralWidget);
        umtriLogo->setObjectName(QStringLiteral("umtriLogo"));
        umtriLogo->setGeometry(QRect(30, 510, 511, 71));
        majorFileSettings = new QGroupBox(centralWidget);
        majorFileSettings->setObjectName(QStringLiteral("majorFileSettings"));
        majorFileSettings->setGeometry(QRect(10, 10, 561, 501));
        label_5 = new QLabel(majorFileSettings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 420, 51, 16));
        animationStartZ = new QLineEdit(majorFileSettings);
        animationStartZ->setObjectName(QStringLiteral("animationStartZ"));
        animationStartZ->setGeometry(QRect(340, 440, 41, 20));
        label_6 = new QLabel(majorFileSettings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 440, 47, 13));
        animationStartY = new QLineEdit(majorFileSettings);
        animationStartY->setObjectName(QStringLiteral("animationStartY"));
        animationStartY->setGeometry(QRect(300, 440, 41, 20));
        animationEndZ = new QLineEdit(majorFileSettings);
        animationEndZ->setObjectName(QStringLiteral("animationEndZ"));
        animationEndZ->setGeometry(QRect(340, 460, 41, 20));
        animationStartX = new QLineEdit(majorFileSettings);
        animationStartX->setObjectName(QStringLiteral("animationStartX"));
        animationStartX->setGeometry(QRect(260, 440, 41, 20));
        animationEndX = new QLineEdit(majorFileSettings);
        animationEndX->setObjectName(QStringLiteral("animationEndX"));
        animationEndX->setGeometry(QRect(260, 460, 41, 20));
        animationEndY = new QLineEdit(majorFileSettings);
        animationEndY->setObjectName(QStringLiteral("animationEndY"));
        animationEndY->setGeometry(QRect(300, 460, 41, 20));
        label_30 = new QLabel(majorFileSettings);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(200, 460, 31, 16));
        animationOn = new QCheckBox(majorFileSettings);
        animationOn->setObjectName(QStringLiteral("animationOn"));
        animationOn->setGeometry(QRect(250, 420, 16, 17));
        shapeOption = new QComboBox(majorFileSettings);
        shapeOption->setObjectName(QStringLiteral("shapeOption"));
        shapeOption->setGeometry(QRect(460, 360, 81, 22));
        fcwIconName = new QLineEdit(majorFileSettings);
        fcwIconName->setObjectName(QStringLiteral("fcwIconName"));
        fcwIconName->setGeometry(QRect(460, 390, 81, 20));
        groupBox = new QGroupBox(majorFileSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 320, 361, 171));
        fcwOn = new QCheckBox(groupBox);
        fcwOn->setObjectName(QStringLiteral("fcwOn"));
        fcwOn->setGeometry(QRect(120, 0, 16, 17));
        colorButton = new QPushButton(groupBox);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(230, 100, 91, 23));
        colorDisplay = new QLabel(groupBox);
        colorDisplay->setObjectName(QStringLiteral("colorDisplay"));
        colorDisplay->setGeometry(QRect(230, 130, 91, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(200, 70, 61, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 40, 47, 13));
        groupBox_2 = new QGroupBox(majorFileSettings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 290, 141, 61));
        showBlindSpotWarning = new QCheckBox(groupBox_2);
        showBlindSpotWarning->setObjectName(QStringLiteral("showBlindSpotWarning"));
        showBlindSpotWarning->setGeometry(QRect(20, 30, 91, 16));
        groupBox_3 = new QGroupBox(majorFileSettings);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 261, 201));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 50, 21, 16));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(220, 80, 21, 16));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(220, 110, 21, 16));
        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(220, 140, 31, 16));
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(220, 170, 31, 16));
        followMinAccelLabl = new QLabel(groupBox_3);
        followMinAccelLabl->setObjectName(QStringLiteral("followMinAccelLabl"));
        followMinAccelLabl->setGeometry(QRect(10, 170, 91, 16));
        followMaxAccelLabel = new QLabel(groupBox_3);
        followMaxAccelLabel->setObjectName(QStringLiteral("followMaxAccelLabel"));
        followMaxAccelLabel->setGeometry(QRect(10, 140, 91, 16));
        solModelLabel = new QLabel(groupBox_3);
        solModelLabel->setObjectName(QStringLiteral("solModelLabel"));
        solModelLabel->setGeometry(QRect(10, 20, 51, 16));
        minFollowSpeedLabel = new QLabel(groupBox_3);
        minFollowSpeedLabel->setObjectName(QStringLiteral("minFollowSpeedLabel"));
        minFollowSpeedLabel->setGeometry(QRect(10, 110, 61, 16));
        followVehicleDistanceLabel = new QLabel(groupBox_3);
        followVehicleDistanceLabel->setObjectName(QStringLiteral("followVehicleDistanceLabel"));
        followVehicleDistanceLabel->setGeometry(QRect(10, 50, 47, 13));
        maxFollowSpeedLabel = new QLabel(groupBox_3);
        maxFollowSpeedLabel->setObjectName(QStringLiteral("maxFollowSpeedLabel"));
        maxFollowSpeedLabel->setGeometry(QRect(10, 80, 61, 16));
        groupBox_4 = new QGroupBox(majorFileSettings);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(290, 20, 261, 201));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(220, 50, 21, 16));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(220, 80, 21, 16));
        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(220, 110, 21, 16));
        label_38 = new QLabel(groupBox_4);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(220, 140, 31, 16));
        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(220, 170, 31, 16));
        leadSolModel = new QComboBox(majorFileSettings);
        leadSolModel->setObjectName(QStringLiteral("leadSolModel"));
        leadSolModel->setGeometry(QRect(390, 40, 111, 22));
        solModelLabel_2 = new QLabel(majorFileSettings);
        solModelLabel_2->setObjectName(QStringLiteral("solModelLabel_2"));
        solModelLabel_2->setGeometry(QRect(300, 40, 51, 16));
        leadDistanceLineEdit = new QLineEdit(majorFileSettings);
        leadDistanceLineEdit->setObjectName(QStringLiteral("leadDistanceLineEdit"));
        leadDistanceLineEdit->setGeometry(QRect(390, 70, 113, 20));
        maxFollowSpeedLabel_2 = new QLabel(majorFileSettings);
        maxFollowSpeedLabel_2->setObjectName(QStringLiteral("maxFollowSpeedLabel_2"));
        maxFollowSpeedLabel_2->setGeometry(QRect(300, 100, 61, 16));
        leadVehicleDistanceLabel = new QLabel(majorFileSettings);
        leadVehicleDistanceLabel->setObjectName(QStringLiteral("leadVehicleDistanceLabel"));
        leadVehicleDistanceLabel->setGeometry(QRect(300, 70, 47, 13));
        leadMaxAccelLineEdit = new QLineEdit(majorFileSettings);
        leadMaxAccelLineEdit->setObjectName(QStringLiteral("leadMaxAccelLineEdit"));
        leadMaxAccelLineEdit->setGeometry(QRect(390, 160, 113, 20));
        followMaxAccelLabel_2 = new QLabel(majorFileSettings);
        followMaxAccelLabel_2->setObjectName(QStringLiteral("followMaxAccelLabel_2"));
        followMaxAccelLabel_2->setGeometry(QRect(300, 160, 91, 16));
        leadMaxSpeedLineEdit = new QLineEdit(majorFileSettings);
        leadMaxSpeedLineEdit->setObjectName(QStringLiteral("leadMaxSpeedLineEdit"));
        leadMaxSpeedLineEdit->setGeometry(QRect(390, 100, 113, 20));
        leadMinSpeedLineEdit = new QLineEdit(majorFileSettings);
        leadMinSpeedLineEdit->setObjectName(QStringLiteral("leadMinSpeedLineEdit"));
        leadMinSpeedLineEdit->setGeometry(QRect(390, 130, 113, 20));
        followMinAccelLabl_2 = new QLabel(majorFileSettings);
        followMinAccelLabl_2->setObjectName(QStringLiteral("followMinAccelLabl_2"));
        followMinAccelLabl_2->setGeometry(QRect(300, 190, 91, 16));
        minFollowSpeedLabel_2 = new QLabel(majorFileSettings);
        minFollowSpeedLabel_2->setObjectName(QStringLiteral("minFollowSpeedLabel_2"));
        minFollowSpeedLabel_2->setGeometry(QRect(300, 130, 61, 16));
        leadMaxDecel = new QLineEdit(majorFileSettings);
        leadMaxDecel->setObjectName(QStringLiteral("leadMaxDecel"));
        leadMaxDecel->setGeometry(QRect(390, 190, 113, 20));
        followMaxAccelLineEdit = new QLineEdit(majorFileSettings);
        followMaxAccelLineEdit->setObjectName(QStringLiteral("followMaxAccelLineEdit"));
        followMaxAccelLineEdit->setGeometry(QRect(110, 160, 113, 20));
        followMaxDecel = new QLineEdit(majorFileSettings);
        followMaxDecel->setObjectName(QStringLiteral("followMaxDecel"));
        followMaxDecel->setGeometry(QRect(110, 190, 113, 20));
        followMinSpeedLineEdit = new QLineEdit(majorFileSettings);
        followMinSpeedLineEdit->setObjectName(QStringLiteral("followMinSpeedLineEdit"));
        followMinSpeedLineEdit->setGeometry(QRect(110, 130, 113, 20));
        followDistanceLineEdit = new QLineEdit(majorFileSettings);
        followDistanceLineEdit->setObjectName(QStringLiteral("followDistanceLineEdit"));
        followDistanceLineEdit->setGeometry(QRect(110, 70, 113, 20));
        followDistanceLineEdit->setLayoutDirection(Qt::LeftToRight);
        followMaxSpeedLineEdit = new QLineEdit(majorFileSettings);
        followMaxSpeedLineEdit->setObjectName(QStringLiteral("followMaxSpeedLineEdit"));
        followMaxSpeedLineEdit->setGeometry(QRect(110, 100, 113, 20));
        followSolModel = new QComboBox(majorFileSettings);
        followSolModel->setObjectName(QStringLiteral("followSolModel"));
        followSolModel->setGeometry(QRect(110, 40, 111, 22));
        lengthOfRoadLabel = new QLabel(majorFileSettings);
        lengthOfRoadLabel->setObjectName(QStringLiteral("lengthOfRoadLabel"));
        lengthOfRoadLabel->setGeometry(QRect(50, 230, 121, 20));
        fileManager = new QGroupBox(majorFileSettings);
        fileManager->setObjectName(QStringLiteral("fileManager"));
        fileManager->setGeometry(QRect(30, 390, 141, 91));
        loadFile = new QPushButton(fileManager);
        loadFile->setObjectName(QStringLiteral("loadFile"));
        loadFile->setGeometry(QRect(20, 20, 101, 21));
        saveFileButton = new QPushButton(fileManager);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(20, 60, 101, 23));
        label_4 = new QLabel(majorFileSettings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 390, 47, 13));
        fcwPositionZ = new QLineEdit(majorFileSettings);
        fcwPositionZ->setObjectName(QStringLiteral("fcwPositionZ"));
        fcwPositionZ->setGeometry(QRect(340, 390, 41, 20));
        frequencyLineEdit = new QLineEdit(majorFileSettings);
        frequencyLineEdit->setObjectName(QStringLiteral("frequencyLineEdit"));
        frequencyLineEdit->setGeometry(QRect(260, 360, 101, 20));
        fcwPositionY = new QLineEdit(majorFileSettings);
        fcwPositionY->setObjectName(QStringLiteral("fcwPositionY"));
        fcwPositionY->setGeometry(QRect(300, 390, 41, 20));
        fcwPositionX = new QLineEdit(majorFileSettings);
        fcwPositionX->setObjectName(QStringLiteral("fcwPositionX"));
        fcwPositionX->setGeometry(QRect(260, 390, 41, 20));
        frequency = new QLabel(majorFileSettings);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setGeometry(QRect(200, 360, 51, 16));
        lengthOfRoadLineEdit = new QLineEdit(majorFileSettings);
        lengthOfRoadLineEdit->setObjectName(QStringLiteral("lengthOfRoadLineEdit"));
        lengthOfRoadLineEdit->setGeometry(QRect(50, 250, 121, 20));
        numberOpposingVehicles = new QLineEdit(majorFileSettings);
        numberOpposingVehicles->setObjectName(QStringLiteral("numberOpposingVehicles"));
        numberOpposingVehicles->setGeometry(QRect(400, 260, 113, 20));
        label = new QLabel(majorFileSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 260, 91, 16));
        numberCars = new QLineEdit(majorFileSettings);
        numberCars->setObjectName(QStringLiteral("numberCars"));
        numberCars->setGeometry(QRect(330, 290, 31, 20));
        label_33 = new QLabel(majorFileSettings);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(300, 290, 21, 16));
        label_34 = new QLabel(majorFileSettings);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(380, 290, 31, 16));
        numberTrucks = new QLineEdit(majorFileSettings);
        numberTrucks->setObjectName(QStringLiteral("numberTrucks"));
        numberTrucks->setGeometry(QRect(420, 290, 31, 20));
        groupBox_5 = new QGroupBox(majorFileSettings);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(290, 230, 261, 91));
        generateOpposingTraffic = new QCheckBox(groupBox_5);
        generateOpposingTraffic->setObjectName(QStringLiteral("generateOpposingTraffic"));
        generateOpposingTraffic->setGeometry(QRect(140, 0, 16, 16));
        groupBox_5->raise();
        lengthOfRoadLabel->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox->raise();
        label_5->raise();
        animationStartZ->raise();
        label_6->raise();
        animationStartY->raise();
        animationEndZ->raise();
        animationStartX->raise();
        animationEndX->raise();
        animationEndY->raise();
        label_30->raise();
        animationOn->raise();
        shapeOption->raise();
        fcwIconName->raise();
        groupBox_2->raise();
        leadSolModel->raise();
        solModelLabel_2->raise();
        leadDistanceLineEdit->raise();
        maxFollowSpeedLabel_2->raise();
        leadVehicleDistanceLabel->raise();
        leadMaxAccelLineEdit->raise();
        followMaxAccelLabel_2->raise();
        leadMaxSpeedLineEdit->raise();
        leadMinSpeedLineEdit->raise();
        followMinAccelLabl_2->raise();
        minFollowSpeedLabel_2->raise();
        leadMaxDecel->raise();
        followMaxAccelLineEdit->raise();
        followMaxDecel->raise();
        followMinSpeedLineEdit->raise();
        followDistanceLineEdit->raise();
        followMaxSpeedLineEdit->raise();
        followSolModel->raise();
        fileManager->raise();
        label_4->raise();
        fcwPositionZ->raise();
        frequencyLineEdit->raise();
        fcwPositionY->raise();
        fcwPositionX->raise();
        frequency->raise();
        lengthOfRoadLineEdit->raise();
        numberOpposingVehicles->raise();
        label->raise();
        numberCars->raise();
        label_33->raise();
        label_34->raise();
        numberTrucks->raise();
        trialManager = new QGroupBox(centralWidget);
        trialManager->setObjectName(QStringLiteral("trialManager"));
        trialManager->setGeometry(QRect(570, 10, 621, 571));
        leadVehicleInstructions = new QGroupBox(trialManager);
        leadVehicleInstructions->setObjectName(QStringLiteral("leadVehicleInstructions"));
        leadVehicleInstructions->setGeometry(QRect(320, 50, 291, 161));
        leadTrialOn = new QCheckBox(leadVehicleInstructions);
        leadTrialOn->setObjectName(QStringLiteral("leadTrialOn"));
        leadTrialOn->setGeometry(QRect(130, 0, 16, 17));
        leadTrialVelocityChange = new QCheckBox(leadVehicleInstructions);
        leadTrialVelocityChange->setObjectName(QStringLiteral("leadTrialVelocityChange"));
        leadTrialVelocityChange->setGeometry(QRect(30, 30, 101, 17));
        leadTrialForceLaneChange = new QCheckBox(leadVehicleInstructions);
        leadTrialForceLaneChange->setObjectName(QStringLiteral("leadTrialForceLaneChange"));
        leadTrialForceLaneChange->setGeometry(QRect(30, 100, 111, 17));
        leadTrialVelocityChangeAbsoluteSpeed = new QLineEdit(leadVehicleInstructions);
        leadTrialVelocityChangeAbsoluteSpeed->setObjectName(QStringLiteral("leadTrialVelocityChangeAbsoluteSpeed"));
        leadTrialVelocityChangeAbsoluteSpeed->setGeometry(QRect(160, 80, 113, 20));
        verticalLayoutWidget_2 = new QWidget(leadVehicleInstructions);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 50, 131, 46));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        leadTrialMatchExternalDriver = new QRadioButton(verticalLayoutWidget_2);
        leadTrialMatchExternalDriver->setObjectName(QStringLiteral("leadTrialMatchExternalDriver"));
        leadTrialMatchExternalDriver->setChecked(true);

        verticalLayout_3->addWidget(leadTrialMatchExternalDriver);

        leadTrialVelocityChangeAbsolute = new QRadioButton(verticalLayoutWidget_2);
        leadTrialVelocityChangeAbsolute->setObjectName(QStringLiteral("leadTrialVelocityChangeAbsolute"));

        verticalLayout_3->addWidget(leadTrialVelocityChangeAbsolute);

        gridLayoutWidget_4 = new QWidget(leadVehicleInstructions);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(50, 120, 131, 31));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        leadTrialChangeLeft = new QRadioButton(gridLayoutWidget_4);
        leadTrialChangeLeft->setObjectName(QStringLiteral("leadTrialChangeLeft"));
        leadTrialChangeLeft->setChecked(true);

        gridLayout_10->addWidget(leadTrialChangeLeft, 0, 0, 1, 1);

        leadTrialChangeRight = new QRadioButton(gridLayoutWidget_4);
        leadTrialChangeRight->setObjectName(QStringLiteral("leadTrialChangeRight"));

        gridLayout_10->addWidget(leadTrialChangeRight, 0, 1, 1, 1);

        leadTrialOn->raise();
        leadTrialVelocityChange->raise();
        leadTrialForceLaneChange->raise();
        leadTrialMatchExternalDriver->raise();
        leadTrialVelocityChangeAbsoluteSpeed->raise();
        leadTrialVelocityChangeAbsolute->raise();
        leadTrialVelocityChange->raise();
        leadTrialForceLaneChange->raise();
        leadTrialVelocityChangeAbsoluteSpeed->raise();
        verticalLayoutWidget_2->raise();
        gridLayoutWidget_4->raise();
        roadSideVehicleControl = new QGroupBox(trialManager);
        roadSideVehicleControl->setObjectName(QStringLiteral("roadSideVehicleControl"));
        roadSideVehicleControl->setGeometry(QRect(10, 220, 311, 341));
        roadSideTrialOn = new QCheckBox(roadSideVehicleControl);
        roadSideTrialOn->setObjectName(QStringLiteral("roadSideTrialOn"));
        roadSideTrialOn->setGeometry(QRect(140, 0, 16, 17));
        roadSideTrialAddToList = new QRadioButton(roadSideVehicleControl);
        roadSideTrialAddToList->setObjectName(QStringLiteral("roadSideTrialAddToList"));
        roadSideTrialAddToList->setGeometry(QRect(180, 220, 82, 17));
        label_23 = new QLabel(roadSideVehicleControl);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(200, 200, 31, 16));
        gridLayoutWidget_2 = new QWidget(roadSideVehicleControl);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 210, 131, 46));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        roadSideTrialBlinkerHazards = new QRadioButton(gridLayoutWidget_2);
        roadSideTrialBlinkerHazards->setObjectName(QStringLiteral("roadSideTrialBlinkerHazards"));

        gridLayout_2->addWidget(roadSideTrialBlinkerHazards, 0, 0, 1, 1);

        roadSideTrialBlinkerRight = new QRadioButton(gridLayoutWidget_2);
        roadSideTrialBlinkerRight->setObjectName(QStringLiteral("roadSideTrialBlinkerRight"));

        gridLayout_2->addWidget(roadSideTrialBlinkerRight, 0, 1, 1, 1);

        roadSideTrialBlinkerLeft = new QRadioButton(gridLayoutWidget_2);
        roadSideTrialBlinkerLeft->setObjectName(QStringLiteral("roadSideTrialBlinkerLeft"));

        gridLayout_2->addWidget(roadSideTrialBlinkerLeft, 1, 0, 1, 1);

        roadSideTrialBlinkerNone = new QRadioButton(gridLayoutWidget_2);
        roadSideTrialBlinkerNone->setObjectName(QStringLiteral("roadSideTrialBlinkerNone"));
        roadSideTrialBlinkerNone->setChecked(true);

        gridLayout_2->addWidget(roadSideTrialBlinkerNone, 1, 1, 1, 1);

        label_20 = new QLabel(roadSideVehicleControl);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 190, 71, 16));
        gridLayoutWidget = new QWidget(roadSideVehicleControl);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 291, 167));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_7->addWidget(label_16, 0, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_7->addWidget(label_18, 1, 0, 1, 1);

        roadSideTrialPullFrontStopSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontStopSpeed->setObjectName(QStringLiteral("roadSideTrialPullFrontStopSpeed"));

        gridLayout_7->addWidget(roadSideTrialPullFrontStopSpeed, 0, 1, 1, 1);

        roadSideTrialPullFrontStopDistance = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontStopDistance->setObjectName(QStringLiteral("roadSideTrialPullFrontStopDistance"));

        gridLayout_7->addWidget(roadSideTrialPullFrontStopDistance, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_7, 4, 1, 1, 1);

        roadSideTrialRemainStationary = new QRadioButton(gridLayoutWidget);
        roadSideTrialRemainStationary->setObjectName(QStringLiteral("roadSideTrialRemainStationary"));
        roadSideTrialRemainStationary->setChecked(true);

        gridLayout->addWidget(roadSideTrialRemainStationary, 0, 0, 1, 1);

        roadSideTrialDriveOnShoulder = new QRadioButton(gridLayoutWidget);
        roadSideTrialDriveOnShoulder->setObjectName(QStringLiteral("roadSideTrialDriveOnShoulder"));

        gridLayout->addWidget(roadSideTrialDriveOnShoulder, 3, 0, 1, 1);

        roadSideTrialPullFront = new QRadioButton(gridLayoutWidget);
        roadSideTrialPullFront->setObjectName(QStringLiteral("roadSideTrialPullFront"));

        gridLayout->addWidget(roadSideTrialPullFront, 2, 0, 1, 1);

        roadSideTrialPullFrontStop = new QRadioButton(gridLayoutWidget);
        roadSideTrialPullFrontStop->setObjectName(QStringLiteral("roadSideTrialPullFrontStop"));

        gridLayout->addWidget(roadSideTrialPullFrontStop, 4, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        roadSideTrialPullFrontSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontSpeed->setObjectName(QStringLiteral("roadSideTrialPullFrontSpeed"));

        gridLayout_8->addWidget(roadSideTrialPullFrontSpeed, 0, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        roadSideTrialPullFrontDistance = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontDistance->setObjectName(QStringLiteral("roadSideTrialPullFrontDistance"));

        gridLayout_8->addWidget(roadSideTrialPullFrontDistance, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_8->addWidget(label_2, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_8, 2, 1, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_9->addWidget(label_19, 0, 0, 1, 1);

        roadSideTrialDriveOnShoulderSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialDriveOnShoulderSpeed->setObjectName(QStringLiteral("roadSideTrialDriveOnShoulderSpeed"));

        gridLayout_9->addWidget(roadSideTrialDriveOnShoulderSpeed, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_9, 3, 1, 1, 1);

        gridLayoutWidget_8 = new QWidget(roadSideVehicleControl);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(80, 270, 160, 61));
        gridLayout_13 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        roadSideTrialDeletionSlowDown = new QRadioButton(gridLayoutWidget_8);
        roadSideTrialDeletionSlowDown->setObjectName(QStringLiteral("roadSideTrialDeletionSlowDown"));

        gridLayout_13->addWidget(roadSideTrialDeletionSlowDown, 2, 0, 1, 1);

        roadSideTrialDeletionPullToSide = new QRadioButton(gridLayoutWidget_8);
        roadSideTrialDeletionPullToSide->setObjectName(QStringLiteral("roadSideTrialDeletionPullToSide"));
        roadSideTrialDeletionPullToSide->setChecked(true);

        gridLayout_13->addWidget(roadSideTrialDeletionPullToSide, 1, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_8);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_13->addWidget(label_22, 0, 0, 1, 1);

        leftLaneVehicleControl = new QGroupBox(trialManager);
        leftLaneVehicleControl->setObjectName(QStringLiteral("leftLaneVehicleControl"));
        leftLaneVehicleControl->setGeometry(QRect(320, 220, 291, 341));
        leftLaneTrialOn = new QCheckBox(leftLaneVehicleControl);
        leftLaneTrialOn->setObjectName(QStringLiteral("leftLaneTrialOn"));
        leftLaneTrialOn->setGeometry(QRect(130, 0, 16, 17));
        gridLayoutWidget_5 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 220, 122, 46));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialBlinkerHazards = new QRadioButton(gridLayoutWidget_5);
        leftLaneTrialBlinkerHazards->setObjectName(QStringLiteral("leftLaneTrialBlinkerHazards"));

        gridLayout_5->addWidget(leftLaneTrialBlinkerHazards, 0, 0, 1, 1);

        leftLaneTrialBlinkerRight = new QRadioButton(gridLayoutWidget_5);
        leftLaneTrialBlinkerRight->setObjectName(QStringLiteral("leftLaneTrialBlinkerRight"));

        gridLayout_5->addWidget(leftLaneTrialBlinkerRight, 0, 1, 1, 1);

        leftLaneTrialBlinkerLeft = new QRadioButton(gridLayoutWidget_5);
        leftLaneTrialBlinkerLeft->setObjectName(QStringLiteral("leftLaneTrialBlinkerLeft"));

        gridLayout_5->addWidget(leftLaneTrialBlinkerLeft, 1, 0, 1, 1);

        leftLaneTrialBlinkerNone = new QRadioButton(gridLayoutWidget_5);
        leftLaneTrialBlinkerNone->setObjectName(QStringLiteral("leftLaneTrialBlinkerNone"));
        leftLaneTrialBlinkerNone->setChecked(true);

        gridLayout_5->addWidget(leftLaneTrialBlinkerNone, 1, 1, 1, 1);

        label_26 = new QLabel(leftLaneVehicleControl);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(20, 200, 71, 16));
        gridLayoutWidget_3 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 271, 170));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        leftLaneTrialCutFrontDistance = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialCutFrontDistance->setObjectName(QStringLiteral("leftLaneTrialCutFrontDistance"));

        gridLayout_6->addWidget(leftLaneTrialCutFrontDistance, 1, 1, 1, 1);

        leftLaneTrialCutFrontSpeed = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialCutFrontSpeed->setObjectName(QStringLiteral("leftLaneTrialCutFrontSpeed"));

        gridLayout_6->addWidget(leftLaneTrialCutFrontSpeed, 0, 1, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_6->addWidget(label_25, 0, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_3);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_6->addWidget(label_27, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 2, 2, 1, 1);

        leftLaneTrialCutBehind = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialCutBehind->setObjectName(QStringLiteral("leftLaneTrialCutBehind"));

        gridLayout_3->addWidget(leftLaneTrialCutBehind, 1, 0, 1, 1);

        leftLaneTrialCutFront = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialCutFront->setObjectName(QStringLiteral("leftLaneTrialCutFront"));

        gridLayout_3->addWidget(leftLaneTrialCutFront, 2, 0, 1, 1);

        leftLaneTrialBlindSpot = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialBlindSpot->setObjectName(QStringLiteral("leftLaneTrialBlindSpot"));
        leftLaneTrialBlindSpot->setChecked(true);

        gridLayout_3->addWidget(leftLaneTrialBlindSpot, 0, 0, 1, 1);

        leftLaneTRialRemainLane = new QRadioButton(gridLayoutWidget_3);
        leftLaneTRialRemainLane->setObjectName(QStringLiteral("leftLaneTRialRemainLane"));

        gridLayout_3->addWidget(leftLaneTRialRemainLane, 5, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        leftLaneTrialRemainLaneAbsolute = new QCheckBox(gridLayoutWidget_3);
        leftLaneTrialRemainLaneAbsolute->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsolute"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsolute, 3, 0, 1, 1);

        leftLaneTrialRemainLaneAbsoluteSpeed = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialRemainLaneAbsoluteSpeed->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsoluteSpeed"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsoluteSpeed, 3, 1, 1, 1);

        leftLaneTrialRemainLaneMatchET = new QCheckBox(gridLayoutWidget_3);
        leftLaneTrialRemainLaneMatchET->setObjectName(QStringLiteral("leftLaneTrialRemainLaneMatchET"));
        leftLaneTrialRemainLaneMatchET->setChecked(true);

        gridLayout_4->addWidget(leftLaneTrialRemainLaneMatchET, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 5, 2, 1, 1);

        label_24 = new QLabel(leftLaneVehicleControl);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(200, 200, 31, 16));
        leftLaneTrialAddToFCW = new QRadioButton(leftLaneVehicleControl);
        leftLaneTrialAddToFCW->setObjectName(QStringLiteral("leftLaneTrialAddToFCW"));
        leftLaneTrialAddToFCW->setGeometry(QRect(180, 220, 71, 17));
        gridLayoutWidget_7 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(60, 270, 160, 68));
        gridLayout_12 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        label_36 = new QLabel(gridLayoutWidget_7);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout_12->addWidget(label_36, 1, 2, 1, 1);

        leftLaneTrialDistanceFromET = new QLineEdit(gridLayoutWidget_7);
        leftLaneTrialDistanceFromET->setObjectName(QStringLiteral("leftLaneTrialDistanceFromET"));

        gridLayout_12->addWidget(leftLaneTrialDistanceFromET, 2, 2, 1, 1);

        leftLaneTrialCreationFront = new QRadioButton(gridLayoutWidget_7);
        leftLaneTrialCreationFront->setObjectName(QStringLiteral("leftLaneTrialCreationFront"));

        gridLayout_12->addWidget(leftLaneTrialCreationFront, 1, 0, 1, 1);

        leftLaneTrialCreationBehind = new QRadioButton(gridLayoutWidget_7);
        leftLaneTrialCreationBehind->setObjectName(QStringLiteral("leftLaneTrialCreationBehind"));
        leftLaneTrialCreationBehind->setChecked(true);

        gridLayout_12->addWidget(leftLaneTrialCreationBehind, 2, 0, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_7);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_12->addWidget(label_29, 0, 1, 1, 1);

        prevTrial = new QPushButton(trialManager);
        prevTrial->setObjectName(QStringLiteral("prevTrial"));
        prevTrial->setGeometry(QRect(120, 20, 41, 23));
        goToLinEdit = new QLineEdit(trialManager);
        goToLinEdit->setObjectName(QStringLiteral("goToLinEdit"));
        goToLinEdit->setGeometry(QRect(370, 20, 61, 20));
        goToButton = new QPushButton(trialManager);
        goToButton->setObjectName(QStringLiteral("goToButton"));
        goToButton->setGeometry(QRect(290, 20, 71, 23));
        nextTrial = new QPushButton(trialManager);
        nextTrial->setObjectName(QStringLiteral("nextTrial"));
        nextTrial->setGeometry(QRect(230, 20, 41, 23));
        currentTrial = new QLabel(trialManager);
        currentTrial->setObjectName(QStringLiteral("currentTrial"));
        currentTrial->setGeometry(QRect(190, 20, 31, 21));
        leftLaneVehicleControl->raise();
        roadSideVehicleControl->raise();
        leadVehicleInstructions->raise();
        prevTrial->raise();
        goToLinEdit->raise();
        goToButton->raise();
        nextTrial->raise();
        currentTrial->raise();
        followVehicleInstruction = new QGroupBox(centralWidget);
        followVehicleInstruction->setObjectName(QStringLiteral("followVehicleInstruction"));
        followVehicleInstruction->setGeometry(QRect(580, 60, 311, 161));
        followTrialOn = new QCheckBox(followVehicleInstruction);
        followTrialOn->setObjectName(QStringLiteral("followTrialOn"));
        followTrialOn->setGeometry(QRect(140, 0, 16, 17));
        followTrialVelocityChangeAbsoluteLineEdit = new QLineEdit(followVehicleInstruction);
        followTrialVelocityChangeAbsoluteLineEdit->setObjectName(QStringLiteral("followTrialVelocityChangeAbsoluteLineEdit"));
        followTrialVelocityChangeAbsoluteLineEdit->setGeometry(QRect(170, 80, 113, 20));
        verticalLayoutWidget = new QWidget(followVehicleInstruction);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 50, 131, 46));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        followTrialVelocityChangeMatchExternalDriver = new QRadioButton(verticalLayoutWidget);
        followTrialVelocityChangeMatchExternalDriver->setObjectName(QStringLiteral("followTrialVelocityChangeMatchExternalDriver"));
        followTrialVelocityChangeMatchExternalDriver->setChecked(true);

        verticalLayout_2->addWidget(followTrialVelocityChangeMatchExternalDriver);

        followTrialVelocityChangeAbsolute = new QRadioButton(verticalLayoutWidget);
        followTrialVelocityChangeAbsolute->setObjectName(QStringLiteral("followTrialVelocityChangeAbsolute"));

        verticalLayout_2->addWidget(followTrialVelocityChangeAbsolute);

        followTrialVelocityChange = new QCheckBox(followVehicleInstruction);
        followTrialVelocityChange->setObjectName(QStringLiteral("followTrialVelocityChange"));
        followTrialVelocityChange->setGeometry(QRect(40, 30, 101, 17));
        followTrialForceLaneChange = new QCheckBox(followVehicleInstruction);
        followTrialForceLaneChange->setObjectName(QStringLiteral("followTrialForceLaneChange"));
        followTrialForceLaneChange->setGeometry(QRect(40, 100, 121, 17));
        gridLayoutWidget_6 = new QWidget(followVehicleInstruction);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(60, 120, 131, 31));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        followTrialChangeLeft = new QRadioButton(gridLayoutWidget_6);
        followTrialChangeLeft->setObjectName(QStringLiteral("followTrialChangeLeft"));
        followTrialChangeLeft->setChecked(true);

        gridLayout_11->addWidget(followTrialChangeLeft, 0, 0, 1, 1);

        followTrialChangeRight = new QRadioButton(gridLayoutWidget_6);
        followTrialChangeRight->setObjectName(QStringLiteral("followTrialChangeRight"));

        gridLayout_11->addWidget(followTrialChangeRight, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        trialManager->raise();
        followVehicleInstruction->raise();
        majorFileSettings->raise();
        umtriLogo->raise();
        QWidget::setTabOrder(followSolModel, followDistanceLineEdit);
        QWidget::setTabOrder(followDistanceLineEdit, followMaxSpeedLineEdit);
        QWidget::setTabOrder(followMaxSpeedLineEdit, followMinSpeedLineEdit);
        QWidget::setTabOrder(followMinSpeedLineEdit, followMaxAccelLineEdit);
        QWidget::setTabOrder(followMaxAccelLineEdit, followMaxDecel);
        QWidget::setTabOrder(followMaxDecel, leadSolModel);
        QWidget::setTabOrder(leadSolModel, leadDistanceLineEdit);
        QWidget::setTabOrder(leadDistanceLineEdit, leadMaxSpeedLineEdit);
        QWidget::setTabOrder(leadMaxSpeedLineEdit, leadMinSpeedLineEdit);
        QWidget::setTabOrder(leadMinSpeedLineEdit, leadMaxAccelLineEdit);
        QWidget::setTabOrder(leadMaxAccelLineEdit, leadMaxDecel);
        QWidget::setTabOrder(leadMaxDecel, lengthOfRoadLineEdit);
        QWidget::setTabOrder(lengthOfRoadLineEdit, showBlindSpotWarning);
        QWidget::setTabOrder(showBlindSpotWarning, generateOpposingTraffic);
        QWidget::setTabOrder(generateOpposingTraffic, numberOpposingVehicles);
        QWidget::setTabOrder(numberOpposingVehicles, numberCars);
        QWidget::setTabOrder(numberCars, numberTrucks);
        QWidget::setTabOrder(numberTrucks, fcwOn);
        QWidget::setTabOrder(fcwOn, frequencyLineEdit);
        QWidget::setTabOrder(frequencyLineEdit, fcwPositionX);
        QWidget::setTabOrder(fcwPositionX, fcwPositionY);
        QWidget::setTabOrder(fcwPositionY, fcwPositionZ);
        QWidget::setTabOrder(fcwPositionZ, shapeOption);
        QWidget::setTabOrder(shapeOption, fcwIconName);
        QWidget::setTabOrder(fcwIconName, animationOn);
        QWidget::setTabOrder(animationOn, colorButton);
        QWidget::setTabOrder(colorButton, animationStartX);
        QWidget::setTabOrder(animationStartX, animationStartY);
        QWidget::setTabOrder(animationStartY, animationStartZ);
        QWidget::setTabOrder(animationStartZ, animationEndX);
        QWidget::setTabOrder(animationEndX, animationEndY);
        QWidget::setTabOrder(animationEndY, animationEndZ);
        QWidget::setTabOrder(animationEndZ, prevTrial);
        QWidget::setTabOrder(prevTrial, nextTrial);
        QWidget::setTabOrder(nextTrial, goToButton);
        QWidget::setTabOrder(goToButton, goToLinEdit);
        QWidget::setTabOrder(goToLinEdit, followTrialOn);
        QWidget::setTabOrder(followTrialOn, followTrialVelocityChange);
        QWidget::setTabOrder(followTrialVelocityChange, followTrialVelocityChangeMatchExternalDriver);
        QWidget::setTabOrder(followTrialVelocityChangeMatchExternalDriver, followTrialVelocityChangeAbsolute);
        QWidget::setTabOrder(followTrialVelocityChangeAbsolute, followTrialVelocityChangeAbsoluteLineEdit);
        QWidget::setTabOrder(followTrialVelocityChangeAbsoluteLineEdit, followTrialForceLaneChange);
        QWidget::setTabOrder(followTrialForceLaneChange, leadTrialOn);
        QWidget::setTabOrder(leadTrialOn, leadTrialVelocityChange);
        QWidget::setTabOrder(leadTrialVelocityChange, leadTrialVelocityChangeAbsoluteSpeed);
        QWidget::setTabOrder(leadTrialVelocityChangeAbsoluteSpeed, leadTrialForceLaneChange);
        QWidget::setTabOrder(leadTrialForceLaneChange, roadSideTrialOn);
        QWidget::setTabOrder(roadSideTrialOn, roadSideTrialRemainStationary);
        QWidget::setTabOrder(roadSideTrialRemainStationary, roadSideTrialPullFront);
        QWidget::setTabOrder(roadSideTrialPullFront, roadSideTrialPullFrontSpeed);
        QWidget::setTabOrder(roadSideTrialPullFrontSpeed, roadSideTrialPullFrontDistance);
        QWidget::setTabOrder(roadSideTrialPullFrontDistance, roadSideTrialDriveOnShoulder);
        QWidget::setTabOrder(roadSideTrialDriveOnShoulder, roadSideTrialDriveOnShoulderSpeed);
        QWidget::setTabOrder(roadSideTrialDriveOnShoulderSpeed, roadSideTrialPullFrontStop);
        QWidget::setTabOrder(roadSideTrialPullFrontStop, roadSideTrialPullFrontStopSpeed);
        QWidget::setTabOrder(roadSideTrialPullFrontStopSpeed, roadSideTrialPullFrontStopDistance);
        QWidget::setTabOrder(roadSideTrialPullFrontStopDistance, roadSideTrialBlinkerHazards);
        QWidget::setTabOrder(roadSideTrialBlinkerHazards, roadSideTrialBlinkerRight);
        QWidget::setTabOrder(roadSideTrialBlinkerRight, roadSideTrialBlinkerLeft);
        QWidget::setTabOrder(roadSideTrialBlinkerLeft, roadSideTrialBlinkerNone);
        QWidget::setTabOrder(roadSideTrialBlinkerNone, roadSideTrialAddToList);
        QWidget::setTabOrder(roadSideTrialAddToList, leftLaneTrialOn);
        QWidget::setTabOrder(leftLaneTrialOn, leftLaneTrialBlindSpot);
        QWidget::setTabOrder(leftLaneTrialBlindSpot, leftLaneTrialCutBehind);
        QWidget::setTabOrder(leftLaneTrialCutBehind, leftLaneTrialCutFront);
        QWidget::setTabOrder(leftLaneTrialCutFront, leftLaneTrialCutFrontSpeed);
        QWidget::setTabOrder(leftLaneTrialCutFrontSpeed, leftLaneTrialCutFrontDistance);
        QWidget::setTabOrder(leftLaneTrialCutFrontDistance, leftLaneTRialRemainLane);
        QWidget::setTabOrder(leftLaneTRialRemainLane, leftLaneTrialRemainLaneMatchET);
        QWidget::setTabOrder(leftLaneTrialRemainLaneMatchET, leftLaneTrialRemainLaneAbsolute);
        QWidget::setTabOrder(leftLaneTrialRemainLaneAbsolute, leftLaneTrialRemainLaneAbsoluteSpeed);
        QWidget::setTabOrder(leftLaneTrialRemainLaneAbsoluteSpeed, leftLaneTrialBlinkerHazards);
        QWidget::setTabOrder(leftLaneTrialBlinkerHazards, leftLaneTrialBlinkerRight);
        QWidget::setTabOrder(leftLaneTrialBlinkerRight, leftLaneTrialBlinkerLeft);
        QWidget::setTabOrder(leftLaneTrialBlinkerLeft, leftLaneTrialBlinkerNone);
        QWidget::setTabOrder(leftLaneTrialBlinkerNone, leftLaneTrialAddToFCW);
        QWidget::setTabOrder(leftLaneTrialAddToFCW, leftLaneTrialDistanceFromET);
        QWidget::setTabOrder(leftLaneTrialDistanceFromET, loadFile);
        QWidget::setTabOrder(loadFile, saveFileButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Expressway Scenario Interface", 0));
        umtriLogo->setText(QString());
        majorFileSettings->setTitle(QApplication::translate("MainWindow", "Major File Settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "<u>Animation", 0));
        label_6->setText(QApplication::translate("MainWindow", "Start", 0));
        label_30->setText(QApplication::translate("MainWindow", "End", 0));
        animationOn->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Frontal Crash Warning", 0));
#ifndef QT_NO_TOOLTIP
        fcwOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Generate a frontal crash warning for scenario vehicles.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fcwOn->setText(QString());
        colorButton->setText(QApplication::translate("MainWindow", "Choose Color", 0));
        colorDisplay->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Icon Name", 0));
        label_3->setText(QApplication::translate("MainWindow", "Shape", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Blind Spot Warning", 0));
#ifndef QT_NO_TOOLTIP
        showBlindSpotWarning->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Show a blind spot warning for left lane and roadside vehicles.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        showBlindSpotWarning->setText(QApplication::translate("MainWindow", "Show Warning", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Follow Vehicle", 0));
        label_11->setText(QApplication::translate("MainWindow", "feet", 0));
        label_15->setText(QApplication::translate("MainWindow", "mph", 0));
        label_32->setText(QApplication::translate("MainWindow", "mph", 0));
        label_35->setText(QApplication::translate("MainWindow", "m/s^2", 0));
        label_37->setText(QApplication::translate("MainWindow", "m/s^2", 0));
        followMinAccelLabl->setText(QApplication::translate("MainWindow", "Max Deceleration", 0));
        followMaxAccelLabel->setText(QApplication::translate("MainWindow", "Max Acceleration", 0));
        solModelLabel->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        minFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Min Speed", 0));
        followVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Distance", 0));
        maxFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Max Speed", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Lead Vehicle", 0));
        label_21->setText(QApplication::translate("MainWindow", "feet", 0));
        label_28->setText(QApplication::translate("MainWindow", "mph", 0));
        label_31->setText(QApplication::translate("MainWindow", "mph", 0));
        label_38->setText(QApplication::translate("MainWindow", "m/s^2", 0));
        label_39->setText(QApplication::translate("MainWindow", "m/s^2", 0));
#ifndef QT_NO_TOOLTIP
        leadSolModel->setToolTip(QApplication::translate("MainWindow", "Sol Model of the lead vehicle.", 0));
#endif // QT_NO_TOOLTIP
        solModelLabel_2->setText(QApplication::translate("MainWindow", "Sol Model", 0));
#ifndef QT_NO_TOOLTIP
        leadDistanceLineEdit->setToolTip(QApplication::translate("MainWindow", "Distance gap between the lead vehicle and external driver (must be negative).", 0));
#endif // QT_NO_TOOLTIP
        maxFollowSpeedLabel_2->setText(QApplication::translate("MainWindow", "Max Speed", 0));
        leadVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        leadMaxAccelLineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Maximum acceleration of the lead vehicle.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        followMaxAccelLabel_2->setText(QApplication::translate("MainWindow", "Max Acceleration", 0));
#ifndef QT_NO_TOOLTIP
        leadMaxSpeedLineEdit->setToolTip(QApplication::translate("MainWindow", "Maximum speed of lead vehicle.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        leadMinSpeedLineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Maximum speed of lead vehicle.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        followMinAccelLabl_2->setText(QApplication::translate("MainWindow", "Max Deceleration", 0));
        minFollowSpeedLabel_2->setText(QApplication::translate("MainWindow", "Min Speed", 0));
#ifndef QT_NO_TOOLTIP
        leadMaxDecel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Maximum deceleration of the follow vehicle.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followMaxAccelLineEdit->setToolTip(QApplication::translate("MainWindow", "Maximum acceleration of the follow vehicle.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followMaxDecel->setToolTip(QApplication::translate("MainWindow", "Maximum deceleration of the follow vehicle (must be a negative number).", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followMinSpeedLineEdit->setToolTip(QApplication::translate("MainWindow", "Minimum speed of the follow vehicle.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followDistanceLineEdit->setToolTip(QApplication::translate("MainWindow", "Distance gap between the follow vehicle and external driver.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followMaxSpeedLineEdit->setToolTip(QApplication::translate("MainWindow", "Maximum speed of follow vehicle.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followSolModel->setToolTip(QApplication::translate("MainWindow", "Sol Model of the follow vehicle.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        followSolModel->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lengthOfRoadLabel->setText(QApplication::translate("MainWindow", "<center>Number of Trials</center>", 0));
        fileManager->setTitle(QApplication::translate("MainWindow", "File Manager", 0));
#ifndef QT_NO_TOOLTIP
        loadFile->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Load a .scn file.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        loadFile->setText(QApplication::translate("MainWindow", "Load File", 0));
#ifndef QT_NO_TOOLTIP
        saveFileButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Save the new .scn file.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", 0));
        label_4->setText(QApplication::translate("MainWindow", "Position", 0));
        frequency->setText(QApplication::translate("MainWindow", "Frequency", 0));
#ifndef QT_NO_TOOLTIP
        lengthOfRoadLineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of trials in input file.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        numberOpposingVehicles->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of opposing lane vehicles per trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Number of Vehicles", 0));
#ifndef QT_NO_TOOLTIP
        numberCars->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of cars in car/truck ratio of opposing lane traffic.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_33->setText(QApplication::translate("MainWindow", "Cars", 0));
        label_34->setText(QApplication::translate("MainWindow", "Trucks", 0));
#ifndef QT_NO_TOOLTIP
        numberTrucks->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of trucks in car/truck ratio of opposing lane traffic.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Generate Opposing Traffic", 0));
#ifndef QT_NO_TOOLTIP
        generateOpposingTraffic->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Generate opposing lane traffic for scenario.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        generateOpposingTraffic->setText(QString());
        trialManager->setTitle(QApplication::translate("MainWindow", "Trial Manager", 0));
        leadVehicleInstructions->setTitle(QApplication::translate("MainWindow", "Lead Vehicle Instructions", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a lead vehicle change for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        leadTrialOn->setText(QString());
#ifndef QT_NO_TOOLTIP
        leadTrialVelocityChange->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Change the velocity of the lead vehicle.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        leadTrialVelocityChange->setText(QApplication::translate("MainWindow", "Velocity Change", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialForceLaneChange->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Force the lead vehicle to change lanes.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        leadTrialForceLaneChange->setText(QApplication::translate("MainWindow", "Force Lane Change", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialVelocityChangeAbsoluteSpeed->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Absolute speed value.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        leadTrialMatchExternalDriver->setToolTip(QApplication::translate("MainWindow", "Match the velocity of the external driver.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match External Driver", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialVelocityChangeAbsolute->setToolTip(QApplication::translate("MainWindow", "Set the velocity of the follow vehicle to an absolute value.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialVelocityChangeAbsolute->setText(QApplication::translate("MainWindow", "Absolute Speed", 0));
        leadTrialChangeLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        leadTrialChangeRight->setText(QApplication::translate("MainWindow", "Right", 0));
        roadSideVehicleControl->setTitle(QApplication::translate("MainWindow", "Road Side Vehicle Control", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a roadside vehicle for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialOn->setText(QString());
        roadSideTrialAddToList->setText(QApplication::translate("MainWindow", "Add To List", 0));
        label_23->setText(QApplication::translate("MainWindow", "<u><center>FCW</center></u>", 0));
        roadSideTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
        roadSideTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
        roadSideTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        roadSideTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_20->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        label_16->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_18->setText(QApplication::translate("MainWindow", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialRemainStationary->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Remain stationary on the side of the road.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialRemainStationary->setText(QApplication::translate("MainWindow", "Remain Stationary", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialDriveOnShoulder->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Drive on shoulder for entire trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialDriveOnShoulder->setText(QApplication::translate("MainWindow", "Drive On Shoulder", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFront->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Pull out in front of the external driver. </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialPullFront->setText(QApplication::translate("MainWindow", "Pull Out In Front", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFrontStop->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Pull out in front of the external driver and stop.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialPullFrontStop->setText(QApplication::translate("MainWindow", "Pull Out In Front and Stop", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFrontSpeed->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Speed for the vehicle to pull out at.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_17->setText(QApplication::translate("MainWindow", "Speed", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFrontDistance->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Distance between the external driver and the roadside vehicle when the vehicle is fully merged into traffic.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "Distance", 0));
        label_19->setText(QApplication::translate("MainWindow", "Speed", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialDriveOnShoulderSpeed->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Speed to drive on shoulder at.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialDeletionSlowDown->setText(QApplication::translate("MainWindow", "Slow Down", 0));
        roadSideTrialDeletionPullToSide->setText(QApplication::translate("MainWindow", "Pull To Side", 0));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">Deletion</span></p></body></html>", 0));
        leftLaneVehicleControl->setTitle(QApplication::translate("MainWindow", "Left Lane Vehicle Control", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a left lane vehicle for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialOn->setText(QString());
        leftLaneTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
        leftLaneTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
        leftLaneTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        leftLaneTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_26->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        label_25->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_27->setText(QApplication::translate("MainWindow", "Distance", 0));
        leftLaneTrialCutBehind->setText(QApplication::translate("MainWindow", "Cut Behind Driver", 0));
        leftLaneTrialCutFront->setText(QApplication::translate("MainWindow", "Cut In Front of Driver", 0));
        leftLaneTrialBlindSpot->setText(QApplication::translate("MainWindow", "Blind Spot", 0));
        leftLaneTRialRemainLane->setText(QApplication::translate("MainWindow", "Remain in Lane", 0));
        leftLaneTrialRemainLaneAbsolute->setText(QApplication::translate("MainWindow", "Absolute", 0));
        leftLaneTrialRemainLaneMatchET->setText(QApplication::translate("MainWindow", "Match", 0));
        label_24->setText(QApplication::translate("MainWindow", "<u><center>FCW</center></u>", 0));
        leftLaneTrialAddToFCW->setText(QApplication::translate("MainWindow", "Add To List", 0));
        label_36->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Distance</p></body></html>", 0));
        leftLaneTrialCreationFront->setText(QApplication::translate("MainWindow", "Front", 0));
        leftLaneTrialCreationBehind->setText(QApplication::translate("MainWindow", "Behind", 0));
        label_29->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">Creation</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        prevTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to the previous trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        prevTrial->setText(QApplication::translate("MainWindow", "Prev", 0));
#ifndef QT_NO_TOOLTIP
        goToLinEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to trial number.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        goToLinEdit->setText(QApplication::translate("MainWindow", "0", 0));
#ifndef QT_NO_TOOLTIP
        goToButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Jump to a given trial (number entered must be in range).</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        goToButton->setText(QApplication::translate("MainWindow", "Go To", 0));
#ifndef QT_NO_TOOLTIP
        nextTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to the next trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nextTrial->setText(QApplication::translate("MainWindow", "Next", 0));
#ifndef QT_NO_TOOLTIP
        currentTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Current trial number.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currentTrial->setText(QApplication::translate("MainWindow", "0", 0));
        followVehicleInstruction->setTitle(QApplication::translate("MainWindow", "Follow Vehicle Instructions", 0));
#ifndef QT_NO_TOOLTIP
        followTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a follow vehicle change for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        followTrialOn->setText(QString());
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChangeAbsoluteLineEdit->setToolTip(QApplication::translate("MainWindow", "Absolute speed value.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChangeMatchExternalDriver->setToolTip(QApplication::translate("MainWindow", "Match the velocity of the external driver.", 0));
#endif // QT_NO_TOOLTIP
        followTrialVelocityChangeMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match External Driver", 0));
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChangeAbsolute->setToolTip(QApplication::translate("MainWindow", "Set the velocity of the follow vehicle to an absolute value.", 0));
#endif // QT_NO_TOOLTIP
        followTrialVelocityChangeAbsolute->setText(QApplication::translate("MainWindow", "Absolute Speed", 0));
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChange->setToolTip(QApplication::translate("MainWindow", "Change the velocity of the follow vehicle.", 0));
#endif // QT_NO_TOOLTIP
        followTrialVelocityChange->setText(QApplication::translate("MainWindow", "Velocity Change", 0));
#ifndef QT_NO_TOOLTIP
        followTrialForceLaneChange->setToolTip(QApplication::translate("MainWindow", "Force the follow vehicle to change lanes.", 0));
#endif // QT_NO_TOOLTIP
        followTrialForceLaneChange->setText(QApplication::translate("MainWindow", "Force Lane Change", 0));
        followTrialChangeLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        followTrialChangeRight->setText(QApplication::translate("MainWindow", "Right", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

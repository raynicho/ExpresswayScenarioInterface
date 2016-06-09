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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *followVehicleLabel;
    QLabel *solModelLabel;
    QComboBox *followSolModel;
    QLabel *followVehicleDistanceLabel;
    QLineEdit *followDistanceLineEdit;
    QLabel *maxFollowSpeedLabel;
    QLineEdit *followMaxSpeedLineEdit;
    QLabel *minFollowSpeedLabel;
    QLineEdit *followMinSpeedLineEdit;
    QLabel *followMaxAccelLabel;
    QLineEdit *followMaxAccelLineEdit;
    QLabel *followMinAccelLabl;
    QLineEdit *followMinAccel;
    QLabel *followMaxAccelLabel_2;
    QLineEdit *leadDistanceLineEdit;
    QLabel *solModelLabel_2;
    QLabel *minFollowSpeedLabel_2;
    QLineEdit *leadMaxAccelLineEdit;
    QLabel *maxFollowSpeedLabel_2;
    QLabel *leadVehicleLabel;
    QLabel *followMinAccelLabl_2;
    QLabel *leadVehicleDistanceLabel;
    QLineEdit *leadMaxSpeedLineEdit;
    QComboBox *leadSolModel;
    QLineEdit *leadMinAccelLineEdit;
    QLineEdit *leadMinSpeedLineEdit;
    QLabel *roadwaySettingsLabel;
    QLabel *lengthOfRoadLabel;
    QLineEdit *lengthOfRoadLineEdit;
    QLabel *opposingTrafficLabel;
    QCheckBox *generateOpposingTraffic;
    QLabel *label;
    QCheckBox *showBlindSpotWarning;
    QLabel *label_2;
    QLabel *frequency;
    QLineEdit *frequencyLineEdit;
    QLabel *label_4;
    QLineEdit *fcwPositionX;
    QLineEdit *fcwPositionY;
    QLineEdit *fcwPositionZ;
    QLabel *umtriLogo;
    QLabel *label_8;
    QLineEdit *followTrialDistance;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *followTrialVelocityChangeMatchExternalDriver;
    QRadioButton *followTrialVelocityChangeAbsolute;
    QCheckBox *followTrialVelocityChange;
    QLineEdit *followTrialVelocityChangeAbsoluteLineEdit;
    QCheckBox *followTrialForceLaneChange;
    QLabel *label_9;
    QLineEdit *followTrialForceLaneChangeSpeed;
    QLabel *label_10;
    QLineEdit *followTrialForceLaneChangeAcceleration;
    QLabel *label_12;
    QLineEdit *leadTrialMaxLeadDistance;
    QCheckBox *leadTrialVelocityChange;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *leadTrialMatchExternalDriver;
    QRadioButton *leadTrialVelocityChangeAbsolute;
    QLineEdit *leadTrialVelocityChangeAbsoluteSpeed;
    QCheckBox *leadTrialForceLaneChange;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *leadTrialForceLaneChangeSpeed;
    QLineEdit *leadTrialForceLaneChangeAcceleration;
    QGroupBox *majorFileSettings;
    QCheckBox *fcwOn;
    QPushButton *colorButton;
    QLabel *colorDisplay;
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
    QLabel *label_3;
    QGroupBox *trialManager;
    QGroupBox *leadVehicleInstructions;
    QCheckBox *leadTrialOn;
    QGroupBox *roadSideVehicleControl;
    QCheckBox *roadSideTrialOn;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *roadSideTrialDeletionPullToSide;
    QRadioButton *roadSideTrialDeletionSlowDown;
    QLabel *label_22;
    QRadioButton *roadSideTrialAddToList;
    QLabel *label_23;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *roadSideTrialBlinkerHazards;
    QRadioButton *roadSideTrialBlinkerRight;
    QRadioButton *roadSideTrialBlinkerLeft;
    QRadioButton *roadSideTrialBlinkerNone;
    QLabel *label_20;
    QGroupBox *leftLaneVehicleControl;
    QLabel *label_29;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *leftLaneTrialCreationBehind;
    QRadioButton *leftLaneTrialCreationFront;
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
    QLineEdit *leftLaneTrialRemainLaneAbsoluteSpeed;
    QCheckBox *leftLaneTrialRemainLaneAbsolute;
    QCheckBox *leftLaneTrialRemainLaneMatchET;
    QLabel *label_24;
    QRadioButton *leftLaneTrialAddToFCW;
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
    QLabel *label_17;
    QLineEdit *roadSideTrialPullFrontSpeed;
    QGridLayout *gridLayout_9;
    QLabel *label_19;
    QLineEdit *roadSideTrialDriveOnShoulderSpeed;
    QPushButton *prevTrial;
    QLineEdit *goToLinEdit;
    QPushButton *goToButton;
    QPushButton *nextTrial;
    QLabel *currentTrial;
    QGroupBox *fileManager;
    QPushButton *loadFile;
    QPushButton *saveFileButton;
    QGroupBox *followVehicleInstruction;
    QCheckBox *followTrialOn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1198, 614);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        followVehicleLabel = new QLabel(centralWidget);
        followVehicleLabel->setObjectName(QStringLiteral("followVehicleLabel"));
        followVehicleLabel->setGeometry(QRect(70, 30, 81, 16));
        solModelLabel = new QLabel(centralWidget);
        solModelLabel->setObjectName(QStringLiteral("solModelLabel"));
        solModelLabel->setGeometry(QRect(30, 50, 51, 16));
        followSolModel = new QComboBox(centralWidget);
        followSolModel->setObjectName(QStringLiteral("followSolModel"));
        followSolModel->setGeometry(QRect(120, 50, 111, 22));
        followVehicleDistanceLabel = new QLabel(centralWidget);
        followVehicleDistanceLabel->setObjectName(QStringLiteral("followVehicleDistanceLabel"));
        followVehicleDistanceLabel->setGeometry(QRect(30, 80, 47, 13));
        followDistanceLineEdit = new QLineEdit(centralWidget);
        followDistanceLineEdit->setObjectName(QStringLiteral("followDistanceLineEdit"));
        followDistanceLineEdit->setGeometry(QRect(120, 80, 113, 20));
        maxFollowSpeedLabel = new QLabel(centralWidget);
        maxFollowSpeedLabel->setObjectName(QStringLiteral("maxFollowSpeedLabel"));
        maxFollowSpeedLabel->setGeometry(QRect(30, 110, 61, 16));
        followMaxSpeedLineEdit = new QLineEdit(centralWidget);
        followMaxSpeedLineEdit->setObjectName(QStringLiteral("followMaxSpeedLineEdit"));
        followMaxSpeedLineEdit->setGeometry(QRect(120, 110, 113, 20));
        minFollowSpeedLabel = new QLabel(centralWidget);
        minFollowSpeedLabel->setObjectName(QStringLiteral("minFollowSpeedLabel"));
        minFollowSpeedLabel->setGeometry(QRect(30, 140, 61, 16));
        followMinSpeedLineEdit = new QLineEdit(centralWidget);
        followMinSpeedLineEdit->setObjectName(QStringLiteral("followMinSpeedLineEdit"));
        followMinSpeedLineEdit->setGeometry(QRect(120, 140, 113, 20));
        followMaxAccelLabel = new QLabel(centralWidget);
        followMaxAccelLabel->setObjectName(QStringLiteral("followMaxAccelLabel"));
        followMaxAccelLabel->setGeometry(QRect(30, 170, 91, 16));
        followMaxAccelLineEdit = new QLineEdit(centralWidget);
        followMaxAccelLineEdit->setObjectName(QStringLiteral("followMaxAccelLineEdit"));
        followMaxAccelLineEdit->setGeometry(QRect(120, 170, 113, 20));
        followMinAccelLabl = new QLabel(centralWidget);
        followMinAccelLabl->setObjectName(QStringLiteral("followMinAccelLabl"));
        followMinAccelLabl->setGeometry(QRect(30, 200, 91, 16));
        followMinAccel = new QLineEdit(centralWidget);
        followMinAccel->setObjectName(QStringLiteral("followMinAccel"));
        followMinAccel->setGeometry(QRect(120, 200, 113, 20));
        followMaxAccelLabel_2 = new QLabel(centralWidget);
        followMaxAccelLabel_2->setObjectName(QStringLiteral("followMaxAccelLabel_2"));
        followMaxAccelLabel_2->setGeometry(QRect(270, 170, 91, 16));
        leadDistanceLineEdit = new QLineEdit(centralWidget);
        leadDistanceLineEdit->setObjectName(QStringLiteral("leadDistanceLineEdit"));
        leadDistanceLineEdit->setGeometry(QRect(360, 80, 113, 20));
        solModelLabel_2 = new QLabel(centralWidget);
        solModelLabel_2->setObjectName(QStringLiteral("solModelLabel_2"));
        solModelLabel_2->setGeometry(QRect(270, 50, 51, 16));
        minFollowSpeedLabel_2 = new QLabel(centralWidget);
        minFollowSpeedLabel_2->setObjectName(QStringLiteral("minFollowSpeedLabel_2"));
        minFollowSpeedLabel_2->setGeometry(QRect(270, 140, 61, 16));
        leadMaxAccelLineEdit = new QLineEdit(centralWidget);
        leadMaxAccelLineEdit->setObjectName(QStringLiteral("leadMaxAccelLineEdit"));
        leadMaxAccelLineEdit->setGeometry(QRect(360, 170, 113, 20));
        maxFollowSpeedLabel_2 = new QLabel(centralWidget);
        maxFollowSpeedLabel_2->setObjectName(QStringLiteral("maxFollowSpeedLabel_2"));
        maxFollowSpeedLabel_2->setGeometry(QRect(270, 110, 61, 16));
        leadVehicleLabel = new QLabel(centralWidget);
        leadVehicleLabel->setObjectName(QStringLiteral("leadVehicleLabel"));
        leadVehicleLabel->setGeometry(QRect(330, 30, 81, 16));
        followMinAccelLabl_2 = new QLabel(centralWidget);
        followMinAccelLabl_2->setObjectName(QStringLiteral("followMinAccelLabl_2"));
        followMinAccelLabl_2->setGeometry(QRect(270, 200, 91, 16));
        leadVehicleDistanceLabel = new QLabel(centralWidget);
        leadVehicleDistanceLabel->setObjectName(QStringLiteral("leadVehicleDistanceLabel"));
        leadVehicleDistanceLabel->setGeometry(QRect(270, 80, 47, 13));
        leadMaxSpeedLineEdit = new QLineEdit(centralWidget);
        leadMaxSpeedLineEdit->setObjectName(QStringLiteral("leadMaxSpeedLineEdit"));
        leadMaxSpeedLineEdit->setGeometry(QRect(360, 110, 113, 20));
        leadSolModel = new QComboBox(centralWidget);
        leadSolModel->setObjectName(QStringLiteral("leadSolModel"));
        leadSolModel->setGeometry(QRect(360, 50, 111, 22));
        leadMinAccelLineEdit = new QLineEdit(centralWidget);
        leadMinAccelLineEdit->setObjectName(QStringLiteral("leadMinAccelLineEdit"));
        leadMinAccelLineEdit->setGeometry(QRect(360, 200, 113, 20));
        leadMinSpeedLineEdit = new QLineEdit(centralWidget);
        leadMinSpeedLineEdit->setObjectName(QStringLiteral("leadMinSpeedLineEdit"));
        leadMinSpeedLineEdit->setGeometry(QRect(360, 140, 113, 20));
        roadwaySettingsLabel = new QLabel(centralWidget);
        roadwaySettingsLabel->setObjectName(QStringLiteral("roadwaySettingsLabel"));
        roadwaySettingsLabel->setGeometry(QRect(80, 240, 91, 16));
        lengthOfRoadLabel = new QLabel(centralWidget);
        lengthOfRoadLabel->setObjectName(QStringLiteral("lengthOfRoadLabel"));
        lengthOfRoadLabel->setGeometry(QRect(30, 270, 81, 16));
        lengthOfRoadLineEdit = new QLineEdit(centralWidget);
        lengthOfRoadLineEdit->setObjectName(QStringLiteral("lengthOfRoadLineEdit"));
        lengthOfRoadLineEdit->setGeometry(QRect(120, 270, 111, 20));
        opposingTrafficLabel = new QLabel(centralWidget);
        opposingTrafficLabel->setObjectName(QStringLiteral("opposingTrafficLabel"));
        opposingTrafficLabel->setGeometry(QRect(350, 240, 81, 20));
        generateOpposingTraffic = new QCheckBox(centralWidget);
        generateOpposingTraffic->setObjectName(QStringLiteral("generateOpposingTraffic"));
        generateOpposingTraffic->setGeometry(QRect(280, 270, 221, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 310, 91, 20));
        showBlindSpotWarning = new QCheckBox(centralWidget);
        showBlindSpotWarning->setObjectName(QStringLiteral("showBlindSpotWarning"));
        showBlindSpotWarning->setGeometry(QRect(30, 340, 151, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 310, 111, 16));
        frequency = new QLabel(centralWidget);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setGeometry(QRect(180, 340, 51, 16));
        frequencyLineEdit = new QLineEdit(centralWidget);
        frequencyLineEdit->setObjectName(QStringLiteral("frequencyLineEdit"));
        frequencyLineEdit->setGeometry(QRect(240, 340, 101, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 370, 47, 13));
        fcwPositionX = new QLineEdit(centralWidget);
        fcwPositionX->setObjectName(QStringLiteral("fcwPositionX"));
        fcwPositionX->setGeometry(QRect(240, 370, 41, 20));
        fcwPositionY = new QLineEdit(centralWidget);
        fcwPositionY->setObjectName(QStringLiteral("fcwPositionY"));
        fcwPositionY->setGeometry(QRect(280, 370, 41, 20));
        fcwPositionZ = new QLineEdit(centralWidget);
        fcwPositionZ->setObjectName(QStringLiteral("fcwPositionZ"));
        fcwPositionZ->setGeometry(QRect(320, 370, 41, 20));
        umtriLogo = new QLabel(centralWidget);
        umtriLogo->setObjectName(QStringLiteral("umtriLogo"));
        umtriLogo->setGeometry(QRect(210, 500, 331, 71));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(620, 90, 101, 16));
        followTrialDistance = new QLineEdit(centralWidget);
        followTrialDistance->setObjectName(QStringLiteral("followTrialDistance"));
        followTrialDistance->setGeometry(QRect(740, 90, 113, 20));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(640, 130, 129, 42));
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

        followTrialVelocityChange = new QCheckBox(centralWidget);
        followTrialVelocityChange->setObjectName(QStringLiteral("followTrialVelocityChange"));
        followTrialVelocityChange->setGeometry(QRect(620, 110, 101, 17));
        followTrialVelocityChangeAbsoluteLineEdit = new QLineEdit(centralWidget);
        followTrialVelocityChangeAbsoluteLineEdit->setObjectName(QStringLiteral("followTrialVelocityChangeAbsoluteLineEdit"));
        followTrialVelocityChangeAbsoluteLineEdit->setGeometry(QRect(740, 150, 113, 20));
        followTrialForceLaneChange = new QCheckBox(centralWidget);
        followTrialForceLaneChange->setObjectName(QStringLiteral("followTrialForceLaneChange"));
        followTrialForceLaneChange->setGeometry(QRect(620, 180, 121, 17));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(640, 200, 41, 16));
        followTrialForceLaneChangeSpeed = new QLineEdit(centralWidget);
        followTrialForceLaneChangeSpeed->setObjectName(QStringLiteral("followTrialForceLaneChangeSpeed"));
        followTrialForceLaneChangeSpeed->setGeometry(QRect(740, 200, 113, 20));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(640, 220, 61, 16));
        followTrialForceLaneChangeAcceleration = new QLineEdit(centralWidget);
        followTrialForceLaneChangeAcceleration->setObjectName(QStringLiteral("followTrialForceLaneChangeAcceleration"));
        followTrialForceLaneChangeAcceleration->setGeometry(QRect(740, 220, 113, 20));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(930, 90, 91, 16));
        leadTrialMaxLeadDistance = new QLineEdit(centralWidget);
        leadTrialMaxLeadDistance->setObjectName(QStringLiteral("leadTrialMaxLeadDistance"));
        leadTrialMaxLeadDistance->setGeometry(QRect(1050, 90, 113, 20));
        leadTrialVelocityChange = new QCheckBox(centralWidget);
        leadTrialVelocityChange->setObjectName(QStringLiteral("leadTrialVelocityChange"));
        leadTrialVelocityChange->setGeometry(QRect(930, 110, 101, 17));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(950, 130, 129, 42));
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

        leadTrialVelocityChangeAbsoluteSpeed = new QLineEdit(centralWidget);
        leadTrialVelocityChangeAbsoluteSpeed->setObjectName(QStringLiteral("leadTrialVelocityChangeAbsoluteSpeed"));
        leadTrialVelocityChangeAbsoluteSpeed->setGeometry(QRect(1050, 150, 113, 20));
        leadTrialForceLaneChange = new QCheckBox(centralWidget);
        leadTrialForceLaneChange->setObjectName(QStringLiteral("leadTrialForceLaneChange"));
        leadTrialForceLaneChange->setGeometry(QRect(930, 180, 111, 17));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(950, 200, 41, 16));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(950, 220, 61, 16));
        leadTrialForceLaneChangeSpeed = new QLineEdit(centralWidget);
        leadTrialForceLaneChangeSpeed->setObjectName(QStringLiteral("leadTrialForceLaneChangeSpeed"));
        leadTrialForceLaneChangeSpeed->setGeometry(QRect(1050, 200, 113, 20));
        leadTrialForceLaneChangeAcceleration = new QLineEdit(centralWidget);
        leadTrialForceLaneChangeAcceleration->setObjectName(QStringLiteral("leadTrialForceLaneChangeAcceleration"));
        leadTrialForceLaneChangeAcceleration->setGeometry(QRect(1050, 220, 113, 20));
        majorFileSettings = new QGroupBox(centralWidget);
        majorFileSettings->setObjectName(QStringLiteral("majorFileSettings"));
        majorFileSettings->setGeometry(QRect(10, 10, 561, 471));
        fcwOn = new QCheckBox(majorFileSettings);
        fcwOn->setObjectName(QStringLiteral("fcwOn"));
        fcwOn->setGeometry(QRect(230, 300, 16, 17));
        colorButton = new QPushButton(majorFileSettings);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(370, 360, 75, 23));
        colorDisplay = new QLabel(majorFileSettings);
        colorDisplay->setObjectName(QStringLiteral("colorDisplay"));
        colorDisplay->setGeometry(QRect(460, 360, 91, 21));
        label_5 = new QLabel(majorFileSettings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 390, 51, 16));
        animationStartZ = new QLineEdit(majorFileSettings);
        animationStartZ->setObjectName(QStringLiteral("animationStartZ"));
        animationStartZ->setGeometry(QRect(400, 410, 41, 20));
        label_6 = new QLabel(majorFileSettings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 410, 47, 13));
        animationStartY = new QLineEdit(majorFileSettings);
        animationStartY->setObjectName(QStringLiteral("animationStartY"));
        animationStartY->setGeometry(QRect(360, 410, 41, 20));
        animationEndZ = new QLineEdit(majorFileSettings);
        animationEndZ->setObjectName(QStringLiteral("animationEndZ"));
        animationEndZ->setGeometry(QRect(400, 430, 41, 20));
        animationStartX = new QLineEdit(majorFileSettings);
        animationStartX->setObjectName(QStringLiteral("animationStartX"));
        animationStartX->setGeometry(QRect(320, 410, 41, 20));
        animationEndX = new QLineEdit(majorFileSettings);
        animationEndX->setObjectName(QStringLiteral("animationEndX"));
        animationEndX->setGeometry(QRect(320, 430, 41, 20));
        animationEndY = new QLineEdit(majorFileSettings);
        animationEndY->setObjectName(QStringLiteral("animationEndY"));
        animationEndY->setGeometry(QRect(360, 430, 41, 20));
        label_30 = new QLabel(majorFileSettings);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(260, 430, 31, 16));
        animationOn = new QCheckBox(majorFileSettings);
        animationOn->setObjectName(QStringLiteral("animationOn"));
        animationOn->setGeometry(QRect(310, 390, 16, 17));
        label_3 = new QLabel(majorFileSettings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 330, 47, 13));
        trialManager = new QGroupBox(centralWidget);
        trialManager->setObjectName(QStringLiteral("trialManager"));
        trialManager->setGeometry(QRect(570, 10, 621, 591));
        leadVehicleInstructions = new QGroupBox(trialManager);
        leadVehicleInstructions->setObjectName(QStringLiteral("leadVehicleInstructions"));
        leadVehicleInstructions->setGeometry(QRect(320, 50, 291, 191));
        leadTrialOn = new QCheckBox(leadVehicleInstructions);
        leadTrialOn->setObjectName(QStringLiteral("leadTrialOn"));
        leadTrialOn->setGeometry(QRect(130, 0, 16, 17));
        roadSideVehicleControl = new QGroupBox(trialManager);
        roadSideVehicleControl->setObjectName(QStringLiteral("roadSideVehicleControl"));
        roadSideVehicleControl->setGeometry(QRect(10, 240, 311, 341));
        roadSideTrialOn = new QCheckBox(roadSideVehicleControl);
        roadSideTrialOn->setObjectName(QStringLiteral("roadSideTrialOn"));
        roadSideTrialOn->setGeometry(QRect(140, 0, 16, 17));
        verticalLayoutWidget_4 = new QWidget(roadSideVehicleControl);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(20, 290, 81, 42));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        roadSideTrialDeletionPullToSide = new QRadioButton(verticalLayoutWidget_4);
        roadSideTrialDeletionPullToSide->setObjectName(QStringLiteral("roadSideTrialDeletionPullToSide"));
        roadSideTrialDeletionPullToSide->setChecked(true);

        verticalLayout_5->addWidget(roadSideTrialDeletionPullToSide);

        roadSideTrialDeletionSlowDown = new QRadioButton(verticalLayoutWidget_4);
        roadSideTrialDeletionSlowDown->setObjectName(QStringLiteral("roadSideTrialDeletionSlowDown"));

        verticalLayout_5->addWidget(roadSideTrialDeletionSlowDown);

        label_22 = new QLabel(roadSideVehicleControl);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(40, 270, 41, 16));
        roadSideTrialAddToList = new QRadioButton(roadSideVehicleControl);
        roadSideTrialAddToList->setObjectName(QStringLiteral("roadSideTrialAddToList"));
        roadSideTrialAddToList->setGeometry(QRect(180, 220, 82, 17));
        label_23 = new QLabel(roadSideVehicleControl);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(200, 190, 31, 16));
        gridLayoutWidget_2 = new QWidget(roadSideVehicleControl);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 210, 131, 42));
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
        leftLaneVehicleControl = new QGroupBox(trialManager);
        leftLaneVehicleControl->setObjectName(QStringLiteral("leftLaneVehicleControl"));
        leftLaneVehicleControl->setGeometry(QRect(320, 240, 291, 341));
        label_29 = new QLabel(leftLaneVehicleControl);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(20, 270, 47, 13));
        verticalLayoutWidget_6 = new QWidget(leftLaneVehicleControl);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 290, 61, 42));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialCreationBehind = new QRadioButton(verticalLayoutWidget_6);
        leftLaneTrialCreationBehind->setObjectName(QStringLiteral("leftLaneTrialCreationBehind"));
        leftLaneTrialCreationBehind->setChecked(true);

        verticalLayout_7->addWidget(leftLaneTrialCreationBehind);

        leftLaneTrialCreationFront = new QRadioButton(verticalLayoutWidget_6);
        leftLaneTrialCreationFront->setObjectName(QStringLiteral("leftLaneTrialCreationFront"));

        verticalLayout_7->addWidget(leftLaneTrialCreationFront);

        leftLaneTrialOn = new QCheckBox(leftLaneVehicleControl);
        leftLaneTrialOn->setObjectName(QStringLiteral("leftLaneTrialOn"));
        leftLaneTrialOn->setGeometry(QRect(130, 0, 16, 17));
        gridLayoutWidget_5 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 220, 121, 42));
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
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 271, 168));
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
        leftLaneTrialRemainLaneAbsoluteSpeed = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialRemainLaneAbsoluteSpeed->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsoluteSpeed"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsoluteSpeed, 0, 1, 1, 1);

        leftLaneTrialRemainLaneAbsolute = new QCheckBox(gridLayoutWidget_3);
        leftLaneTrialRemainLaneAbsolute->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsolute"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsolute, 0, 0, 1, 1);

        leftLaneTrialRemainLaneMatchET = new QCheckBox(gridLayoutWidget_3);
        leftLaneTrialRemainLaneMatchET->setObjectName(QStringLiteral("leftLaneTrialRemainLaneMatchET"));
        leftLaneTrialRemainLaneMatchET->setChecked(true);

        gridLayout_4->addWidget(leftLaneTrialRemainLaneMatchET, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 5, 2, 1, 1);

        label_24 = new QLabel(leftLaneVehicleControl);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(200, 200, 31, 16));
        leftLaneTrialAddToFCW = new QRadioButton(leftLaneVehicleControl);
        leftLaneTrialAddToFCW->setObjectName(QStringLiteral("leftLaneTrialAddToFCW"));
        leftLaneTrialAddToFCW->setGeometry(QRect(180, 220, 71, 17));
        gridLayoutWidget = new QWidget(trialManager);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 260, 291, 165));
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
        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        roadSideTrialPullFrontSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontSpeed->setObjectName(QStringLiteral("roadSideTrialPullFrontSpeed"));

        gridLayout_8->addWidget(roadSideTrialPullFrontSpeed, 0, 1, 1, 1);


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
        currentTrial->setGeometry(QRect(180, 20, 31, 21));
        leftLaneVehicleControl->raise();
        roadSideVehicleControl->raise();
        leadVehicleInstructions->raise();
        gridLayoutWidget->raise();
        prevTrial->raise();
        goToLinEdit->raise();
        goToButton->raise();
        nextTrial->raise();
        currentTrial->raise();
        fileManager = new QGroupBox(centralWidget);
        fileManager->setObjectName(QStringLiteral("fileManager"));
        fileManager->setGeometry(QRect(10, 490, 171, 91));
        loadFile = new QPushButton(fileManager);
        loadFile->setObjectName(QStringLiteral("loadFile"));
        loadFile->setGeometry(QRect(20, 20, 131, 21));
        saveFileButton = new QPushButton(fileManager);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(20, 60, 131, 23));
        followVehicleInstruction = new QGroupBox(centralWidget);
        followVehicleInstruction->setObjectName(QStringLiteral("followVehicleInstruction"));
        followVehicleInstruction->setGeometry(QRect(580, 60, 311, 191));
        followTrialOn = new QCheckBox(followVehicleInstruction);
        followTrialOn->setObjectName(QStringLiteral("followTrialOn"));
        followTrialOn->setGeometry(QRect(140, 0, 16, 17));
        MainWindow->setCentralWidget(centralWidget);
        trialManager->raise();
        followVehicleInstruction->raise();
        fileManager->raise();
        majorFileSettings->raise();
        followVehicleLabel->raise();
        solModelLabel->raise();
        followSolModel->raise();
        followVehicleDistanceLabel->raise();
        followDistanceLineEdit->raise();
        maxFollowSpeedLabel->raise();
        followMaxSpeedLineEdit->raise();
        minFollowSpeedLabel->raise();
        followMinSpeedLineEdit->raise();
        followMaxAccelLabel->raise();
        followMaxAccelLineEdit->raise();
        followMinAccelLabl->raise();
        followMinAccel->raise();
        followMaxAccelLabel_2->raise();
        leadDistanceLineEdit->raise();
        solModelLabel_2->raise();
        minFollowSpeedLabel_2->raise();
        leadMaxAccelLineEdit->raise();
        maxFollowSpeedLabel_2->raise();
        leadVehicleLabel->raise();
        followMinAccelLabl_2->raise();
        leadVehicleDistanceLabel->raise();
        leadMaxSpeedLineEdit->raise();
        leadSolModel->raise();
        leadMinAccelLineEdit->raise();
        leadMinSpeedLineEdit->raise();
        roadwaySettingsLabel->raise();
        lengthOfRoadLabel->raise();
        lengthOfRoadLineEdit->raise();
        opposingTrafficLabel->raise();
        generateOpposingTraffic->raise();
        label->raise();
        showBlindSpotWarning->raise();
        label_2->raise();
        frequency->raise();
        frequencyLineEdit->raise();
        label_4->raise();
        fcwPositionX->raise();
        fcwPositionY->raise();
        fcwPositionZ->raise();
        umtriLogo->raise();
        label_8->raise();
        followTrialDistance->raise();
        verticalLayoutWidget->raise();
        followTrialVelocityChange->raise();
        followTrialVelocityChangeAbsoluteLineEdit->raise();
        followTrialForceLaneChange->raise();
        label_9->raise();
        followTrialForceLaneChangeSpeed->raise();
        label_10->raise();
        followTrialForceLaneChangeAcceleration->raise();
        label_12->raise();
        leadTrialMaxLeadDistance->raise();
        leadTrialVelocityChange->raise();
        verticalLayoutWidget_2->raise();
        leadTrialVelocityChangeAbsoluteSpeed->raise();
        leadTrialForceLaneChange->raise();
        label_13->raise();
        label_14->raise();
        leadTrialForceLaneChangeSpeed->raise();
        leadTrialForceLaneChangeAcceleration->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        followVehicleLabel->setText(QApplication::translate("MainWindow", "<u>Follow Vehicle</u>", 0));
        solModelLabel->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        followVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Distance", 0));
        maxFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Max Speed", 0));
        minFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Min Speed", 0));
        followMaxAccelLabel->setText(QApplication::translate("MainWindow", "Max Acceleration", 0));
        followMinAccelLabl->setText(QApplication::translate("MainWindow", "Min Acceleration", 0));
        followMaxAccelLabel_2->setText(QApplication::translate("MainWindow", "Max Acceleration", 0));
        solModelLabel_2->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        minFollowSpeedLabel_2->setText(QApplication::translate("MainWindow", "Min Speed", 0));
        maxFollowSpeedLabel_2->setText(QApplication::translate("MainWindow", "Max Speed", 0));
        leadVehicleLabel->setText(QApplication::translate("MainWindow", "<u>Lead Vehicle</u>", 0));
        followMinAccelLabl_2->setText(QApplication::translate("MainWindow", "Min Acceleration", 0));
        leadVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Distance", 0));
        roadwaySettingsLabel->setText(QApplication::translate("MainWindow", "<u>Roadway Settings</u>", 0));
        lengthOfRoadLabel->setText(QApplication::translate("MainWindow", "Number of Trials", 0));
        opposingTrafficLabel->setText(QApplication::translate("MainWindow", "<u>Opposing Traffic</u>", 0));
        generateOpposingTraffic->setText(QApplication::translate("MainWindow", "Generate Opposing Traffic Upon Creation", 0));
        label->setText(QApplication::translate("MainWindow", "<u>Blind Spot Warning</u>", 0));
        showBlindSpotWarning->setText(QApplication::translate("MainWindow", "Show Blind Spot Warning", 0));
        label_2->setText(QApplication::translate("MainWindow", "<u>Frontal Crash Warning</u>", 0));
        frequency->setText(QApplication::translate("MainWindow", "Frequency", 0));
        label_4->setText(QApplication::translate("MainWindow", "Position", 0));
        umtriLogo->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Max Follow Distance", 0));
        followTrialVelocityChangeMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match External Driver", 0));
        followTrialVelocityChangeAbsolute->setText(QApplication::translate("MainWindow", "Absolute Speed", 0));
        followTrialVelocityChange->setText(QApplication::translate("MainWindow", "Velocity Change", 0));
        followTrialForceLaneChange->setText(QApplication::translate("MainWindow", "Force Lane Change", 0));
        label_9->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_10->setText(QApplication::translate("MainWindow", "Acceleration", 0));
        label_12->setText(QApplication::translate("MainWindow", "Max Lead Distance", 0));
        leadTrialVelocityChange->setText(QApplication::translate("MainWindow", "Velocity Change", 0));
        leadTrialMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match External Driver", 0));
        leadTrialVelocityChangeAbsolute->setText(QApplication::translate("MainWindow", "Absolute Speed", 0));
        leadTrialForceLaneChange->setText(QApplication::translate("MainWindow", "Force Lane Change", 0));
        label_13->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_14->setText(QApplication::translate("MainWindow", "Acceleration", 0));
        majorFileSettings->setTitle(QApplication::translate("MainWindow", "Major File Settings", 0));
        fcwOn->setText(QString());
        colorButton->setText(QApplication::translate("MainWindow", "Choose Color", 0));
        colorDisplay->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "<u>Animation", 0));
        label_6->setText(QApplication::translate("MainWindow", "Start", 0));
        label_30->setText(QApplication::translate("MainWindow", "End", 0));
        animationOn->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Shape", 0));
        trialManager->setTitle(QApplication::translate("MainWindow", "Trial Manager", 0));
        leadVehicleInstructions->setTitle(QApplication::translate("MainWindow", "Lead Vehicle Instructions", 0));
        leadTrialOn->setText(QString());
        roadSideVehicleControl->setTitle(QApplication::translate("MainWindow", "Road Side Vehicle Control", 0));
        roadSideTrialOn->setText(QString());
        roadSideTrialDeletionPullToSide->setText(QApplication::translate("MainWindow", "Pull To Side", 0));
        roadSideTrialDeletionSlowDown->setText(QApplication::translate("MainWindow", "Slow Down", 0));
        label_22->setText(QApplication::translate("MainWindow", "<u>Deletion</u>", 0));
        roadSideTrialAddToList->setText(QApplication::translate("MainWindow", "Add To List", 0));
        label_23->setText(QApplication::translate("MainWindow", "<u><center>FCW</center></u>", 0));
        roadSideTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
        roadSideTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
        roadSideTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        roadSideTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_20->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        leftLaneVehicleControl->setTitle(QApplication::translate("MainWindow", "Left Lane Vehicle Control", 0));
        label_29->setText(QApplication::translate("MainWindow", "<u>Creation</u>", 0));
        leftLaneTrialCreationBehind->setText(QApplication::translate("MainWindow", "Behind", 0));
        leftLaneTrialCreationFront->setText(QApplication::translate("MainWindow", "Front", 0));
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
        label_16->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_18->setText(QApplication::translate("MainWindow", "Distance", 0));
        roadSideTrialRemainStationary->setText(QApplication::translate("MainWindow", "Remain Stationary", 0));
        roadSideTrialDriveOnShoulder->setText(QApplication::translate("MainWindow", "Drive On Shoulder", 0));
        roadSideTrialPullFront->setText(QApplication::translate("MainWindow", "Pull Out In Front", 0));
        roadSideTrialPullFrontStop->setText(QApplication::translate("MainWindow", "Pull Out In Front and Stop", 0));
        label_17->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_19->setText(QApplication::translate("MainWindow", "Speed", 0));
        prevTrial->setText(QApplication::translate("MainWindow", "Prev", 0));
        goToLinEdit->setText(QApplication::translate("MainWindow", "0", 0));
        goToButton->setText(QApplication::translate("MainWindow", "Go To", 0));
        nextTrial->setText(QApplication::translate("MainWindow", "Next", 0));
        currentTrial->setText(QApplication::translate("MainWindow", "0", 0));
        fileManager->setTitle(QApplication::translate("MainWindow", "File Manager", 0));
        loadFile->setText(QApplication::translate("MainWindow", "Load File", 0));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", 0));
        followVehicleInstruction->setTitle(QApplication::translate("MainWindow", "Follow Vehicle Instructions", 0));
        followTrialOn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

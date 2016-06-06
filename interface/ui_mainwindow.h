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
    QPushButton *loadFile;
    QLabel *fileStatus;
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
    QComboBox *fcwComboBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *fcwPositionX;
    QLineEdit *fcwPositionY;
    QLineEdit *fcwPositionZ;
    QLabel *label_5;
    QLineEdit *fcwColorLineEdit;
    QLabel *umtriLogo;
    QLabel *currentTrial;
    QPushButton *nextTrial;
    QPushButton *prevTrial;
    QPushButton *saveFileButton;
    QLineEdit *goToLinEdit;
    QPushButton *goToButton;
    QLabel *label_8;
    QLineEdit *trialFollowDistance;
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
    QLineEdit *followTialForceLaneChangeAcceleration;
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
    QLabel *label_6;
    QLineEdit *animationStartY;
    QLineEdit *animationStartZ;
    QLineEdit *animationStartX;
    QLabel *label_30;
    QLineEdit *animationEndX;
    QLineEdit *animationEndZ;
    QLineEdit *animationEndY;
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
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *roadSideTrialLifeTimeExperiment;
    QRadioButton *roadSideTrialLifeTimeTrial;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *roadSideTrialBlinkerHazards;
    QRadioButton *roadSideTrialBlinkerRight;
    QRadioButton *roadSideTrialBlinkerLeft;
    QRadioButton *roadSideTrialBlinkerNone;
    QLabel *label_20;
    QLabel *label_21;
    QGroupBox *leftLaneVehicleControl;
    QLabel *label_29;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *leftLaneTrialCreationBehind;
    QRadioButton *leftLaneTrialCreationFront;
    QCheckBox *leftLaneTrialOn;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *leftLaneTrialRemainLaneAbsoluteSpeed;
    QRadioButton *leftLaneTrialRemainLaneAbsolute;
    QRadioButton *leftLaneTrialRemainLaneMatchET;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *leftLaneTrialLifetimeExperiment;
    QRadioButton *leftLaneTrialLifetimeTrial;
    QLabel *label_28;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QRadioButton *leftLaneTrialBlinkerHazards;
    QRadioButton *leftLaneTrialBlinkerRight;
    QRadioButton *leftLaneTrialBlinkerLeft;
    QRadioButton *leftLaneTrialBlinkerNone;
    QLabel *label_26;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *leftLaneTrialCutFrontSpeed;
    QLabel *label_25;
    QLineEdit *leftLaneTrialCutFrontDistance;
    QRadioButton *leftLaneTrialBlindSpot;
    QRadioButton *leftLaneTRialRemainLane;
    QRadioButton *leftLaneTrialCutBehind;
    QRadioButton *leftLaneTrialCutFront;
    QLabel *label_27;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLineEdit *roadSideTrialDirveOnShoulderSpeed;
    QRadioButton *roadSideTrialRemainStationary;
    QRadioButton *roadSideTrialDriveOnShoulder;
    QLineEdit *roadSideTrialPullFrontSpeed;
    QLabel *label_17;
    QRadioButton *roadSideTrialPullFront;
    QRadioButton *roadSideTrialPullFrontStop;
    QLabel *label_16;
    QLineEdit *roadSideTrialPullFrontStopSpeed;
    QLabel *label_18;
    QLineEdit *roadSideTrialPullFrontStopDistance;
    QGroupBox *fileManager;
    QGroupBox *followVehicleInstruction;
    QCheckBox *followTrialOn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1220, 614);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loadFile = new QPushButton(centralWidget);
        loadFile->setObjectName(QStringLiteral("loadFile"));
        loadFile->setGeometry(QRect(30, 490, 131, 21));
        fileStatus = new QLabel(centralWidget);
        fileStatus->setObjectName(QStringLiteral("fileStatus"));
        fileStatus->setGeometry(QRect(30, 520, 161, 16));
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
        fcwComboBox = new QComboBox(centralWidget);
        fcwComboBox->setObjectName(QStringLiteral("fcwComboBox"));
        fcwComboBox->setGeometry(QRect(400, 340, 101, 22));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 340, 47, 13));
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
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 370, 47, 13));
        fcwColorLineEdit = new QLineEdit(centralWidget);
        fcwColorLineEdit->setObjectName(QStringLiteral("fcwColorLineEdit"));
        fcwColorLineEdit->setGeometry(QRect(400, 370, 101, 20));
        umtriLogo = new QLabel(centralWidget);
        umtriLogo->setObjectName(QStringLiteral("umtriLogo"));
        umtriLogo->setGeometry(QRect(210, 470, 211, 41));
        currentTrial = new QLabel(centralWidget);
        currentTrial->setObjectName(QStringLiteral("currentTrial"));
        currentTrial->setGeometry(QRect(760, 30, 16, 21));
        nextTrial = new QPushButton(centralWidget);
        nextTrial->setObjectName(QStringLiteral("nextTrial"));
        nextTrial->setGeometry(QRect(780, 30, 41, 23));
        prevTrial = new QPushButton(centralWidget);
        prevTrial->setObjectName(QStringLiteral("prevTrial"));
        prevTrial->setGeometry(QRect(714, 30, 41, 23));
        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(30, 540, 131, 23));
        goToLinEdit = new QLineEdit(centralWidget);
        goToLinEdit->setObjectName(QStringLiteral("goToLinEdit"));
        goToLinEdit->setGeometry(QRect(910, 30, 61, 20));
        goToButton = new QPushButton(centralWidget);
        goToButton->setObjectName(QStringLiteral("goToButton"));
        goToButton->setGeometry(QRect(830, 30, 71, 23));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(620, 90, 101, 16));
        trialFollowDistance = new QLineEdit(centralWidget);
        trialFollowDistance->setObjectName(QStringLiteral("trialFollowDistance"));
        trialFollowDistance->setGeometry(QRect(740, 90, 113, 20));
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
        followTialForceLaneChangeAcceleration = new QLineEdit(centralWidget);
        followTialForceLaneChangeAcceleration->setObjectName(QStringLiteral("followTialForceLaneChangeAcceleration"));
        followTialForceLaneChangeAcceleration->setGeometry(QRect(740, 220, 113, 20));
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
        majorFileSettings->setGeometry(QRect(10, 10, 561, 421));
        label_6 = new QLabel(majorFileSettings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(170, 390, 47, 13));
        animationStartY = new QLineEdit(majorFileSettings);
        animationStartY->setObjectName(QStringLiteral("animationStartY"));
        animationStartY->setGeometry(QRect(270, 390, 41, 20));
        animationStartZ = new QLineEdit(majorFileSettings);
        animationStartZ->setObjectName(QStringLiteral("animationStartZ"));
        animationStartZ->setGeometry(QRect(310, 390, 41, 20));
        animationStartX = new QLineEdit(majorFileSettings);
        animationStartX->setObjectName(QStringLiteral("animationStartX"));
        animationStartX->setGeometry(QRect(230, 390, 41, 20));
        label_30 = new QLabel(majorFileSettings);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(360, 390, 31, 16));
        animationEndX = new QLineEdit(majorFileSettings);
        animationEndX->setObjectName(QStringLiteral("animationEndX"));
        animationEndX->setGeometry(QRect(390, 390, 41, 20));
        animationEndZ = new QLineEdit(majorFileSettings);
        animationEndZ->setObjectName(QStringLiteral("animationEndZ"));
        animationEndZ->setGeometry(QRect(470, 390, 41, 20));
        animationEndY = new QLineEdit(majorFileSettings);
        animationEndY->setObjectName(QStringLiteral("animationEndY"));
        animationEndY->setGeometry(QRect(430, 390, 41, 20));
        trialManager = new QGroupBox(centralWidget);
        trialManager->setObjectName(QStringLiteral("trialManager"));
        trialManager->setGeometry(QRect(570, 10, 641, 591));
        leadVehicleInstructions = new QGroupBox(trialManager);
        leadVehicleInstructions->setObjectName(QStringLiteral("leadVehicleInstructions"));
        leadVehicleInstructions->setGeometry(QRect(320, 50, 311, 191));
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
        verticalLayoutWidget_4->setGeometry(QRect(20, 270, 81, 42));
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
        label_22->setGeometry(QRect(40, 250, 41, 16));
        roadSideTrialAddToList = new QRadioButton(roadSideVehicleControl);
        roadSideTrialAddToList->setObjectName(QStringLiteral("roadSideTrialAddToList"));
        roadSideTrialAddToList->setGeometry(QRect(190, 290, 82, 17));
        label_23 = new QLabel(roadSideVehicleControl);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(210, 260, 31, 16));
        verticalLayoutWidget_3 = new QWidget(roadSideVehicleControl);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(190, 210, 84, 42));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        roadSideTrialLifeTimeExperiment = new QRadioButton(verticalLayoutWidget_3);
        roadSideTrialLifeTimeExperiment->setObjectName(QStringLiteral("roadSideTrialLifeTimeExperiment"));

        verticalLayout_4->addWidget(roadSideTrialLifeTimeExperiment);

        roadSideTrialLifeTimeTrial = new QRadioButton(verticalLayoutWidget_3);
        roadSideTrialLifeTimeTrial->setObjectName(QStringLiteral("roadSideTrialLifeTimeTrial"));
        roadSideTrialLifeTimeTrial->setChecked(true);

        verticalLayout_4->addWidget(roadSideTrialLifeTimeTrial);

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
        label_21 = new QLabel(roadSideVehicleControl);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(210, 190, 41, 20));
        roadSideTrialOn->raise();
        verticalLayoutWidget_4->raise();
        label_22->raise();
        roadSideTrialAddToList->raise();
        label_23->raise();
        verticalLayoutWidget_3->raise();
        gridLayoutWidget_2->raise();
        label_20->raise();
        label_21->raise();
        leftLaneVehicleControl = new QGroupBox(trialManager);
        leftLaneVehicleControl->setObjectName(QStringLiteral("leftLaneVehicleControl"));
        leftLaneVehicleControl->setGeometry(QRect(320, 240, 311, 341));
        label_29 = new QLabel(leftLaneVehicleControl);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(20, 260, 47, 13));
        verticalLayoutWidget_6 = new QWidget(leftLaneVehicleControl);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 280, 61, 51));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialCreationBehind = new QRadioButton(verticalLayoutWidget_6);
        leftLaneTrialCreationBehind->setObjectName(QStringLiteral("leftLaneTrialCreationBehind"));

        verticalLayout_7->addWidget(leftLaneTrialCreationBehind);

        leftLaneTrialCreationFront = new QRadioButton(verticalLayoutWidget_6);
        leftLaneTrialCreationFront->setObjectName(QStringLiteral("leftLaneTrialCreationFront"));

        verticalLayout_7->addWidget(leftLaneTrialCreationFront);

        leftLaneTrialOn = new QCheckBox(leftLaneVehicleControl);
        leftLaneTrialOn->setObjectName(QStringLiteral("leftLaneTrialOn"));
        leftLaneTrialOn->setGeometry(QRect(130, 0, 16, 17));
        gridLayoutWidget_4 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(140, 160, 161, 51));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialRemainLaneAbsoluteSpeed = new QLineEdit(gridLayoutWidget_4);
        leftLaneTrialRemainLaneAbsoluteSpeed->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsoluteSpeed"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsoluteSpeed, 0, 1, 1, 1);

        leftLaneTrialRemainLaneAbsolute = new QRadioButton(gridLayoutWidget_4);
        leftLaneTrialRemainLaneAbsolute->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsolute"));
        leftLaneTrialRemainLaneAbsolute->setChecked(true);

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsolute, 0, 0, 1, 1);

        leftLaneTrialRemainLaneMatchET = new QRadioButton(gridLayoutWidget_4);
        leftLaneTrialRemainLaneMatchET->setObjectName(QStringLiteral("leftLaneTrialRemainLaneMatchET"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneMatchET, 1, 0, 1, 1);

        verticalLayoutWidget_5 = new QWidget(leftLaneVehicleControl);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(150, 260, 140, 61));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialLifetimeExperiment = new QRadioButton(verticalLayoutWidget_5);
        leftLaneTrialLifetimeExperiment->setObjectName(QStringLiteral("leftLaneTrialLifetimeExperiment"));

        verticalLayout_6->addWidget(leftLaneTrialLifetimeExperiment);

        leftLaneTrialLifetimeTrial = new QRadioButton(verticalLayoutWidget_5);
        leftLaneTrialLifetimeTrial->setObjectName(QStringLiteral("leftLaneTrialLifetimeTrial"));
        leftLaneTrialLifetimeTrial->setChecked(true);

        verticalLayout_6->addWidget(leftLaneTrialLifetimeTrial);

        label_28 = new QLabel(leftLaneVehicleControl);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(190, 240, 41, 20));
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
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 291, 168));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialCutFrontSpeed = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialCutFrontSpeed->setObjectName(QStringLiteral("leftLaneTrialCutFrontSpeed"));

        gridLayout_3->addWidget(leftLaneTrialCutFrontSpeed, 5, 3, 1, 1);

        label_25 = new QLabel(gridLayoutWidget_3);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_3->addWidget(label_25, 5, 1, 1, 1);

        leftLaneTrialCutFrontDistance = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialCutFrontDistance->setObjectName(QStringLiteral("leftLaneTrialCutFrontDistance"));

        gridLayout_3->addWidget(leftLaneTrialCutFrontDistance, 2, 3, 1, 1);

        leftLaneTrialBlindSpot = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialBlindSpot->setObjectName(QStringLiteral("leftLaneTrialBlindSpot"));
        leftLaneTrialBlindSpot->setChecked(true);

        gridLayout_3->addWidget(leftLaneTrialBlindSpot, 0, 0, 1, 1);

        leftLaneTRialRemainLane = new QRadioButton(gridLayoutWidget_3);
        leftLaneTRialRemainLane->setObjectName(QStringLiteral("leftLaneTRialRemainLane"));

        gridLayout_3->addWidget(leftLaneTRialRemainLane, 6, 0, 1, 1);

        leftLaneTrialCutBehind = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialCutBehind->setObjectName(QStringLiteral("leftLaneTrialCutBehind"));

        gridLayout_3->addWidget(leftLaneTrialCutBehind, 1, 0, 1, 1);

        leftLaneTrialCutFront = new QRadioButton(gridLayoutWidget_3);
        leftLaneTrialCutFront->setObjectName(QStringLiteral("leftLaneTrialCutFront"));

        gridLayout_3->addWidget(leftLaneTrialCutFront, 2, 0, 1, 1);

        label_27 = new QLabel(gridLayoutWidget_3);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_3->addWidget(label_27, 2, 1, 1, 1);

        label_29->raise();
        verticalLayoutWidget_6->raise();
        leftLaneTrialOn->raise();
        verticalLayoutWidget_5->raise();
        gridLayoutWidget_4->raise();
        verticalLayoutWidget_5->raise();
        label_28->raise();
        gridLayoutWidget_5->raise();
        label_26->raise();
        gridLayoutWidget_3->raise();
        gridLayoutWidget = new QWidget(trialManager);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 260, 291, 165));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 3, 1, 1, 1);

        roadSideTrialDirveOnShoulderSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialDirveOnShoulderSpeed->setObjectName(QStringLiteral("roadSideTrialDirveOnShoulderSpeed"));

        gridLayout->addWidget(roadSideTrialDirveOnShoulderSpeed, 3, 2, 1, 1);

        roadSideTrialRemainStationary = new QRadioButton(gridLayoutWidget);
        roadSideTrialRemainStationary->setObjectName(QStringLiteral("roadSideTrialRemainStationary"));
        roadSideTrialRemainStationary->setChecked(true);

        gridLayout->addWidget(roadSideTrialRemainStationary, 0, 0, 1, 1);

        roadSideTrialDriveOnShoulder = new QRadioButton(gridLayoutWidget);
        roadSideTrialDriveOnShoulder->setObjectName(QStringLiteral("roadSideTrialDriveOnShoulder"));

        gridLayout->addWidget(roadSideTrialDriveOnShoulder, 3, 0, 1, 1);

        roadSideTrialPullFrontSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontSpeed->setObjectName(QStringLiteral("roadSideTrialPullFrontSpeed"));

        gridLayout->addWidget(roadSideTrialPullFrontSpeed, 2, 2, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 2, 1, 1, 1);

        roadSideTrialPullFront = new QRadioButton(gridLayoutWidget);
        roadSideTrialPullFront->setObjectName(QStringLiteral("roadSideTrialPullFront"));

        gridLayout->addWidget(roadSideTrialPullFront, 2, 0, 1, 1);

        roadSideTrialPullFrontStop = new QRadioButton(gridLayoutWidget);
        roadSideTrialPullFrontStop->setObjectName(QStringLiteral("roadSideTrialPullFrontStop"));

        gridLayout->addWidget(roadSideTrialPullFrontStop, 4, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 4, 1, 1, 1);

        roadSideTrialPullFrontStopSpeed = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontStopSpeed->setObjectName(QStringLiteral("roadSideTrialPullFrontStopSpeed"));

        gridLayout->addWidget(roadSideTrialPullFrontStopSpeed, 4, 2, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 5, 1, 1, 1);

        roadSideTrialPullFrontStopDistance = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontStopDistance->setObjectName(QStringLiteral("roadSideTrialPullFrontStopDistance"));

        gridLayout->addWidget(roadSideTrialPullFrontStopDistance, 5, 2, 1, 1);

        leftLaneVehicleControl->raise();
        roadSideVehicleControl->raise();
        leadVehicleInstructions->raise();
        gridLayoutWidget->raise();
        fileManager = new QGroupBox(centralWidget);
        fileManager->setObjectName(QStringLiteral("fileManager"));
        fileManager->setGeometry(QRect(10, 450, 171, 121));
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
        loadFile->raise();
        fileStatus->raise();
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
        fcwComboBox->raise();
        label_3->raise();
        label_4->raise();
        fcwPositionX->raise();
        fcwPositionY->raise();
        fcwPositionZ->raise();
        label_5->raise();
        fcwColorLineEdit->raise();
        umtriLogo->raise();
        currentTrial->raise();
        nextTrial->raise();
        prevTrial->raise();
        saveFileButton->raise();
        goToLinEdit->raise();
        goToButton->raise();
        label_8->raise();
        trialFollowDistance->raise();
        verticalLayoutWidget->raise();
        followTrialVelocityChange->raise();
        followTrialVelocityChangeAbsoluteLineEdit->raise();
        followTrialForceLaneChange->raise();
        label_9->raise();
        followTrialForceLaneChangeSpeed->raise();
        label_10->raise();
        followTialForceLaneChangeAcceleration->raise();
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
        loadFile->setText(QApplication::translate("MainWindow", "Load File", 0));
        fileStatus->setText(QApplication::translate("MainWindow", "File Status: please open file", 0));
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
        lengthOfRoadLabel->setText(QApplication::translate("MainWindow", "Length of Road", 0));
        opposingTrafficLabel->setText(QApplication::translate("MainWindow", "<u>Opposing Traffic</u>", 0));
        generateOpposingTraffic->setText(QApplication::translate("MainWindow", "Generate Opposing Traffic Upon Creation", 0));
        label->setText(QApplication::translate("MainWindow", "<u>Blind Spot Warning</u>", 0));
        showBlindSpotWarning->setText(QApplication::translate("MainWindow", "Show Blind Spot Warning", 0));
        label_2->setText(QApplication::translate("MainWindow", "<u>Frontal Crash Warning</u>", 0));
        frequency->setText(QApplication::translate("MainWindow", "Frequency", 0));
        label_3->setText(QApplication::translate("MainWindow", "Shape", 0));
        label_4->setText(QApplication::translate("MainWindow", "Position", 0));
        label_5->setText(QApplication::translate("MainWindow", "Color", 0));
        umtriLogo->setText(QString());
        currentTrial->setText(QApplication::translate("MainWindow", "0", 0));
        nextTrial->setText(QApplication::translate("MainWindow", "Next", 0));
        prevTrial->setText(QApplication::translate("MainWindow", "Prev", 0));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", 0));
        goToLinEdit->setText(QApplication::translate("MainWindow", "0", 0));
        goToButton->setText(QApplication::translate("MainWindow", "Go To", 0));
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
        label_6->setText(QApplication::translate("MainWindow", "Start", 0));
        label_30->setText(QApplication::translate("MainWindow", "End", 0));
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
        roadSideTrialLifeTimeExperiment->setText(QApplication::translate("MainWindow", "Experiment", 0));
        roadSideTrialLifeTimeTrial->setText(QApplication::translate("MainWindow", "Trial", 0));
        roadSideTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
        roadSideTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
        roadSideTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        roadSideTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_20->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        label_21->setText(QApplication::translate("MainWindow", "<u>Lifetime</u>", 0));
        leftLaneVehicleControl->setTitle(QApplication::translate("MainWindow", "Left Lane Vehicle Control", 0));
        label_29->setText(QApplication::translate("MainWindow", "<u>Creation</u>", 0));
        leftLaneTrialCreationBehind->setText(QApplication::translate("MainWindow", "Behind", 0));
        leftLaneTrialCreationFront->setText(QApplication::translate("MainWindow", "Front", 0));
        leftLaneTrialOn->setText(QString());
        leftLaneTrialRemainLaneAbsolute->setText(QApplication::translate("MainWindow", "Absolute", 0));
        leftLaneTrialRemainLaneMatchET->setText(QApplication::translate("MainWindow", "Match Driver", 0));
        leftLaneTrialLifetimeExperiment->setText(QApplication::translate("MainWindow", "Experiment", 0));
        leftLaneTrialLifetimeTrial->setText(QApplication::translate("MainWindow", "Trial", 0));
        label_28->setText(QApplication::translate("MainWindow", "<u>Lifetime</u>", 0));
        leftLaneTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
        leftLaneTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
        leftLaneTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
        leftLaneTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_26->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        label_25->setText(QApplication::translate("MainWindow", "Speed", 0));
        leftLaneTrialBlindSpot->setText(QApplication::translate("MainWindow", "Blind Spot", 0));
        leftLaneTRialRemainLane->setText(QApplication::translate("MainWindow", "Remain in Lane", 0));
        leftLaneTrialCutBehind->setText(QApplication::translate("MainWindow", "Cut Behind Driver", 0));
        leftLaneTrialCutFront->setText(QApplication::translate("MainWindow", "Cut In Front of Driver", 0));
        label_27->setText(QApplication::translate("MainWindow", "Distance", 0));
        label_19->setText(QApplication::translate("MainWindow", "Speed", 0));
        roadSideTrialRemainStationary->setText(QApplication::translate("MainWindow", "Remain Stationary", 0));
        roadSideTrialDriveOnShoulder->setText(QApplication::translate("MainWindow", "Drive On Shoulder", 0));
        label_17->setText(QApplication::translate("MainWindow", "Speed", 0));
        roadSideTrialPullFront->setText(QApplication::translate("MainWindow", "Pull Out In Front", 0));
        roadSideTrialPullFrontStop->setText(QApplication::translate("MainWindow", "Pull Out In Front and Stop", 0));
        label_16->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_18->setText(QApplication::translate("MainWindow", "Distance", 0));
        fileManager->setTitle(QApplication::translate("MainWindow", "File Manager", 0));
        followVehicleInstruction->setTitle(QApplication::translate("MainWindow", "Follow Vehicle Instructions", 0));
        followTrialOn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
#include <QtWidgets/QHBoxLayout>
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
    QGroupBox *groupBox;
    QCheckBox *fcwOn;
    QWidget *gridLayoutWidget_16;
    QGridLayout *gridLayout_25;
    QLineEdit *fcwPositionZ;
    QLabel *label_4;
    QLineEdit *fcwPositionY;
    QLineEdit *fcwPositionX;
    QLineEdit *frequencyLineEdit;
    QLabel *frequency;
    QComboBox *shapeOption;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *fcwIconName;
    QPushButton *colorButton;
    QLabel *colorDisplay;
    QLabel *label_14;
    QLineEdit *fcwDistanceLineEdit;
    QLabel *label_12;
    QLabel *label_44;
    QLineEdit *fcwPeriodOnLineEdit;
    QLabel *label_45;
    QLabel *label_46;
    QGroupBox *groupBox_6;
    QWidget *gridLayoutWidget_13;
    QGridLayout *gridLayout_21;
    QLineEdit *animationStartX;
    QLineEdit *animationStartY;
    QLineEdit *animationStartZ;
    QLabel *label_6;
    QLabel *label_30;
    QLineEdit *animationEndX;
    QLineEdit *animationEndY;
    QLineEdit *animationEndZ;
    QCheckBox *animationOn;
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
    QLineEdit *lengthOfRoadLineEdit;
    QLabel *label_33;
    QGroupBox *groupBox_5;
    QCheckBox *generateOpposingTraffic;
    QLineEdit *numberOpposingVehicles;
    QLabel *label;
    QLineEdit *numberTrucks;
    QLabel *label_34;
    QLineEdit *numberCars;
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
    QLabel *label_36;
    QGroupBox *roadSideVehicleControl;
    QCheckBox *roadSideTrialOn;
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
    QLabel *label_22;
    QRadioButton *roadSideTrialDeletionSlowDown;
    QRadioButton *roadSideTrialDeletionPullToSide;
    QRadioButton *roadSideTrialAddToList;
    QLabel *label_23;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_55;
    QComboBox *roadSideSolModel;
    QLabel *solModelLabel_4;
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
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_12;
    QRadioButton *leftLaneTrialCreationFront;
    QRadioButton *leftLaneTrialCreationBehind;
    QLabel *label_8;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_14;
    QLabel *label_9;
    QLineEdit *leftLaneTrialDistanceFromET;
    QLabel *label_24;
    QRadioButton *leftLaneTrialAddToFCW;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QRadioButton *leftLaneTrialRemainLaneMatchET;
    QRadioButton *leftLaneTrialRemainLaneAbsolute;
    QLineEdit *leftLaneTrialRemainLaneAbsoluteSpeed;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QComboBox *leftLaneSolModel;
    QLabel *solModelLabel_3;
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
    QLabel *label_29;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QLabel *currentTrial;
    QPushButton *prevTrial;
    QPushButton *nextTrial;
    QPushButton *goToButton;
    QLineEdit *goToLinEdit;
    QLabel *label_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1206, 641);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        umtriLogo = new QLabel(centralWidget);
        umtriLogo->setObjectName(QStringLiteral("umtriLogo"));
        umtriLogo->setGeometry(QRect(10, 560, 511, 71));
        majorFileSettings = new QGroupBox(centralWidget);
        majorFileSettings->setObjectName(QStringLiteral("majorFileSettings"));
        majorFileSettings->setGeometry(QRect(10, 10, 531, 541));
        groupBox = new QGroupBox(majorFileSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(190, 320, 331, 211));
        fcwOn = new QCheckBox(groupBox);
        fcwOn->setObjectName(QStringLiteral("fcwOn"));
        fcwOn->setGeometry(QRect(120, 0, 16, 17));
        gridLayoutWidget_16 = new QWidget(groupBox);
        gridLayoutWidget_16->setObjectName(QStringLiteral("gridLayoutWidget_16"));
        gridLayoutWidget_16->setGeometry(QRect(10, 90, 151, 24));
        gridLayout_25 = new QGridLayout(gridLayoutWidget_16);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        fcwPositionZ = new QLineEdit(gridLayoutWidget_16);
        fcwPositionZ->setObjectName(QStringLiteral("fcwPositionZ"));
        QFont font;
        font.setPointSize(8);
        fcwPositionZ->setFont(font);
        fcwPositionZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_25->addWidget(fcwPositionZ, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_16);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_25->addWidget(label_4, 0, 0, 1, 1);

        fcwPositionY = new QLineEdit(gridLayoutWidget_16);
        fcwPositionY->setObjectName(QStringLiteral("fcwPositionY"));
        fcwPositionY->setFont(font);
        fcwPositionY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_25->addWidget(fcwPositionY, 0, 2, 1, 1);

        fcwPositionX = new QLineEdit(gridLayoutWidget_16);
        fcwPositionX->setObjectName(QStringLiteral("fcwPositionX"));
        fcwPositionX->setFont(font);
        fcwPositionX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_25->addWidget(fcwPositionX, 0, 1, 1, 1);

        frequencyLineEdit = new QLineEdit(groupBox);
        frequencyLineEdit->setObjectName(QStringLiteral("frequencyLineEdit"));
        frequencyLineEdit->setGeometry(QRect(260, 30, 41, 22));
        frequencyLineEdit->setFont(font);
        frequencyLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        frequency = new QLabel(groupBox);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setGeometry(QRect(180, 30, 51, 22));
        shapeOption = new QComboBox(groupBox);
        shapeOption->setObjectName(QStringLiteral("shapeOption"));
        shapeOption->setGeometry(QRect(60, 30, 101, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 41, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 51, 22));
        fcwIconName = new QLineEdit(groupBox);
        fcwIconName->setObjectName(QStringLiteral("fcwIconName"));
        fcwIconName->setGeometry(QRect(70, 60, 91, 22));
        fcwIconName->setFont(font);
        fcwIconName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        colorButton = new QPushButton(groupBox);
        colorButton->setObjectName(QStringLiteral("colorButton"));
        colorButton->setGeometry(QRect(40, 130, 81, 21));
        colorDisplay = new QLabel(groupBox);
        colorDisplay->setObjectName(QStringLiteral("colorDisplay"));
        colorDisplay->setGeometry(QRect(30, 160, 101, 22));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(180, 90, 71, 16));
        fcwDistanceLineEdit = new QLineEdit(groupBox);
        fcwDistanceLineEdit->setObjectName(QStringLiteral("fcwDistanceLineEdit"));
        fcwDistanceLineEdit->setGeometry(QRect(260, 90, 41, 21));
        fcwDistanceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(310, 30, 16, 21));
        label_44 = new QLabel(groupBox);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(180, 60, 47, 13));
        fcwPeriodOnLineEdit = new QLineEdit(groupBox);
        fcwPeriodOnLineEdit->setObjectName(QStringLiteral("fcwPeriodOnLineEdit"));
        fcwPeriodOnLineEdit->setGeometry(QRect(260, 60, 41, 21));
        fcwPeriodOnLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_45 = new QLabel(groupBox);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(310, 60, 16, 16));
        label_46 = new QLabel(groupBox);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(310, 90, 16, 16));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(150, 110, 171, 91));
        gridLayoutWidget_13 = new QWidget(groupBox_6);
        gridLayoutWidget_13->setObjectName(QStringLiteral("gridLayoutWidget_13"));
        gridLayoutWidget_13->setGeometry(QRect(10, 30, 131, 52));
        gridLayout_21 = new QGridLayout(gridLayoutWidget_13);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        animationStartX = new QLineEdit(gridLayoutWidget_13);
        animationStartX->setObjectName(QStringLiteral("animationStartX"));
        animationStartX->setFont(font);
        animationStartX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationStartX, 0, 1, 1, 1);

        animationStartY = new QLineEdit(gridLayoutWidget_13);
        animationStartY->setObjectName(QStringLiteral("animationStartY"));
        animationStartY->setFont(font);
        animationStartY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationStartY, 0, 2, 1, 1);

        animationStartZ = new QLineEdit(gridLayoutWidget_13);
        animationStartZ->setObjectName(QStringLiteral("animationStartZ"));
        animationStartZ->setFont(font);
        animationStartZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationStartZ, 0, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_13);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_21->addWidget(label_6, 0, 0, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_13);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_21->addWidget(label_30, 1, 0, 1, 1);

        animationEndX = new QLineEdit(gridLayoutWidget_13);
        animationEndX->setObjectName(QStringLiteral("animationEndX"));
        animationEndX->setFont(font);
        animationEndX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationEndX, 1, 1, 1, 1);

        animationEndY = new QLineEdit(gridLayoutWidget_13);
        animationEndY->setObjectName(QStringLiteral("animationEndY"));
        animationEndY->setFont(font);
        animationEndY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationEndY, 1, 2, 1, 1);

        animationEndZ = new QLineEdit(gridLayoutWidget_13);
        animationEndZ->setObjectName(QStringLiteral("animationEndZ"));
        animationEndZ->setFont(font);
        animationEndZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(animationEndZ, 1, 3, 1, 1);

        animationOn = new QCheckBox(groupBox_6);
        animationOn->setObjectName(QStringLiteral("animationOn"));
        animationOn->setGeometry(QRect(60, 0, 16, 17));
        groupBox_6->raise();
        fcwOn->raise();
        gridLayoutWidget_16->raise();
        frequencyLineEdit->raise();
        frequency->raise();
        shapeOption->raise();
        label_3->raise();
        label_7->raise();
        fcwIconName->raise();
        colorButton->raise();
        colorDisplay->raise();
        label_14->raise();
        fcwDistanceLineEdit->raise();
        label_12->raise();
        label_44->raise();
        fcwPeriodOnLineEdit->raise();
        label_45->raise();
        label_46->raise();
        groupBox_2 = new QGroupBox(majorFileSettings);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 250, 141, 61));
        showBlindSpotWarning = new QCheckBox(groupBox_2);
        showBlindSpotWarning->setObjectName(QStringLiteral("showBlindSpotWarning"));
        showBlindSpotWarning->setGeometry(QRect(20, 30, 91, 16));
        groupBox_3 = new QGroupBox(majorFileSettings);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 221, 201));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 50, 21, 16));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(170, 80, 21, 16));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(170, 110, 21, 16));
        label_35 = new QLabel(groupBox_3);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(170, 140, 31, 16));
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(170, 170, 31, 16));
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
        groupBox_4->setGeometry(QRect(290, 20, 221, 201));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(170, 50, 21, 16));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(170, 80, 21, 16));
        label_31 = new QLabel(groupBox_4);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(170, 110, 21, 16));
        label_38 = new QLabel(groupBox_4);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(170, 140, 31, 16));
        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(170, 170, 31, 16));
        leadSolModel = new QComboBox(majorFileSettings);
        leadSolModel->setObjectName(QStringLiteral("leadSolModel"));
        leadSolModel->setGeometry(QRect(390, 40, 111, 22));
        solModelLabel_2 = new QLabel(majorFileSettings);
        solModelLabel_2->setObjectName(QStringLiteral("solModelLabel_2"));
        solModelLabel_2->setGeometry(QRect(300, 40, 51, 16));
        leadDistanceLineEdit = new QLineEdit(majorFileSettings);
        leadDistanceLineEdit->setObjectName(QStringLiteral("leadDistanceLineEdit"));
        leadDistanceLineEdit->setGeometry(QRect(390, 70, 61, 20));
        leadDistanceLineEdit->setFont(font);
        leadDistanceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxFollowSpeedLabel_2 = new QLabel(majorFileSettings);
        maxFollowSpeedLabel_2->setObjectName(QStringLiteral("maxFollowSpeedLabel_2"));
        maxFollowSpeedLabel_2->setGeometry(QRect(300, 100, 61, 16));
        leadVehicleDistanceLabel = new QLabel(majorFileSettings);
        leadVehicleDistanceLabel->setObjectName(QStringLiteral("leadVehicleDistanceLabel"));
        leadVehicleDistanceLabel->setGeometry(QRect(300, 70, 47, 13));
        leadMaxAccelLineEdit = new QLineEdit(majorFileSettings);
        leadMaxAccelLineEdit->setObjectName(QStringLiteral("leadMaxAccelLineEdit"));
        leadMaxAccelLineEdit->setGeometry(QRect(390, 160, 61, 20));
        leadMaxAccelLineEdit->setFont(font);
        leadMaxAccelLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMaxAccelLabel_2 = new QLabel(majorFileSettings);
        followMaxAccelLabel_2->setObjectName(QStringLiteral("followMaxAccelLabel_2"));
        followMaxAccelLabel_2->setGeometry(QRect(300, 160, 91, 16));
        leadMaxSpeedLineEdit = new QLineEdit(majorFileSettings);
        leadMaxSpeedLineEdit->setObjectName(QStringLiteral("leadMaxSpeedLineEdit"));
        leadMaxSpeedLineEdit->setGeometry(QRect(390, 100, 61, 20));
        leadMaxSpeedLineEdit->setFont(font);
        leadMaxSpeedLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leadMinSpeedLineEdit = new QLineEdit(majorFileSettings);
        leadMinSpeedLineEdit->setObjectName(QStringLiteral("leadMinSpeedLineEdit"));
        leadMinSpeedLineEdit->setGeometry(QRect(390, 130, 61, 20));
        leadMinSpeedLineEdit->setFont(font);
        leadMinSpeedLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMinAccelLabl_2 = new QLabel(majorFileSettings);
        followMinAccelLabl_2->setObjectName(QStringLiteral("followMinAccelLabl_2"));
        followMinAccelLabl_2->setGeometry(QRect(300, 190, 91, 16));
        minFollowSpeedLabel_2 = new QLabel(majorFileSettings);
        minFollowSpeedLabel_2->setObjectName(QStringLiteral("minFollowSpeedLabel_2"));
        minFollowSpeedLabel_2->setGeometry(QRect(300, 130, 61, 16));
        leadMaxDecel = new QLineEdit(majorFileSettings);
        leadMaxDecel->setObjectName(QStringLiteral("leadMaxDecel"));
        leadMaxDecel->setGeometry(QRect(390, 190, 61, 20));
        leadMaxDecel->setFont(font);
        leadMaxDecel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMaxAccelLineEdit = new QLineEdit(majorFileSettings);
        followMaxAccelLineEdit->setObjectName(QStringLiteral("followMaxAccelLineEdit"));
        followMaxAccelLineEdit->setGeometry(QRect(110, 160, 61, 20));
        followMaxAccelLineEdit->setFont(font);
        followMaxAccelLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMaxDecel = new QLineEdit(majorFileSettings);
        followMaxDecel->setObjectName(QStringLiteral("followMaxDecel"));
        followMaxDecel->setGeometry(QRect(110, 190, 61, 20));
        followMaxDecel->setFont(font);
        followMaxDecel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMinSpeedLineEdit = new QLineEdit(majorFileSettings);
        followMinSpeedLineEdit->setObjectName(QStringLiteral("followMinSpeedLineEdit"));
        followMinSpeedLineEdit->setGeometry(QRect(110, 130, 61, 20));
        followMinSpeedLineEdit->setFont(font);
        followMinSpeedLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followDistanceLineEdit = new QLineEdit(majorFileSettings);
        followDistanceLineEdit->setObjectName(QStringLiteral("followDistanceLineEdit"));
        followDistanceLineEdit->setGeometry(QRect(110, 70, 61, 20));
        followDistanceLineEdit->setFont(font);
        followDistanceLineEdit->setLayoutDirection(Qt::LeftToRight);
        followDistanceLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followMaxSpeedLineEdit = new QLineEdit(majorFileSettings);
        followMaxSpeedLineEdit->setObjectName(QStringLiteral("followMaxSpeedLineEdit"));
        followMaxSpeedLineEdit->setGeometry(QRect(110, 100, 61, 20));
        followMaxSpeedLineEdit->setFont(font);
        followMaxSpeedLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        followSolModel = new QComboBox(majorFileSettings);
        followSolModel->setObjectName(QStringLiteral("followSolModel"));
        followSolModel->setGeometry(QRect(110, 40, 111, 22));
        lengthOfRoadLabel = new QLabel(majorFileSettings);
        lengthOfRoadLabel->setObjectName(QStringLiteral("lengthOfRoadLabel"));
        lengthOfRoadLabel->setGeometry(QRect(50, 330, 121, 20));
        fileManager = new QGroupBox(majorFileSettings);
        fileManager->setObjectName(QStringLiteral("fileManager"));
        fileManager->setGeometry(QRect(30, 390, 141, 91));
        loadFile = new QPushButton(fileManager);
        loadFile->setObjectName(QStringLiteral("loadFile"));
        loadFile->setGeometry(QRect(20, 20, 101, 21));
        saveFileButton = new QPushButton(fileManager);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(20, 60, 101, 23));
        lengthOfRoadLineEdit = new QLineEdit(majorFileSettings);
        lengthOfRoadLineEdit->setObjectName(QStringLiteral("lengthOfRoadLineEdit"));
        lengthOfRoadLineEdit->setGeometry(QRect(50, 350, 121, 20));
        lengthOfRoadLineEdit->setFont(font);
        lengthOfRoadLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_33 = new QLabel(majorFileSettings);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(260, 290, 51, 16));
        groupBox_5 = new QGroupBox(majorFileSettings);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(250, 230, 261, 91));
        generateOpposingTraffic = new QCheckBox(groupBox_5);
        generateOpposingTraffic->setObjectName(QStringLiteral("generateOpposingTraffic"));
        generateOpposingTraffic->setGeometry(QRect(140, 0, 16, 16));
        numberOpposingVehicles = new QLineEdit(groupBox_5);
        numberOpposingVehicles->setObjectName(QStringLiteral("numberOpposingVehicles"));
        numberOpposingVehicles->setGeometry(QRect(160, 30, 61, 20));
        numberOpposingVehicles->setFont(font);
        numberOpposingVehicles->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(groupBox_5);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 111, 16));
        numberTrucks = new QLineEdit(groupBox_5);
        numberTrucks->setObjectName(QStringLiteral("numberTrucks"));
        numberTrucks->setGeometry(QRect(200, 60, 31, 20));
        numberTrucks->setFont(font);
        numberTrucks->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_34 = new QLabel(groupBox_5);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(110, 60, 81, 20));
        numberCars = new QLineEdit(groupBox_5);
        numberCars->setObjectName(QStringLiteral("numberCars"));
        numberCars->setGeometry(QRect(70, 60, 31, 20));
        numberCars->setFont(font);
        numberCars->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox_5->raise();
        lengthOfRoadLabel->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox->raise();
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
        lengthOfRoadLineEdit->raise();
        label_33->raise();
        trialManager = new QGroupBox(centralWidget);
        trialManager->setObjectName(QStringLiteral("trialManager"));
        trialManager->setGeometry(QRect(570, 10, 631, 611));
        leadVehicleInstructions = new QGroupBox(trialManager);
        leadVehicleInstructions->setObjectName(QStringLiteral("leadVehicleInstructions"));
        leadVehicleInstructions->setGeometry(QRect(320, 70, 261, 161));
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
        leadTrialVelocityChangeAbsoluteSpeed->setGeometry(QRect(160, 80, 61, 20));
        leadTrialVelocityChangeAbsoluteSpeed->setFont(font);
        leadTrialVelocityChangeAbsoluteSpeed->setLayoutDirection(Qt::LeftToRight);
        leadTrialVelocityChangeAbsoluteSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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

        label_36 = new QLabel(leadVehicleInstructions);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(230, 80, 21, 16));
        roadSideVehicleControl = new QGroupBox(trialManager);
        roadSideVehicleControl->setObjectName(QStringLiteral("roadSideVehicleControl"));
        roadSideVehicleControl->setGeometry(QRect(10, 260, 301, 341));
        roadSideTrialOn = new QCheckBox(roadSideVehicleControl);
        roadSideTrialOn->setObjectName(QStringLiteral("roadSideTrialOn"));
        roadSideTrialOn->setGeometry(QRect(140, 0, 16, 17));
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
        gridLayoutWidget->setGeometry(QRect(10, 20, 251, 167));
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
        roadSideTrialPullFrontStopSpeed->setFont(font);
        roadSideTrialPullFrontStopSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(roadSideTrialPullFrontStopSpeed, 0, 1, 1, 1);

        roadSideTrialPullFrontStopDistance = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontStopDistance->setObjectName(QStringLiteral("roadSideTrialPullFrontStopDistance"));
        roadSideTrialPullFrontStopDistance->setFont(font);
        roadSideTrialPullFrontStopDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

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
        roadSideTrialPullFrontSpeed->setFont(font);
        roadSideTrialPullFrontSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(roadSideTrialPullFrontSpeed, 0, 1, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_8->addWidget(label_17, 0, 0, 1, 1);

        roadSideTrialPullFrontDistance = new QLineEdit(gridLayoutWidget);
        roadSideTrialPullFrontDistance->setObjectName(QStringLiteral("roadSideTrialPullFrontDistance"));
        roadSideTrialPullFrontDistance->setFont(font);
        roadSideTrialPullFrontDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

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
        roadSideTrialDriveOnShoulderSpeed->setFont(font);
        roadSideTrialDriveOnShoulderSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(roadSideTrialDriveOnShoulderSpeed, 0, 1, 1, 1);


        gridLayout->addLayout(gridLayout_9, 3, 1, 1, 1);

        gridLayoutWidget_8 = new QWidget(roadSideVehicleControl);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(10, 260, 165, 65));
        gridLayout_13 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(gridLayoutWidget_8);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_13->addWidget(label_22, 0, 0, 1, 1);

        roadSideTrialDeletionSlowDown = new QRadioButton(gridLayoutWidget_8);
        roadSideTrialDeletionSlowDown->setObjectName(QStringLiteral("roadSideTrialDeletionSlowDown"));

        gridLayout_13->addWidget(roadSideTrialDeletionSlowDown, 2, 0, 1, 1);

        roadSideTrialDeletionPullToSide = new QRadioButton(gridLayoutWidget_8);
        roadSideTrialDeletionPullToSide->setObjectName(QStringLiteral("roadSideTrialDeletionPullToSide"));
        roadSideTrialDeletionPullToSide->setChecked(true);

        gridLayout_13->addWidget(roadSideTrialDeletionPullToSide, 1, 0, 1, 1);

        roadSideTrialAddToList = new QRadioButton(gridLayoutWidget_8);
        roadSideTrialAddToList->setObjectName(QStringLiteral("roadSideTrialAddToList"));

        gridLayout_13->addWidget(roadSideTrialAddToList, 1, 1, 1, 1);

        label_23 = new QLabel(gridLayoutWidget_8);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_13->addWidget(label_23, 0, 1, 1, 1);

        label_40 = new QLabel(roadSideVehicleControl);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(270, 50, 21, 16));
        label_41 = new QLabel(roadSideVehicleControl);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(270, 110, 21, 16));
        label_42 = new QLabel(roadSideVehicleControl);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(270, 140, 21, 16));
        label_43 = new QLabel(roadSideVehicleControl);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(270, 80, 21, 16));
        label_55 = new QLabel(roadSideVehicleControl);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(270, 170, 21, 16));
        roadSideSolModel = new QComboBox(roadSideVehicleControl);
        roadSideSolModel->setObjectName(QStringLiteral("roadSideSolModel"));
        roadSideSolModel->setGeometry(QRect(180, 230, 111, 21));
        solModelLabel_4 = new QLabel(roadSideVehicleControl);
        solModelLabel_4->setObjectName(QStringLiteral("solModelLabel_4"));
        solModelLabel_4->setGeometry(QRect(210, 210, 51, 16));
        leftLaneVehicleControl = new QGroupBox(trialManager);
        leftLaneVehicleControl->setObjectName(QStringLiteral("leftLaneVehicleControl"));
        leftLaneVehicleControl->setGeometry(QRect(320, 260, 301, 341));
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
        label_26->setGeometry(QRect(40, 200, 71, 16));
        gridLayoutWidget_3 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 241, 170));
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
        leftLaneTrialCutFrontDistance->setFont(font);
        leftLaneTrialCutFrontDistance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(leftLaneTrialCutFrontDistance, 1, 1, 1, 1);

        leftLaneTrialCutFrontSpeed = new QLineEdit(gridLayoutWidget_3);
        leftLaneTrialCutFrontSpeed->setObjectName(QStringLiteral("leftLaneTrialCutFrontSpeed"));
        leftLaneTrialCutFrontSpeed->setFont(font);
        leftLaneTrialCutFrontSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

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

        gridLayoutWidget_7 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(210, 280, 71, 46));
        gridLayout_12 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialCreationFront = new QRadioButton(gridLayoutWidget_7);
        leftLaneTrialCreationFront->setObjectName(QStringLiteral("leftLaneTrialCreationFront"));

        gridLayout_12->addWidget(leftLaneTrialCreationFront, 0, 0, 1, 1);

        leftLaneTrialCreationBehind = new QRadioButton(gridLayoutWidget_7);
        leftLaneTrialCreationBehind->setObjectName(QStringLiteral("leftLaneTrialCreationBehind"));
        leftLaneTrialCreationBehind->setChecked(true);

        gridLayout_12->addWidget(leftLaneTrialCreationBehind, 1, 0, 1, 1);

        label_8 = new QLabel(leftLaneVehicleControl);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 260, 81, 16));
        gridLayoutWidget_9 = new QWidget(leftLaneVehicleControl);
        gridLayoutWidget_9->setObjectName(QStringLiteral("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(10, 280, 155, 43));
        gridLayout_14 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(gridLayoutWidget_9);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_14->addWidget(label_9, 0, 1, 1, 1);

        leftLaneTrialDistanceFromET = new QLineEdit(gridLayoutWidget_9);
        leftLaneTrialDistanceFromET->setObjectName(QStringLiteral("leftLaneTrialDistanceFromET"));
        leftLaneTrialDistanceFromET->setFont(font);
        leftLaneTrialDistanceFromET->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(leftLaneTrialDistanceFromET, 1, 1, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_9);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_14->addWidget(label_24, 0, 0, 1, 1);

        leftLaneTrialAddToFCW = new QRadioButton(gridLayoutWidget_9);
        leftLaneTrialAddToFCW->setObjectName(QStringLiteral("leftLaneTrialAddToFCW"));

        gridLayout_14->addWidget(leftLaneTrialAddToFCW, 1, 0, 1, 1);

        layoutWidget = new QWidget(leftLaneVehicleControl);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 150, 117, 49));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        leftLaneTrialRemainLaneMatchET = new QRadioButton(layoutWidget);
        leftLaneTrialRemainLaneMatchET->setObjectName(QStringLiteral("leftLaneTrialRemainLaneMatchET"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneMatchET, 2, 0, 1, 1);

        leftLaneTrialRemainLaneAbsolute = new QRadioButton(layoutWidget);
        leftLaneTrialRemainLaneAbsolute->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsolute"));

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsolute, 3, 0, 1, 1);

        leftLaneTrialRemainLaneAbsoluteSpeed = new QLineEdit(layoutWidget);
        leftLaneTrialRemainLaneAbsoluteSpeed->setObjectName(QStringLiteral("leftLaneTrialRemainLaneAbsoluteSpeed"));
        leftLaneTrialRemainLaneAbsoluteSpeed->setFont(font);
        leftLaneTrialRemainLaneAbsoluteSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(leftLaneTrialRemainLaneAbsoluteSpeed, 3, 1, 1, 1);

        label_56 = new QLabel(leftLaneVehicleControl);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(260, 130, 21, 16));
        label_57 = new QLabel(leftLaneVehicleControl);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(170, 300, 21, 16));
        label_58 = new QLabel(leftLaneVehicleControl);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(260, 100, 21, 16));
        label_59 = new QLabel(leftLaneVehicleControl);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(260, 180, 21, 16));
        leftLaneSolModel = new QComboBox(leftLaneVehicleControl);
        leftLaneSolModel->setObjectName(QStringLiteral("leftLaneSolModel"));
        leftLaneSolModel->setGeometry(QRect(160, 230, 111, 22));
        solModelLabel_3 = new QLabel(leftLaneVehicleControl);
        solModelLabel_3->setObjectName(QStringLiteral("solModelLabel_3"));
        solModelLabel_3->setGeometry(QRect(190, 210, 51, 16));
        followVehicleInstruction = new QGroupBox(trialManager);
        followVehicleInstruction->setObjectName(QStringLiteral("followVehicleInstruction"));
        followVehicleInstruction->setGeometry(QRect(10, 70, 271, 161));
        followTrialOn = new QCheckBox(followVehicleInstruction);
        followTrialOn->setObjectName(QStringLiteral("followTrialOn"));
        followTrialOn->setGeometry(QRect(140, 0, 16, 17));
        followTrialVelocityChangeAbsoluteLineEdit = new QLineEdit(followVehicleInstruction);
        followTrialVelocityChangeAbsoluteLineEdit->setObjectName(QStringLiteral("followTrialVelocityChangeAbsoluteLineEdit"));
        followTrialVelocityChangeAbsoluteLineEdit->setGeometry(QRect(170, 80, 61, 20));
        followTrialVelocityChangeAbsoluteLineEdit->setFont(font);
        followTrialVelocityChangeAbsoluteLineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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

        label_29 = new QLabel(followVehicleInstruction);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(240, 80, 21, 16));
        horizontalLayoutWidget = new QWidget(trialManager);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 30, 371, 24));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout->addWidget(label_13);

        currentTrial = new QLabel(horizontalLayoutWidget);
        currentTrial->setObjectName(QStringLiteral("currentTrial"));

        horizontalLayout->addWidget(currentTrial);

        prevTrial = new QPushButton(horizontalLayoutWidget);
        prevTrial->setObjectName(QStringLiteral("prevTrial"));

        horizontalLayout->addWidget(prevTrial);

        nextTrial = new QPushButton(horizontalLayoutWidget);
        nextTrial->setObjectName(QStringLiteral("nextTrial"));

        horizontalLayout->addWidget(nextTrial);

        goToButton = new QPushButton(horizontalLayoutWidget);
        goToButton->setObjectName(QStringLiteral("goToButton"));

        horizontalLayout->addWidget(goToButton);

        goToLinEdit = new QLineEdit(horizontalLayoutWidget);
        goToLinEdit->setObjectName(QStringLiteral("goToLinEdit"));
        goToLinEdit->setFont(font);
        goToLinEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(goToLinEdit);

        leftLaneVehicleControl->raise();
        roadSideVehicleControl->raise();
        leadVehicleInstructions->raise();
        followVehicleInstruction->raise();
        horizontalLayoutWidget->raise();
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(570, 620, 161, 16));
        MainWindow->setCentralWidget(centralWidget);
        trialManager->raise();
        majorFileSettings->raise();
        umtriLogo->raise();
        label_10->raise();
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
        QWidget::setTabOrder(leadMaxDecel, generateOpposingTraffic);
        QWidget::setTabOrder(generateOpposingTraffic, numberOpposingVehicles);
        QWidget::setTabOrder(numberOpposingVehicles, numberCars);
        QWidget::setTabOrder(numberCars, numberTrucks);
        QWidget::setTabOrder(numberTrucks, showBlindSpotWarning);
        QWidget::setTabOrder(showBlindSpotWarning, lengthOfRoadLineEdit);
        QWidget::setTabOrder(lengthOfRoadLineEdit, loadFile);
        QWidget::setTabOrder(loadFile, saveFileButton);
        QWidget::setTabOrder(saveFileButton, fcwOn);
        QWidget::setTabOrder(fcwOn, shapeOption);
        QWidget::setTabOrder(shapeOption, fcwIconName);
        QWidget::setTabOrder(fcwIconName, fcwPositionX);
        QWidget::setTabOrder(fcwPositionX, fcwPositionY);
        QWidget::setTabOrder(fcwPositionY, fcwPositionZ);
        QWidget::setTabOrder(fcwPositionZ, frequencyLineEdit);
        QWidget::setTabOrder(frequencyLineEdit, fcwPeriodOnLineEdit);
        QWidget::setTabOrder(fcwPeriodOnLineEdit, fcwDistanceLineEdit);
        QWidget::setTabOrder(fcwDistanceLineEdit, colorButton);
        QWidget::setTabOrder(colorButton, animationOn);
        QWidget::setTabOrder(animationOn, animationStartX);
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
        QWidget::setTabOrder(followTrialForceLaneChange, followTrialChangeLeft);
        QWidget::setTabOrder(followTrialChangeLeft, followTrialChangeRight);
        QWidget::setTabOrder(followTrialChangeRight, leadTrialOn);
        QWidget::setTabOrder(leadTrialOn, leadTrialVelocityChange);
        QWidget::setTabOrder(leadTrialVelocityChange, leadTrialMatchExternalDriver);
        QWidget::setTabOrder(leadTrialMatchExternalDriver, leadTrialVelocityChangeAbsolute);
        QWidget::setTabOrder(leadTrialVelocityChangeAbsolute, leadTrialVelocityChangeAbsoluteSpeed);
        QWidget::setTabOrder(leadTrialVelocityChangeAbsoluteSpeed, leadTrialForceLaneChange);
        QWidget::setTabOrder(leadTrialForceLaneChange, leadTrialChangeLeft);
        QWidget::setTabOrder(leadTrialChangeLeft, leadTrialChangeRight);
        QWidget::setTabOrder(leadTrialChangeRight, roadSideTrialOn);
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
        QWidget::setTabOrder(roadSideTrialBlinkerNone, roadSideSolModel);
        QWidget::setTabOrder(roadSideSolModel, roadSideTrialDeletionPullToSide);
        QWidget::setTabOrder(roadSideTrialDeletionPullToSide, roadSideTrialAddToList);
        QWidget::setTabOrder(roadSideTrialAddToList, roadSideTrialDeletionSlowDown);
        QWidget::setTabOrder(roadSideTrialDeletionSlowDown, leftLaneTrialOn);
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
        QWidget::setTabOrder(leftLaneTrialBlinkerNone, leftLaneSolModel);
        QWidget::setTabOrder(leftLaneSolModel, leftLaneTrialAddToFCW);
        QWidget::setTabOrder(leftLaneTrialAddToFCW, leftLaneTrialDistanceFromET);
        QWidget::setTabOrder(leftLaneTrialDistanceFromET, leftLaneTrialCreationFront);
        QWidget::setTabOrder(leftLaneTrialCreationFront, leftLaneTrialCreationBehind);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Expressway Scenario Interface (Version 1.0.0)", 0));
        umtriLogo->setText(QString());
        majorFileSettings->setTitle(QApplication::translate("MainWindow", "Major File Settings", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Frontal Crash Warning", 0));
#ifndef QT_NO_TOOLTIP
        fcwOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Generate a frontal crash warning for scenario vehicles.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        fcwOn->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Position", 0));
#ifndef QT_NO_TOOLTIP
        frequencyLineEdit->setToolTip(QApplication::translate("MainWindow", "Frequency of FCW display.", 0));
#endif // QT_NO_TOOLTIP
        frequency->setText(QApplication::translate("MainWindow", "Frequency", 0));
#ifndef QT_NO_TOOLTIP
        shapeOption->setToolTip(QApplication::translate("MainWindow", "Shape of FCW. Choose \"Icon\" for a custom shape.", 0));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Shape", 0));
        label_7->setText(QApplication::translate("MainWindow", "Icon Name", 0));
#ifndef QT_NO_TOOLTIP
        fcwIconName->setToolTip(QApplication::translate("MainWindow", "Name of icon if \"Icon\" shape is option is chosen.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QApplication::translate("MainWindow", "Choose a color for the FCW.", 0));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QApplication::translate("MainWindow", "Choose Color", 0));
        colorDisplay->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">FCW Color</p></body></html>", 0));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">FCW Distance</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        fcwDistanceLineEdit->setToolTip(QApplication::translate("MainWindow", "Distance at which to activate the FCW.", 0));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("MainWindow", "Hz", 0));
        label_44->setText(QApplication::translate("MainWindow", "Period On", 0));
#ifndef QT_NO_TOOLTIP
        fcwPeriodOnLineEdit->setToolTip(QApplication::translate("MainWindow", "The amount of time the FCW on state is to be displayed.", 0));
#endif // QT_NO_TOOLTIP
        label_45->setText(QApplication::translate("MainWindow", "s", 0));
        label_46->setText(QApplication::translate("MainWindow", "ft", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Animation", 0));
#ifndef QT_NO_TOOLTIP
        animationStartX->setToolTip(QApplication::translate("MainWindow", "Animation start x position.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        animationStartY->setToolTip(QApplication::translate("MainWindow", "Animation start y position.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        animationStartZ->setToolTip(QApplication::translate("MainWindow", "Animation start z position.", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("MainWindow", "Start", 0));
        label_30->setText(QApplication::translate("MainWindow", "End", 0));
#ifndef QT_NO_TOOLTIP
        animationEndX->setToolTip(QApplication::translate("MainWindow", "Animation end x position.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        animationEndY->setToolTip(QApplication::translate("MainWindow", "Animation end y position.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        animationEndZ->setToolTip(QApplication::translate("MainWindow", "Animation end z position.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        animationOn->setToolTip(QApplication::translate("MainWindow", "Include an animation for the FCW (optional).", 0));
#endif // QT_NO_TOOLTIP
        animationOn->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Blind Spot Warning", 0));
#ifndef QT_NO_TOOLTIP
        showBlindSpotWarning->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Show a blind spot warning for left lane and roadside vehicles.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        showBlindSpotWarning->setText(QApplication::translate("MainWindow", "Show Warning", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Follow Vehicle", 0));
        label_11->setText(QApplication::translate("MainWindow", "ft", 0));
        label_15->setText(QApplication::translate("MainWindow", "mph", 0));
        label_32->setText(QApplication::translate("MainWindow", "mph", 0));
        label_35->setText(QApplication::translate("MainWindow", "m/s^2", 0));
        label_37->setText(QApplication::translate("MainWindow", "m/s^2", 0));
        followMinAccelLabl->setText(QApplication::translate("MainWindow", "Max Deceleration", 0));
        followMaxAccelLabel->setText(QApplication::translate("MainWindow", "Max Acceleration", 0));
        solModelLabel->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        minFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Min Speed", 0));
        followVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Gap", 0));
        maxFollowSpeedLabel->setText(QApplication::translate("MainWindow", "Max Speed", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Lead Vehicle", 0));
        label_21->setText(QApplication::translate("MainWindow", "ft", 0));
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
        leadVehicleDistanceLabel->setText(QApplication::translate("MainWindow", "Gap", 0));
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
#ifndef QT_NO_TOOLTIP
        lengthOfRoadLineEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of trials in input file.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_33->setText(QApplication::translate("MainWindow", "# of Cars", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Generate Opposing Traffic", 0));
#ifndef QT_NO_TOOLTIP
        generateOpposingTraffic->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Generate opposing lane traffic for scenario.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        generateOpposingTraffic->setText(QString());
#ifndef QT_NO_TOOLTIP
        numberOpposingVehicles->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of opposing lane vehicles per trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "#  of Vehicles Per Trial", 0));
#ifndef QT_NO_TOOLTIP
        numberTrucks->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of trucks in car/truck ratio of opposing lane traffic.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_34->setText(QApplication::translate("MainWindow", "per # of Trucks", 0));
#ifndef QT_NO_TOOLTIP
        numberCars->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Number of cars in car/truck ratio of opposing lane traffic.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
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
        leadTrialMatchExternalDriver->setToolTip(QApplication::translate("MainWindow", "Match the velocity of the subject.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match Subject", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialVelocityChangeAbsolute->setToolTip(QApplication::translate("MainWindow", "Set the velocity of the follow vehicle to an absolute value.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialVelocityChangeAbsolute->setText(QApplication::translate("MainWindow", "Absolute Speed", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialChangeLeft->setToolTip(QApplication::translate("MainWindow", "Force lane change left.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialChangeLeft->setText(QApplication::translate("MainWindow", "Left", 0));
#ifndef QT_NO_TOOLTIP
        leadTrialChangeRight->setToolTip(QApplication::translate("MainWindow", "Force lane change right.", 0));
#endif // QT_NO_TOOLTIP
        leadTrialChangeRight->setText(QApplication::translate("MainWindow", "Right", 0));
        label_36->setText(QApplication::translate("MainWindow", "mph", 0));
        roadSideVehicleControl->setTitle(QApplication::translate("MainWindow", "Road Side Vehicle Control", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a roadside vehicle for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialOn->setText(QString());
#ifndef QT_NO_TOOLTIP
        roadSideTrialBlinkerHazards->setToolTip(QApplication::translate("MainWindow", "Set the blinker to hazards.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialBlinkerRight->setToolTip(QApplication::translate("MainWindow", "Set the blinker to right.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialBlinkerLeft->setToolTip(QApplication::translate("MainWindow", "Set the blinker to left.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialBlinkerNone->setToolTip(QApplication::translate("MainWindow", "Set the blinker to none.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_20->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
        label_16->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_18->setText(QApplication::translate("MainWindow", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFrontStopSpeed->setToolTip(QApplication::translate("MainWindow", "Pull out in front and stop speed.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        roadSideTrialPullFrontStopDistance->setToolTip(QApplication::translate("MainWindow", "Pull out in front and stop distance.", 0));
#endif // QT_NO_TOOLTIP
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
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">Deletion</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialDeletionSlowDown->setToolTip(QApplication::translate("MainWindow", "Delete the road side vehicle by slowing down in the left lane.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialDeletionSlowDown->setText(QApplication::translate("MainWindow", "Slow Down", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialDeletionPullToSide->setToolTip(QApplication::translate("MainWindow", "Delete the road side vehicle by pulling to the right shoulder.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialDeletionPullToSide->setText(QApplication::translate("MainWindow", "Pull To Side", 0));
#ifndef QT_NO_TOOLTIP
        roadSideTrialAddToList->setToolTip(QApplication::translate("MainWindow", "Display a FCW for this road side vehicle.", 0));
#endif // QT_NO_TOOLTIP
        roadSideTrialAddToList->setText(QApplication::translate("MainWindow", "Add To List", 0));
        label_23->setText(QApplication::translate("MainWindow", "<u><center>FCW</center></u>", 0));
        label_40->setText(QApplication::translate("MainWindow", "mph", 0));
        label_41->setText(QApplication::translate("MainWindow", "mph", 0));
        label_42->setText(QApplication::translate("MainWindow", "mph", 0));
        label_43->setText(QApplication::translate("MainWindow", "ft", 0));
        label_55->setText(QApplication::translate("MainWindow", "ft", 0));
#ifndef QT_NO_TOOLTIP
        roadSideSolModel->setToolTip(QApplication::translate("MainWindow", "Set the road side sol model.", 0));
#endif // QT_NO_TOOLTIP
        solModelLabel_4->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        leftLaneVehicleControl->setTitle(QApplication::translate("MainWindow", "Left Lane Vehicle Control", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a left lane vehicle for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialOn->setText(QString());
#ifndef QT_NO_TOOLTIP
        leftLaneTrialBlinkerHazards->setToolTip(QApplication::translate("MainWindow", "Set the blinker to hazards.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialBlinkerHazards->setText(QApplication::translate("MainWindow", "Hazards", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialBlinkerRight->setToolTip(QApplication::translate("MainWindow", "Set the blinker to right.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialBlinkerRight->setText(QApplication::translate("MainWindow", "Right", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialBlinkerLeft->setToolTip(QApplication::translate("MainWindow", "Set the blinker to left.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialBlinkerLeft->setText(QApplication::translate("MainWindow", "Left", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialBlinkerNone->setToolTip(QApplication::translate("MainWindow", "Set the blinker to none.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialBlinkerNone->setText(QApplication::translate("MainWindow", "None", 0));
        label_26->setText(QApplication::translate("MainWindow", "<u>Blinker Control</u>", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCutFrontDistance->setToolTip(QApplication::translate("MainWindow", "Cut in front of driver distance.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCutFrontSpeed->setToolTip(QApplication::translate("MainWindow", "Cut in front of driver speed.", 0));
#endif // QT_NO_TOOLTIP
        label_25->setText(QApplication::translate("MainWindow", "Speed", 0));
        label_27->setText(QApplication::translate("MainWindow", "Distance", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCutBehind->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle cuts behind the subject.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialCutBehind->setText(QApplication::translate("MainWindow", "Cut Behind Driver", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCutFront->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle cuts in front of the driver.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialCutFront->setText(QApplication::translate("MainWindow", "Cut In Front of Driver", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialBlindSpot->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle sits in the the blind spot of the subject.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialBlindSpot->setText(QApplication::translate("MainWindow", "Blind Spot", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTRialRemainLane->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle remains in the left lane. ", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTRialRemainLane->setText(QApplication::translate("MainWindow", "Remain in Lane", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCreationFront->setToolTip(QApplication::translate("MainWindow", "Left lane create in front of the subject.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialCreationFront->setText(QApplication::translate("MainWindow", "Front", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialCreationBehind->setToolTip(QApplication::translate("MainWindow", "Left lane create behind  the subject.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialCreationBehind->setText(QApplication::translate("MainWindow", "Behind", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Creation Option</p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" text-decoration: underline;\">Creation Gap*</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialDistanceFromET->setToolTip(QApplication::translate("MainWindow", "Left lane creation distance.", 0));
#endif // QT_NO_TOOLTIP
        label_24->setText(QApplication::translate("MainWindow", "<u><center>FCW</center></u>", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialAddToFCW->setToolTip(QApplication::translate("MainWindow", "Display a FCW for this left lane vehicle.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialAddToFCW->setText(QApplication::translate("MainWindow", "Add To List", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialRemainLaneMatchET->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle remain in lane and match the subject.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialRemainLaneMatchET->setText(QApplication::translate("MainWindow", "Match", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialRemainLaneAbsolute->setToolTip(QApplication::translate("MainWindow", "Left lane vehicle remain in lane and travel at an absolute speed.", 0));
#endif // QT_NO_TOOLTIP
        leftLaneTrialRemainLaneAbsolute->setText(QApplication::translate("MainWindow", "Absolute", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneTrialRemainLaneAbsoluteSpeed->setToolTip(QApplication::translate("MainWindow", "Left lane remain in lane absolute speed.", 0));
#endif // QT_NO_TOOLTIP
        label_56->setText(QApplication::translate("MainWindow", "ft", 0));
        label_57->setText(QApplication::translate("MainWindow", "ft", 0));
        label_58->setText(QApplication::translate("MainWindow", "mph", 0));
        label_59->setText(QApplication::translate("MainWindow", "mph", 0));
#ifndef QT_NO_TOOLTIP
        leftLaneSolModel->setToolTip(QApplication::translate("MainWindow", "Set the  left lane model.", 0));
#endif // QT_NO_TOOLTIP
        solModelLabel_3->setText(QApplication::translate("MainWindow", "Sol Model", 0));
        followVehicleInstruction->setTitle(QApplication::translate("MainWindow", "Follow Vehicle Instructions", 0));
#ifndef QT_NO_TOOLTIP
        followTrialOn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Include a follow vehicle change for this trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        followTrialOn->setText(QString());
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChangeAbsoluteLineEdit->setToolTip(QApplication::translate("MainWindow", "Absolute speed value.", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        followTrialVelocityChangeMatchExternalDriver->setToolTip(QApplication::translate("MainWindow", "Match the velocity of the subject.", 0));
#endif // QT_NO_TOOLTIP
        followTrialVelocityChangeMatchExternalDriver->setText(QApplication::translate("MainWindow", "Match Subject", 0));
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
#ifndef QT_NO_TOOLTIP
        followTrialChangeLeft->setToolTip(QApplication::translate("MainWindow", "Force lane change left.", 0));
#endif // QT_NO_TOOLTIP
        followTrialChangeLeft->setText(QApplication::translate("MainWindow", "Left", 0));
#ifndef QT_NO_TOOLTIP
        followTrialChangeRight->setToolTip(QApplication::translate("MainWindow", "Force lane change right.", 0));
#endif // QT_NO_TOOLTIP
        followTrialChangeRight->setText(QApplication::translate("MainWindow", "Right", 0));
        label_29->setText(QApplication::translate("MainWindow", "mph", 0));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#e30000;\">Current Trial:</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        currentTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Current trial number.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        currentTrial->setText(QApplication::translate("MainWindow", "0", 0));
#ifndef QT_NO_TOOLTIP
        prevTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to the previous trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        prevTrial->setText(QApplication::translate("MainWindow", "Prev", 0));
#ifndef QT_NO_TOOLTIP
        nextTrial->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to the next trial.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        nextTrial->setText(QApplication::translate("MainWindow", "Next", 0));
#ifndef QT_NO_TOOLTIP
        goToButton->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Jump to a given trial (number entered must be in range).</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        goToButton->setText(QApplication::translate("MainWindow", "Go To:", 0));
#ifndef QT_NO_TOOLTIP
        goToLinEdit->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to trial number.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        goToLinEdit->setText(QApplication::translate("MainWindow", "0", 0));
        label_10->setText(QApplication::translate("MainWindow", "* Relative to subject (CG to CG)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#-------------------------------------------------
#
# Project created by QtCreator 2016-05-27T15:05:15
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExpresswayInterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    Actions.h \
    MajorSettings.h \
    SCNHeader.h \
    SCNHighwayTemplate.h \
    StaticObject.h \
    Trial.h \
    Trigger.h \
    Vehicle.h \
    VirtualObject.h \
    Helpers.h

FORMS    += mainwindow.ui

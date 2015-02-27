#-------------------------------------------------
#
# Project created by QtCreator 2015-02-27T16:46:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectEuler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    problem01.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    problem01.h \
    BaseRunnableClass.h \
    log.h

FORMS    += mainwindow.ui

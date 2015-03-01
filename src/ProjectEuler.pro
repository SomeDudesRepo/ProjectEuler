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
    log.cpp \
    xmlreader.cpp \
    solutions/problem02.cpp \
    solutions/problem01.cpp \
    solutions/problem03.cpp \
    solutions/problem04.cpp \
    solutions/problem05.cpp \
    solutions/problem06.cpp \
    solutions/problem07.cpp \
    primes.cpp \
    solutions/problem08.cpp \
    solutions/problem09.cpp

HEADERS  += mainwindow.h \
    log.h \
    xmlreader.h \
    baserunnable.h \
    solutions/problem02.h \
    solutions/problem01.h \
    solutions/problem03.h \
    solutions/problem04.h \
    solutions/problem05.h \
    solutions/problem06.h \
    solutions/problem07.h \
    primes.h \
    solutions/problem08.h \
    solutions/problem09.h

FORMS    += mainwindow.ui

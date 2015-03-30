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
    primes.cpp \
    solutions/010/problem001.cpp \
    solutions/010/problem002.cpp \
    solutions/010/problem003.cpp \
    solutions/010/problem004.cpp \
    solutions/010/problem005.cpp \
    solutions/010/problem006.cpp \
    solutions/010/problem007.cpp \
    solutions/010/problem008.cpp \
    solutions/010/problem009.cpp \
    solutions/010/problem010.cpp \
    solutions/020/problem011.cpp \
    solutions/020/problem012.cpp \
    solutions/020/problem013.cpp \
    filelinereader.cpp \
    solutions/020/problem014.cpp \
    solutions/020/problem015.cpp \
    solutions/020/problem016.cpp \
    solutions/020/problem017.cpp \
    solutions/020/problem018.cpp \
    solutions/020/problem019.cpp \
    solutions/020/problem020.cpp \
    solutions/030/problem021.cpp \
    solutions/030/problem022.cpp \
    solutions/030/problem023.cpp \
    factors.cpp \
    solutions/030/problem024.cpp \
    solutions/030/problem025.cpp

HEADERS  += mainwindow.h \
    log.h \
    xmlreader.h \
    baserunnable.h \
    primes.h \
    solutions/problems.h \
    solutions/010/problem001.h \
    solutions/010/problem002.h \
    solutions/010/problem003.h \
    solutions/010/problem004.h \
    solutions/010/problem005.h \
    solutions/010/problem006.h \
    solutions/010/problem007.h \
    solutions/010/problem008.h \
    solutions/010/problem009.h \
    solutions/010/problem010.h \
    solutions/020/problem011.h \
    solutions/020/problem012.h \
    solutions/020/problem013.h \
    filelinereader.h \
    solutions/020/problem014.h \
    solutions/020/problem015.h \
    solutions/020/problem016.h \
    solutions/020/problem017.h \
    solutions/020/problem018.h \
    solutions/020/problem019.h \
    ttmath/ttmath.h \
    ttmath/ttmathbig.h \
    ttmath/ttmathdec.h \
    ttmath/ttmathint.h \
    ttmath/ttmathmisc.h \
    ttmath/ttmathobjects.h \
    ttmath/ttmathparser.h \
    ttmath/ttmaththreads.h \
    ttmath/ttmathtypes.h \
    ttmath/ttmathuint.h \
    ttmath/ttmathuint_noasm.h \
    ttmath/ttmathuint_x86.h \
    ttmath/ttmathuint_x86_64.h \
    solutions/020/problem020.h \
    solutions/030/problem021.h \
    solutions/030/problem022.h \
    solutions/030/problem023.h \
    factors.h \
    solutions/030/problem024.h \
    solutions/030/problem025.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    ttmath/ttmathuint_x86_64_msvc.asm

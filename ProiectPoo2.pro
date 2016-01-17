#-------------------------------------------------
#
# Project created by QtCreator 2016-01-14T16:20:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport sql

TARGET = ProiectPoo2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    getdata.cpp \
    monod.cpp \
    browsedata.cpp \
    moser.cpp \
    powel.cpp \
    dialog.cpp \
    oxigen.cpp \
    compare.cpp \
    tabel.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    getdata.h \
    monod.h \
    browsedata.h \
    moser.h \
    powel.h \
    dialog.h \
    oxigen.h \
    compare.h \
    tabel.h

FORMS    += mainwindow.ui \
    browsedata.ui \
    dialog.ui \
    compare.ui \
    tabel.ui

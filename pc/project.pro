#-------------------------------------------------
#
# Project created by QtCreator 2016-08-13T01:27:58
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialportcombobox.cpp \
    baudratecombobox.cpp

HEADERS  += mainwindow.h \
    serialportcombobox.h \
    baudratecombobox.h

FORMS    += mainwindow.ui

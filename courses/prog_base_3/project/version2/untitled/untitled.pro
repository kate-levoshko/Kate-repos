#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T03:12:21
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    registration.cpp \
    personaloffice.cpp \
    user.cpp \
    database.cpp \
    currentuser.cpp

HEADERS  += mainwindow.h \
    user.h \
    currentuser.h \
    registration.h \
    personaloffice.h \
    database.h

FORMS    += mainwindow.ui \
    registration.ui \
    personaloffice.ui

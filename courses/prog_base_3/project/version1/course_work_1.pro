#-------------------------------------------------
#
# Project created by QtCreator 2016-06-06T02:09:25
#
#-------------------------------------------------

QT += core gui
QT += sql
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = course_work_1
TEMPLATE = app


SOURCES += main.cpp\
        start_window.cpp \
    main_window.cpp \
    user.cpp \
    registration.cpp \
    authorisation.cpp \
    bucket.cpp \
    product.cpp

HEADERS  += start_window.h \
    main_window.h \
    user.h \
    registration.h \
    authorisation.h \
    bucket.h \
    product.h

FORMS    += start_window.ui \
    main_window.ui \
    registration.ui \
    authorisation.ui

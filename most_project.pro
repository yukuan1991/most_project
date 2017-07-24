#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T09:04:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG -= c++11
QMAKE_CXXFLAGS += -std=c++1z

TARGET = most_project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cc\
        most_main.cc \
    interface_control/about_us_dlg.cc \
    interface_control/push_button.cpp \
    interface_control/ribbon.cc

HEADERS  += most_main.h \
    interface_control/about_us_dlg.h \
    interface_control/push_button.h \
    interface_control/ribbon.h

FORMS    += most_main.ui

LIBS += -lboost_locale
LIBS += -liconv
LIBS += -lboost_filesystem
LIBS += -lboost_system

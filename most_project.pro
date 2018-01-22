#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T09:04:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG -= c++11
QMAKE_CXXFLAGS += -std=c++1z

TARGET = most
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
    interface_control/ribbon.cc \
    interface_control/ribbon_most.cc \
    most_widget.cc \
    data_widget.cc \
    most_analysis.cc \
    model/json_model.cpp \
    pts/code_edit.cpp \
    pts/pts_delegate.cpp \
    pts/pts_model.cpp \
    Qt-Utils/des.cpp \
    Qt-Utils/encryption.cpp \
    Qt-Utils/tinyxml2.cpp \
    view/table_view.cpp \
    most_selection_dlg.cpp \
    verification/verification.cpp

HEADERS  += most_main.h \
    interface_control/about_us_dlg.h \
    interface_control/push_button.h \
    interface_control/ribbon.h \
    interface_control/ribbon_most.h \
    most_widget.h \
    data_widget.h \
    most_analysis.h \
    model/json_model.h \
    pts/code_edit.h \
    pts/pts_delegate.h \
    pts/pts_model.h \
    Qt-Utils/des.h \
    Qt-Utils/encryption.h \
    Qt-Utils/json.hpp \
    Qt-Utils/krys_application.hpp \
    Qt-Utils/qt.hpp \
    Qt-Utils/stl_extension.hpp \
    Qt-Utils/tinyxml2.h \
    view/table_view.h \
    arithmetic_resource.hpp \
    most_selection_dlg.h \
    verification/verification.h

FORMS    += most_main.ui \
    most_widget.ui \
    data_widget.ui \
    most_analysis.ui \
    most_selection_dlg.ui

LIBS += -lboost_filesystem
LIBS += -lboost_system
LIBS += -lboost_regex
LIBS += -lboost_thread
LIBS += -lboost_locale
LIBS += -liconv
LIBS += -lwininet
LIBS += -lws2_32

#-------------------------------------------------
#
# Project created by QtCreator 2017-09-20T15:59:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_fingerprint
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    verify1.cpp \
    mysql.cpp \
    updatewindow.cpp \
    userwindow.cpp \
    finger.cpp \
    createuserwindow.cpp \
    LoginPwWindow.cpp \
    LoginWindow.cpp

HEADERS += \
        mainwindow.h \
    verify1.h \
    mysql.h \
    updatewindow.h \
    userwindow.h \
    finger.h \
    createuserwindow.h \
    LoginPwWindow.h \
    LoginWindow.h

FORMS += \
        mainwindow.ui \
    verify1.ui \
    updatewindow.ui \
    userwindow.ui \
    createuserwindow.ui \
    LoginPwWindow.ui \
    LoginWindow.ui
LIBS    +=  -lfprint \
    -lmysqlclient
QT += sql


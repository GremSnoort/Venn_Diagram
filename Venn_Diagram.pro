#-------------------------------------------------
#
# Project created by QtCreator 2018-03-23T22:46:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Venn_Diagram
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
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
        imgdiagramwidget.cpp \
    database.cpp \
    usersession_exprtoimgwidget.cpp

HEADERS += \
        mainwindow.h \
        imgdiagramwidget.h \
    database.h \
    usersession_exprtoimgwidget.h

unix|win32: LIBS += -L$$PWD/'../../../../../Program Files/MySQL/MySQL Server 5.7/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Server 5.7/include'
DEPENDPATH += $$PWD/'../../../../../Program Files/MySQL/MySQL Server 5.7/include'

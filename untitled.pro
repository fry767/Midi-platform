#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T15:18:59
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
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

CONFIG += c++11

SOURCES += \
        keybinds.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        keybinds.h \
        mainwindow.h

FORMS += \
        keybinds.ui \
        mainwindow.ui

INCLUDEPATH += QT-VLC\include

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtCore.lib"

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtCored.lib"

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtQml.lib"

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtQmld.lib"

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtWidgets.lib"

LIBS += "E:/Project/Midi keyboard/untitled/QT-VLC/lib/VLCQtWidgetsd.lib"

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

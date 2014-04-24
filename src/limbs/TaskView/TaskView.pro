TEMPLATE = lib
CONFIG += plugin
QT += widgets

DESTDIR = ../../../build/limbs/

TARGET = $$qtLibraryTarget(TaskViewPlugin)

HEADERS += \
    taskviewplugin.h \
    taskview.h \
    nodecontainer.h

SOURCES += \
    taskviewplugin.cpp \
    taskview.cpp \
    nodecontainer.cpp

FORMS += \
    taskview.ui

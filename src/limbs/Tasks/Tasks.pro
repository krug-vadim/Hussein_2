TEMPLATE = lib
CONFIG += plugin
QT +=

DESTDIR = ../../../build/limbs/

TARGET = $$qtLibraryTarget(TasksPlugin)

HEADERS += \
    tasksplugin.h

SOURCES += \
    tasksplugin.cpp

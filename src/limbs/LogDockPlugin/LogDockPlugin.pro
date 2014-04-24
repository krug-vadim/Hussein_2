TEMPLATE      = lib
CONFIG       += plugin
QT           += widgets

HEADERS = \
    logdockplugin.h \
    logdockwidget.h

SOURCES       = \
    logdockplugin.cpp \
    logdockwidget.cpp

TARGET        = $$qtLibraryTarget(LogDockPlugin)

DESTDIR       = ../../../build/limbs/

FORMS += \
    logdockwidget.ui


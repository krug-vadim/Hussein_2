TEMPLATE = lib
CONFIG += plugin
QT += widgets

DESTDIR = ../../../build/limbs/

TARGET = $$qtLibraryTarget(SimpleNodePlugin)

HEADERS += \
    simplenodeplugin.h \
    simplenodewidget.h

SOURCES += \
    simplenodeplugin.cpp \
    simplenodewidget.cpp

FORMS += \
    simplenodewidget.ui


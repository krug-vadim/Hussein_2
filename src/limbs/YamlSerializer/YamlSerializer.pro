TEMPLATE = lib
CONFIG += plugin
QT += widgets

DESTDIR = ../../../build/limbs/

TARGET = $$qtLibraryTarget(YamlSerializerPlugin)

HEADERS += \
    yamlserializerplugin.h

SOURCES += \
    yamlserializerplugin.cpp

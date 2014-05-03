TEMPLATE = lib
CONFIG += plugin
QT += widgets

DESTDIR = ../../../build/limbs/

TARGET = $$qtLibraryTarget(YamlSerializerPlugin)

HEADERS += \
    yamlserializerplugin.h

SOURCES += \
    yamlserializerplugin.cpp

CONFIG(debug, debug|release) {
    win32:LIBS += "-L$$PWD/lib/yaml-cpp/build/debug/"
    win32:LIBS += "-lyamld"
    unix:LIBS += -lyaml-cpp
} else {
    #win32:LIBS += -lyaml
    win32:LIBS += "-L$$PWD/lib/yaml-cpp/build/release/"
    win32:LIBS += "-lyaml"
    unix:LIBS += -lyaml-cpp
}

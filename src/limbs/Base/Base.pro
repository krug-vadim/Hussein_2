QT += core gui widgets

TARGET   = Hussein
TEMPLATE = app

DESTDIR = ../../../build/

SOURCES += main.cpp\
           mainwindow.cpp \
           pluginsmanagerwidget.cpp \
           settingswidget.cpp \
           pluginsmodel.cpp \
           ../../core/core.cpp

HEADERS  += mainwindow.h \
            pluginsmanagerwidget.h \
            settingswidget.h \
            pluginsmodel.h \
            ../../core/core.h

FORMS    += mainwindow.ui \
            pluginsmanagerwidget.ui \
            settingswidget.ui

OTHER_FILES += \
    Hussein.rc \
    Hussein.ico

RESOURCES += \
    Hussein.qrc

win32 {
    RC_FILE += Hussein.rc
}

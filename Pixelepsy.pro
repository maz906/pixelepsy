#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T13:57:50
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pixelepsy
TEMPLATE = app


SOURCES += main.cpp\
    gui/viewer.cpp \
    sprite/buffer.cpp \
    sprite/frame.cpp \
    sprite/sprite.cpp \
    gui/pixelepsy.cpp \
    gui/toolbox.cpp \
    tools/colorpicker.cpp

HEADERS  += \
    gui/viewer.h \
    sprite/buffer.h \
    sprite/frame.h \
    sprite/sprite.h \
    gui/pixelepsy.h \
    gui/toolbox.h \
    tools/tool.h \
    tools/colorpicker.h

FORMS    += pixelepsy.ui

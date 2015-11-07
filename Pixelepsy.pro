#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T13:57:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pixelepsy
TEMPLATE = app


SOURCES += main.cpp\
        pixelepsy.cpp \
    buffer.cpp \
    sprite.cpp \
    frame.cpp

HEADERS  += pixelepsy.h \
    buffer.h \
    sprite.h \
    frame.h

FORMS    += pixelepsy.ui

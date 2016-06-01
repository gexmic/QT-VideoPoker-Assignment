#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T12:34:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokerGameQt
TEMPLATE = app


SOURCES += main.cpp\
        controller/mainwindow.cpp \
    model/Card.cpp \
    model/Deck.cpp \
    model/Hand.cpp \
    model/deck.cpp \
    model/card.cpp \
    model/videopokergame.cpp \
    model/hand.cpp

HEADERS  += controller/mainwindow.h \
    model/Card.h \
    model/Deck.h \
    model/Hand.h \
    model/deck.h \
    model/card.h \
    model/videopokergame.h \
    model/hand.h

FORMS    += view/mainwindow.ui

RESOURCES += \
    resource.qrc

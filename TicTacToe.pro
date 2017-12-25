#-------------------------------------------------
#
# Project created by QtCreator 2017-12-25T14:07:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TicTacToe
TEMPLATE = app


SOURCES += main.cpp\
        settingwindow.cpp \
    tictactoe.cpp \
    Components/GameBoard.cpp \
    Players/Computer.cpp \
    Players/Player.cpp \
    Game.cpp

HEADERS  += settingwindow.h \
    tictactoe.h \
    Components/Figure.h \
    Components/GameBoard.h \
    Components/Result.h \
    Players/Computer.h \
    Players/Player.h \
    Game.h

FORMS    += settingwindow.ui \
    tictactoe.ui

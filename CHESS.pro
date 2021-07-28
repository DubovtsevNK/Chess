TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Managers/GameManager.cpp \
        main.cpp

HEADERS += \
    Interfaces/IAvailableMove.h \
    Interfaces/IGameManager.h \
    Managers/GameManager.h

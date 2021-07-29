TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Managers/GameManager.cpp \
        Managers/figuremanager.cpp \
        main.cpp

HEADERS += \
    Interfaces/IAvailableMove.h \
    Interfaces/IFigureManager.h \
    Interfaces/IGameManager.h \
    Interfaces/IMoveRequest.h \
    Managers/GameManager.h \
    Managers/figuremanager.h

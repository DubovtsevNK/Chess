TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GameItems/chessfigure.cpp \
        Managers/GameManager.cpp \
        Managers/figuremanager.cpp \
        main.cpp

HEADERS += \
    GameItems/chessfigure.h \
    Interfaces/IAvailableMove.h \
    Interfaces/IFigureManager.h \
    Interfaces/IGameManager.h \
    Interfaces/IMoveRequest.h \
    Managers/GameManager.h \
    Managers/figuremanager.h

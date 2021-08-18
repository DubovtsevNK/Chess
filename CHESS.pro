TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        GameItems/chessboard.cpp \
        GameItems/chessfigure.cpp \
        Managers/GameManager.cpp \
        Managers/figuremanager.cpp \
        main.cpp

HEADERS += \
    GameItems/chessboard.h \
    GameItems/chessfigure.h \
    GameItems/squareonboard.h \
    Interfaces/IFigureManager.h \
    Interfaces/IGameManager.h \
    Interfaces/IGraphicsMove.h \
    Interfaces/IMoveRequest.h \
    Managers/GameManager.h \
    Managers/figuremanager.h

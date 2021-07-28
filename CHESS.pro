TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Interfaces/igamemanager.cpp \
        Managers/gamemanager.cpp \
        main.cpp

HEADERS += \
    Interfaces/igamemanager.h \
    Managers/gamemanager.h

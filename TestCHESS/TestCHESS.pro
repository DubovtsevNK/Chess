include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        chessfigureTEST.h \
        tst_firsttest.h


SOURCES += \
        main.cpp

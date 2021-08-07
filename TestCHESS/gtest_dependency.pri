isEmpty(GOOGLETEST_DIR):GOOGLETEST_DIR=$$(GOOGLETEST_DIR)

isEmpty(GOOGLETEST_DIR) {
    GOOGLETEST_DIR = ../googletest
    !isEmpty(GOOGLETEST_DIR) {
        warning("Using googletest src dir specified at Qt Creator wizard")
        message("set GOOGLETEST_DIR as environment variable or qmake variable to get rid of this message")
    }
}

!isEmpty(GOOGLETEST_DIR): {
    GTEST_SRCDIR = $$GOOGLETEST_DIR/googletest
    GMOCK_SRCDIR = $$GOOGLETEST_DIR/googlemock
} else: unix {
    exists(/usr/src/gtest):GTEST_SRCDIR=/usr/src/gtest
    exists(/usr/src/gmock):GMOCK_SRCDIR=/usr/src/gmock
    !isEmpty(GTEST_SRCDIR): message("Using gtest from system")
}

requires(exists($$GTEST_SRCDIR):exists($$GMOCK_SRCDIR))


!isEmpty(GTEST_SRCDIR) {
    INCLUDEPATH *= \
        $$GTEST_SRCDIR \
        $$GTEST_SRCDIR/include

    SOURCES += \
        $$GTEST_SRCDIR/src/gtest-all.cc
}

!isEmpty(GMOCK_SRCDIR) {
    INCLUDEPATH *= \
        $$GMOCK_SRCDIR \
        $$GMOCK_SRCDIR/include

    SOURCES += \
        $$GMOCK_SRCDIR/src/gmock-all.cc
}

#Progect Includes
GAME_ITEMS_FOLDER = GameItems
GRAPHICS_FOLDER = Graphics
INTERFACES_FOLDER = Interfaces
MANAGERS_FOLDER = Managers

requires(exists($$GAME_ITEMS_FOLDER):exists($$GRAPHICS_FOLDER):exists($$INTERFACES_FOLDER):exists($$MANAGERS_FOLDER))

INCLUDEPATH *= \
    ../$$GAME_ITEMS_FOLDER \
    ../$$GRAPHICS_FOLDER \
    ../$$INTERFACES_FOLDER \
    ../$$MANAGERS_FOLDER

SOURCES += \
    ../$$GAME_ITEMS_FOLDER/chessfigure.cpp \
    ../$$MANAGERS_FOLDER/figuremanager.cpp \
    ../$$MANAGERS_FOLDER/GameManager.cpp \


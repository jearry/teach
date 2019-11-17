include (platform.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    plan_game.cpp

DISTFILES += \
    input.txt

HEADERS += \
    plan_game.h


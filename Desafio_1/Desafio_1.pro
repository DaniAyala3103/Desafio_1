TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        combinaciones.cpp \
        eliminaciones.cpp \
        fichas.cpp \
        juego.cpp \
        main.cpp \
        memoria.cpp \
        tablero.cpp \
        visualizacion.cpp

HEADERS += \
    combinaciones.h \
    eliminaciones.h \
    fichas.h \
    juego.h \
    memoria.h \
    tablero.h \
    visualizacion.h

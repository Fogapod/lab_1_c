TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    task.cpp \
    proc.cpp

HEADERS += \
    task.h \
    proc.h

QMAKE_CXXFLAGS += -pthread

LIBS += -pthread

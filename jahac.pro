TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    example/main.cpp \
    utility/convert.cpp \
    network/socket.cpp \
    utility/arraysize.cpp

HEADERS += \
    utility/convert.h \
    network/socket.h \
    utility/arraysize.h

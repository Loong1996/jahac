TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    example/main.cpp \
    utility/convert.cpp \
    utility/arraysize.cpp \
    utility/iddist.cpp \
    utility/define.cpp \
    network/tcpsocket.cpp \
    network/socketaddress.cpp \
    network/socketaddressfactory.cpp \
    network/socketutil.cpp

HEADERS += \
    utility/convert.h \
    utility/arraysize.h \
    utility/iddist.h \
    utility/define.h \
    network/tcpsocket.h \
    network/socketaddress.h \
    network/socketaddressfactory.h \
    network/socketutil.h

LIBS += -lws2_32

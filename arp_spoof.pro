TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
        src/model/arp.cpp \
        src/model/mac.cpp

HEADERS += \
    header/arp.h \
    header/define.h \
    header/mac.h \
    lib/libnet/libnet-headers.h \
    lib/libnet/libnet-macros.h \
    lib/libnet/libnet-types.h \
    src/model/arp.h \
    src/model/mac.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS+= -openmp
QMAKE_LFLAGS +=  -openmp

INCLUDEPATH += /usr/local/include
SOURCES += \
        main.cpp
LIBS += -lomp
#LIBS += /usr/local/opt/libomp/lib/libomp.a

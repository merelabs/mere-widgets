QT       -= gui

TARGET = mere-widgets
TEMPLATE = app 

SOURCES += \
        src/main.cpp \

HEADERS += \


DEPENDPATH += . ../lib
INCLUDEPATH += ../include

LIBS += -L$$PWD/../lib -lmere-widgets
LIBS += -lX11

#
# Install
#
unix {
    target.path = /usr/local/bin
    INSTALLS += target
}

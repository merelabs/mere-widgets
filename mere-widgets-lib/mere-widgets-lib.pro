include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
#include(../../mere-log/mere-log-lib/mere-log-lib.pri)
#include(../../mere-config/mere-config-lib/mere-config-lib.pri)

QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += shared

TARGET = mere-widgets
VERSION= 0.0.1b
TEMPLATE = lib

DEFINES += LIB_CODE=\\\"widgets\\\"
DEFINES += LIB_NAME=\\\"$$TARGET\\\"
DEFINES += LIB_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS MERE_WIDGETS_LIB

SOURCES += \
    src/app.cpp \
    src/defaultapp.cpp \
    src/editablelabel.cpp \
    src/editorpanel.cpp \
    src/meredefaultwin.cpp \
    src/mereresizeablewin.cpp \
    src/meresimplewinheader.cpp \
    src/merestatusbar.cpp \
    src/merewidgetresizer.cpp \
    src/merepushmenu.cpp \
    src/mereballonwidget.cpp \
    src/merelabel.cpp \
    src/mereclickdetector.cpp \
    src/mereshadowwidget.cpp \
    src/merewin.cpp \
    src/merewindefaultheader.cpp \
    src/merewinheader.cpp \
    src/noteeditor.cpp \
    src/texteditor.cpp

HEADERS += \
    src/app.h \
    src/defaultapp.h \
    src/editablelabel.h \
    src/editorpanel.h \
    src/meredefaultwin.h \
    src/meremoveable.h \
    src/mereresizeable.h \
    src/mereresizeablewin.h \
    src/meresimplewinheader.h \
    src/merestatusbar.h \
    src/merewidgetresizer.h \
    src/merepushmenu.h \
    src/mereballonwidget.h \
    src/merelabel.h \
    src/merepopupmenu.h \
    src/mereclickdetector.h \
    src/mereshadowwidget.h \
    src/merewin.h \
    src/merewindefaultheader.h \
    src/merewinheader.h \
    src/noteeditor.h \
    src/texteditor.h

RESOURCES += \
        res/widgets.qrc

INCLUDEPATH += /usr/local/include
LIBS += -lX11

#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/widgets
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}

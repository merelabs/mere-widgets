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
    src/defaultwin.cpp \
    src/defaultwinheader.cpp \
    src/editablelabel.cpp \
    src/headerview.cpp \
    src/merepushmenu.cpp \
    src/mereballonwidget.cpp \
    src/merelabel.cpp \
    src/mereclickdetector.cpp \
    src/mereshadowwidget.cpp \
    src/merewin.cpp \
    src/noteeditor.cpp \
    src/noteeditorpanel.cpp \
    src/panelview.cpp \
    src/resizeablewin.cpp \
    src/resizer.cpp \
    src/scratchboard.cpp \
    src/scratcheditor.cpp \
    src/scratcheditorpanel.cpp \
    src/scratcheditorscroller.cpp \
    src/simplewinheader.cpp \
    src/simplewinheaderex.cpp \
    src/statusbar.cpp \
    src/texteditor.cpp \
    src/winheader.cpp

HEADERS += \
    src/app.h \
    src/defaultapp.h \
    src/defaultwin.h \
    src/defaultwinheader.h \
    src/editablelabel.h \
    src/global.h \
    src/headerview.h \
    src/meremoveable.h \
    src/merepushmenu.h \
    src/mereballonwidget.h \
    src/merelabel.h \
    src/merepopupmenu.h \
    src/mereclickdetector.h \
    src/mereshadowwidget.h \
    src/merewin.h \
    src/noteeditor.h \
    src/noteeditorpanel.h \
    src/panelview.h \
    src/resizeablewin.h \
    src/resizer.h \
    src/scratchboard.h \
    src/scratcheditor.h \
    src/scratcheditorpanel.h \
    src/scratcheditorscroller.h \
    src/simplewinheader.h \
    src/simplewinheaderex.h \
    src/statusbar.h \
    src/texteditor.h \
    src/winheader.h

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

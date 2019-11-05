include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
include(../../mere-log/mere-log-lib/mere-log-lib.pri)

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

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    src/mereapp.cpp \
    src/meredefaultapp.cpp \
    src/meredefaultwin.cpp \
    src/merestatusbar.cpp \
    src/merewidgetresizer.cpp \
    src/merepushmenu.cpp \
    src/mereballonwidget.cpp \
    src/merelabel.cpp \
    src/mereclickdetector.cpp \
    src/mereshadowwidget.cpp \
    src/merewin.cpp \
    src/merewindefaultheader.cpp \
    src/merewinheader.cpp

HEADERS += \
    src/mereapp.h \
    src/meredefaultapp.h \
    src/meredefaultwin.h \
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
    src/merewinheader.h

DESTDIR = $$PWD/../lib
LIBS += -lX11

defineTest(copy) {
    source = $$1
    target = $$2

    for(file, source) {
        sdir = $${dirname(file)}
        sdir = $$replace(sdir, "src", "")
        path = $${target}$${sdir}

        QMAKE_POST_LINK += $$QMAKE_MKDIR $$quote($$path) $$escape_expand(\\n\\t)
        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$file) $$quote($$path) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

copy($$HEADERS, $$PWD/../include/mere/widgets)

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

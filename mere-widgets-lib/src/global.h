#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtCore/qglobal.h>
#include <QDebug>

#if defined(MERE_WIDGETS_LIB)
#  define MERE_WIDGETS_LIBSPEC Q_DECL_EXPORT
#else
#  define MERE_WIDGETS_LIBSPEC Q_DECL_IMPORT
#endif

#endif // GLOBAL_H

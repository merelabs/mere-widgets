#ifndef MERERESIZEABLE_H
#define MERERESIZEABLE_H

#include <QSize>

class MereResizeable
{
public:
    virtual void adjustSize(const QSize &size) = 0;
};

#endif // MERERESIZEABLE_H

#ifndef MEREMOVEABLE_H
#define MEREMOVEABLE_H

#include <QPoint>

class MereMoveable
{
public:
    virtual void adjustMove(const QPoint &point) = 0;
};

#endif // MEREMOVEABLE_H

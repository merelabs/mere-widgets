#ifndef MERE_WIDGETS_MOVEABLE_H
#define MERE_WIDGETS_MOVEABLE_H

#include <QPoint>

namespace Mere
{
namespace Widgets
{

class Moveable
{
public:
    virtual void adjustMove(const QPoint &point) = 0;
};

}
}
#endif // MERE_WIDGETS_MOVEABLE_H

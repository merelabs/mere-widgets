#ifndef MERE_WIDGETS_RESIABLEWIN_H
#define MERE_WIDGETS_RESIABLEWIN_H

#include "defaultwin.h"

namespace Mere
{

namespace Widgets
{

class Resizer;
class MERE_WIDGETS_LIBSPEC ResizeableWin : public DefaultWin
{
    Q_OBJECT
public:
    virtual ~ResizeableWin();
    explicit ResizeableWin(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Resizer *m_resizer;
};

}
}

#endif // MERE_WIDGETS_RESIABLEWIN_H

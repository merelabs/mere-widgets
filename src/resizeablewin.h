#ifndef MERERESIABLEWIN_H
#define MERERESIABLEWIN_H

#include "defaultwin.h"

namespace Mere {

namespace Widgets {

class Resizer;
class ResizeableWin : public DefaultWin
{
    Q_OBJECT
public:
    explicit ResizeableWin(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Resizer *m_resizer;
};

}
}

#endif // MERERESIABLEWIN_H

#ifndef MERE_WIDGETS_DEFAULTWIN_H
#define MERE_WIDGETS_DEFAULTWIN_H

#include "win.h"
#include "moveable.h"

#include <QWidget>

namespace Mere
{

namespace Widgets
{

class SimpleWinHeader;

class DefaultWin : public Win, public Moveable
{
    Q_OBJECT
public:
    explicit DefaultWin(QWidget *parent = nullptr);

protected:
    virtual void initHeaderUI() override;
    virtual void initContentUI() override;
    virtual void initFooterUI() override;

//    virtual void adjustSize(const QSize &size) override;
    virtual void adjustMove(const QPoint &point) override;

private:
    SimpleWinHeader *m_header;
};

}
}

#endif // MERE_WIDGETS_DEFAULTWIN_H

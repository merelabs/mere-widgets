#ifndef MEREDEFAULTWIN_H
#define MEREDEFAULTWIN_H

#include "merewin.h"
#include "meremoveable.h"

#include <QWidget>

namespace Mere
{

namespace Widgets
{

class SimpleWinHeader;

class DefaultWin : public MereWin, public MereMoveable
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

signals:

public slots:

private:
    SimpleWinHeader *m_header;
};

}
}

#endif // MEREDEFAULTWIN_H

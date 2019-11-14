#ifndef MEREDEFAULTWIN_H
#define MEREDEFAULTWIN_H

#include "merewin.h"
#include "meremoveable.h"
#include "mereresizeable.h"

#include <QWidget>

class MereWinDefaultHeader;

class MereDefaultWin : public MereWin, public MereMoveable, public MereResizeable
{
    Q_OBJECT
public:
    explicit MereDefaultWin(QWidget *parent = nullptr);


protected:
    virtual void initHeaderUI() override;
    virtual void initContentUI() override;
    virtual void initFooterUI() override;

    virtual void adjustSize(const QSize &size) override;
    virtual void adjustMove(const QPoint &point) override;

signals:

public slots:

private:
    MereWinDefaultHeader *m_header;
//    MereWidgetMover *m_mover;
};

#endif // MEREDEFAULTWIN_H

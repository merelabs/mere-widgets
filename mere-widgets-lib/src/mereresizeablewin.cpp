#include "mereresizeablewin.h"
#include "merewidgetresizer.h"

#include <QResizeEvent>

MereResizeableWin::MereResizeableWin(QWidget *parent)
    : MereDefaultWin(parent)
{
    m_resizer = new MereWidgetResizer(this);
    m_resizer->setParent(this);
}

void MereResizeableWin::resizeEvent(QResizeEvent *event)
{
    MereDefaultWin::resizeEvent(event);

    m_resizer->move( event->size().width() - m_resizer->width(),
    event->size().height() - m_resizer->height() );

    event->accept();
}

void MereResizeableWin::adjustSize(const QSize &size)
{
    resize(width() + size.width(), height() + size.height());
}

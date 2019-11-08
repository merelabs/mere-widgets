#include "merewidgetresizer.h"

#include <QLabel>
#include <QMouseEvent>

MereWidgetResizer::MereWidgetResizer(MereResizeable *resizeable)
    : m_resizeable(resizeable)
{
    setCursor(QCursor(Qt::SizeFDiagCursor));

    QLabel *label = new QLabel(this);
    label->setPixmap(QPixmap(":/widgets/resize.png"));
    label->setScaledContents(true);
    label->setContentsMargins(0,0,0,0);
    label->setMinimumSize(sizeHint());
    label->setMaximumSize(sizeHint());

    setMaximumSize(sizeHint());
}

QSize MereWidgetResizer::sizeHint() const
{
    return QSize( 16, 16);
}


void MereWidgetResizer::mousePressEvent(QMouseEvent *event)
{
    m_point = event->globalPos();
}

void MereWidgetResizer::mouseReleaseEvent(QMouseEvent *event)
{
}

void MereWidgetResizer::mouseMoveEvent(QMouseEvent *event)
{
    const QPoint diff = event->globalPos() - m_point;
    m_point = event->globalPos();
    m_resizeable->adjustSize(QSize( diff.x(), diff.y()));
}

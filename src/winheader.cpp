#include "winheader.h"

#include <QLayout>
Mere::Widgets::WinHeader::~WinHeader()
{

}

Mere::Widgets::WinHeader::WinHeader(QWidget *parent)
    : HeaderView(parent),
      m_lock(false),
      m_parent(parentWidget())
{

}

void Mere::Widgets::WinHeader::initUI()
{
    initLeftPanel();
    initCenterPanel();
    initRightPanel();
}

void Mere::Widgets::WinHeader::mousePressEvent(QMouseEvent *event)
{
    m_lock = true;

    QMargins margins = m_parent->layout()->contentsMargins();
    QPoint  point(margins.left(), margins.top());
    m_pos = event->pos() + point;
}

void Mere::Widgets::WinHeader::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_lock = false;
}

void Mere::Widgets::WinHeader::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_lock) return;
    m_parent->move(event->globalPos()- m_pos);

    this->update();
}

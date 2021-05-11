#include "resizeablewin.h"
#include "resizer.h"

#include <QResizeEvent>

Mere::Widgets::ResizeableWin::~ResizeableWin()
{
    if(m_resizer)
    {
        delete m_resizer;
        m_resizer = nullptr;
    }
}

Mere::Widgets::ResizeableWin::ResizeableWin(QWidget *parent)
    : DefaultWin(parent)
{
    m_resizer = new Mere::Widgets::Resizer(this);
}

void Mere::Widgets::ResizeableWin::resizeEvent(QResizeEvent *event)
{
    DefaultWin::resizeEvent(event);

    m_resizer->move( event->size().width() - m_resizer->width(),
    event->size().height() - m_resizer->height() );

    event->accept();
}

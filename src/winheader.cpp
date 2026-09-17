#include "winheader.h"

#include <QLayout>
#include <QWindow>
#include <QHBoxLayout>

Mere::Widgets::WinHeader::~WinHeader()
{

}

Mere::Widgets::WinHeader::WinHeader(QWidget *parent)
    : HeaderView(parent),
      m_lock(false),
      m_parent(parentWidget())
{
    QHBoxLayout *layout = qobject_cast<QHBoxLayout *>(this->layout());

    m_leftPane = new QWidget(this);
    m_leftPane->setMinimumWidth(24);

    m_centerPane = new QWidget(this);
    m_centerPane->setMinimumWidth(100);

    m_rightPane = new QWidget(this);
    // m_rightPane->setStyleSheet("background-color: #ffd93d; border: 2px solid #c9a100;");
    m_rightPane->setMinimumWidth(24);

    layout->addWidget(m_leftPane, 1);
    layout->addWidget(m_centerPane, 0);
    layout->addWidget(m_rightPane, 1);
}

void Mere::Widgets::WinHeader::initUI()
{
    initLeftPanel(m_leftPane);
    initCenterPanel(m_centerPane);
    initRightPanel(m_rightPane);
}

void Mere::Widgets::WinHeader::mousePressEvent(QMouseEvent *event)
{
    m_lock = true;

    QMargins margins = m_parent->layout()->contentsMargins();
    QPoint  point(margins.left(), margins.top());
    m_pos = event->pos() + point;

    QString platform = QGuiApplication::platformName();
    if (platform.startsWith("wayland"))
    {
        if (event->button() == Qt::LeftButton)
        {
            QWindow *handler = window()->windowHandle();
            if (handler && handler->startSystemMove())
            {
                event->accept();
                return;
            }
        }
    }

     QWidget::mousePressEvent(event);
}

void Mere::Widgets::WinHeader::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_lock = false;

    QWidget::mouseReleaseEvent(event);
}

void Mere::Widgets::WinHeader::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_lock) return;

    m_parent->move(event->globalPosition().toPoint() - m_pos);

    this->update();

    QWidget::mouseMoveEvent(event);
}

#include "resizer.h"

#include <QLabel>
#include <QMouseEvent>

Mere::Widgets::Resizer::~Resizer()
{

}

Mere::Widgets::Resizer::Resizer(QWidget *parent)
    : QWidget(parent),
      m_lock(false),
      m_parent(parentWidget())
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

QSize Mere::Widgets::Resizer::sizeHint() const
{
    return QSize( 16, 16);
}

void Mere::Widgets::Resizer::mousePressEvent(QMouseEvent *event)
{
    m_lock = true;
    m_point = event->globalPos();
    m_rect   = m_parent->geometry();
}

void Mere::Widgets::Resizer::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_lock = false;
}

void Mere::Widgets::Resizer::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_lock) return;

    const QPoint diff = event->globalPos() - m_point;

    m_parent->resize(m_rect.width() + diff.x(), m_rect.height() + diff.y());

    this->update();
}

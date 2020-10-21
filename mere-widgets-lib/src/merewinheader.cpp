#include "merewinheader.h"

#include <QLabel>
#include <QHostInfo>
#include <QPushButton>
#include <QApplication>

MereWinHeader::MereWinHeader(QWidget *parent)
    : QWidget(parent),
//      m_title(nullptr),
      m_lock(false)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);
}

void MereWinHeader::initUI()
{
    initLeftPanel();
    initCenterPanel();
    initRightPanel();
}

//void MereWinHeader::setTitle(const QString &title)
//{
//    qDebug() << "????" << title << m_title;
////    m_title->setText(title);
//}

void MereWinHeader::mousePressEvent(QMouseEvent *event)
{
    m_lock = false;
    m_point = event->globalPos();
}

void MereWinHeader::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    m_lock = true;
}

void MereWinHeader::mouseMoveEvent(QMouseEvent *event)
{
    if (m_lock) return;

    QPoint point = event->globalPos();
    parentWidget()->move(parentWidget()->pos() + point - m_point);
    m_point = point;
}

void MereWinHeader::close()
{
    emit closed();

    qApp->exit();
}


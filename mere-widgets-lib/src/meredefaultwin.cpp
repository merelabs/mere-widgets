#include "meredefaultwin.h"
#include "merewindefaultheader.h"

#include <QVBoxLayout>

MereDefaultWin::MereDefaultWin(QWidget *parent)
    : MereWin(parent)
{
    setObjectName(QString::fromUtf8("MereDefaultWin"));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}

void MereDefaultWin::initHeaderUI()
{
    m_header = new MereWinDefaultHeader();
    m_header->setTitle("Default");

    layout()->addWidget(m_header);
}

void MereDefaultWin::initContentUI()
{

}

void MereDefaultWin::initFooterUI()
{

}

void MereDefaultWin::adjustSize(const QSize &size)
{

}

void MereDefaultWin::adjustMove(const QPoint &point)
{

}



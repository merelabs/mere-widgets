#include "merewindefaultheader.h"

#include <QHostInfo>
#include <QPushButton>
#include <QVBoxLayout>

MereWinDefaultHeader::MereWinDefaultHeader(QWidget *parent)
    : MereWinHeader(parent)
{
    setMaximumHeight(48);
}

void MereWinDefaultHeader::setHeaderStyle(MereHeaderStyle style)
{
    m_style = style;
}

void MereWinDefaultHeader::initLeftPanel()
{
    QWidget *pane = new QWidget(this);
    pane->setMaximumWidth(100);
    layout()->addWidget(pane);
}

void MereWinDefaultHeader::initCenterPanel()
{
    QWidget *pane = new QWidget(this);
    layout()->addWidget(pane);

    QVBoxLayout *layout = new QVBoxLayout(pane);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

     m_title = new QLabel("[Unknown app]");
     m_title->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
     m_title->setObjectName("MereWinHeaderTitle");
     layout->addWidget(m_title);

     QLabel *host = new QLabel(QString("@").append(QHostInfo::localHostName()));
     host->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
     layout->addWidget(host);
}

void MereWinDefaultHeader::initRightPanel()
{
    QWidget *pane = new QWidget(this);
    pane->setMaximumWidth(100);
    layout()->addWidget(pane);

    QHBoxLayout *layout = new QHBoxLayout(pane);
    layout->setAlignment(Qt::AlignRight);

    QPushButton *close = new QPushButton(QIcon(":/widgets/close.png"),"");
    close->setMaximumWidth(24);
    close->setFlat(true);
    layout->addWidget(close);
    connect(close, SIGNAL(clicked(bool)), this, SLOT(close()));
}


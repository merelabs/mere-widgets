#include "meresimplewinheader.h"

#include <QPushButton>

MereSimpleWinHeader::MereSimpleWinHeader(QWidget *parent)
    : MereWinHeader(parent)
{

}

void MereSimpleWinHeader::initLeftPanel()
{
    QWidget *pane = new QWidget(this);
    pane->setMaximumWidth(100);
    layout()->addWidget(pane);
}

void MereSimpleWinHeader::initCenterPanel()
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
}

void MereSimpleWinHeader::initRightPanel()
{
    QPushButton *close = new QPushButton(QIcon(":/widgets/close.png"),"");
    close->setMaximumWidth(24);
    close->setMaximumHeight(24);
    close->setFlat(true);
    layout()->addWidget(close);
    connect(close, SIGNAL(clicked(bool)), this, SLOT(close()));
}


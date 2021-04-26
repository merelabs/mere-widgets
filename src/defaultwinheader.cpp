#include "defaultwinheader.h"

#include <QLayout>
#include <QPushButton>

Mere::Widgets::DefaultWinHeader::~DefaultWinHeader()
{

}

Mere::Widgets::DefaultWinHeader::DefaultWinHeader(QWidget *parent)
    : WinHeader(parent)
{
}

void Mere::Widgets::DefaultWinHeader::initRightPanel()
{
    QMargins margins = layout()->contentsMargins();
    margins.setRight(margins.right() + 3);
    layout()->setContentsMargins(margins);

    QPushButton *close = new QPushButton(QIcon(":/widgets/icons/times-circle.svg"),"", this);
    close->setIconSize(QSize(20, 20));
    close->setMaximumSize(QSize(20, 20));
    close->setFlat(true);
    layout()->addWidget(close);

    connect(close, SIGNAL(clicked(bool)), this, SIGNAL(closed()));
}

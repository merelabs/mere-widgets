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
    close->setObjectName("DefaultWinHeaderCloseButton");
    close->setStyleSheet("QPushButton#DefaultWinHeaderCloseButton:hover:pressed{border: none;}");
    close->setIconSize(QSize(20, 20));
    close->setMaximumSize(QSize(20, 20));
    close->setFlat(true);
    close->setFocusPolicy(Qt::NoFocus);

    layout()->addWidget(close);

    connect(close, SIGNAL(clicked(bool)), this, SIGNAL(closed()));
}

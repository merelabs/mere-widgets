#include "defaultwinheader.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QApplication>

Mere::Widgets::DefaultWinHeader::~DefaultWinHeader()
{

}

Mere::Widgets::DefaultWinHeader::DefaultWinHeader(QWidget *parent)
    : WinHeader(parent)
{
}

void Mere::Widgets::DefaultWinHeader::initRightPanel()
{
    QPushButton *close = new QPushButton(QIcon(":/widgets/icons/times-circle.svg"),"", this);
    close->setIconSize(QSize(20, 20));
    close->setMaximumSize(QSize(20, 20));
    close->setFlat(true);
    layout()->addWidget(close);

    connect(close, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Mere::Widgets::DefaultWinHeader::close()
{
    emit closed();
}

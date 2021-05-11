#include "simplewinheaderex.h"

#include <QHostInfo>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


Mere::Widgets::SimpleWinHeaderEx::~SimpleWinHeaderEx()
{
}

Mere::Widgets::SimpleWinHeaderEx::SimpleWinHeaderEx(QWidget *parent)
    : SimpleWinHeader(parent)
{
    setMaximumHeight(48);
}

void Mere::Widgets::SimpleWinHeaderEx::initCenterPanel()
{
    SimpleWinHeader::initCenterPanel();

    QWidget *pane = new QWidget(this);
    layout()->addWidget(pane);

    QVBoxLayout *layout = new QVBoxLayout(pane);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignCenter);

    QLabel *title = findChild<QLabel *>("SimpleWinHeaderTitle");
    layout->addWidget(title);

    QLabel *host = new QLabel(QString("@").append(QHostInfo::localHostName()));
    host->setAlignment(Qt::AlignCenter);
    layout->addWidget(host);
}

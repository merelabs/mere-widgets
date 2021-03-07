#include "simplewinheaderex.h"

#include <QHostInfo>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


Mere::Widgets::SimpleWinHeaderEx::~SimpleWinHeaderEx()
{
    if (m_title)
    {
        delete m_title;
        m_title = nullptr;
    }
}

Mere::Widgets::SimpleWinHeaderEx::SimpleWinHeaderEx(QWidget *parent)
    : SimpleWinHeader(parent),
      m_title(nullptr)
{
    setMaximumHeight(48);
}

// FIXME: Use the label of SimpleWinHeader and move that to v-layout
void Mere::Widgets::SimpleWinHeaderEx::initCenterPanel()
{
    QWidget *pane = new QWidget(this);
    layout()->addWidget(pane);

    QVBoxLayout *layout = new QVBoxLayout(pane);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignCenter);

     m_title = new QLabel("[Unknown app]");
     m_title->setAlignment(Qt::AlignCenter);
     m_title->setObjectName("MereWinHeaderTitle");
     layout->addWidget(m_title);

     QLabel *host = new QLabel(QString("@").append(QHostInfo::localHostName()));
     host->setAlignment(Qt::AlignCenter);
     layout->addWidget(host);
}

void Mere::Widgets::SimpleWinHeaderEx::setTitle(const QString &title)
{
    m_title->setText(title);
}

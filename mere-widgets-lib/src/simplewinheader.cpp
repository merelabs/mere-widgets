#include "simplewinheader.h"

#include <QLayout>

Mere::Widgets::SimpleWinHeader::~SimpleWinHeader()
{
    if (m_title)
    {
        delete m_title;
        m_title = nullptr;
    }
}

Mere::Widgets::SimpleWinHeader::SimpleWinHeader(QWidget *parent)
    : DefaultWinHeader(parent),
      m_title(nullptr)
{

}

void Mere::Widgets::SimpleWinHeader::initLeftPanel()
{
}

void Mere::Widgets::SimpleWinHeader::initCenterPanel()
{
     m_title = new QLabel("[Unknown app]");
     m_title->setAlignment(Qt::AlignCenter);
     m_title->setObjectName("SimpleWinHeaderTitle");
     layout()->addWidget(m_title);
}

void Mere::Widgets::SimpleWinHeader::setTitle(const QString &title)
{
    m_title->setText(title);
}



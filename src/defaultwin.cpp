#include "defaultwin.h"
#include "simplewinheader.h"

#include <QVBoxLayout>

Mere::Widgets::DefaultWin::~DefaultWin()
{

}

Mere::Widgets::DefaultWin::DefaultWin(QWidget *parent)
    : Win(parent)
{
    setObjectName(QString::fromUtf8("MereDefaultWin"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);
}

void Mere::Widgets::DefaultWin::initHeaderUI()
{
    m_header = new SimpleWinHeader();
    m_header->setTitle("Default");

    layout()->addWidget(m_header);
}

void Mere::Widgets::DefaultWin::initContentUI()
{

}

void Mere::Widgets::DefaultWin::initFooterUI()
{

}

void Mere::Widgets::DefaultWin::adjustMove(const QPoint &point)
{
    Q_UNUSED(point)
}



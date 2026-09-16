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

void Mere::Widgets::SimpleWinHeaderEx::initCenterPanel(QWidget *container)
{
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);

    m_title = new QLabel("[Unknown app]");
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setObjectName("SimpleWinHeaderExTitle");

    QFont font = m_title->font();
    font.setBold(true);
    m_title->setFont(font);

    layout->addWidget(m_title);

    m_host = new QLabel(QString("%1@%2").arg(username()).arg(QHostInfo::localHostName()));
    m_host->setAlignment(Qt::AlignCenter);
    layout->addWidget(m_host);
}

void Mere::Widgets::SimpleWinHeaderEx::setTitle(const QString &title)
{
    m_title->setText(title);
}



QString Mere::Widgets::SimpleWinHeaderEx::username() const
{
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");
    return name;
}

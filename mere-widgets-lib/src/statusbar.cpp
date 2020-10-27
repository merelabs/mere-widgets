#include "statusbar.h"

#include <QHBoxLayout>

Mere::Widgets::StatusBar::StatusBar(QWidget *parent)
    : QWidget(parent),
      m_status(new QLabel)
{
    setObjectName("Mere::Widgets::StatusBar");

    setMaximumHeight(24);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(9, 2, 9, 2);
    setLayout(layout);

    initUI();
}

void Mere::Widgets::StatusBar::initUI()
{
    layout()->addWidget(m_status);

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout()->addItem(spacer);

    setStatus("...");
}

void Mere::Widgets::StatusBar::setStatus(const QString &status)
{
    m_status->setText(status);
}

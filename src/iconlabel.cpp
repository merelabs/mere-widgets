#include "iconlabel.h"

#include <QLabel>
#include <QHBoxLayout>

Mere::Widgets::IconLabel::IconLabel(QWidget *parent)
    : Mere::Widgets::IconLabel{QPixmap(), "text", parent}
{
}

Mere::Widgets::IconLabel::IconLabel(const std::string &icon, const std::string &text, QWidget *parent)
    : Mere::Widgets::IconLabel(QPixmap(icon.c_str()), text, parent)
{
}

Mere::Widgets::IconLabel::IconLabel(const QPixmap &icon, const std::string &text, QWidget *parent)
    : QWidget{parent}, m_icon(icon), m_text(text)
{
    setObjectName("MereIconLabel");
    initUI();
}

void Mere::Widgets::IconLabel::initUI()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(7);
    layout->setAlignment(Qt::AlignLeft);

    auto icon = new QLabel(this);
    icon->setPixmap(m_icon);
    layout->addWidget(icon);

    auto text = new QLabel(m_text.c_str(), this);
    layout->addWidget(text);
}

void Mere::Widgets::IconLabel::setIcon(const QPixmap &icon)
{
    m_icon = icon;
    auto label = static_cast<QLabel*>(this->layout()->itemAt(0)->widget());
    label->setPixmap(m_icon);
}

void Mere::Widgets::IconLabel::setIcon(const std::string &icon)
{
    setIcon(QPixmap(icon.c_str()));
}

void Mere::Widgets::IconLabel::setText(const std::string &text)
{
    m_text = text;
    auto label = static_cast<QLabel*>(this->layout()->itemAt(1)->widget());
    label->setText(text.c_str());
}

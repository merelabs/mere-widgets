#include "win.h"

#include <QPainter>
#include <QStyleOption>

Mere::Widgets::Win::~Win()
{
}

Mere::Widgets::Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QString::fromUtf8("MereWin"));
    setWindowFlags(Qt::FramelessWindowHint);
}

void Mere::Widgets::Win::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
}

void Mere::Widgets::Win::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QStyleOption option;
    option.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);

    QWidget::paintEvent(event);
}

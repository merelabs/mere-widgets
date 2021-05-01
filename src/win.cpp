#include "win.h"

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

#include "merewin.h"

MereWin::~MereWin()
{

}

MereWin::MereWin(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QString::fromUtf8("MereWin"));
    setWindowFlags(Qt::FramelessWindowHint);
}

void MereWin::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
}

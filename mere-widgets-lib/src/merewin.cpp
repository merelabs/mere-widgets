#include "merewin.h"

MereWin::~MereWin()
{

}

MereWin::MereWin(QWidget *parent)
    : QWidget(parent)
{
}

void MereWin::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
}

#include "merefloateditpanel.h"

MereFloatEditPanel::MereFloatEditPanel(QWidget *parent)
    : MereSimpleEditPanel(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0, 46, 99, 25));
    setAutoFillBackground(true);
    setPalette(pal);
}

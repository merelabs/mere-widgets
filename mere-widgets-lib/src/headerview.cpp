#include "headerview.h"

#include <QHBoxLayout>
Mere::Widgets::HeaderView::~HeaderView()
{

}

Mere::Widgets::HeaderView::HeaderView(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, QColor(0, 0, 0, 50));
    palette.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette(palette);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);
}

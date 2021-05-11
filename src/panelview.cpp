#include "panelview.h"

Mere::Widgets::PanelView::~PanelView()
{

}

Mere::Widgets::PanelView::PanelView(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, QColor(0, 0, 0, 50));
    palette.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette(palette);
}

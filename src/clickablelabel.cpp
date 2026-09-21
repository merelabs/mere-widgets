#include "clickablelabel.h"

#include <QMouseEvent>

namespace Mere::Widgets
{

// ClickableLabel::ClickableLabel(QLabel *parent)
//     : QLabel{parent}
// {
// }

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked(event->globalPosition().toPoint());
    QLabel::mousePressEvent(event);
}
}

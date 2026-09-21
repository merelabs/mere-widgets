#ifndef MERE_WIDGETS_CLICKABLELABEL_H
#define MERE_WIDGETS_CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>

namespace Mere::Widgets
{

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    using QLabel::QLabel;
    // explicit ClickableLabel(QLabel *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *e) override;

signals:
    void clicked(const QPoint &globalPos);

};

}
#endif // MERE_WIDGETS_CLICKABLELABEL_H

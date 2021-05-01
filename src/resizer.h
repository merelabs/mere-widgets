#ifndef MERE_WIDGETS_RESIZER_H
#define MERE_WIDGETS_RESIZER_H

#include <QWidget>
#include <QDebug>

namespace Mere
{
namespace Widgets
{

class Resizer : public QWidget
{
    Q_OBJECT
public:
    virtual ~Resizer();
    explicit Resizer(QWidget *parent);

    QSize sizeHint() const override;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool m_lock;
    QRect m_rect;
    QPoint m_point;
    QWidget *m_parent;
};

}
}

#endif // MERE_WIDGETS_RESIZER_H

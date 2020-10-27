#ifndef MEREWIDGETS_RESIZER_H
#define MEREWIDGETS_RESIZER_H

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

    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool m_lock;
    QRect m_rect;
    QPoint m_point;
    QWidget *m_parent;
};

}
}

#endif // MEREWIDGETS_RESIZER_H

#ifndef MEREWIDGETRESIZER_H
#define MEREWIDGETRESIZER_H

#include "mereresizeable.h"

#include <QWidget>
#include <QDebug>

class MereWidgetResizer : public QWidget
{
    Q_OBJECT
public:
    explicit MereWidgetResizer(MereResizeable *resizeable);

    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

signals:

public slots:
private:
    QPoint m_point;
    MereResizeable *m_resizeable;
};

#endif // MEREWIDGETRESIZER_H

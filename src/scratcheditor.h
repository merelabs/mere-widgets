#ifndef MERE_WIDGETS_SCRATCHEDITOR_H
#define MERE_WIDGETS_SCRATCHEDITOR_H

#include <QPen>
#include <QWidget>
#include <QDebug>



namespace Mere
{
namespace Widgets
{

class Resizer;
class ScratchEditor : public QWidget
{
    Q_OBJECT
public:
    virtual ~ScratchEditor();
    explicit ScratchEditor(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

signals:

public slots:
    void setPenSize(const int &size);
    void setPenColor(const QColor &color);

private:
    bool m_lock;
    QPoint m_point;

    int m_penSize;
    QColor m_penColor;

    QPixmap *m_buffer;
    QPainter *m_painter;

    Resizer *m_resizer;
};

}
}

#endif // MERE_WIDGETS_SCRATCHEDITOR_H

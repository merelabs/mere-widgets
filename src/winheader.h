#ifndef MERE_WIDGETS_WINHEADER_H
#define MERE_WIDGETS_WINHEADER_H

#include "headerview.h"

#include <QMouseEvent>

namespace Mere
{

namespace Widgets
{

class MERE_WIDGETS_LIBSPEC WinHeader : public HeaderView
{
    Q_OBJECT
public:
    virtual ~WinHeader();
    explicit WinHeader(QWidget *parent = nullptr);

    void initUI();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool m_lock;
    QPoint m_pos;

    QWidget *m_parent;
};

}
}

#endif // MERE_WIDGETS_WINHEADER_H

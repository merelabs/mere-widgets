#ifndef MERERESIABLEWIN_H
#define MERERESIABLEWIN_H

#include "mereresizeable.h"
#include "meredefaultwin.h"

class MereWidgetResizer;

class MereResizeableWin : public MereDefaultWin
{
    Q_OBJECT
public:
    explicit MereResizeableWin(QWidget *parent = nullptr);

protected:
    void adjustSize(const QSize &size) override;
    void resizeEvent(QResizeEvent *event) override;

signals:

public slots:

private:
    MereWidgetResizer *m_resizer;
};

#endif // MERERESIABLEWIN_H

#ifndef MEREDEFAULTWIN_H
#define MEREDEFAULTWIN_H

#include "merewin.h"

#include <QWidget>

class MereDefaultWin : public MereWin
{
    Q_OBJECT
public:
    explicit MereDefaultWin(QWidget *parent = nullptr);

protected:
    virtual void initHeaderUI() override;
    virtual void initContentUI() override;
    virtual void initFooterUI() override;

signals:

public slots:
};

#endif // MEREDEFAULTWIN_H

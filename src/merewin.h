#ifndef MEREWIN_H
#define MEREWIN_H

#include <QWidget>

class MereWin : public QWidget
{
    Q_OBJECT
public:
    virtual ~MereWin();
    explicit MereWin(QWidget *parent = nullptr);

    void initUI();

protected:
    virtual void initHeaderUI() = 0;
    virtual void initContentUI()= 0;
    virtual void initFooterUI() = 0;

signals:

public slots:
};

#endif // MEREWIN_H

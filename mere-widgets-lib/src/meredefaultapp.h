#ifndef MEREDEFAULTAPP_H
#define MEREDEFAULTAPP_H

#include "mereapp.h"

#include <QObject>
#include <QDebug>

class MereDefaultApp : public MereApp
{
    Q_OBJECT
public:
    explicit MereDefaultApp(int &argc, char **argv);

private:
    virtual void initStyle() override;
    virtual void applyStyle(QString style);

signals:

public slots:
};

#endif // MEREDEFAULTAPP_H

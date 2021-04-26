#ifndef MEREDEFAULTAPP_H
#define MEREDEFAULTAPP_H

#include "app.h"

#include <QObject>
#include <QDebug>

namespace Mere
{

class DefaultApp : public App
{
    Q_OBJECT
public:
    virtual ~DefaultApp();
    explicit DefaultApp(int &argc, char **argv);

    virtual int init();

private:
    virtual int initStyle() override;
    virtual int applyStyle(QString style);

signals:

public slots:
};

}
#endif // MEREDEFAULTAPP_H

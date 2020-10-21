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
    explicit DefaultApp(int &argc, char **argv);

    virtual void init();

private:
    virtual void initStyle() override;
    virtual void applyStyle(QString style);

signals:

public slots:
};

}
#endif // MEREDEFAULTAPP_H

#ifndef MERE_WIDGETS_DEFAULTAPP_H
#define MERE_WIDGETS_DEFAULTAPP_H

#include "app.h"

#include <QObject>

namespace Mere
{

namespace Widgets
{

class MERE_WIDGETS_LIBSPEC DefaultApp : public App
{
    Q_OBJECT
public:
    virtual ~DefaultApp();
    explicit DefaultApp(int &argc, char **argv);

    virtual int init();

private:
    virtual int initStyle() override;
    virtual int applyStyle(const std::string &path);
};

}
}
#endif // MERE_WIDGETS_DEFAULTAPP_H

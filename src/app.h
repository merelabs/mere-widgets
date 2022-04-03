#ifndef MERE_WIDGETS_APP_H
#define MERE_WIDGETS_APP_H

#include "global.h"
#include <iostream>

#include <QApplication>

#ifndef MERE_NO_LOGGER
class MereLogger;
#endif

namespace Mere
{
namespace Widgets
{

class MERE_WIDGETS_LIBSPEC App : public QApplication
{
    Q_OBJECT
public:
    virtual ~App();
    explicit App(int &argc, char **argv);

    std::string appCode() const;
    void setAppCode(const std::string &code);

    std::string appName() const;
    void setAppName(const std::string &name);

    std::string appVersion() const;
    void setAppVersion(const std::string &version);

#ifndef MERE_NO_LOGGER
    MereLogger* logger();
    void setLogger(MereLogger *logger);
#endif

private:
    virtual int initStyle() = 0;

signals:
    void codeSet(const std::string &code);
    void nameSet(const std::string &name);
    void versionSet(const std::string &version);

public slots:
private:
#ifndef MERE_NO_LOGGER
    MereLogger* m_logger;
#endif
};

}
}


#endif // MERE_WIDGETS_APP_H

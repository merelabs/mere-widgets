#ifndef MERE_WIDGETS_APP_H
#define MERE_WIDGETS_APP_H

#include "global.h"

#include <QApplication>

#ifndef MERE_NO_LOGGER
class MereLogger;
#endif

namespace Mere::Widgets
{

class MERE_WIDGETS_LIBSPEC App : public QApplication
{
    Q_OBJECT
public:
    virtual ~App();
    explicit App(int &argc, char **argv);

    std::string appCode() const;
    void setAppCode(const std::string &code);

#ifndef MERE_NO_LOGGER
    MereLogger* logger();
    void setLogger(MereLogger *logger);
#endif

private:
    virtual int initStyle() = 0;

signals:
    void codeChanged(const std::string &code);

public slots:
private:
#ifndef MERE_NO_LOGGER
    MereLogger* m_logger;
#endif
};

}



#endif // MERE_WIDGETS_APP_H

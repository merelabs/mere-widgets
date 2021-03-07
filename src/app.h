#ifndef MEREAPP_H
#define MEREAPP_H

#include <QApplication>

namespace Mere
{
//    namespace App
//    {
//        #ifdef APP_CODE
//        const QString AppCode   = APP_CODE;
//        #else
//        const QString AppCode   = "unknown";
//        #endif

//        #ifdef APP_NAME
//        const QString AppName   = APP_NAME;
//        #else
//        const QString AppName   = "mere-unknown";
//        #endif

//        #ifdef APP_VERSION
//        const QString AppVersion= APP_VERSION;
//        #else
//        const QString AppVersion= "0.0.0b";
//        #endif
//    }
}

#ifndef MERE_NO_LOGGER
class MereLogger;
#endif

namespace Mere
{

class App : public QApplication
{
    Q_OBJECT
public:
    virtual ~App();
    explicit App(int &argc, char **argv);

    QString appCode() const;
    void setAppCode(QString appCode);

#ifndef MERE_NO_LOGGER
    MereLogger* logger();
    void setLogger(MereLogger *logger);
#endif

private:
    virtual int initStyle() = 0;

signals:
    void codeChanged(const QString &code);

public slots:
private:
    QString m_code;

#ifndef MERE_NO_LOGGER
    MereLogger* m_logger;
#endif
};

}
#endif // MEREAPP_H

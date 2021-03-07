#include "app.h"

#ifndef MERE_NO_LOGGER
#include "mere/log/logger.h"
#endif


Mere::App::~App()
{

}

Mere::App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    #ifdef APP_CODE
    const QString AppCode   = APP_CODE;
    #else
    const QString AppCode   = "unknown";
    #endif

    #ifdef APP_NAME
    const QString AppName   = APP_NAME;
    #else
    const QString AppName   = "mere-unknown";
    #endif

    #ifdef APP_VERSION
    const QString AppVersion= APP_VERSION;
    #else
    const QString AppVersion= "0.0.0b";
    #endif

    setAppCode(AppCode);
    setApplicationName(AppName);
    setApplicationVersion(AppVersion);
}

QString Mere::App::appCode() const
{
    return m_code;
}

void Mere::App::setAppCode(QString code)
{
    m_code = code;
    emit codeChanged(m_code);
}

#ifndef MERE_NO_LOGGER
MereLogger* Mere::App::logger()
{
    return m_logger;
}

void Mere::App::setLogger(MereLogger *logger)
{
    m_logger = logger;
}

#endif



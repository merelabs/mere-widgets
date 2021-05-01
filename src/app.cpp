#include "app.h"

#ifndef MERE_NO_LOGGER
#include "mere/log/logger.h"
#endif


Mere::Widgets::App::~App()
{

}

Mere::Widgets::App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    #ifdef APP_CODE
    const std::string AppCode   = APP_CODE;
    #else
    const std::string AppCode   = "unknown";
    #endif

    #ifdef APP_NAME
    const std::string AppName   = APP_NAME;
    #else
    const std::string AppName   = "mere-unknown";
    #endif

    #ifdef APP_VERSION
    const std::string AppVersion= APP_VERSION;
    #else
    const std::string AppVersion= "0.0.0b";
    #endif

    setAppCode(AppCode);
    setApplicationName(QString::fromStdString(AppName));
    setApplicationVersion(QString::fromStdString(AppVersion));
}

std::string Mere::Widgets::App::appCode() const
{
    return m_code;
}

void Mere::Widgets::App::setAppCode(const std::string &code)
{
    m_code = code;
    emit codeChanged(m_code);
}

#ifndef MERE_NO_LOGGER
MereLogger* Mere::Widgets::App::logger()
{
    return m_logger;
}

void Mere::Widgets::App::setLogger(MereLogger *logger)
{
    m_logger = logger;
}

#endif



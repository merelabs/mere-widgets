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
}

std::string Mere::Widgets::App::appCode() const
{
    return qApp->property("appCode").toString().toStdString();
}

void Mere::Widgets::App::setAppCode(const std::string &code)
{
    QVariant appCode = qApp->property("appCode");
    if (appCode.isValid())
    {
        std::cout << "App code already set, can't be override;" << std::endl;
        return;
    }
    qApp->setProperty("appCode", code.c_str());
    emit codeSet(code);
}

std::string Mere::Widgets::App::appName() const
{
    return qApp->applicationName().toStdString();
}

void Mere::Widgets::App::setAppName(const std::string &name)
{
    QString appName = qApp->applicationName();
    if (!appName.isEmpty())
    {
        std::cout << "App name already set, can't be override;" << std::endl;
        return;
    }
    qApp->setApplicationName(QString::fromStdString(name));
    emit nameSet(name);
}

std::string Mere::Widgets::App::appVersion() const
{
    return qApp->applicationVersion().toStdString();
}

void Mere::Widgets::App::setAppVersion(const std::string &version)
{
    QString appVersion = qApp->applicationVersion();
    if (!appVersion.isEmpty())
    {
        std::cout << "App version already set, can't be override;" << std::endl;
        return;
    }
    qApp->setApplicationVersion(QString::fromStdString(version));
    emit versionSet(version);
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



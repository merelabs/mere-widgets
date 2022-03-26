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
    emit codeChanged(code);
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



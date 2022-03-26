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



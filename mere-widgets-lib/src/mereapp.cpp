#include "mereapp.h"

#ifndef MERE_NO_LOGGER
#include "mere/log/merelogger.h"
#endif


MereApp::~MereApp()
{

}

MereApp::MereApp(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setAppCode(Mere::App::AppCode);
    setApplicationName(Mere::App::AppName);
    setApplicationVersion(Mere::App::AppVersion);
}

QString MereApp::appCode() const
{
    return m_code;
}

void MereApp::setAppCode(QString code)
{
    m_code = code;
    emit codeChanged(m_code);
}

#ifndef MERE_NO_LOGGER
MereLogger* MereApp::logger()
{
    return m_logger;
}

void MereApp::setLogger(MereLogger *logger)
{
    m_logger = logger;
}

#endif



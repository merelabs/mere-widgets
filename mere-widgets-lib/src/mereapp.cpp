#include "mereapp.h"

MereApp::~MereApp()
{

}

MereApp::MereApp(int &argc, char **argv)
    : QApplication(argc, argv)
{

}

QString MereApp::code() const
{
    return m_code;
}

void MereApp::setCode(QString code)
{
    m_code = code;
    emit codeChanged(m_code);
}


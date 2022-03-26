#include "defaultapp.h"

#include "mere/utils/stringutils.h"
#include "mere/utils/fileutils.h"

#include <iostream>

#include <QFile>

Mere::Widgets::DefaultApp::~DefaultApp()
{

}

Mere::Widgets::DefaultApp::DefaultApp(int &argc, char **argv)
    : App(argc, argv)
{

}

int Mere::Widgets::DefaultApp::init()
{
    initStyle();

    return 0;
}

int Mere::Widgets::DefaultApp::initStyle()
{
    std::string code = this->appCode();
    if (Mere::Utils::StringUtils::isBlank(code))
    {
        std::cout << "Style initialization faile as no app-code found." << std::endl;
        return 1;
    }

    std::string style(":/");
    style.append(code).append("/");
    style.append(code).append(".qss");
    applyStyle(style);

    return 0;
}

int Mere::Widgets::DefaultApp::applyStyle(const std::string &path)
{
    QFile file(path.c_str());
    if(!file.exists())
    {
        std::cout << "Failed to apply style - " << path << " not found." << std::endl;
        return 1;
    }

    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());
    if (Mere::Utils::StringUtils::isBlank(styleSheet))
    {
        std::cout << "Failed to apply style - " << path << " contain nothing." << std::endl;
        return 2;
    }

    std::cout << "Applying following stylesheet: " << path << std::endl;

    setStyleSheet(styleSheet);
    return 0;
}

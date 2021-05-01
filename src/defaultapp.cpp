#include "defaultapp.h"

#include "mere/utils/stringutils.h"
#include "mere/utils/fileutils.h"

#include <fstream>
#include <sstream>
#include <iostream>

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
    if(!Mere::Utils::FileUtils::isExist(path))
    {
        std::cout << "Failed to apply style - " << path << " not found." << std::endl;
        return 1;
    }

    std::ifstream file(path);

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string styleSheet = buffer.str();

    if (Mere::Utils::StringUtils::isBlank(styleSheet))
    {
        std::cout << "Failed to apply style - " << path << " contain nothing." << std::endl;
        return 2;
    }

    std::cout << "Applying following stylesheet: " << path << std::endl;
    setStyleSheet(QString::fromStdString(styleSheet));

    return 0;
}

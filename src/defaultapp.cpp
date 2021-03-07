#include "defaultapp.h"

#include "mere/utils/stringutils.h"

#include <QFile>

Mere::DefaultApp::DefaultApp(int &argc, char **argv)
    : App(argc, argv)
{
}

int Mere::DefaultApp::init()
{
    initStyle();

    return 0;
}

int Mere::DefaultApp::initStyle()
{
    QString code = this->appCode();
    if (Mere::Utils::StringUtils::isBlank(code))
    {
        qDebug() << "Style initialization faile as no app-code found.";
        return 1;
    }

    QString style(":/%1/%2.qss");
    style = style.arg(code)
                 .arg(code);

    applyStyle(style);

    return 0;
}

int Mere::DefaultApp::applyStyle(QString style)
{
    QFile file(style);
    if (!file.exists())
    {
        qDebug() << QString("Failed to apply style - %1 not found.").arg(style);
        return 1;
    }

    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());
    if (Mere::Utils::StringUtils::isBlank(styleSheet))
    {
        qDebug() << QString("Failed to apply style - %1 contain nothing.").arg(style);
        return 2;
    }

    qDebug() << "Applying following stylesheet: " << style;
    setStyleSheet(styleSheet);

    return 0;
}

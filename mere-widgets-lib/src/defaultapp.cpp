#include "defaultapp.h"

#include "mere/utils/stringutils.h"

#include <QFile>

Mere::DefaultApp::DefaultApp(int &argc, char **argv)
    : App(argc, argv)
{
}

void Mere::DefaultApp::init()
{
    initStyle();
}

void Mere::DefaultApp::initStyle()
{
    QString code = this->appCode();
    if (Mere::Utils::StringUtils::isBlank(code))
    {
        qDebug() << "Style initialization faile as no app-code found.";
        return;
    }

    QString style(":/%1/%2.qss");
    style = style.arg(code)
                 .arg(code);

    applyStyle(style);
}

void Mere::DefaultApp::applyStyle(QString style)
{
    QFile file(style);
    if (!file.exists())
    {
        qDebug() << QString("Failed to apply style - %1 not found.").arg(style);
        return;
    }

    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());
    if (Mere::Utils::StringUtils::isBlank(styleSheet))
    {
        qDebug() << QString("Failed to apply style - %1 contain nothing.").arg(style);
        return;
    }

    qDebug() << "Applying following stylesheet: " << style;
    setStyleSheet(styleSheet);
}

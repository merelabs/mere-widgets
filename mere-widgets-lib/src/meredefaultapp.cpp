#include "meredefaultapp.h"

#include "mere/utils/merestringutils.h"

#include <QFile>

MereDefaultApp::MereDefaultApp(int &argc, char **argv)
    : MereApp(argc, argv)
{
    initStyle();
}

void MereDefaultApp::initStyle()
{
    QString code = this->code();
    if (MereStringUtils::isBlank(code))
    {
        qDebug() << "Style initialization faile as no app-code found.";
        return;
    }

    QString style(":/%1/%2.qss");
    style = style.arg(code)
                 .arg(code);

    applyStyle(style);
}

void MereDefaultApp::applyStyle(QString style)
{
    QFile file(style);
    if (!file.exists())
    {
        qDebug() << QString("Failed to apply style - %1 not found.").arg(style);
        return;
    }

    file.open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(file.readAll());
    if (MereStringUtils::isBlank(styleSheet))
    {
        qDebug() << QString("Failed to apply style - %1 contain nothing.").arg(style);
        return;
    }

    setStyleSheet(styleSheet);
}

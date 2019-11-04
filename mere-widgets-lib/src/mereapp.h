#ifndef MEREAPP_H
#define MEREAPP_H

#include <QApplication>

class MereApp : public QApplication
{
    Q_OBJECT
//    Q_PROPERTY(QString appCode READ appCode WRITE setAppCode NOTIFY appCodeChanged)
public:
    explicit MereApp(int &argc, char **argv);

signals:

public slots:
};

#endif // MEREAPP_H

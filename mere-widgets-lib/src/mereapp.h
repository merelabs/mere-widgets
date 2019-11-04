#ifndef MEREAPP_H
#define MEREAPP_H

#include <QApplication>

class MereApp : public QApplication
{
    Q_OBJECT
public:
    virtual ~MereApp();
    explicit MereApp(int &argc, char **argv);

    QString code() const;
    void setCode(QString code);

private:
    virtual void initStyle() = 0;

signals:
    void codeChanged(const QString &code);

public slots:
private:
    QString m_code;
};

#endif // MEREAPP_H

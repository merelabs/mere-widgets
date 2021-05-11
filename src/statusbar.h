#ifndef MERESTATUSBAR_H
#define MERESTATUSBAR_H

#include <QLabel>
#include <QWidget>

namespace Mere {

namespace Widgets {

class StatusBar : public QWidget
{
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = nullptr);

    void setStatus(const QString &status);

private:
    void initUI();

signals:

public slots:
private:
    QLabel *m_status;
};

}
}

#endif // MERESTATUSBAR_H

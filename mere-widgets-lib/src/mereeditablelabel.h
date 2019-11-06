#ifndef MEREEDITABLELABEL_H
#define MEREEDITABLELABEL_H

#include <QLabel>
#include <QDebug>

class MereEditableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MereEditableLabel(QWidget *parent = nullptr);
    void setEditable(bool flag = true);

protected:
    bool eventFilter(QObject* object, QEvent* event) override;

private:
    void makeEditable();
    void makeViewable();
    void updateDirtyText();

signals:

public slots:
private:
    bool m_flag;
};

#endif // MEREEDITABLELABEL_H

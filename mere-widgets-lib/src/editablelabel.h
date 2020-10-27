#ifndef MERE_WIDGETS_EDITABLELABEL_H
#define MERE_WIDGETS_EDITABLELABEL_H

#include <QLabel>
#include <QDebug>

namespace Mere
{

namespace  Widgets
{

class EditableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr);
    void setEditable(bool flag = true);
    void setPlaceholder(const QString &placeholder);

    QString text() const;
    void setText(const QString &text);

protected:
    bool eventFilter(QObject* object, QEvent* event) override;

private:
    void makeEditable();
    void makeViewable();
    void updateDirtyText();

    void resetPlaceholder();
    void clearPlaceholder();

signals:
    void changed();

private:
    bool m_placeholderMark;
    QString m_placeholderText;
};

}
}
#endif // MERE_WIDGETS_EDITABLELABEL_H
